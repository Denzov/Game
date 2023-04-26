//
// Created by podlesnyims on 07.04.2023.
//
#include <string>
#include <vector>
#include "raylib.h"
#include <iostream>
#include <cmath>
#include "variable.h"
#ifndef RAYLIBTEMPLATE_BALL_H
#define RAYLIBTEMPLATE_BALL_H

using namespace std;

class Ball {
public:
    Vector2 BallPosition = {300, 400};          //Позиция мяча
    Vector2 BallSpeed = {0, 0};
    float ballRadius = 5;                       //Радиус мяча
    bool isOutOfBounds = false;                 //Мяч в не границе     //Сторона пушки
    float screenZona = screenLenghtY-underScreensZone;//Вычисление области, в которой мяч отражается



    bool checkCollisionBall(Vector2 ballPosition, float ballRadius, Vector2 bricPosition);

    void drawBall();
    void ballReflaction(Vector2 bricPosition);
};


#endif //RAYLIBTEMPLATE_BALL_H
