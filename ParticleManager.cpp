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

void ParticleManager::Draw()
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

        particles.push_back(new Particle(LP::SetSprite(x_, y_, dot1), x_, y_, vx, vy, 1, 10, 0, 0, .1f, .5f, 0, 255, 255, 255, 255));
    }
}

void ParticleManager::Explosion(float x_, float y_)
{
    srand(time(NULL));

    for (int i = 0; i < 70; i++)
    {
                float angle = (rand() % 360) * (M_PI / 180);
                float speed = rand() % 8;
                float vx = (float)cos(angle) * speed;
                float vy = (float)sin(angle) * speed;

                particles.push_back(new Particle(LP::SetSprite(x_, y_, fire), x_, y_, vx, vy, 1, 10, 0, 0, .1f, .5f, 255, 255, 255, 255, 255));
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

        particles.push_back(new Particle(LP::SetSprite(x_, y_, square8x8), x_, y_, vx, vy, .9f, 1, 0, 0, startScale, startScale+1, red, green, blue, startAlpha, 0));
    }
}

void ParticleManager::UpArrowSlash(float x_, float y_)
{
    float speed = 5.0f;
    float vx = -(rand() % 6 + 3) * speed;
    float vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, upArrowL), x_, y_, vx, vy, 1, 1, 0, -20, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 6 + 3) * speed;
    vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, upArrowR), x_, y_, vx, vy, 1, 1, 0, 20, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(x_, y_, line32x32), x_ - 16, y_ + 8, 0, 0, 1, .5f, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::DownArrowSlash(float x_, float y_)
{
    float speed = 5.0f;
    float vx = -(rand() % 6 + 3) * speed;
    float vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, downArrowL), x_, y_, vx, vy, 1, 1, 0, -20, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 6 + 3) * speed;
    vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, downArrowR), x_, y_, vx, vy, 1, 1, 0, 20, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(x_, y_, line32x32), x_ - 16, y_ + 8, 0, 0, 1, .5f, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::LeftArrowSlash(float x_, float y_)
{
    float speed = 5.0f;
    float vx = -(rand() % 6 + 3) * speed;
    float vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, leftArrowL), x_, y_, vx, vy, 1, 1, 0, -20, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 6 + 3) * speed;
    vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, leftArrowR), x_, y_, vx, vy, 1, 1, 0, 20, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(x_, y_, line32x32), x_ - 16, y_ + 8, 0, 0, 1, .5f, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::RightArrowSlash(float x_, float y_)
{
    float speed = 5.0f;
    float vx = -(rand() % 6 + 3) * speed;
    float vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, rightArrowL), x_, y_, vx, vy, 1, 1, 0, -20, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 6 + 3) * speed;
    vy = (rand() % 10) * speed;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, rightArrowR), x_, y_, vx, vy, 1, 1, 0, 20, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(x_, y_, line32x32), x_ - 16, y_ + 8, 0, 0, 1, .5f, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::WhiteOut(float x_, float y_)
{
    particles.push_back(new Particle(LP::SetSprite(x_, y_, white), x_, y_, 0, 0, 1, .5f, 0, 0, 1, 1, 255, 255, 255, 255, 0));
}