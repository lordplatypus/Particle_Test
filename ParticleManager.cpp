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

void ParticleManager::Update()
{
    for (auto i : particles)
    {
        if(!i->isDead) i->Update();
    }

    int numOfParticles = particles.size();
    for (int i = 0; i < numOfParticles; i++)
    {//Remove GameObjects that are dead
        if (particles[i]->isDead) 
        {
            particles.erase(particles.begin() + i);
            numOfParticles = particles.size();
            i--;
        }
    }
}

void ParticleManager::Draw()
{
    for (auto i : particles)
    {
        if (!i->isDead) i->Draw();
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
            vx = 10;
            vy = 0;
        }
        else if (i == 1)
        {
            vx = -10;
            vy = 0;
        }
        else if (i == 2)
        {
            vx = 0;
            vy = 10;
        }
        else
        {
            vx = 0;
            vy = -10;
        }

        particles.push_back(new Particle(LP::SetSprite(x_, y_, dot1), x_, y_, vx, vy, 1, 1000000, 0, 0, .1f, .5f, 0, 255, 255, 255, 255));
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
                //float startScale = MyRandom.Range(0.5f, 1.3f);

                particles.push_back(new Particle(LP::SetSprite(x_, y_, fire), x_, y_, vx, vy, 1, 1000000, 0, 0, .1f, .5f, 255, 255, 255, 255, 255));

                // particles.push_back(new Particle());
                // particles.push_back(new Particle());
                // particles.back()->x = rand() % 20 + (x_ - 10);
                // particles.back()->y = rand() % 20 + (y_ - 10);
                // particles.back()->lifespan = rand() % 500000 + (MP::GetCurrentPlayingMusicOffSetInMS() + 250000);
                // particles.back()->imageHandle = LP::SetSprite(x_, y_, fire);
                // particles.back()->vx = (float)cos(angle) * speed;
                // particles.back()->vy = (float)sin(angle) * speed;
                // particles.back()->damp = 0.88f;
                // particles.back()->startScale = .5f;
                // particles.back()->endScale = .5f * 0.75f;
                // particles.back()->endAlpha = 0;
    }
}

void ParticleManager::SquareExplosion(float x_, float y_)
{
    srand(time(NULL));

    for (int i = 0; i < 50; i++)
    {
                float angle = (rand() % 360) * (M_PI / 180);
                float speed = rand() % 8;
                float vx = (float)cos(angle) * speed;
                float vy = (float)sin(angle) * speed;
                float startScale = (rand() % 10) / 10 + .5f;
                int startAlpha = rand() % 255;
                int red = rand() % 255;
                int green = rand() % 255;
                int blue = rand() % 255;

                particles.push_back(new Particle(LP::SetSprite(x_, y_, square8x8), x_, y_, vx, vy, .9f, 1000000, 0, 0, startScale, startScale+1, red, green, blue, startAlpha, 0));
    }
}

void ParticleManager::UpArrowSlash(float x_, float y_)
{
    float vx = -(rand() % 5 + 1) / 10.f;
    float vy = (rand() % 10) / 10.f;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, upArrowL), x_, y_, vx, vy, 1, 1000000, 0, -1, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 5 + 1) / 10.f;
    vy = (rand() % 10) / 10.f;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, upArrowR), x_, y_, vx, vy, 1, 1000000, 0, 1, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(x_, y_, line32x32), x_ - 10, y_ + 10, 0, 0, 1, 200000, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::DownArrowSlash(float x_, float y_)
{
    float vx = -(rand() % 5 + 1) / 10.f;
    float vy = (rand() % 10) / 10.f;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, downArrowL), x_, y_, vx, vy, 1, 1000000, 0, -1, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 5 + 1) / 10.f;
    vy = (rand() % 10) / 10.f;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, downArrowR), x_, y_, vx, vy, 1, 1000000, 0, 1, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(x_, y_, line32x32), x_ - 10, y_ + 10, 0, 0, 1, 200000, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::LeftArrowSlash(float x_, float y_)
{
    float vx = -(rand() % 5 + 1) / 10.f;
    float vy = (rand() % 10) / 10.f;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, leftArrowL), x_, y_, vx, vy, 1, 1000000, 0, -1, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 5 + 1) / 10.f;
    vy = (rand() % 10) / 10.f;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, leftArrowR), x_, y_, vx, vy, 1, 1000000, 0, 1, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(x_, y_, line32x32), x_ - 10, y_ + 10, 0, 0, 1, 200000, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::RightArrowSlash(float x_, float y_)
{
    float vx = -(rand() % 5 + 1) / 10.f;
    float vy = (rand() % 10) / 10.f;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, rightArrowL), x_, y_, vx, vy, 1, 1000000, 0, -1, 2, 2, 255, 255, 255, 255, 0));

    vx = (rand() % 5 + 1) / 10.f;
    vy = (rand() % 10) / 10.f;
    particles.push_back(new Particle(LP::SetSprite(x_, y_, rightArrowR), x_, y_, vx, vy, 1, 1000000, 0, 1, 2, 2, 255, 255, 255, 255, 0));

    particles.push_back(new Particle(LP::SetSprite(x_, y_, line32x32), x_ - 10, y_ + 10, 0, 0, 1, 200000, -45, 0, 1, 1, 255, 255, 255, 255, 0));
}

void ParticleManager::WhiteOut(float x_, float y_)
{
    particles.push_back(new Particle(LP::SetSprite(x_, y_, white), x_, y_, 0, 0, 1, 500000, 0, 0, 1, 1, 255, 255, 255, 255, 0));
}