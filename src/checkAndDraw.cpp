//
// Created by podlesnyims on 07.04.2023.
//
#include "chechAndDraw.h"
void spawnAndShiftBrics(vector<Bric>& brics, int& gamesPoints, int &nSeats, bool& isGameOver, vector<Ball>& balls,
    vector<BallWithPoint> &ballWithPoints) {
    for (int i = 0; i < brics.size(); ++i) {
        brics[i].shiftBric();
        if (brics[i].bricPosition.y + heightBric >= screenLenghtY) {
            isGameOver = true;
            gamesPoints = 0;
            balls.clear();
            brics.clear();
            ballWithPoints.clear();
            nSeats=0;

        }
    }
    for (int i = 0; i < ballWithPoints.size(); i++) {
        ballWithPoints[i].shiftPoint();
    }

    if (nSeats != bricsInLineX) {
        nSeats = (int(gamesPoints / 15) + 2)%bricsInLineX;
    }
    vector <int> availableSeats(bricsInLineX);
    for (int i = 0; i < bricsInLineX; i++)
    {
        availableSeats[i] = i;
    }
    for (int i = 0; i < GetRandomValue(1, nSeats); ++i)
    {
        int randPosition = GetRandomValue(0, availableSeats.size() - 1);
        Bric br;
        br.bricPosition.x = availableSeats[randPosition] * widthBric;
        availableSeats.erase(availableSeats.begin() + randPosition);
        br.point = GetRandomValue(initialPoints + gamesPoints / 2, 2 * initialPoints + gamesPoints / 2);
        br.colorMiniBric = colorBrics[GetRandomValue(1, 5)];
        brics.push_back(br);



        }
    if (GetRandomValue(0, 100)>=50 && availableSeats.size() != 0 && brics.size() > ballWithPoints.size()) {
        int randPosition = GetRandomValue(0, availableSeats.size() - 1);
        BallWithPoint point;
        point.pointPosition.x = availableSeats[randPosition] * widthBric + widthBric/2;
        availableSeats.erase(availableSeats.begin() + randPosition);
        ballWithPoints.push_back(point);
    }
}

    
    
    
    

void drawTextSpeedTime(float timeInGame)
    {

    int speedTime = timeInGame / stepTimeSpeedInGame  + 1;
    string strSpeedTime = to_string(speedTime);


    string textTimeSpeed = strSpeedTime+'X';
    
    DrawText(textTimeSpeed.c_str(), screenLenghtX/1.2, 0, 40, LIGHTGRAY);

    }
void checkAndDraw(bool &wasSpacePressed,
                  Cannon &cannon,
                  float &lastBall,
                  vector<Ball> &balls,
                  vector<Bric> &brics,
                  bool &inGame, int &valueBalls,
                  int &gamesPoints,
                  bool &isGameOver,
                  int &nSeats,
                  vector<BallWithPoint> &ballWithPoints,
                  int &addBals, float &timeInGame) {

//////////////////////////////////////////////////////
    static bool firstStep=false;
    static float lasGetTime;
    if(!inGame && firstStep == 0){
        firstStep=true;
        spawnAndShiftBrics(brics, gamesPoints, nSeats, isGameOver, balls, ballWithPoints);
    }

    if (inGame) {
        
        timeInGame = GetTime() - lasGetTime;
        int isOutOfBoundsBalls = 0;
        drawTextSpeedTime(timeInGame);
        for (int i = 0; i < balls.size(); ++i) {    ///Берем все выпущенные мячи
            if (balls[i].BallPosition.y + balls[i].ballRadius >= screenLenghtY - underScreensZone) {    ///Если мяч выходит за белую черту,
                balls[i].isOutOfBounds = true;                                                              ///то отмечаем это
            }

            if (!(balls[i].isOutOfBounds)) {///Если мяч не за пределами линии рисуем его с коллизией
                for (int j = 0; j < brics.size(); ++j) {

                    if(balls[i].checkCollisionBall({brics[j].bricPosition.x, brics[j].bricPosition.y})){
                        ///////////////////////////////////////////////////////////////////////
                        balls[i].ballReflaction({brics[j].bricPosition.x, brics[j].bricPosition.y});
                        ///////////////////////////////////////////////////////////////////////
                        brics[j].point--;
                        if(brics[j].point<=0){
                            brics.erase(brics.begin()+j);
                        }



                    }
                    if(j < ballWithPoints.size()){
                        if(ballWithPoints[j].checkCollisionBallWithPoints(balls[i])){
                            addBals++;
                            ballWithPoints.erase(ballWithPoints.begin()+j);
                        }

                    }

                }
//////////////////////////////////////////////////////Смотрим за каждым выпущенным мячом на наличие выхода за ограничительную линию и расчитываем рисовать его или нет
/////////////////////////////////////////////////////Проверяем на столкновение с каждым кирпичом
/////////////////////////////////////////////////////Отрисовываем выпущенные мячи


                balls[i].drawBall();                //Рисуем мяч
            }
            else
            {
                isOutOfBoundsBalls++;
            }

        }
        if (isOutOfBoundsBalls >= valueBalls)
        {
            gamesPoints++;
            spawnAndShiftBrics(brics, gamesPoints, nSeats, isGameOver, balls, ballWithPoints);
            wasSpacePressed = false;
            balls.clear();
            cannon.isShooting= false;
            inGame = false;
            valueBalls += addBals;
            addBals=0;
            lasGetTime = GetTime();
            timeInGame = 0;
        }
    }
}
