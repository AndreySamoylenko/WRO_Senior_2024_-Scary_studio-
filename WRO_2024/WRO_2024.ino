#include <GyverOLED.h>
#include <Servo.h>
#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include "TCS34725.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

//----------------------- LED_STRIP ----------------------------
#define LED_PIN    A4
#define LED_COUNT 16
#define USE_LED 1
Adafruit_NeoPixel lent(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//------------------------- DRIVER -------------------------
#define ma1 6
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


// initialisation
Servo wheel_servo;
Servo manup_l;
Servo manup_r;
Servo claw_l;
Servo claw_r;
Servo ramk;
Servo table_serv;
//---------------------------MANIPULATOR-----------------
#define MANUPL 33
#define MANDOWNL 105
#define MANDOWNISHL 92
#define MANDOWNISHISHL 80
#define MANDOWNDROPL 105

#define MANUPR 116
#define MANDOWNR 39
#define MANDOWNISHR 52
#define MANDOWNISHISHR 64
#define MANDOWNDROPR 68

#define CLAWLCLOSE 5
#define CLAWLCLOSECUBE 125
#define CLAWLOPEN 180
#define CLAWLOPENISH 120

#define CLAWRCLOSE 15
#define CLAWRCLOSECUBE 130
#define CLAWROPEN 180
#define CLAWROPENISH 125


//--------------------------------------------------------
#define MIN_SPEED 50



int datflmin = 516;
int datfrmin = 508;
int datblmin = 500;
int datbrmin = 490;
int datplmin = 120;
int datprmin = 150;

int datflmax = 988;
int datfrmax = 988;
int datblmax = 988;
int datbrmax = 988;
int datplmax = 600;
int datprmax = 700;

float e_old = 0;
float dat1, dat2 = 0;

int count_c_l = 0;
int count_c_r = 0;

uint16_t r1, g1, b1, c1;
uint16_t r2, g2, b2, c2;
volatile long countl = 0;
volatile long countr = 0;
int r2y_count = 0;

char colorr = 'r';
char colorl = 'y';
char colorsl[4] = {'g', 'g', ' ', ' '};
char colorsr[4] = {'b', 'b', ' ', ' '};

uint32_t time = millis();
uint32_t time2 = millis();
uint32_t idle_time = 0;

uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;
bool ultra_lgbt_flag = 0;
bool bread = 0;

char left_grob = 'g';
char right_grob = 'b';
char start_cubes[2] = {'g', 'b'};
const char random_colors[8] = {'r', 'y', 'g', 'b', 'd', 'r', 'y', 'g'};

GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;
SparkFun_APDS9960 apds = SparkFun_APDS9960();
TCS34725 tcs_left;





void setup(void) {
  Serial.begin(115200);

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
  pinMode(A3, OUTPUT);
  pinMode(A7, OUTPUT);
  digitalWrite(RELAY_PIN, 0);
  digitalWrite(buzz, 0);
  digitalWrite(A3, 0);
  digitalWrite(A7, 1);
  beep(200);
  //-----------------------TCS--------------------------

  Wire.begin();
  Wire.setClock(400000L);
  if (!tcs_left.attach(Wire))
    Serial.println("ERROR: TCS34725 NOT FOUND !!!");

  tcs_left.integrationTime(33); // ms
  tcs_left.gain(TCS34725::Gain::X01);

  if ( apds.init() ) {
    //    Serial.println(F("APDS-9960 initialization complete"));
    delay(1);
  } else {
    delay(1);
  }

  if ( apds.enableLightSensor(false) ) {
    delay(1);
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }

  // Wait for initialization and calibration to finish
  delay(400);

  if (  !apds.readAmbientLight(ambient_light) ||
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
  ramk.attach(RAMK_SERV);

  digitalWrite(RELAY_PIN, 1);
  delay(50);

  manup_l.write(MANUPL);
  manup_r.write(MANUPR);
  delay(100);
  claw_l.write(CLAWLOPENISH);
  claw_r.write(CLAWROPENISH);

  delay(250);

  claw_l.write(CLAWLCLOSE);
  claw_r.write(CLAWRCLOSE);
  //  claw_l.write(CLAWLOPENISH);
  //  claw_r.write(CLAWROPENISH);fh
  //  palk_r.write(0);
  //  palk_l.write(180);

  //  table_serv.write(180);
  //  delay(2000);
  table_serv.write(94);
  ramk.write(90);


  beep(200);

  //  digitalWrite(RELAY_PIN, 0);
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
  lent.setBrightness(40);
  //---------------------------------------------------------
  delay(300);
  digitalWrite(RELAY_PIN, 1);
  delay(150);
  ramk.write(130);
}

//------------------------------------------------------- START TYPE -------------------------------------------------------------

#define START_TYPE  0 // 0 = storona dalshe ot musora, 1 = storona blizhe k musoru

// start
// 1 - 28.4 secs
// 0 - 28.5 secs
// most
// 20 - 24 secs


void loop(void) {
  //----------------------testing------------------------------

  time = millis();
  wait_button(0);
  //  pidx(0.3, 0.03, 3, 120, 1, 0, 9);
  //  obstacle();
  pidx(0.2, 0.02, 3, 60, 0, 0, 60);
  pidenc(0.3, 0.02, 3, -100, 1, 400, 0);
  pidenc(0.3, 0.03, 3, -250, 0, 1400, 0);
  pidenc(0.3, 0.03, 3, -90, 0, 600, 0);
  trashNeMost();
  turnl(1, 90, 1);
  pidenc(0.4, 0.03, 4, 70, 1, 500, 0);
  pidenc(0.3, 0.02, 3, 255, 0, 1400, 0);
  pidenc(0.3, 0.02, 3, 170, 0, 600, 0);
  pidx(0.2, 0.02, 3, 60, 0, 0, 100);
  MoveSync(-180, -180, 0, 30, 20);

  sbros();
  timer();
  delay(1000);
  //  turn(120,1,90);
  //  Serial.println(get_distance());
  //  ramkTube();
  //  delay(600);
  //  driveToWall(530);


  //-----------------------main program------------------------
  //  time = millis();
  //  wait_button(0);
  //  start();
  //  main_loop();
  //  timer();
  //  wait_button(0);

  //  delay(10000);
}
