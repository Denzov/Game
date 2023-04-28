//
// Created by podlesnyims on 07.04.2023.
//

#include "Cannon.h"

void Cannon::drawCannon() {
    if (IsKeyDown(KEY_LEFT)) {
        cannonPositionX -= shiftCannon;
    } else if (IsKeyDown(KEY_RIGHT)) {
        cannonPositionX += shiftCannon;
    }
    if (!isShooting) {
        
        if (IsKeyDown(KEY_UP)) {
            cannonAngle -= 0.5;
        } else if (IsKeyDown(KEY_DOWN)) {
            cannonAngle += 0.5;
        }
        if (cannonAngle <= 92) {
            cannonAngle += 0.5;
        }
        else if (cannonAngle >= 268) {
            cannonAngle -= 0.5;
        }
    }
    if (cannonPositionX+sideCannonX/2 >= screenWidth) {
        cannonPositionX -= shiftCannon;
    }
    else if (cannonPositionX <= 0) {
        cannonPositionX += shiftCannon;
    }

    DrawRectanglePro({(float) (cannonPositionX + sideCannonX / 4),
                      (float) (cannonPositionY - thickBoundaryLine*2 ), cannonMuzzleWidth, cannonMuzzleHeight},
        { (sideCannonX / 4)/2, 0 }, cannonAngle, GOLD);
    DrawRectangle(cannonPositionX, cannonPositionY, sideCannonX / 2, sideCannonY, BLUE);
}

