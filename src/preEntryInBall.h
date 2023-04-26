//
// Created by podlesnyims on 18.04.2023.
//

#ifndef RAYLIBTEMPLATE_PREENTRYINBALL_H
#define RAYLIBTEMPLATE_PREENTRYINBALL_H
#include <string>
#include <vector>
#include "raylib.h"
#include <iostream>
#include <cmath>
#include "Ball.h"
#include "Cannon.h"
#include "Bric.h"
#include "variable.h"

using namespace std;
Vector2 preEntryInBall(bool &wasSpacePressed,
                       bool &inGame,
                       Cannon &cannon,
                       float &lastBall,
                       vector<Ball> &balls,
                       int valueBalls,
                       vector<Bric> &brics);
#endif //RAYLIBTEMPLATE_PREENTRYINBALL_H
