#ifndef GLOBALS_H
#define GLOBALS_H

#include "ship.h"
#include "aliens.h"
#include <cstdlib>
#include <time.h>
#include <vector>

extern bool shoot, goLeft, goRight;

// HW STUFF:
#include "mbed.h"
#include "uLCD_4DGL.h"
#include "PinDetect.h"
#include "MMA8452.h"

extern uLCD_4DGL uLCD;
extern PinDetect pbLeft;
extern PinDetect pbRight;
extern PinDetect pbFire;
extern MMA8452 acc;

// On pb release, set flag to high
void pbLeft_callback(void) { goLeft = true; }
void pbRight_callback(void) { goRight = true; }
void pbFire_callback(void) { shoot = true; }  // fire();

// Collision Checker
bool collisionCheck(bullet &m, vector<ScreenAliens *> &A) {
  bool collision = false;
  int missileAltitude = m.getAlt();
  if(missileAltitude <= 0) { collision = true; }   // Offscreen
    else {  // Check aliens
      int missileX = m.getX();
      bool xMatch, yMatch;
      int alienX, alienY;

      for(int n = 0; n < A.size(); n++) {
        alienX = A[n]->getX(); alienY = A[n]->getY();   // Get Alien coordinates
        xMatch = ((missileX <= (alienX+12)) & (missileX >= (alienX-2)));
        yMatch = ((missileAltitude <= (alienY+5)) & (missileAltitude >= (alienY-9)));
        if (xMatch&yMatch) {
          A[n]->remove();
          A.erase(A.begin()+n);
          collision = true; break;
        }
      }
    }
  return collision;  // True if hit, false if miss
}

// Random Alien Generator
ScreenAliens* createAliens(int nthAlien) {
    ScreenAliens *A;
    int type = rand() % 4;  // 4 Alien classes

    switch(type){
      case 0: A = new AlienBob; break;
      case 1: A = new AlienAlice; break;
      case 2: A = new AlienSpock; break;
      case 3: A = new AlienUhura; break;
      default: A = new AlienBob;  // Redundacy, shouldn't ever get here
    }
    A->setY(5+nthAlien*ALIEN_OFFSET);  // Start at 5, each alien shifted down 10 more pixels
    return A;
}

#endif
