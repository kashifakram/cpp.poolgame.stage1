#include "ballfactory.h"

BallFactory::BallFactory()
{

}

BallFactory::~BallFactory()
{

}

Ball * BallFactory::CreateBall()
{
    return new Ball();
}
