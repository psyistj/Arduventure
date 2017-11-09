#include <Arduboy.h>
Arduboy arduboy;
void setup() {
  arduboy.begin();
  //Set the game to 60 frames per second
  arduboy.setFrameRate(60);
  arduboy.clear();
}
void loop() {
  //Prevent the Arduboy from running too fast
  if(!arduboy.nextFrame()) {
    return;
  }
  arduboy.clear();
  //Game code here
  //Gameplay frame
    //outline
    arduboy.drawLine(0, 0, 127, 0, WHITE);
    arduboy.drawLine(127, 0, 127, 63, WHITE);
    arduboy.drawLine(0, 0, 0, 63, WHITE);
    arduboy.drawLine(0, 63, 127, 63, WHITE);
    arduboy.drawLine(32, 0, 32, 63, WHITE);
    arduboy.drawLine(95, 0, 95, 63, WHITE);
    //mapline
    for(int i = 7; i<57; i=i+7){
      arduboy.drawLine(32, i, 94, i, WHITE);
      arduboy.drawLine(32+i, 0, 32+i, 127, WHITE);
    }
  arduboy.display();
}