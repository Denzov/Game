//
// Created by podlesnyims on 07.04.2023.
//

#ifndef RAYLIBTEMPLATE_VARIABLE_H
#define RAYLIBTEMPLATE_VARIABLE_H
////////////_____LENGHT_____////////////////////
const float sideCannonX = 50;
const float sideCannonY = 0;
const int widthBric = 80;
const int heightBric = 40;
const int thickBoundaryLine = 5;            //Ширина ограничитиленьной линии

//////////////______VALUE______/////////////////////
const int bricsInLineX= 5;
const int bricsInLineY= 20;
const int initialPoints = 5;

const Color colorBrics[6] = {MAROON, DARKGREEN, SKYBLUE, DARKPURPLE, ORANGE, DARKBROWN};
////////////_____Screen_____/////////////////////
const int screenWidth = 400;
const int screenHeight = bricsInLineY*heightBric;
const int underScreensZone = thickBoundaryLine+50;
const int screenLenghtX = screenWidth;
const int screenLenghtY = screenHeight + underScreensZone;
//////////////////////////////////
const int FPS = 120;                         //Кадры в секунду

///////////////______TIME______///////////////////////
const float ballDelta = 0.1;                      //Время между выпуском мяча
const float EnterDelta = 0.1;
//////////////______STRINGS______///////////////////






///////////////////////////////////


#endif //RAYLIBTEMPLATE_VARIABLE_H
