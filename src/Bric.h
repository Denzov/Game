//
// Created by podlesnyims on 07.04.2023.
//

#ifndef RAYLIBTEMPLATE_BRIC_H
#define RAYLIBTEMPLATE_BRIC_H
#include <string>
#include <vector>
#include "raylib.h"
#include <iostream>
#include "variable.h"
using namespace std;

class Bric {
public:

    Vector2 vecShiftBric={ (float)widthBric,(float)heightBric};
    Vector2 bricPosition = {0, (float)heightBric};
    Color colorBigBric = {WHITE};
    Color colorMiniBric = {GREEN};
    int point = initialPoints;

    void drawBric();
    void shiftBric();

};


#endif //RAYLIBTEMPLATE_BRIC_H
