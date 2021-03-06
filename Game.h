#ifndef GAME_H_
#define GAME_H_
#include "ParticleManager.h"
#include "LoadImage.h"

class Game
{
public:
    Game();
    ~Game();
    void Update(float delta_time);
    void Draw() const;

private:
    LoadImage lm;
    ParticleManager pm;
    float timer{0};
    bool particleLimiter{false};

    //Used to make "on button press" system
    bool pressedZ = true;
    bool pressedX = true;
    bool pressedC = true;
    bool pressedQ = true;
    bool pressedW = true;
    bool pressedE = true;
    bool pressedA = true;
    bool pressedS = true;
    bool pressedD = true;
    bool pressedUp = true;
    bool pressedDown = true;
    bool pressedLeft = true;
    bool pressedRight = true;
};

#endif