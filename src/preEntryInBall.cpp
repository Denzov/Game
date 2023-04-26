//
// Created by podlesnyims on 07.04.2023.
//
#include "preEntryInBall.h"
Vector2 preEntryInBall(bool &wasSpacePressed,
                       bool &inGame,
                       Cannon &cannon,
                       float &lastBall,
                       vector<Ball> &balls,
                       int valueBalls,
                       vector<Bric> &brics){
    Vector2 cannonAngle;
    cannonAngle.x = -cos(cannon.cannonAngle / 180 * PI - PI / 2) * 3;
    cannonAngle.y = -sin(cannon.cannonAngle / 180 * PI - PI / 2) * 3;
    cout<<cannonAngle.y<<endl;
    if (IsKeyPressed(KEY_SPACE) || wasSpacePressed) {                       ///Если нажат ПРОБЕЛ
        inGame = true;
        cannon.isShooting = true;

        Ball b;

        if (GetTime() - lastBall > ballDelta && balls.size() < valueBalls) {    ///Когда наступает время ballDelta и кол-во мячей меньше чем нужное кол-во
            //Создаем вспомогательный мяч
            b.BallSpeed = {cannonAngle.x*3, cannonAngle.y*3};
            b.BallPosition.x = cannon.cannonPositionX + sideCannonX / 4;                                 ///Точка появление мяча по оси x = середине пушки по X
            b.BallPosition.y = cannon.cannonPositionY - thickBoundaryLine * 3;                          ///Точка появление мяча по оси y = высоте пушки
            balls.push_back(b);                                   ///Кладем в конец вектора мячей вспомогательный мяч
            lastBall = GetTime();
            wasSpacePressed = true;
        }
    }
    return cannonAngle;
}
