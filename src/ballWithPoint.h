#ifndef RAYLIBTEMPLATE_BALLWITHPOINT_H
#define RAYLIBTEMPLATE_BALLWITHPOINT_H
#include <raylib.h>
#include "Ball.h"
#include "variable.h"

using namespace std;
class BallWithPoint {
public:
	Vector2 pointPosition = { widthBric, heightBric+heightBric/2};
	float pointRadius=10;


	void drawPoint();
	bool checkCollisionBallWithPoints(Ball ball);
	void shiftPoint();
};




#endif //RAYLIBTEMPLATE_BALLWITHPOINT_H