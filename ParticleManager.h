#ifndef PARTICLE_MANAGER_H_
#define PARTICLE_MANAGER_H_
#include <vector>
#include "Particle.h"

class ParticleManager
{
public:
    ParticleManager();
    ~ParticleManager();
    void Update(float delta_time);
    void Draw() const;

    void Test(float x, float y);
    void Explosion(float x, float y);
    void SquareExplosion(float x, float y);

    void UpArrowSlash(float x, float y);
    void DownArrowSlash(float x, float y);
    void LeftArrowSlash(float x, float y);
    void RightArrowSlash(float x, float y);

    void WhiteOut(float x, float y);

    void Foutain(float x, float y);
    void Shockwave(float x, float y);
    void Spark(float x, float y, float angle);
    void Fire(float x, float y);
    void WormHole(float x, float y);
    void Charge(float x, float y);
    void Firework(float x, float y);
    void Heal(float x, float y);
    void PickUp(float x, float y);

    void SmokeScreen(float x, float y);
    void EnemyDeath(float x, float y);

private:
    std::vector<Particle*> particles;
};

#endif