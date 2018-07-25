#ifndef ALIENS_H
#define ALIENS_H

#include "uLCD_4DGL.h"
extern uLCD_4DGL uLCD;

// Class Interfaces for Alien Objects

class ScreenAliens {
  public:
    ScreenAliens();
    virtual ~ScreenAliens();    // Virtual destructor for Derived classes
    void remove();

    virtual void draw() =0;
    virtual void update() =0;

    int getX() const;
    int getY() const;
    void setY( int );

  protected:
    int xpos;
    int ypos;
    int startY;
    int **coordinates;  // For destructor
};

class AlienBob: public ScreenAliens {
  public:
    AlienBob();
    ~AlienBob();

    void draw();    // Draw Sprite on screen
    void update();  // Update position

  private:
    bool armsUp;
    bool left;  // true->left | false->right
    bool **bobData;   // For destructor
};

class AlienAlice: public ScreenAliens {
  public:
    AlienAlice();
    ~AlienAlice();

    void draw();    // Draw Sprite on screen
    void update();  // Update position

  private:
    bool left;  // true->left | false->right
    bool up;  //   true->up | false->down
    bool **aliceData;   // For destructor
};

class AlienSpock: public ScreenAliens {
  public:
    AlienSpock();
    ~AlienSpock();

    void draw();
    void update();

  private:
    bool left;
    bool up;
    bool **spockData;
};

class AlienUhura: public ScreenAliens {
  public:
    AlienUhura();
    ~AlienUhura();

    void draw();
    void update();

  private:
    bool left;
    bool **uhuraData;
};

// Alien Sprites
#define ALIEN_OFFSET 13
#define ALIEN_SPEED 4
#define ALIEN_HEIGHT 8
#define ALIEN_WIDTH 11
#define _ 0x000000 //BLACK
#define X 0xFFFFFF   //WHITE

static int alienBobDown_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
          _,_,X,_,_,_,_,_,X,_,_,
          _,_,_,X,_,_,_,X,_,_,_,
          _,_,X,X,X,X,X,X,X,_,_,
          _,X,X,_,X,X,X,_,X,X,_,
          X,X,X,X,X,X,X,X,X,X,X,
          X,_,X,X,X,X,X,X,X,_,X,
          X,_,X,_,_,_,_,_,X,_,X,
          _,_,_,X,X,_,X,X,_,_,_,
        };

static int alienBobUp_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
          _,_,X,_,_,_,_,_,X,_,_,
          X,_,_,X,_,_,_,X,_,_,X,
          X,_,X,X,X,X,X,X,X,_,X,
          X,X,X,_,X,X,X,_,X,X,X,
          X,X,X,X,X,X,X,X,X,X,X,
          _,_,X,X,X,X,X,X,X,_,_,
          _,_,X,_,_,_,_,_,X,_,_,
          _,X,_,_,_,_,_,_,_,X,_,
        };

static int alienAlice_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
          _,_,_,_,X,X,X,_,_,_,_,
          _,X,X,X,X,X,X,X,X,X,_,
          X,X,X,X,X,X,X,X,X,X,X,
          X,X,X,_,_,X,_,_,X,X,X,
          X,X,X,X,X,X,X,X,X,X,X,
          _,_,_,X,X,_,X,X,_,_,_,
          _,_,X,X,_,_,_,X,X,_,_,
          X,X,_,_,_,X,_,_,_,X,X,
        };


static int alienSpock_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
          X,_,_,_,_,_,_,_,_,_,X,
          X,X,_,_,X,X,X,_,_,X,X,
          _,X,X,X,X,X,X,X,X,X,_,
          _,X,_,_,_,X,_,_,_,X,_,
          _,X,X,_,X,X,X,_,X,X,_,
          _,_,X,X,X,X,X,X,X,_,_,
          _,_,X,X,_,_,_,X,X,_,_,
          _,_,_,X,X,X,X,X,_,_,_,
        };

static int alienUhura_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
          X,X,X,X,X,X,X,X,X,X,X,
          X,_,X,X,X,X,X,X,X,_,X,
          X,_,X,_,_,X,_,_,X,_,X,
          X,_,X,X,_,X,_,X,X,_,X,
          X,_,X,X,X,X,X,X,X,_,X,
          X,_,_,X,_,_,_,X,_,_,X,
          X,_,_,X,X,X,X,X,_,_,X,
          X,_,_,_,X,X,X,_,_,_,X,
        };

static int BLANKSPRITE[ALIEN_HEIGHT * ALIEN_WIDTH] = {
          _,_,_,_,_,_,_,_,_,_,_,
          _,_,_,_,_,_,_,_,_,_,_,
          _,_,_,_,_,_,_,_,_,_,_,
          _,_,_,_,_,_,_,_,_,_,_,
          _,_,_,_,_,_,_,_,_,_,_,
          _,_,_,_,_,_,_,_,_,_,_,
          _,_,_,_,_,_,_,_,_,_,_,
          _,_,_,_,_,_,_,_,_,_,_,
        };

#endif
