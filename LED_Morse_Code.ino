#include <rgb_lcd.h>
#include <list>

int userInput[4] = {};

for (int i = 0; i < 4; i++) {
  userInput[i] 
}
// 1 is dot, 2 is dash, 0 is nothing
int a[4] = {1,2,0,0};
int b[4] = {2,1,1,0};
int c[4] = {2,1,2,1};
int d[4] = {2,1,1,0};
int e[4] = {1,0,0,0};
int f[4] = {1,1,2,1};
int g[4] = {2,2,1,0};
int h[4] = {1,1,1,1};
int i[4] = {1,1,0,0};
int j[4] = {1,2,2,2};
int k[4] = {2,1,2,0};
int l[4] = {1,2,1,1};
int m[4] = {2,2,0,0};
int n[4] = {2,1,0,0};
int o[4] = {2,2,2,0};
int p[4] = {1,2,2,1};
int q[4] = {2,2,1,2};
int r[4] = {1,2,1,0};
int s[4] = {1,1,1,0};
int t[4] = {2,0,0,0};
int u[4] = {1,1,2,0};
int v[4] = {1,1,1,2};
int w[4] = {1,2,2,0};
int x[4] = {2,1,1,2};
int y[4] = {2,1,2,2};
int z[4] = {2,2,1,1};

//RGB Values for the LCD screen
int colorR = 70;
int colorG = 123;
int colorB = 35;

//assigning sensors to pins
const int button = 6;
const int RLED = 4;
const int BLED = 7;

//values needed to work
int buttonPress = 0;
int counter = 0;
int startTime = 0;
int endTime = 0;
int elapsedTime = 0;

//assigning a variable to lcd
rgb_lcd lcd;

void setup() {
  //assinging if the pin reads or writes
  pinMode(button,INPUT);
  pinMode(RLED,OUTPUT);
  pinMode(BLED,OUTPUT);

  //settings columns and rows and color
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  delay(1000);
}

void loop() {
  //if button is pressed then light turn on
  buttonPress = digitalRead(button);
  //counts the milliseconds since reset
  counter = (millis());  
  
  //if button is pressed then stop counter
  if (buttonPress == HIGH)
  {
    digitalWrite(RLED,HIGH);
    startTime = counter;
    /*lcd.setCursor(0,0);
    lcd.print(startTime);*/

  }
  //if button realeased sync counters
  else
  {
    digitalWrite(RLED,LOW);
    endTime = (millis());    
    /*lcd.setCursor(0,1);
    lcd.print(endTime);*/
  }

  //subtracts stopped time with always running time
  elapsedTime = endTime - startTime;
  lcd.setCursor(8,0);
  lcd.print(elapsedTime);

  if (elapsedTime <= -500)
  {
    lcd.setCursor(8,1);
    lcd.print("DASH");
  }
  else if ((elapsedTime < 0) && (elapsedTime > -500))
  {
    lcd.setCursor(11,1);
    lcd.print(" ");
    lcd.setCursor(8,1);
    lcd.print("DOT");
    
  }
  else if (elapsedTime >= 800)
  {
    lcd.setCursor(8,1);
    lcd.print("ZERO");
  }

}
