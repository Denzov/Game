
#include "runGame.h"
void drawTextPoints(int &gamesPoints) {
    string strGamesPoint = to_string(gamesPoints);
    DrawText(strGamesPoint.c_str(), 0, 0, 40, WHITE);
}
void drawTextValueBalls(int valueBalls){
    string strGamesValueBalls = to_string(valueBalls);
    DrawText(strGamesValueBalls.c_str(), screenLenghtX/2.8 ,  screenLenghtY-underScreensZone+5, 40, WHITE);
    DrawText("Value balls:",  20 ,  screenLenghtY-underScreensZone+20, 20, WHITE);
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
              int &addBals, float &timeInGame){



    drawTextPoints(gamesPoints);

    if(!inMenu &&  GetTime() - lastEnterPressed >= EnterDelta && !isGameOver ) {
        Vector2 cannonAngle;
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
        drawTextValueBalls(valueBalls);
        cannonAngle = preEntryInBall(wasSpacePressed, inGame, cannon, lastBall, balls, valueBalls, brics);
        /////////////////////////////////////////////////////////////
        previewOfBalls(cannonAngle, cannon, brics, inGame);
        checkAndDraw(wasSpacePressed,
                     cannon,
                     lastBall,
                     balls,
                     brics,
                     inGame,
                     valueBalls,
                     gamesPoints, isGameOver, nSeats,
                     ballWithPoints,
                     addBals, timeInGame);


        cannon.drawCannon();
        drawBoundaryLine();

    }
}