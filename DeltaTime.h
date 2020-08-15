#ifndef DELTA_TIME_H_
#define DELTA_TIME_H
#include <SFML/Graphics.hpp>

class DeltaTime
{
public:
    DeltaTime() = default;
    ~DeltaTime() = default;
    void ResetDeltaTime()
    {
        clock_.restart();
    }
    //Returns time elapsed in seconds(経過時間を返す)
    float GetDeltaTime()
    {
        return clock_.restart().asSeconds();
    }

private:
    sf::Clock clock_;
};

#endif