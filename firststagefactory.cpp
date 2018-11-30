#include "firststagefactory.h"

FirstStageFactory::FirstStageFactory()
{

}

FirstStageFactory::~FirstStageFactory(){}

//CreateBall method will be used to create and return pointer to new instance of ball
Ball * FirstStageFactory::CreateBall(QColor color, double xPos, double yPos, double xVel, double yVel, double mass, double radius)
{
    return new Ball(color, xPos, yPos, xVel, yVel, mass, radius);
}


//CreateBall method will be used to create and return pointer to new instance of table
Table * FirstStageFactory::CreateTable(QColor color, double xSize, double ySize, double friction)
{
    return new Table(color, xSize, ySize, friction);
}
