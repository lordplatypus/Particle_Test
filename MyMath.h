#ifndef MY_MATH_H_
#define MY_MATH_H_
#include <cmath>

class MyMath
{
public:
    MyMath();
    ~MyMath();
    static bool RectRectIntersection(float aLeft, float aTop, float aRight, float aBottom,
                                     float bLeft, float bTop, float bRight, float bBottom);
    static float Lerp(float a, float b, float t);
    static float PointToPointAngle(float fromX, float fromY, float toX, float toY);
    static float DistanceBetweenTwoPoints(float fromX, float fromY, float toX, float toY);

    const float PI = M_PI;
    const float Deg2Rad = PI / 180.0f;
    const float Sqrt2 = 1.41421356237f;
};

MyMath::MyMath()
{}

MyMath::~MyMath()
{}

bool MyMath::RectRectIntersection(float aLeft, float aTop, float aRight, float aBottom,
                                  float bLeft, float bTop, float bRight, float bBottom)
{
    return
    aLeft < bRight &&
    aRight > bLeft &&
    aTop < bBottom &&
    aBottom > bTop;
}

float MyMath::Lerp(float a, float b, float t)
{
    return a + (b - a) * t;
}

float MyMath::PointToPointAngle(float fromX, float fromY, float toX, float toY)
{
    return (float)atan2(toY - fromY, toX - fromX);
}

float MyMath::DistanceBetweenTwoPoints(float fromX, float fromY, float toX, float toY)
{
    return (float)sqrt(pow(toX - fromX, 2) + pow(toY - fromY, 2));
}

#endif