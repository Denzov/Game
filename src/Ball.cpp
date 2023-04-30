//
// Created by podlesnyims on 07.04.2023.
//

#include "Ball.h"

bool Ball::checkCollisionBall( Vector2 bricPosition) {

    Vector2 newBallPosition = {BallPosition.x + BallSpeed.x, BallPosition.y + BallSpeed.y};
    if (CheckCollisionCircleRec(newBallPosition, ballRadius, {
            bricPosition.x+1,
            bricPosition.y+1,
            (float) widthBric,
            (float) heightBric
    })) {
            return true;


    }
    else{
        return false;
    }
}

void Ball::drawBall() {
    BallPosition.x += BallSpeed.x;
    BallPosition.y += BallSpeed.y;
    if ((BallPosition.x + ballRadius >= screenWidth) || (BallPosition.x - ballRadius <= 0)) BallSpeed.x *= -1;
    if (BallPosition.y + ballRadius <= 0) BallSpeed.y *= -1;

    DrawCircle(BallPosition.x, BallPosition.y, ballRadius, ballColor);
}

void Ball::ballReflaction(Vector2 bricPosition) {

    if (BallPosition.x + ballRadius <= bricPosition.x || BallPosition.x - ballRadius >= bricPosition.x + widthBric) BallSpeed.x *= -1;
    if (BallPosition.y + ballRadius <= bricPosition.y || BallPosition.y - ballRadius >= bricPosition.y + heightBric) BallSpeed.y *= -1;
}

