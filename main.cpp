#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "LP.h"
#include "Game.h"
#include "DeltaTime.h"
using namespace sf;
using namespace std;

int main()
{
    bool isRunning = true;//bool for main game loop
    RenderWindow window(VideoMode(1080, 720), "game window"); //game window
    //window.setFramerateLimit(60);
    DeltaTime delta_time;
    Game game; //Create game class, handles scenes

    while (isRunning)
    {//main game loop
        Event event; //events
        while (window.pollEvent(event))
        {//
            if (event.type == Event::Closed)
            {
                isRunning = false;
            }
            else if (event.key.code == Keyboard::Escape)
            {
                isRunning = false;
            }
        }
        game.Update(delta_time.GetDeltaTime());
        game.Draw(); //objects are added to the draw maps
        window.clear();
        LP::Draw(&window); //actually draw objects
        window.display();
    }
    return EXIT_SUCCESS;
}