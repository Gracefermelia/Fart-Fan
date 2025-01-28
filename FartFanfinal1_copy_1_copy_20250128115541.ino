 #include <Adafruit_NeoPixel.h>

#define PIN13 13
#define PIN12 12
#define PIN11 11  // input pin Neopixel is attached to
#define PIN10 10
#define PIN9 9

#define BigfanPIN 8 //big fan


#define NUMPIXELS 8  // number of neopixels in strip

Adafruit_NeoPixel pixels13 = Adafruit_NeoPixel(NUMPIXELS, PIN13, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels12 = Adafruit_NeoPixel(NUMPIXELS, PIN12, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels11 = Adafruit_NeoPixel(NUMPIXELS, PIN11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels10 = Adafruit_NeoPixel(NUMPIXELS, PIN10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels9 = Adafruit_NeoPixel(NUMPIXELS, PIN9, NEO_GRB + NEO_KHZ800);

int delayval = 1000;  // timing delay in milliseconds

int sensor1Thres = 310;
int sensor2Thres = 300;
int sensor3Thres = 430;
int sensor4Thres = 155;
int sensor5Thres = 320;
//value1: 187
//value2: 210
//value3: 206
//value4: 91
//value5 182

//value1: 394   124  207
//value2: 327   72   117
//value3: 471   216   264
//value4: 133         42
//value5 319          137

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  // Initialize the NeoPixel library.
  pixels13.begin();
  pixels12.begin();
  pixels11.begin();
  pixels10.begin();
  pixels9.begin();

  Serial.begin(9600);
  pinMode(13, OUTPUT);  //neopixel pin
  pinMode(12, OUTPUT);  //neopixel pin
  pinMode(11, OUTPUT);  //neopixel pin
  pinMode(10, OUTPUT);  //neopixel pin
  pinMode(9, OUTPUT);   //neopixel pin

  pinMode(BigfanPIN, OUTPUT);   //big fan
 

  pinMode(A1, INPUT);  // gas pin
  pinMode(A2, INPUT);  // gas pin
  pinMode(A3, INPUT);  // gas pin
  pinMode(A4, INPUT);  // gas pin
  pinMode(A5, INPUT);  // gas pin
}

void loop() {

  int value1 = analogRead(A1);
  int value2 = analogRead(A2);
  int value3 = analogRead(A3);
  int value4 = analogRead(A4);
  int value5 = analogRead(A5);

  Serial.print("value1: ");
    Serial.println(value1);

  Serial.print("value2: ");
    Serial.println(value2);

   Serial.print("value3: ");
      Serial.println(value3);

   Serial.print("value4: ");
      Serial.println(value4);

  Serial.print("value5 ");
   Serial.println(value5);


  if (value1 > sensor1Thres) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels13.setPixelColor(i, pixels13.Color(250, 0, 0));
      pixels13.show();
       digitalWrite(BigfanPIN, HIGH); //turn big fan on

    }
  } else {

    for (int i = 0; i < NUMPIXELS; i++) {
      pixels13.setPixelColor(i, pixels13.Color(0, 255, 0));
      pixels13.show();
    }
  }
  if (value2 > sensor2Thres) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels12.setPixelColor(i, pixels12.Color(250, 0, 0));
      pixels12.show();
       digitalWrite(BigfanPIN, HIGH); //turn big fan on
    }
  } else {

    for (int i = 0; i < NUMPIXELS; i++) {
      pixels12.setPixelColor(i, pixels12.Color(0, 255, 0));
      pixels12.show();
    }
  }
  if (value3 > sensor3Thres) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels11.setPixelColor(i, pixels11.Color(250, 0, 0));
      pixels11.show();
             digitalWrite(BigfanPIN, HIGH); //turn big fan on

    }
  } else {

    for (int i = 0; i < NUMPIXELS; i++) {
      pixels11.setPixelColor(i, pixels11.Color(0, 255, 0));
      pixels11.show();
    }
  }
  if (value4 > sensor4Thres) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels1 0.setPixelColor(i, pixels10.Color(250, 0, 0));
      pixels10.show();
             digitalWrite(BigfanPIN, HIGH); //turn big fan on

    }
  } else {

    for (int i = 0; i < NUMPIXELS; i++) {
      pixels10.setPixelColor(i, pixels10.Color(0, 255, 0));
      pixels10.show();
    }
  }
  if (value5 > sensor5Thres) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels9.setPixelColor(i, pixels9.Color(250, 0, 0));
      pixels9.show();
             digitalWrite(BigfanPIN, HIGH); //turn big fan on

    }
  } else {

    for (int i = 0; i < NUMPIXELS; i++) {
      pixels9.setPixelColor(i, pixels9.Color(0, 255, 0));
      pixels9.show();
    }
    }
if(value1<sensor1Thres&&value2<sensor2Thres&&value3<sensor3Thres&&value4<sensor4Thres&&value5<sensor5Thres){
         digitalWrite(BigfanPIN, LOW); //turn big fan off
 delay(1000);
}
}
