//
// Created by podlesnyims on 18.04.2023.
//

#include "Cannon.h"
#include "Bric.h"
#include <string>
#include <vector>
#include <raylib.h>
#include <iostream>
#include <cmath>
#include "Ball.h"
#include "Cannon.h"
#include "Bric.h"
#include "chechAndDraw.h"
#include "drawBoundaryLine.h"
#include "preEntryInBall.h"
#include "ballWithPoint.h"
#include "previewOfBalls.h"
#ifndef RAYLIBTEMPLATE_RUNGAME_H
#define RAYLIBTEMPLATE_RUNGAME_H
void runGame(bool &wasSpacePressed,
             bool &inGame,
             Cannon &cannon,
             float &lastBall,
             vector<Ball> &balls,
             int &valueBalls,
             vector<Bric> &brics,
             bool &inMenu, float &lastEnterPressed,
             int &gamesPoints,
             bool &isGameOver,
             int &nSeats, vector<BallWithPoint> &ballWithPoints,
             int &addBals);

#endif //RAYLIBTEMPLATE_RUNGAME_H
