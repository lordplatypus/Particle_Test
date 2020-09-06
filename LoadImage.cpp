#include <iostream>
#include <SFML/Graphics.hpp>
#include "LoadImage.h"
#include "LP.h"
#include "TextureID.h"

LoadImage::LoadImage()
{}

LoadImage::~LoadImage()
{}

void LoadImage::Load()
{
    //Particles
    LP::SetTexture(dot1, "./Particle/particle_dot_1.png", 32, 32);
    LP::SetTexture(dot2, "./Particle/particle_dot_2.png", 64, 64);
    LP::SetTexture(dot3, "./Particle/particle_dot_3.png", 64, 64);
    LP::SetTexture(fire, "./Particle/particle_fire.png", 128, 128);
    LP::SetTexture(glitter1, "./Particle/particle_glitter_1.png", 128, 128);
    LP::SetTexture(glitter2, "./Particle/particle_glitter_2.png", 128, 128);
    LP::SetTexture(glitter3, "./Particle/particle_glitter_3.png", 128, 128);
    LP::SetTexture(glitter4, "./Particle/particle_glitter_4.png", 128, 128);
    LP::SetTexture(glitter5, "./Particle/particle_glitter_5.png", 128, 128);
    LP::SetTexture(sparkle1, "./Particle/particle_sparkle_1.png", 128, 128);
    LP::SetTexture(square8x8, "./Particle/particle_square8x8.png", 8, 8);
    LP::SetTexture(line32x32, "./Particle/Particle_Line32x32.png", 32, 32);
    LP::SetTexture(slash, "./Particle/particle_slash.png", 256, 64);
    LP::SetTexture(line1, "./Particle/particle_line_1.png", 64, 64);
    LP::SetTexture(line2, "./Particle/particle_line_2.png", 128, 64);
    LP::SetTexture(ring1, "./Particle/particle_ring_1.png", 256, 256);
    LP::SetTexture(ring2, "./Particle/particle_ring_2.png", 256, 256);
    LP::SetTexture(ring3, "./Particle/particle_ring_3.png", 256, 256);
    LP::SetTexture(ring4, "./Particle/particle_ring_4.png", 128, 256);

    LP::SetTexture(upArrowL, "./Particle/Particle_UpArrowL.png", 8, 8);
    LP::SetTexture(upArrowR, "./Particle/Particle_UpArrowR.png", 8, 8);
    LP::SetTexture(downArrowL, "./Particle/Particle_DownArrowL.png", 8, 8);
    LP::SetTexture(downArrowR, "./Particle/Particle_DownArrowR.png", 8, 8);
    LP::SetTexture(leftArrowL, "./Particle/Particle_LeftArrowL.png", 8, 8);
    LP::SetTexture(leftArrowR, "./Particle/Particle_LeftArrowR.png", 8, 8);
    LP::SetTexture(rightArrowL, "./Particle/Particle_RightArrowL.png", 8, 8);
    LP::SetTexture(rightArrowR, "./Particle/Particle_RightArrowR.png", 8, 8);

    LP::SetTexture(white, "./Particle/white.png", 1080, 720);
}