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
    RenderWindow window(VideoMode(1080, 720), "game window"); //game window(ゲームのウィンドウ)
    //window.setFramerateLimit(60);
    DeltaTime delta_time; //Calculates time inbetween frames(次のフレームの時間を計算する)
    Game game; //Handles input and houses the particle manager(キーボードの入力とParticleManagerを管理する)

    while (isRunning)
    {//main game loop(ゲームのループ)
        Event event; //events(イベント)
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
        game.Update(delta_time.GetDeltaTime()); //Update phase(ゲームを更新)
        game.Draw(); //Draw phase(ゲームを描画)
        window.clear(); //Clear window for next frame
        LP::Draw(&window); //draw objects in the window
        window.display(); //display window
    }
    return EXIT_SUCCESS;
}