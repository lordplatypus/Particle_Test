#include <SFML/Graphics.hpp>
#include "LP.h"
#include "Particle.h"
#include "MyMath.h"
using namespace sf;
using namespace std;

Particle::Particle(int imageHandle_, float x_, float y_, float vx_, float vy_, float damp_, float lifespan_, float angle_, float angularVelocity_, float startScale_, float endScale_, int red_, int green_, int blue_, int startAlpha_, int endAlpha_) :
imageHandle{imageHandle_}, x{x_}, y{y_}, vx{vx_}, vy{vy_}, damp{damp_}, lifespan{lifespan_}, angle{angle_}, angularVelocity{angularVelocity_}, startScale{startScale_}, endScale{endScale_}, red{red_}, green{green_}, blue{blue_}, startAlpha{startAlpha_}, endAlpha{endAlpha_}
{}

Particle::~Particle()
{
    LP::DeleteSprite(imageHandle);
}

bool Particle::IsDead() const
{
    return isDead;
}

void Particle::Update(float delta_time)
{
    age += delta_time;

    if (age >= lifespan)
    {
        isDead = true;
        return;
    }

    float progressRate = age / lifespan;
    scale = MyMath::Lerp(startScale, endScale, progressRate);

    // vx += forceX;
    // vy += forceY;

    vx *= pow(damp, delta_time*60);
    vy *= pow(damp, delta_time*60);

    x += vx * delta_time;
    y += vy * delta_time;

    //angularVelocity *= angularDamp;
    angle += angularVelocity * delta_time;

    alpha = MyMath::Lerp(startAlpha, endAlpha, progressRate);

    LP::SetSpriteRotation(imageHandle, angle);
    LP::SetSpriteColor(imageHandle, red, green, blue, alpha);
}

void Particle::Draw()
{
    if (isDead) return;

    LP::DrawSprite(x, y, false, scale, scale, imageHandle);
}