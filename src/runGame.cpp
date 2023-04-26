
#include "runGame.h"
void drawTextPoints(int &gamesPoints) {
    string strGamesPoint = to_string(gamesPoints);
    DrawText(strGamesPoint.c_str(), 0, 0, 40, WHITE);
}
void runGame( bool &wasSpacePressed,
             bool &inGame,
             Cannon &cannon,
             float &lastBall,
             vector<Ball> &balls,
             int &valueBalls,
             vector<Bric> &brics,
             bool &inMenu,  float &lastEnterPressed,
             int &gamesPoints,
             bool &isGameOver,
             int &nSeats,
             vector<BallWithPoint> &ballWithPoints,
              int &addBals){



    drawTextPoints(gamesPoints);
    if(!inMenu &&  GetTime() - lastEnterPressed >= EnterDelta && !isGameOver ) {
        if(IsKeyPressed(KEY_ENTER) ){
            inMenu = true;

        }
        ClearBackground(BLACK);
        for (auto brick: brics) {

            brick.drawBric();
        }
        //После нажатия на пробел
        for (int i = 0; i < ballWithPoints.size(); i++) {
            ballWithPoints[i].drawPoint();
        }
        Vector2 cannonAngle;
        cannonAngle = preEntryInBall(wasSpacePressed, inGame, cannon, lastBall, balls, valueBalls, brics);
        /////////////////////////////////////////////////////////////
        previewOfBalls(cannonAngle, cannon, brics);
        checkAndDraw(wasSpacePressed,
                     cannon,
                     lastBall,
                     balls,
                     brics,
                     inGame,
                     valueBalls,
                     gamesPoints, isGameOver, nSeats,
                     ballWithPoints,
                     addBals);


        cannon.drawCannon();
        drawBoundaryLine();

    }
}