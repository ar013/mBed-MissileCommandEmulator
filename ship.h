#ifndef SHIP_H
#define SHIP_H

#include "uLCD_4DGL.h"
extern uLCD_4DGL uLCD;

#define SHIP_SPEED 4
#define BULLET_SPEED 7

// Class Interfaces for spaceship and bullet
class spaceship {
  friend class bullet;      // Give bullet access to protected data (to set readyToFire)
  public: // MEMBER FUNCTIONS: Draw, Update, Move, Fire
    spaceship();      // Constructor

    void draw();      // draw ship on screen
    void update();    // No need to redraw ship unless movement is detected
    void moveLeft();
    void moveRight();
    bool fire();

  private:
    int pos;          // X-Position
    bool readyToFire; // true if no bullet currently on screen
};

class bullet {
  public: // MEMBER FUNCTIONS: Draw, Update, Collision Checker
    bullet(const spaceship &ship);         // Constructor
    ~bullet();        // removes bullet, sets readyToFire to true

    void draw(int);      // Draw Bullet (with defined color)
    void update();       // Update bullet position and redraw
    void detonate(spaceship &ship); // detonate on impact, ship to reload
    int getAlt();
    int getX();
    
    void operator =(const bullet &copy);

  private:
    int **coordinates;   // For destructor
    int xpos;
    int ypos;
};

#endif
