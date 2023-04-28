//
// Created by podlesnyims on 25.04.2023.
//
#include "previewOfBalls.h"

void previewOfBalls(Vector2 cannonAngle, Cannon cannon, vector<Bric> brics, bool inGame) {
    vector<Ball> balls;
    Ball b;
    static float cannonAngle0 = 3;
    static int nFarame = 60;
    static float KSpeed = (screenHeight / cannonAngle0) / nFarame + 1.5;
    if(true){
    for (int i = 0; i < nFarame; ++i) {


        b.BallSpeed = {cannonAngle.x * 15, cannonAngle.y * 15 };
        b.BallPosition.x = (cannon.cannonPositionX + sideCannonX /
                                                     4);                                 ///Точка появление мяча по оси x = середине пушки по X
        b.BallPosition.y = cannon.cannonPositionY - thickBoundaryLine *
                                                    3;                          ///Точка появление мяча по оси y = высоте пушки
        balls.push_back(b);                                   ///Клад
        for (int j = 0; j < balls.size(); ++j) {
            if (!brics.empty()) {

                for (int k = 0; k < brics.size(); ++k) {


                    if (balls[j].checkCollisionBall({brics[k].bricPosition.x, brics[k].bricPosition.y})) {
                        ///////////////////////////////////////////////////////////////////////
                        balls[j].ballReflaction({brics[k].bricPosition.x, brics[k].bricPosition.y});
                        ///////////////////////////////////////////////////////////////////////
                    }

                }
            }
            balls[j].ballColor = WHITE;
            balls[j].drawBall();
        }
    }
        }

    }