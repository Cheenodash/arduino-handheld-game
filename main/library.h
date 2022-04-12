#ifndef LIBRARY_H
#define LIBRARY_H
#include <Arduino.h>
void disSetup();
void butSetup();
void buttonPush(int pinNumber);
void gameState();
void switchInstance(int a);
void startGame();
void startingGame();
void inGame(int level, int score, int aTile);
void timerBar(int barLength);
void endGame(int currentScore);
void theGame();
void tileSelector();
void successScreen();
#endif
