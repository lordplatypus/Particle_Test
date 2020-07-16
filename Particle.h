#ifndef PARTICLE_H_
#define PARTICLE_H_
//#include <chrono>

class Particle
{
public:
    Particle(int imageHandle, float x, float y, float vx, float vy, float damp, float lifespan, float angle, float angularVelocity, float startScale, float endScale, int red, int green, int blue, int startAlpha, int endAlpha);
    ~Particle();
    void Update(float delta_time);
    void Draw();
    bool IsDead() const;

    // std::chrono::high_resolution_clock::time_point lifespanTest;
    // bool firstInstance = true;

private:  
    bool isDead = false;
    float x;
    float y;
    float lifespan = 0;
    //float lifespanInMS;
    float age = 0;
    int imageHandle;
    float progressRate = 0;
    float counter = 0.f;
    float scale = 1.f;
    float startScale = 1.f;
    float endScale = 1.f;
    float vx = 0;
    float vy = 0;
    float angularVelocity = 0;
    float angularDamp = 1.f;
    float angle = 0;
    float forceX = 0;
    float forceY = 0;
    float damp = 1.f;
    int red = 255;
    int green = 255;
    int blue = 255;
    int alphaCounter = 0;
    int alpha = 255;
    int startAlpha = 255;
    int endAlpha = 255;

    int timer = 0;
};

#endif