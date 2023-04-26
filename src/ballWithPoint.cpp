#include "ballWithPoint.h"
void BallWithPoint::drawPoint()
{
	DrawCircle(pointPosition.x, pointPosition.y, pointRadius, YELLOW);
}
bool BallWithPoint::checkCollisionBallWithPoints(Ball ball)
{
	if (CheckCollisionCircles(pointPosition, pointRadius, ball.BallPosition, ball.ballRadius)) {
		return true;
	}
	else false;
	
}

void BallWithPoint::shiftPoint()
{
	pointPosition.y += heightBric;
}
