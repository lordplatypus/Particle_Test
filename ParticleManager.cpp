#include <SFML/Graphics.hpp>
#include "LP.h"
#include "ParticleManager.h"
#include "LoadImage.h"
#include "TextureID.h"
#include <cmath>
using namespace sf;
using namespace std;

ParticleManager::ParticleManager()
{}

ParticleManager::~ParticleManager()
{
    for (auto i : particles)
    {
        delete i;
    }
}

void ParticleManager::Update(float delta_time)
{
    for (auto i : particles)
    {
        if(!i->IsDead()) i->Update(delta_time);
    }

    for (auto i = particles.begin(); i != particles.end(); )
    {
        if ((*i)->IsDead())
        {
            delete *i;
            i = particles.erase(i);
        }
        else i++;
    }
}

void ParticleManager::Draw() const
{
    for (auto i : particles)
    {
        if (!i->IsDead()) i->Draw();
    }
}

void ParticleManager::Test(float x_, float y_)
{
    for (int i = 0; i < 4; i++)
    {
        float vx = 0;
        float vy = 0;
        if (i == 0)
        {
            vx = 100;
            vy = 0;
        }
        else if (i == 1)
        {
            vx = -100;
            vy = 0;
        }
        else if (i == 2)
        {
            vx = 0;
            vy = 100;
        }
        else
        {
            vx = 0;
            vy = -100;
        }

        particles.push_back(new Particle(LP::SetSprite(dot1, Vector2f(x_, y_)), x_, y_, vx, vy, 1, 10, 0, 0, 0, 0, .1f, .5f, 0, 255, 255, 255, 255));
    }
}

void ParticleManager::Explosion(float x_, float y_)
{
    for (int i = 0; i < 70; i++)
    {
                float angle = (rand() % 360) * (M_PI / 180);
                float speed = rand() % 8;
                float vx = (float)cos(angle) * speed;
                float vy = (float)sin(angle) * speed;

                particles.push_back(new Particle(LP::SetSprite(fire, Vector2f(x_, y_)), x_, y_, vx, vy, 1, 10, 0, 0, 0, 0, .1f, .5f, 255, 255, 255, 255, 255));
    }
}

void ParticleManager::SquareExplosion(float x_, float y_)
{
    for (int i = 0; i < 50; i++)
    {
        float speed = (rand() % 50) + 40;
        float vx = ((rand() % 20) - 10) * speed;
        float vy = ((rand() % 20) - 10) * speed;
        float startScale = (rand() % 10) / 10 + .5f;
        int startAlpha = rand() % 255;
        int red = rand() % 255;
        int green = rand() % 255;
        int blue = rand() % 255;

        particles.push_back(new Particle(LP::SetSprite(square8x8, Vector2f(x_, y_)), x_, y_, vx, vy, .9f, 1, 0, 0, 0, 0, startScale, startScale+1, red, green, blue, startAlpha, 0));
    }
}

void ParticleManager::UpArrowSlash(float x_, float y_)
{
    float speed = 5.0f;
    float vx = -(rand() % 6 + 3) * speed;
    float vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(upArrowL, Vector2f(x_, y_)), x_, y_, vx, vy, 1, 1, 0, 0, 0, -20, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 6 + 3) * speed;
    vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(upArrowR, Vector2f(x_, y_)), x_, y_, vx, vy, 1, 1, 0, 0, 0, 20, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(line32x32, Vector2f(x_, y_)), x_ - 16, y_ + 8, 0, 0, 1, .5f, 0, 0, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::DownArrowSlash(float x_, float y_)
{
    float speed = 5.0f;
    float vx = -(rand() % 6 + 3) * speed;
    float vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(downArrowL, Vector2f(x_, y_)), x_, y_, vx, vy, 1, 1, 0, 0, 0, -20, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 6 + 3) * speed;
    vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(downArrowR, Vector2f(x_, y_)), x_, y_, vx, vy, 1, 1, 0, 0, 0, 20, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(line32x32, Vector2f(x_, y_)), x_ - 16, y_ + 8, 0, 0, 1, .5f, 0, 0, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::LeftArrowSlash(float x_, float y_)
{
    float speed = 5.0f;
    float vx = -(rand() % 6 + 3) * speed;
    float vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(leftArrowL, Vector2f(x_, y_)), x_, y_, vx, vy, 1, 1, 0, 0, 0, -20, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 6 + 3) * speed;
    vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(leftArrowR, Vector2f(x_, y_)), x_, y_, vx, vy, 1, 1, 0, 0, 0, 20, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(line32x32, Vector2f(x_, y_)), x_ - 16, y_ + 8, 0, 0, 1, .5f, 0, 0, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::RightArrowSlash(float x_, float y_)
{
    float speed = 5.0f;
    float vx = -(rand() % 6 + 3) * speed;
    float vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(rightArrowL, Vector2f(x_, y_)), x_, y_, vx, vy, 1, 1, 0, 0, 0, -20, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 6 + 3) * speed;
    vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(rightArrowR, Vector2f(x_, y_)), x_, y_, vx, vy, 1, 1, 0, 0, 0, 20, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(line32x32, Vector2f(x_, y_)), x_ - 16, y_ + 8, 0, 0, 1, .5f, 0, 0, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::WhiteOut(float x_, float y_)
{
    particles.push_back(new Particle(LP::SetSprite(white, Vector2f(x_, y_)), x_, y_, 0, 0, 1, .5f, 0, 0, 0, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::Foutain(float x_, float y_)
{
    float lifespan = rand() % 2 + 2;
    float vx = (rand() % 80) - 40;
    float vy = (rand() % 30 + 170) * -1;
    particles.push_back(new Particle(LP::SetSprite(dot1, Vector2f(x_, y_)), x_, y_, vx, vy, 1, lifespan, 0, .05f, 0, 0, .5f, 0, 170, 170, 255, 255, 0));
}

void ParticleManager::Shockwave(float x_, float y_)
{
    int key = LP::SetSprite(ring4, Vector2f(x_, y_));
    LP::SetSpriteOriginCenter(key);
    particles.push_back(new Particle(key, x_, y_, 0, 0, 1, .2f, 0, 0, 0, 0, .15f, .8f, 255, 255, 255, 255, 0));
}

void ParticleManager::Spark(float x_, float y_, float baseAngle_)
{
    for (int i = 0; i < 30; i++)
    {
        float angle = baseAngle_ + (rand() % 20 - 10) * (M_PI / 180);
        float speed = (rand() % 300) + 100;
        float lifespan = (rand() % 2) + 2;
        float vx = float(cos(angle) * speed);
        float vy = float(sin(angle) * speed);
        particles.push_back(new Particle(LP::SetSprite(dot1, Vector2f(x_, y_)), x_, y_, vx, vy, .95f, lifespan, 0, .5f, 0, 0, .1f, .05f, 255, 255, 0, 255, 0));
    }
}

void ParticleManager::Fire(float x_, float y_)
{
    x_ += (rand() % 16) - 8;
    y_ += (rand() % 16) - 8;
    float lifespan = (rand() % 1) + 1;
    float vx = (rand() % 40) - 20;
    float vy = (rand() % 40) - 20;
    float startScale = float((rand() % 5) + 3) / 10.0f;
    float endScale = float((rand() % 2) + 2) / 10.0f;
    float startAlpha = (rand() % 85) + 170;
    float angle = (rand() % 360);
    float angleVelocity = float((rand() % 24) - 12) / 100.0f;
    int key = LP::SetSprite(fire, Vector2f(x_, y_));
    LP::SetSpriteOriginCenter(key);
    particles.push_back(new Particle(key, x_, y_, vx, vy, .97f, lifespan, 0, -.07f, angle, angleVelocity, startScale, endScale, 255, 255, 0, startAlpha, 0));
}

void ParticleManager::WormHole(float x_, float y_)
{
    float angle = rand() % 360 * (M_PI / 180);
    x_ += float(sin(angle)) * 100.0f;
    y_ += float(cos(angle)) * 100.0f;
    float lifespan = 3.0f;
    float vx = -float(sin(angle)) * 100;
    float vy = -float(cos(angle)) * 100;
    float startScale = float(rand() % 7 + 1) / 10.0f;
    float endScale = float(rand() % 3);
    int red = rand() % 256;
    int green = rand() % 256;
    int blue = rand() % 256;
    int startAlpha = rand() % 85 + 170;
    particles.push_back(new Particle(LP::SetSprite(dot1, Vector2f(x_, y_)), x_, y_, vx, vy, .99f, lifespan, 0, .1f, 0, 0, startScale, endScale, 255, 255, 255, startAlpha, 0));
}

void ParticleManager::Charge(float x_, float y_)
{
    float angle = rand() % 360;
    float distance = rand() % 50 + 50;
    float distanceX = float(cos(angle * (M_PI / 180))) * distance;
    float distanceY = float(sin(angle * (M_PI / 180))) * distance;
    float lifespan = float(rand() % 10) / 10.0f;
    x_ += distanceX;
    y_ += distanceY;
    float vx = -distanceX / lifespan;
    float vy = -distanceY / lifespan;
    float startScale = float(rand() % 20 + 10) / 100.0f;

    int key = LP::SetSprite(dot2, Vector2f(x_, y_));
    LP::SetSpriteOriginCenter(key);

    particles.push_back(new Particle(key, x_, y_, vx, vy, 1, lifespan, 0, 0, angle, 0, startScale, 0, 255, 255, 255, 255, 0));

    // float angle = MyRandom.PlusMinus(MyMath.PI);
    //         float distance = MyRandom.Range(20f, 80f);
    //         float distanceX = (float)Math.Cos(angle) * distance;
    //         float distanceY = (float)Math.Sin(angle) * distance;
    //         int lifeSpan = MyRandom.Range(15, 40);

    //         particles.Add(new Particle() {
    //             x = x + distanceX,
    //             y = y + distanceY,
    //             lifeSpan = lifeSpan,
    //             imageHandle = Image.particleDot2,
    //             vx = -distanceX / lifeSpan,
    //             vy = -distanceY / lifeSpan,
    //             startScale = MyRandom.Range(0.13f, 0.25f),
    //             endScale = 0.0f,
    //             startAlpha = 0,
    //             endAlpha = 255,
    //             angle = angle,
    //         });
}

void ParticleManager::Firework(float x_, float y_)
{    
    int red = rand() % 256;
    int green = rand() % 256;
    int blue = rand() % 256;

    for (int i = 0; i < 400; i++)
    {
        float lifespan = rand() % 2 + 2;
        float angle = rand() % 360 * (M_PI / 180);
        float speed = rand() % 300;
        float vx = float(sin(angle) * speed);
        float vy = float(cos(angle) * speed);
        particles.push_back(new Particle(LP::SetSprite(dot3, Vector2f(x_, y_)), x_, y_, vx, vy, .95f, lifespan, 0, .1f, 0, 0, .2f, 0, red, green, blue, 255, 0));
    }

    red = rand() % 256;
    green = rand() % 256;
    blue = rand() % 256;

    for (int i = 0; i < 700; i++)
    {
        float lifespan = rand() % 2 + 1;
        float angle = rand() % 360 * (M_PI / 180);
        float speed = rand() % 600;
        float vx = float(sin(angle) * speed);
        float vy = float(cos(angle) * speed);
        particles.push_back(new Particle(LP::SetSprite(dot3, Vector2f(x_, y_)), x_, y_, vx, vy, .95f, lifespan, 0, .1f, 0, 0, .2f, 0, red, green, blue, 255, 0));
    }
}

void ParticleManager::Heal(float x_, float y_)
{


    // particles.Add(new Particle()
    //         {
    //             x = x,
    //             y = y,
    //             lifeSpan = 25,
    //             imageHandle = Image.particleRing2,
    //             startScale = 0.1f,
    //             endScale = 0.4f,
    //             startAlpha = 180,
    //             endAlpha = 0,
    //             blendMode = DX.DX_BLENDMODE_ADD,
    //             red = 170,
    //             green = 255,
    //             blue = 170
    //         });
    //         particles.Add(new Particle()
    //         {
    //             x = x,
    //             y = y,
    //             lifeSpan = 12,
    //             imageHandle = Image.particleRing2,
    //             startScale = 0.2f,
    //             endScale = 0.6f,
    //             startAlpha = 150,
    //             endAlpha = 0,
    //             blendMode = DX.DX_BLENDMODE_ADD,
    //             red = 170,
    //             green = 255,
    //             blue = 170
    //         });

    //         for (int i = 0; i < 20; i++)
    //         {
    //             particles.Add(new Particle()
    //             {
    //                 x = x + MyRandom.PlusMinus(20),
    //                 y = y + MyRandom.PlusMinus(20),
    //                 vx = MyRandom.PlusMinus(0.8f),
    //                 vy = MyRandom.Range(-0.3f, 0.9f),
    //                 forceY = -0.06f,
    //                 damp = 0.98f,
    //                 lifeSpan = MyRandom.Range(10, 45),
    //                 imageHandle = Image.particleGlitter1,
    //                 startScale = 0.05f,
    //                 endScale = MyRandom.Range(0.4f, 0.8f),
    //                 startAlpha = 255,
    //                 endAlpha = 0,
    //                 blendMode = DX.DX_BLENDMODE_ADD,
    //                 red = 170,
    //                 green = 255,
    //                 blue = 170
    //             });
    //         }

    //         for (int i = 0; i < 20; i++)
    //         {
    //             particles.Add(
    //                 new Particle()
    //                 {
    //                     x = x + MyRandom.PlusMinus(30),
    //                     y = y  + 30 + MyRandom.PlusMinus(30),
    //                     lifeSpan = MyRandom.Range(20, 40),
    //                     imageHandle = Image.particleLine1,
    //                     vy = -MyRandom.Range(1f, 5f),
    //                     vx = 0,
    //                     forceY = -0.07f,
    //                     damp = 1f,
    //                     startScale = 0.3f,
    //                     endScale = 0.15f,
    //                     startAlpha = 255,
    //                     endAlpha = 0,
    //                     angle = 90f * MyMath.Deg2Rad,
    //                     blendMode = DX.DX_BLENDMODE_ADD,
    //                     red = 170,
    //                     green = 255,
    //                     blue = 170
    //                 });
    //         }
}

void ParticleManager::PickUp(float x_, float y_)
{

    // particles.Add(new Particle()
    //         {
    //             x = x,
    //             y = y,
    //             lifeSpan = 12,
    //             imageHandle = Image.particleRing2,
    //             startScale = 0.15f,
    //             endScale = 0.35f,
    //             startAlpha = 150,
    //             endAlpha = 0,
    //             blendMode = DX.DX_BLENDMODE_ADD,
    //             red = 170,
    //             green = 170,
    //         });

    //         particles.Add(new Particle()
    //         {
    //             x = x,
    //             y = y,
    //             lifeSpan = 24,
    //             imageHandle = Image.particleGlitter1,
    //             startScale = 1f,
    //             endScale = 0.4f,
    //             endAlpha = 0,
    //             blendMode = DX.DX_BLENDMODE_ADD,
    //             blue = 100,
    //         });

    //         for (int i = 0; i < 7; i++)
    //         {
    //             particles.Add(new Particle()
    //             {
    //                 x = x + MyRandom.PlusMinus(10f),
    //                 y = y + MyRandom.PlusMinus(10f),
    //                 lifeSpan = MyRandom.Range(20, 50),
    //                 imageHandle = Image.particleGlitter1,
    //                 startScale = 0.6f,
    //                 endScale = 0.1f,
    //                 startAlpha = 190,
    //                 endAlpha = 0,
    //                 blendMode = DX.DX_BLENDMODE_ADD,
    //                 blue = 100,
    //                 vx = MyRandom.PlusMinus(2f),
    //                 vy = MyRandom.Range(-3, -7f),
    //                 damp = 0.96f,
    //                 forceY = 0.15f,
    //             });
    //         }
}