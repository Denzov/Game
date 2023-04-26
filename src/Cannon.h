//
// Created by podlesnyims on 07.04.2023.
//
#include <string>
#include <vector>
#include "raylib.h"
#include <iostream>
#include <cmath>
#include "Ball.h"
#ifndef RAYLIBTEMPLATE_CANNON_H
#define RAYLIBTEMPLATE_CANNON_H
using namespace std;

class Cannon {
public:
    bool isShooting = false;
    const float cannonPositionY = screenLenghtY- underScreensZone;
    int cannonPositionX = screenWidth / 2;
    float cannonAngle = 180;
    float cannonMuzzleWidth = 15;
    float cannonMuzzleHeight = 15;
    float shiftCannon = 3;
    void drawCannon();


};


#endif //RAYLIBTEMPLATE_CANNON_H
