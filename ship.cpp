#include "ship.h"

// SPACESHIP MEMBER FUNCTIONS
spaceship::spaceship() { pos = 64; readyToFire = true; }

void spaceship::draw() {  // Tie-Fighter style design
  uLCD.line(pos-7, 125, pos-5, 110, DGREY);
  uLCD.line(pos+7, 125, pos+5, 110, DGREY);
  uLCD.circle(pos,120,2,WHITE);
}

void spaceship::update() {
  uLCD.filled_rectangle(0,128,128,100,BLACK); // Draw black rectangle to "erase" any previous ship drawing
  spaceship::draw();
}

void spaceship::moveLeft() {
  if(pos >= 4) { pos -= SHIP_SPEED; spaceship::update(); }
    else { speaker.PlayNote(500.0, 0.1, 0.01); }
}

void spaceship::moveRight() {
  if(pos <= 124) { pos += SHIP_SPEED; spaceship::update(); }
    else { speaker.PlayNote(500.0, 0.1, 0.01); }
}

bool spaceship::fire() {
  if(!readyToFire){ // Flash "wings" red to indicate reloading
    uLCD.line(pos-7, 125, pos-5, 110, RED);
    uLCD.line(pos+7, 125, pos+5, 110, RED);
    speaker.PlayNote(500.0, 0.1, 0.01);
    uLCD.line(pos-7, 125, pos-5, 110, DGREY);
    uLCD.line(pos+7, 125, pos+5, 110, DGREY);
    return readyToFire;   // false
  } else { readyToFire = false; return true; } // Add firing sound effect???
}

// BULLET MEMBER FUNCTIONS
bullet::bullet(const spaceship &ship) {
  xpos = ship.pos;
  ypos = 110;
  coordinates = new int*[2];
  coordinates[0] = &xpos; coordinates[1] = &ypos;
}

bullet::~bullet() { delete [] coordinates; } // Clean Up Memory

void bullet::draw(int c) {
  uLCD.filled_rectangle(xpos-1, ypos, xpos+1, ypos-5, c);
}

void bullet::update() {
  this->draw(BLACK);
  ypos -= BULLET_SPEED;
  this->draw(WHITE);
}

void bullet::detonate(spaceship &ship) {
  this->draw(RED); this->draw(WHITE); this->draw(BLACK);
  delete this;
  ship.readyToFire = true;
}

int bullet::getAlt() { return ypos; }
int bullet::getX() { return xpos; }

void bullet::operator =(const bullet &copy) { xpos = copy.xpos; ypos = copy.ypos; }
