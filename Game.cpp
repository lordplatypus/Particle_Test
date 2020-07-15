#include <SFML/Graphics.hpp>
#include "Game.h"
#include "LoadImage.h"
using namespace std;
using namespace sf;

Game::Game()
{
    lm.Load();
}

Game::~Game()
{
}

void Game::Update()
{
    if (!pressedZ && Keyboard::isKeyPressed(Keyboard::Z))
    {
        pm.Test(540, 360);
        pressedZ = true;
    }
    if (!pressedX && Keyboard::isKeyPressed(Keyboard::X))
    {
        pm.Explosion(540, 360);
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

    pm.Update();
}

void Game::Draw()
{
    pm.Draw();
}