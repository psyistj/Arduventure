#include <Arduboy.h>
Arduboy arduboy;
int randomnumber;
int randomscale;
int upbuffer;
int downbuffer;
int abuffer;
void setup() {
  arduboy.begin();
  //Set the game to 60 frames per second
  arduboy.setFrameRate(60);
  srand(7 / 8);
  upbuffer = 0;
  downbuffer = 0;
  abuffer = 0;
  arduboy.clear();
}
void loop() {
  //Prevent the Arduboy from running too fast
  if (!arduboy.nextFrame()) {
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
  for (int i = 7; i < 57; i = i + 7) {
    arduboy.drawLine(32, i, 94, i, WHITE);
    arduboy.drawLine(32 + i, 0, 32 + i, 127, WHITE);
  }

  if ( arduboy.pressed(UP_BUTTON) == true and upbuffer == 0 ) {
    upbuffer = 1;
    randomscale = randomscale + 1;
  }
  if ( arduboy.pressed(DOWN_BUTTON) == true and downbuffer == 0 ) {
    downbuffer = 1;
    if(randomscale>1){
      randomscale = randomscale - 1;
    }
  }
  if ( arduboy.pressed(A_BUTTON) == true and abuffer == 0 ) {
    abuffer = 1;
    randomnumber = 1 + rand() % randomscale;
  }
  arduboy.setCursor(2, 2);
  arduboy.print("Q:");
  arduboy.print(randomscale);
  arduboy.print("\n");
  arduboy.setCursor(97, 2);
  arduboy.print("A:");
  arduboy.print(randomnumber);
  arduboy.print("\n");
  if ( arduboy.notPressed(A_BUTTON) == true) {
    abuffer = 0;
  }
  if ( arduboy.notPressed(DOWN_BUTTON) == true ) {
    downbuffer = 0;
  }
  if ( arduboy.notPressed(UP_BUTTON) == true ) {
    upbuffer = 0;
  }
  arduboy.display();
}
