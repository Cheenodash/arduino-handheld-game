#include "library.h"
int input4Pin = 7;
int input3Pin = 4;
int input2Pin = 8;
int input1Pin = 0;
int instance = 0;
int tileSelect = 0;
int aTile = 0;
int gameLevel = 1;
int currentScore = 0;
int scoreModifier = 10;
int gameSpeed = -2;
int barLength = 0;
int barIncrease = 10;

void butSetup() {
  pinMode(input4Pin, INPUT);
  pinMode(input3Pin, INPUT);
  pinMode(input2Pin, INPUT);
  pinMode(input1Pin, INPUT);
}

void switchInstance(int a) {
  if (a == 1) {
    int pushed = digitalRead(7);  // read input value
    if (pushed == HIGH) { // check if the input is HIGH (button released)
      // digitalWrite(ledPin, LOW);   turn LED OFF
      instance = a;
    }
    else {
      //digitalWrite(ledPin, HIGH);  // turn LED ON

    }
  } else {
    if (a == 0) {
      int push = digitalRead(7);  // read input value
    if (push == HIGH) { // check if the input is HIGH (button released)
      instance = 0;
      tileSelect = 0;
    aTile = 0;
    gameLevel = 1;
    currentScore = 0;
    scoreModifier = 10;
    gameSpeed = 0;
    }
    else {
      //digitalWrite(ledPin, HIGH);  // turn LED ON

    }
      
    } else {
    instance = a;
    }
  }
}

void gameState() {
  if (currentScore <= 99) {
    gameSpeed = -2;
    gameLevel = 1;
    scoreModifier = 10;
    barIncrease = 10;
  }
  if (currentScore >= 100) {
    gameSpeed = 0;
    gameLevel = 2;
    scoreModifier = 14;
    barIncrease = 12;
  }
  if (currentScore >= 250) {
    gameSpeed = 2;
    gameLevel = 3;
    scoreModifier = 18;
    barIncrease = 15;
  }
  if (currentScore >= 500) {
    gameSpeed = 4;
    gameLevel = 4;
    scoreModifier = 22;
    barIncrease = 20;
  }
  if (currentScore >= 800) {
    gameSpeed = 6;
    gameLevel = 5;
    scoreModifier = 26;
    barIncrease = 30;
  }

  if (instance == 0) {
    startGame();
  }
  if (instance == 1) {
    startingGame();
  }
  if (instance == 2) {
    theGame();
  }
  if (instance == 3) {
    endGame(currentScore);
  }

}

void theGame() {
  int success = 0;
  int pinNum;
  int wrongPin1;
  int wrongPin2;
  int bonus = 10;
  tileSelector();
  inGame(gameLevel, currentScore, aTile);
  int speedo = 2;
  for (int i = gameSpeed; i <= 10; i++) {
    if (success == 0) {
      barLength = barLength + barIncrease;
      timerBar(barLength);

      if (aTile == 0) {
        pinNum = 0;
        wrongPin1 = 8;
        wrongPin2 = 4;
      }
      if (aTile == 1) {
        pinNum = 8;
        wrongPin1 = 0;
        wrongPin2 = 4;
      }
      if (aTile == 2) {
        pinNum = 4;
        wrongPin1 = 8;
        wrongPin2 = 0;
      }

      int pushed = digitalRead(pinNum);  // read input value
      if (pushed == HIGH) { // check if the input is HIGH (button released)
        success = 1;
      }
      else {
        int wrongPush1 = digitalRead(wrongPin1);  // read input value
        if (wrongPush1 == HIGH) { // check if the input is HIGH (button released)
          success = 0;
          switchInstance(3);
           i = 11;
        }
        int wrongPush2 = digitalRead(wrongPin2);
        if (wrongPush2 == HIGH) { // check if the input is HIGH (button released)
          success = 0;
          switchInstance(3);
          i = 11;
        }
      }
      delay(100);
      bonus = scoreModifier - i;
    } else {

      i = 10;
    }
  }
  barLength = 0;
  if (success == 0) {
    switchInstance(3);
  } else {
    successScreen();

    currentScore = currentScore + bonus;

  }
}

void tileSelector() {
  randomSeed(analogRead(1));
  int randomNumber = random(3);
  aTile = randomNumber;

}

void buttonPush(int pinNumber)
{

  int pushed = digitalRead(pinNumber);  // read input value
  if (pushed == HIGH) { // check if the input is HIGH (button released)
    // digitalWrite(ledPin, LOW);   turn LED OFF
    Serial.print(pinNumber);
  }
  else {
    //digitalWrite(ledPin, HIGH);  // turn LED ON

  }
}
