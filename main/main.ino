#include "library.h"


void setup() {
  Serial.begin(9600);
 
  disSetup();
  butSetup();
}

void loop() {
  
 gameState();

}
