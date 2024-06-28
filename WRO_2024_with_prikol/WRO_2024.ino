// подключение всякого
#include <GyverOLED.h>          // олег
#include <Servo.h>              // крутилки
#include <Wire.h>               // что то для I2C
#include <SparkFun_APDS9960.h>  // датчик цвета 1
#include "TCS34725.h"           // датчик цвета 2
#include <Adafruit_NeoPixel.h>  // лента
#ifdef __AVR__                  // ваще хз чо это
#include <avr/power.h>          // Required for 16 MHz Adafruit Trinket
#endif

//----------------------- LED_STRIP ----------------------------
#define LED_PIN    A4
#define LED_COUNT 16
#define USE_LED 1
Adafruit_NeoPixel lent(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
//------------------------- COLOR SENSOR STATE -------------
#define STATE_PIN 34

//------------------------- DRIVER -------------------------
#define ma1 6 // пины всякого
#define ma2 4
#define mb1 8
#define mb2 10

#define PASSIVE_A 52
#define PASSIVE_B 46

//-------------------SOFT I2C-------------------------------

#define SDApin 23
#define SCLpin 24


//-------------------BUZZER---------------------------------
#define buzz A9
//#define buzz_gnd 47

//-------------------BUTTON---------------------------------
#define buttonPin A6

//---------------RELAY----------------
#define RELAY_PIN 31
//---------------DISTANCE-------------
#define SHARP_PIN A13

//---------------SERVOS----------------
//PINS
#define MANIPUL_UP_L 7
#define MANIPUL_CLAW_L 25
#define MANIPUL_UP_R 5
#define MANIPUL_CLAW_R 17
#define TABLE_SERVO 3
#define RAMK_SERV 15
#define T_SERVO 13


// initialisation
Servo wheel_servo;
Servo manup_l;
Servo manup_r;
Servo claw_l;
Servo claw_r;
Servo ramk;
Servo t_servo;
Servo table_serv;
//---------------------------MANIPULATOR-----------------
#define MANUPL 32 // всякие константы, замеренные через боль пот и слёзы
#define MANDOWNL 105
#define MANDOWNISHL 92
#define MANDOWNISHISHL 80
#define MANDOWNDROPL 105

#define MANUPR 117
#define MANDOWNR 39
#define MANDOWNISHR 52
#define MANDOWNISHISHR 64
#define MANDOWNDROPR 68

#define CLAWLCLOSE 7
#define CLAWLCLOSECUBE 92
#define CLAWLOPEN 180
#define CLAWLOPENISH  110

#define CLAWRCLOSE 7
#define CLAWRCLOSECUBE 92
#define CLAWROPEN 180
#define CLAWROPENISH 125


//--------------------------------------------------------
#define MIN_SPEED 50

// калибровка всякого

int datflmin = 439;
int datfrmin = 420;
int datblmin = 421;
int datbrmin = 464;
int datplmin = 300;
int datprmin = 340;

int datflmax = 942;
int datfrmax = 943;
int datblmax = 980;
int datbrmax = 980;
int datplmax = 770;
int datprmax = 880;

float e_old = 0;
float dat1, dat2 = 0;

int count_c_l = 0;
int count_c_r = 0;

uint16_t r1, g1, b1, c1;
uint16_t r2, g2, b2, c2;
volatile long countl = 0;
volatile long countr = 0;
int r2y_count = 0;


// объявление всякого
char colorr = 'r'; // цвет после скана цвета слева
char colorl = 'y';// то же самое только справа
char colorsl[4] = {' ', ' ', ' ', ' '}; // массив кубов левого шкафа
char colorsr[4] = {' ', ' ', ' ', ' '}; // массив кубов правого

uint32_t time = millis(); // переменные нужные для подсчета времени
uint32_t time2 = millis();
uint32_t idle_time = 0;

uint16_t ambient_light = 0; // переменые для датчиков цвета
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;

bool ultra_lgbt_flag = 0; // флаги
bool bread = 0;

char left_grob = colorsl[0];  // цвет кубов, которые везем в левом шкафу
char right_grob = colorsr[0]; // то же самое для правого
char start_cubes[2] = {'b', 'b'}; // цвет кубов у старта
const char random_colors[8] = {'r', 'y', 'g', 'b', 'd', 'r', 'y', 'g'}; // не важн

GyverOLED<SSD1306_128x64, OLED_BUFFER> oled; // инициализация дисплея
SparkFun_APDS9960 apds = SparkFun_APDS9960(); // правого датчика цвета
TCS34725 tcs_left; // левого датчика цвета





void setup(void) {
  Serial.begin(115200); // старт монитора порта

  //------------------------PINS------------------------
  pinMode(ma1, OUTPUT);
  pinMode(ma2, OUTPUT);
  pinMode(mb1, OUTPUT);
  pinMode(mb2, OUTPUT);
  pinMode(PASSIVE_A, OUTPUT);
  pinMode(PASSIVE_B, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(A3, OUTPUT); // питание бокового датчик линии 1
  pinMode(A7, OUTPUT); // питание бокового датчик линии 2
  pinMode(STATE_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, 0);
  digitalWrite(buzz, 0);
  digitalWrite(A3, 0); // минус бокового датчика линии
  digitalWrite(A7, 1); // плюс его же
  beep(200);
  //-----------------------TCS--------------------------

  Wire.begin(); // запуск i2c
  Wire.setClock(400000L); // разгон i2c
  if (!tcs_left.attach(Wire)) // проверка наличия датчика
    Serial.println("ERROR: TCS34725 NOT FOUND !!!");

  tcs_left.integrationTime(33); // настройка времени считывания
  tcs_left.gain(TCS34725::Gain::X01);

  if ( apds.init() ) { // раздупление правого датчика, тк первый скан всегда комом
    delay(1);
  } else {
    delay(1);
  }

  if ( apds.enableLightSensor(false) ) { // второй этап раздупления
    delay(1);
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }

  // Wait for initialization and calibration to finish
  delay(400);

  if (  !apds.readAmbientLight(ambient_light) || // финальный этап раздупления
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Error reading light values");
  } else {
    delay(1);
  }

  delay(100);
  //-----------------------SERVOS------------------------
  table_serv.attach(TABLE_SERVO);
  manup_l.attach(MANIPUL_UP_L);
  manup_r.attach(MANIPUL_UP_R);
  claw_l.attach(MANIPUL_CLAW_L);
  claw_r.attach(MANIPUL_CLAW_R);
  t_servo.attach(T_SERVO);
  ramk.attach(RAMK_SERV);

//  digitalWrite(RELAY_PIN, 1);
//  delay(10);
//  digitalWrite(RELAY_PIN, 0);



  //  t_up();
  manup_l.write(MANUPL);
  manup_r.write(MANUPR);
  delay(100);
  //  claw_l.write(CLAWLOPENISH);
  //  claw_r.write(CLAWROPENISH);

  delay(250);

  claw_l.write(CLAWLCLOSE);
  claw_r.write(CLAWRCLOSE);
  table_serv.write(94);
  //  ramk.write(90);


  beep(200);
  //------------------------OLED-------------------------
  oled.init();
  oled.rect(0, 0, 128, 64);
  oled.update();
  delay(200);
  oled.clear();
  oled.update();
  oled.setScale(3);
  //----------------------INTERRUPTS--------------------
  attachInterrupt(digitalPinToInterrupt(19), encl, RISING);
  attachInterrupt(digitalPinToInterrupt(18), encr, RISING);

  //------------------------LENTA----------------------------
  lent.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  lent.show();            // Turn OFF all pixels ASAP
  lent.setBrightness(60);
  //---------------------------------------------------------
  delay(300);
  ramk.write(130);
  t_down();

  
}

//------------------------------------------------------- START TYPE -------------------------------------------------------------

#define START_TYPE  1 // 0 = storona dalshe ot musora, 1 = storona blizhe k musoru

// start
// 1 - 28.4 secs
// 0 - 28.5 secs
// most
// 20 - 24 secs


void loop(void) {
  //----------------------testing------------------------------
  //  while(1){
  //    Serial.println(get_distance());
  //  }
  //  wait_button(0);
  //  t_up();
  //  table_serv.write(158);
  //  pidx(0.2, 0.02, 3, 60, 0, 0, 60);
  //  //  most();
  //  //  wait_button(0);
  //  obstacle();
  //digitalWrite(STATE_PIN,1);
  //delay(200);
  //digitalWrite(STATE_PIN,0);
  //delay(200);
  //while(1){
  //  get_color_man();
  //  indicate1(colorl,6);
  //  Serial.println(get_distance());
  //  lent.show();
  //  delay(600);
  //}
  //-----------------------main program------------------------

  wait_button(0);
  time = millis();
  start();
  main_loop();
  timer();
  wait_button(0);

  delay(10000);
}
