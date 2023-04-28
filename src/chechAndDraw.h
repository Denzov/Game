//
// Created by podlesnyims on 18.04.2023.
//

#ifndef RAYLIBTEMPLATE_CHECHANDDRAW_H
#define RAYLIBTEMPLATE_CHECHANDDRAW_H
#include <string>
#include <vector>
#include "raylib.h"
#include <iostream>
#include <cmath>
#include "Ball.h"
#include "Cannon.h"
#include "Bric.h"
#include "variable.h"
#include "ballWithPoint.h"

void checkAndDraw(bool &wasSpacePressed,
                  Cannon &cannon,
                  float &lastBall,
                  vector<Ball> &balls,
                  vector<Bric> &brics,
                  bool &inGame, int &valueBalls,
                  int &gamesPoints, bool &isGameOver,
                  int& nSeats, vector<BallWithPoint> &ballWithPoints,
                  int &addBals, float &timeInGame);

#endif //RAYLIBTEMPLATE_CHECHANDDRAW_H

