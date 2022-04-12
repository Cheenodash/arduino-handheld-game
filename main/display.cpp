#include "library.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void disSetup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }


  display.display();
  delay(2000);
  display.clearDisplay();

}

void startGame() {
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(12, 24);
  display.print("READY?");
  display.display();
  switchInstance(1);
}
void startingGame() {
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(28, 20);
  display.print("SET");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(26, 16);
  display.print("GO!");
  display.display();
  delay(1000);
  switchInstance(2);
}
void inGame(int level, int score, int aTile) {
  display.clearDisplay();
if (aTile == 0){
   display.fillRect(1, 12, 40, 44, SSD1306_WHITE);
  display.drawRect(44, 12, 40, 44, SSD1306_WHITE);
  display.drawRect(87, 12, 40, 44, SSD1306_WHITE);
}
if (aTile == 1){
   display.drawRect(1, 12, 40, 44, SSD1306_WHITE);
  display.fillRect(44, 12, 40, 44, SSD1306_WHITE);
  display.drawRect(87, 12, 40, 44, SSD1306_WHITE);
}
if (aTile == 2){
   display.drawRect(1, 12, 40, 44, SSD1306_WHITE);
  display.drawRect(44, 12, 40, 44, SSD1306_WHITE);
  display.fillRect(87, 12, 40, 44, SSD1306_WHITE);
}
  
  
 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(1, 1);
  display.print("LEVEL: ");
  display.setCursor(37, 1);
  display.print(level);
  display.setCursor(70, 1);
  display.print("SCORE: ");
  display.setCursor(106, 1);
  display.print(score);
  display.display();
}

void timerBar(int barLength) {
  display.fillRect(4, 58, barLength, 2, SSD1306_WHITE);
  display.display();
}

void successScreen() {
  display.clearDisplay();
 display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(12, 24);
  display.print("WOO!");
  display.display();
  delay(200);
}
void endGame(int currentScore) {
  display.clearDisplay();
 display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(14, 10);
  display.print("oh no :(");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(14, 30);
  display.print("FINAL SCORE:");
  display.setCursor(90, 30);
  display.print(currentScore);
  
   display.setCursor(28, 50);
  display.print("PLAY AGAIN?");
  display.display();
  switchInstance(0);
}
