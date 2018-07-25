#include "aliens.h"

// CONSTRUCTORS and DESTRUCTORS:
ScreenAliens::ScreenAliens() {    // Base Constructor
  xpos = 1 + rand() % 115;
  coordinates = new int*[3];
  coordinates[0] = &xpos; coordinates[1] = &ypos; coordinates[2] = &startY;
}
ScreenAliens::~ScreenAliens() { delete [] coordinates; }
void ScreenAliens::remove() { // remove function to erase and call destructor for each alien
  uLCD.BLIT(xpos,ypos,ALIEN_WIDTH,ALIEN_HEIGHT,BLANKSPRITE);
  delete this;
}

AlienBob::AlienBob() {
  armsUp = rand() % 2;
  left = rand() % 2;

  bobData = new bool*[2];
  bobData[0] = &armsUp; bobData[1] = &left;
}
AlienBob::~AlienBob() { delete [] bobData; }

AlienAlice::AlienAlice() {
  left = rand() % 2;
  up = rand() % 2;

  aliceData = new bool*[2];
  aliceData[0] = &left; aliceData[1] = &up;
}
AlienAlice::~AlienAlice() { delete [] aliceData; }

AlienSpock::AlienSpock() {
  left = rand() % 2;
  up = rand() % 2;

  spockData = new bool*[2];
  spockData[0] = &left; spockData[1] = &up;
}
AlienSpock::~AlienSpock() { delete [] spockData; }

AlienUhura::AlienUhura() {
  left = rand() % 2;

  uhuraData = new bool*[1]; // Indices unneccessary, but included for upgradability later
  uhuraData[0] = &left;
}
AlienUhura::~AlienUhura() { delete [] uhuraData; }

// GET FUNCTIONS (to pass coordinates to GLOBAL collisionCheck)
int ScreenAliens::getX() const { return xpos; }
int ScreenAliens::getY() const { return ypos; }
void ScreenAliens::setY(int alt) { ypos = alt; startY = alt;}

// 'draw()' MEMBER FUNCTIONS
void AlienBob::draw() {
  if(this->armsUp) {
    armsUp = false;
    uLCD.BLIT(xpos, ypos, ALIEN_WIDTH, ALIEN_HEIGHT, alienBobUp_sprite);
  } else {
    armsUp = true;
    uLCD.BLIT(xpos, ypos, ALIEN_WIDTH, ALIEN_HEIGHT, alienBobDown_sprite);
  }
}

void AlienAlice::draw() {
  uLCD.BLIT(xpos, ypos, ALIEN_WIDTH, ALIEN_HEIGHT, alienAlice_sprite);
}

void AlienSpock::draw() {
  uLCD.BLIT(xpos, ypos, ALIEN_WIDTH, ALIEN_HEIGHT, alienSpock_sprite);
}

void AlienUhura::draw() {
  uLCD.BLIT(xpos, ypos, ALIEN_WIDTH, ALIEN_HEIGHT, alienUhura_sprite);
}

// 'update()' MEMBER FUNCTIONS FOR MOVEMENT
void AlienBob::update() {
  uLCD.BLIT(xpos,ypos,ALIEN_WIDTH,ALIEN_HEIGHT, BLANKSPRITE);

  if(left) {
    if((this->xpos) <= 11) { left = false; xpos += ALIEN_SPEED; }
      else { xpos -= ALIEN_SPEED; } // Keep moving left until left bound hit
  } else {
    if((this->xpos) >=118) { left = true; xpos -= ALIEN_SPEED; }
      else { xpos += ALIEN_SPEED; } // Keep moving right until right bound hit
  }

  this->draw();
}

void AlienAlice::update() { // ZigZag accross screen between Y: 45-55
  uLCD.BLIT(xpos,ypos,ALIEN_WIDTH,ALIEN_HEIGHT, BLANKSPRITE);

  // HORIZONTAL
  if(left) {
    if((this->xpos) <= 11) { left = false; xpos += ALIEN_SPEED; }
      else { xpos -= ALIEN_SPEED; } // Keep moving left until left bound hit
  } else {
    if((this->xpos) >=118) { left = true; xpos -= ALIEN_SPEED; }
      else { xpos += ALIEN_SPEED; } // Keep moving right until right bound hit
  }

  // VERTICAL
  if(up) {
    if((this->ypos) <= startY) {up = false; ypos += ALIEN_SPEED; }
      else { ypos -= ALIEN_SPEED; }
  } else {
    if((this->ypos) >= startY+7) { up = true; ypos -= ALIEN_SPEED; }
      else { ypos += ALIEN_SPEED; }
  }

  this->draw();
}

void AlienSpock::update() { // Random movements within range
  uLCD.BLIT(xpos,ypos,ALIEN_WIDTH,ALIEN_HEIGHT, BLANKSPRITE);

  // HORIZONTAL
  if(left) {
    if((this->xpos) <= 11) { left = false; xpos += ALIEN_SPEED; }
      else { xpos -= ALIEN_SPEED; } // Keep moving left until left bound hit
  } else {
    if((this->xpos) >=118) { left = true; xpos -= ALIEN_SPEED; }
      else { xpos += ALIEN_SPEED; } // Keep moving right until right bound hit
  }

  // VERTICAL
  if(up) {
    if((this->ypos) <= startY) {up = false; ypos += ALIEN_SPEED; }
      else { ypos -= ALIEN_SPEED; }
  } else {
    if((this->ypos) >= startY+7) { up = true; ypos -= ALIEN_SPEED; }
      else { ypos += ALIEN_SPEED; }
  }

  this->draw();
}

void AlienUhura::update() {
  uLCD.BLIT(xpos,ypos,ALIEN_WIDTH,ALIEN_HEIGHT, BLANKSPRITE);

  if(left) {
    if((this->xpos) <= 11) { left = false; xpos += ALIEN_SPEED; }
      else { xpos -= ALIEN_SPEED; } // Keep moving left until left bound hit
  } else {
    if((this->xpos) >=118) { left = true; xpos -= ALIEN_SPEED; }
      else { xpos += ALIEN_SPEED; } // Keep moving right until right bound hit
  }

  this->draw();
}
