//
// Created by podlesnyims on 07.04.2023.
//

#include "Bric.h"

void Bric::drawBric() {
    string strPoint = std::to_string(point);
    DrawRectangle(bricPosition.x, bricPosition.y, widthBric, heightBric, colorBigBric);
    DrawRectangle(bricPosition.x+3, bricPosition.y+3, widthBric-6, heightBric-6, colorMiniBric);
    DrawText(strPoint.c_str(),(int)(bricPosition.x+widthBric/3), (int)(bricPosition.y+heightBric/3),20, WHITE);
}

void Bric::shiftBric() {
    bricPosition.y += vecShiftBric.y;
}


