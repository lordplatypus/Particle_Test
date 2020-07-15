#ifndef PARTICLE_MANAGER_H_
#define PARTICLE_MANAGER_H_
#include <vector>
#include "Particle.h"

class ParticleManager
{
public:
    ParticleManager();
    ~ParticleManager();
    void Update();
    void Draw();

    void Test(float x, float y);
    void Explosion(float x, float y);
    void SquareExplosion(float x, float y);

    void UpArrowSlash(float x, float y);
    void DownArrowSlash(float x, float y);
    void LeftArrowSlash(float x, float y);
    void RightArrowSlash(float x, float y);

    void WhiteOut(float x, float y);

private:
    std::vector<Particle*> particles;
};

#endif