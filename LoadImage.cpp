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
    LP::SetTexture(dot1, "../Particle_Test/Particle/particle_dot_1.png", 32, 32);
    LP::SetTexture(dot2, "../Particle_Test/Particle/particle_dot_2.png", 64, 64);
    LP::SetTexture(dot3, "../Particle_Test/Particle/particle_dot_3.png", 64, 64);
    LP::SetTexture(fire, "../Particle_Test/Particle/particle_fire.png", 128, 128);
    LP::SetTexture(square8x8, "../Particle_Test/Particle/particle_square8x8.png", 8, 8);
    LP::SetTexture(line32x32, "../Particle_Test/Particle/Particle_Line32x32.png", 32, 32);
    LP::SetTexture(slash, "../Particle_Test/Particle/particle_slash.png", 256, 64);
    LP::SetTexture(line2, "../Particle_Test/Particle/particle_line_2.png", 128, 64);
    LP::SetTexture(ring4, "../Particle_Test/Particle/particle_ring_4.png", 128, 256);

    LP::SetTexture(upArrowL, "../Particle_Test/Particle/Particle_UpArrowL.png", 8, 8);
    LP::SetTexture(upArrowR, "../Particle_Test/Particle/Particle_UpArrowR.png", 8, 8);
    LP::SetTexture(downArrowL, "../Particle_Test/Particle/Particle_DownArrowL.png", 8, 8);
    LP::SetTexture(downArrowR, "../Particle_Test/Particle/Particle_DownArrowR.png", 8, 8);
    LP::SetTexture(leftArrowL, "../Particle_Test/Particle/Particle_LeftArrowL.png", 8, 8);
    LP::SetTexture(leftArrowR, "../Particle_Test/Particle/Particle_LeftArrowR.png", 8, 8);
    LP::SetTexture(rightArrowL, "../Particle_Test/Particle/Particle_RightArrowL.png", 8, 8);
    LP::SetTexture(rightArrowR, "../Particle_Test/Particle/Particle_RightArrowR.png", 8, 8);

    LP::SetTexture(white, "../Particle_Test/Particle/white.png", 1080, 720);
}