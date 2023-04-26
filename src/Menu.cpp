//
// Created by podlesnyims on 20.04.2023.
//
#include "raylib.h"
#include "Menu.h"
void drawMenu(bool &inMenu, float &lastEnterPressed, bool &isGameOver ){
    if(inMenu && !isGameOver) {
        ClearBackground(WHITE);
        DrawText("Brics&Balls", 10, screenLenghtY/4, 66, ORANGE);
        DrawText("To play press ENTER", 10, screenLenghtY/1.2, 35, BLUE);
        if(IsKeyPressed(KEY_ENTER)){
            lastEnterPressed = GetTime();
            inMenu = false;
        }
    }
}