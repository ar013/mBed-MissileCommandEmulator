// ECE 2036: Section A - LAB 06
// DATE COMPLETED: 04.18.18
// Andres Rodriguez II
// GTiD: 903126687

#include "globals.h"      // All other libraries and headers included in globals

using namespace std;

// Instantiate HW Objects
uLCD_4DGL uLCD(p28, p27, p29);
PinDetect pbLeft(p17);
PinDetect pbRight(p18);
PinDetect pbFire(p16);
Speaker speaker(p21);

Serial pc(USBTX,USBRX);     // Not used

// For pb callbacks:
bool shoot = false;
bool goLeft = false;
bool goRight = false;

int main () {
  // PRE-GAME SETUP:
  bool gameOver = false;

    // HW Setup
  uLCD.baudrate(300000);
  uLCD.cls();

  MMA8452 acc(p9, p10, 40000);

  pbLeft.mode(PullUp);
  pbRight.mode(PullUp);
  pbFire.mode(PullUp);
  wait(0.1); // allow for initial pullUp

    // Attach Callbacks
  pbLeft.attach_deasserted(&pbLeft_callback);
  pbRight.attach_deasserted(&pbRight_callback);
  pbFire.attach_deasserted(&pbFire_callback);

    // Set Sampling Frequencies
  pbLeft.setSampleFrequency();
  pbRight.setSampleFrequency();
  pbFire.setSampleFrequency();

    // Accelerometer Parameters
  acc.setBitDepth(MMA8452::BIT_DEPTH_12);
  acc.setDynamicRange(MMA8452::DYNAMIC_RANGE_4G);
  acc.setDataRate(MMA8452::RATE_100);
  int accY;

    // Instantiate (and Draw) Aliens (x6)
  vector<ScreenAliens *> Alien;
  for(int ii = 0; ii < 6; ++ii) {
     Alien.push_back(::createAliens(ii)); // Generate 6 aliens of pseudo random class
    (Alien.at(ii))->draw();
  }
    // Instantiate (and Draw) Spaceship (x1)
  spaceship ship;
  ship.draw();

    // Other variable:
  bullet *missile = NULL; // Allocate missile pointer, if NULL, no missile on screen
  int k = 0;

  // BEGIN GAME:
  time_t startTime; startTime = time(0); // Pseudo-timer
  Timer gameClock; gameClock.start();
  while(!gameOver) { // gameOver when all aliens have been destroyed
      // Interrupts: callback and reset
    if(shoot) {
      if(ship.fire()){
        missile = new bullet(ship);
        missile->draw(WHITE);
        speaker.PlayNote(1250.0, 0.1, 0.01);
      }
      shoot = false;
    }
    if(goLeft) { ship.moveLeft(); goLeft = false; }
    if(goRight) { ship.moveRight(); goRight = false; }

      // Accelerometer
    acc.readYCount(&accY);
    if(accY > 75) { goRight = true; }
    if(accY < -75) { goLeft = true; }
      // Update all Objects
    if(missile != NULL) { missile->update(); }
    Alien[k%Alien.size()]->update(); // move one alien per loop, in order

      // Check for collisions, but only if missileOnScreen
    if(missile != NULL) {
      bool hit = ::collisionCheck(*missile, Alien);
      if(hit) { missile->detonate(ship); missile = NULL;}
    }

    k++;
    gameOver = Alien.empty();
  } gameClock.stop();
  time_t endTime = time(0)-startTime;
  // POST-GAME: DISPLAY GAME STATS
  uLCD.printf("\n\n Congratulations!! \n \n Earth Saved! \n \n \n (%d Seconds)", time(0));    // PRINT TIME

  return 0; // Successful completion of main()
} // end game
