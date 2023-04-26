//
// Created by podlesnyims on 07.04.2023.
//

#include "drawBoundaryLine.h"


void drawBoundaryLine() {
    DrawLineEx({0, (float)(screenLenghtY - underScreensZone)},
               {screenWidth, (float)(screenLenghtY - underScreensZone)}, (float)thickBoundaryLine, WHITE);

}