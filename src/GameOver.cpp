#include "GameOver.h"
void drawScreenGameOver(bool &isGameOver, float &lastEnterPressed, bool &inGame, bool &inMenu){
    if(isGameOver) {
        ClearBackground(WHITE);
        DrawText("Brics&Balls", 10, screenLenghtY/4, 38, ORANGE);
        DrawText("GAME OVER", 10, screenLenghtY/1.8, 35, MAROON);
        DrawText("To play press ENTER", 10, screenLenghtY/1.2, 35, BLUE);
        if(IsKeyPressed(KEY_ENTER)){
            isGameOver= false;
            lastEnterPressed = 0;
            inGame=true;
            inMenu=false;
        }

    }
}
