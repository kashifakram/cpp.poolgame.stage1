#ifndef BALLFACTORY_H
#define BALLFACTORY_H

#include "gameabstractfactory.h"

class BallFactory : public GameAbstractFactory
{
public:
    BallFactory();
    virtual ~BallFactory();
    virtual Ball * CreateBall();
};

#endif // BALLFACTORY_H
