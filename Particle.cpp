#include <SFML/Graphics.hpp>
#include "LP.h"
#include "Particle.h"
using namespace sf;
using namespace std;

Particle::Particle(int imageHandle_, float x_, float y_, float vx_, float vy_, float damp_, int lifespan_, float angle_, float angularVelocity_, float startScale_, float endScale_, int red_, int green_, int blue_, int startAlpha_, int endAlpha_) :
imageHandle{imageHandle_}, x{x_}, y{y_}, vx{vx_}, vy{vy_}, damp{damp_}, lifespan{lifespan_}, angle{angle_}, angularVelocity{angularVelocity_}, startScale{startScale_}, endScale{endScale_}, red{red_}, green{green_}, blue{blue_}, startAlpha{startAlpha_}, endAlpha{endAlpha_}
{
    lifespanInMS = lifespan_;
    lifespanTest = chrono::high_resolution_clock::now(); 
}

Particle::~Particle()
{
    LP::DeleteSprite(imageHandle);
}

void Particle::Update()
{
    chrono::high_resolution_clock::time_point now = chrono::high_resolution_clock::now(); 
    auto age = chrono::duration_cast<chrono::microseconds>(now - lifespanTest).count();

    if (age >= lifespanInMS)
    {
        isDead = true;
        return;
    }

    if (age >= timer + (1000000 / 60) || firstInstance)
    {
        timer = age;

        counter += (endScale - startScale) / (60.f * (lifespanInMS / 1000000));
        scale = startScale + counter;

        vx += forceX;
        vy += forceY;

        vx *= damp;
        vy *= damp;

        x += vx;
        y += vy;

        angularVelocity *= angularDamp;
        angle += angularVelocity;

        if (startAlpha != endAlpha) alphaCounter += (endAlpha - startAlpha) / (60.f * (lifespanInMS / 1000000));
        alpha = startAlpha + alphaCounter;

        LP::SetSpriteRotation(imageHandle, angle);
        LP::SetSpriteColor(imageHandle, red, green, blue, alpha);

        if (firstInstance) firstInstance = false;
    }
}

void Particle::Draw()
{
    if (isDead) return;

    LP::DrawSprite(x, y, false, scale, scale, imageHandle);
}