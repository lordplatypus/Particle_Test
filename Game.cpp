#include <SFML/Graphics.hpp>
#include "Game.h"
#include "LoadImage.h"
using namespace std;
using namespace sf;

Game::Game()
{
    lm.Load(); //Load in textures
}

Game::~Game()
{
}

void Game::Update(float delta_time)
{
    timer += delta_time;
    if (timer >= .01f) //regulates the amount of particles 
    {
        if (Keyboard::isKeyPressed(Keyboard::LShift))
        {
            if (!pressedZ && Keyboard::isKeyPressed(Keyboard::Z))
            {
                pm.Charge(540, 360);
                //pressedZ = true;
            }
            if (!pressedX && Keyboard::isKeyPressed(Keyboard::X))
            {
                pm.Firework(540, 360);
                pressedX = true;
            }
            if (!pressedC && Keyboard::isKeyPressed(Keyboard::C))
            {
                pm.SquareExplosion(540, 360);
                pressedC = true;
            }
            if (!pressedQ && Keyboard::isKeyPressed(Keyboard::Q))
            {
                pm.WhiteOut(0, 0);
                pressedQ = true;
            }
            if (!pressedW && Keyboard::isKeyPressed(Keyboard::W))
            {
                pm.Foutain(540, 360);
                //pressedW = true;
            }
            if (!pressedE && Keyboard::isKeyPressed(Keyboard::E))
            {
                pm.Shockwave(540, 360);
                pressedE = true;
            }
            if (!pressedA && Keyboard::isKeyPressed(Keyboard::A))
            {
                float angle = rand() % 360;
                pm.Spark(540, 360, angle);
                pressedA = true;
            }
            if (!pressedS && Keyboard::isKeyPressed(Keyboard::S))
            {
                pm.Fire(540, 360);
                //pressedS = true;
            }
            if (!pressedD && Keyboard::isKeyPressed(Keyboard::D))
            {
                pm.WormHole(540, 360);
                //pressedD = true;
            }
            if (!pressedUp && Keyboard::isKeyPressed(Keyboard::Up))
            {
                pm.UpArrowSlash(540, 360);
                pressedUp = true;
            }
            if (!pressedDown && Keyboard::isKeyPressed(Keyboard::Down))
            {
                pm.DownArrowSlash(540, 360);
                pressedDown = true;
            }
            if (!pressedLeft && Keyboard::isKeyPressed(Keyboard::Left))
            {
                pm.LeftArrowSlash(540, 360);
                pressedLeft = true;
            }
            if (!pressedRight && Keyboard::isKeyPressed(Keyboard::Right))
            {
                pm.RightArrowSlash(540, 360);
                pressedRight = true;
            }
        }
        else
        {
            if (!pressedZ && Keyboard::isKeyPressed(Keyboard::Z))
            {
                pm.Test(540, 360);
                pressedZ = true;
            }
            if (!pressedX && Keyboard::isKeyPressed(Keyboard::X))
            {
                int x = rand() % 1080;
                int y = rand() % 720;
                pm.Firework(x, y);
                pressedX = true;
            }
            if (!pressedC && Keyboard::isKeyPressed(Keyboard::C))
            {
                pm.SquareExplosion(540, 360);
                pressedC = true;
            }
            if (!pressedQ && Keyboard::isKeyPressed(Keyboard::Q))
            {
                pm.WhiteOut(0, 0);
                pressedQ = true;
            }
            if (!pressedW && Keyboard::isKeyPressed(Keyboard::W))
            {
                pm.Foutain(540, 360);
                //pressedW = true;
            }
            if (!pressedE && Keyboard::isKeyPressed(Keyboard::E))
            {
                pm.Shockwave(540, 360);
                pressedE = true;
            }
            if (!pressedA && Keyboard::isKeyPressed(Keyboard::A))
            {
                float angle = rand() % 360;
                pm.Spark(540, 360, angle);
                pressedA = true;
            }
            if (!pressedS && Keyboard::isKeyPressed(Keyboard::S))
            {
                pm.Fire(540, 360);
                //pressedS = true;
            }
            if (!pressedD && Keyboard::isKeyPressed(Keyboard::D))
            {
                pm.WormHole(540, 360);
                //pressedD = true;
            }
            if (!pressedUp && Keyboard::isKeyPressed(Keyboard::Up))
            {
                pm.UpArrowSlash(540, 360);
                pressedUp = true;
            }
            if (!pressedDown && Keyboard::isKeyPressed(Keyboard::Down))
            {
                pm.DownArrowSlash(540, 360);
                pressedDown = true;
            }
            if (!pressedLeft && Keyboard::isKeyPressed(Keyboard::Left))
            {
                pm.LeftArrowSlash(540, 360);
                pressedLeft = true;
            }
            if (!pressedRight && Keyboard::isKeyPressed(Keyboard::Right))
            {
                pm.RightArrowSlash(540, 360);
                pressedRight = true;
            }
        }
        timer = 0;
    }

    //Reset bool when key is released  
    if (!Keyboard::isKeyPressed(Keyboard::Z)) pressedZ = false;
    if (!Keyboard::isKeyPressed(Keyboard::X)) pressedX = false;
    if (!Keyboard::isKeyPressed(Keyboard::C)) pressedC = false;
    if (!Keyboard::isKeyPressed(Keyboard::Q)) pressedQ = false;
    if (!Keyboard::isKeyPressed(Keyboard::W)) pressedW = false;
    if (!Keyboard::isKeyPressed(Keyboard::E)) pressedE = false;
    if (!Keyboard::isKeyPressed(Keyboard::A)) pressedA = false;
    if (!Keyboard::isKeyPressed(Keyboard::S)) pressedS = false;
    if (!Keyboard::isKeyPressed(Keyboard::D)) pressedD = false;
    if (!Keyboard::isKeyPressed(Keyboard::Up)) pressedUp = false;
    if (!Keyboard::isKeyPressed(Keyboard::Down)) pressedDown = false;
    if (!Keyboard::isKeyPressed(Keyboard::Left)) pressedLeft = false;
    if (!Keyboard::isKeyPressed(Keyboard::Right)) pressedRight = false;
        

    pm.Update(delta_time); //update the particles(パーティクルを更新)
}

void Game::Draw() const
{
    pm.Draw(); //draw particles
}