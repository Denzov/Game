#include <string>
#include <vector>
#include <raylib.h>
#include <iostream>
#include <cmath>
#include "Ball.h"
#include "Cannon.h"
#include "Bric.h"
#include <random>
#include "runGame.h"
#include "Menu.h"
#include "GameOver.h"
#include "ballWithPoint.h"
#include <fstream>
using namespace std;

int main() {
    InitWindow(screenLenghtX, screenLenghtY , "raylib [core] example");
    //////////////______VECTORS______///////////////////////
    vector<Ball> balls;                  //Вектор мячей
    vector<Bric> brics;
    vector<BallWithPoint> ballWithPoints;
    ///////////////______STATE______//////////////////////
    bool inMenu = true;
    bool wasSpacePressed = false;               //Прожат ли ПРОБЕЛ
    bool inGame = false;
    bool isGameOver = false;
    ///////////////______TIME______///////////////////////
    float lastBall = 0;
    float lastEnterPressed = 0;
    //Время последнего выпущенного мяча
    //////////////______VALUE______/////////////////////
    int valueBalls = 1;                        //Количество мячей
    int gamesPoints = 0;
    int nSeats = 0;
    int addBalls =0;
    //////////////______STRUCTS______////////////////////
    Cannon cannon;


    string path = "D:\\RayLibTemplate\\BestScore.txt";
    /////////////////////////////////////////////////////////
//
//    ofstream fout;
//    int x = 1000;
//
//    if (fout.is_open()) {
//        fout.write((char*)&x, sizeof(int));
//
//
//    }
//    fout.close();
//
//
//
//    ifstream fin;
//    fin.open(path);
//    if (fin.is_open()) {
//        int i;
//        while (fin.read((char*)&i, sizeof(int)))
//        {
//            cout << i;
//        }
//
//
//
//    }
//    fin.close();
//


    SetTargetFPS(FPS);
    while (!WindowShouldClose()) {
        BeginDrawing();
        drawMenu(inMenu, lastEnterPressed, isGameOver);
        runGame(wasSpacePressed, inGame, cannon, lastBall, balls, valueBalls, brics, inMenu, lastEnterPressed, gamesPoints,
                isGameOver, nSeats, ballWithPoints, addBalls);
        drawScreenGameOver(isGameOver, lastEnterPressed, inGame, inMenu);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}