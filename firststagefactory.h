#ifndef FIRSTSTAGEFACTORY_H
#define FIRSTSTAGEFACTORY_H

#include "gameabstractfactory.h"

//Stage one factory which is responsible to create balll and table objects

class FirstStageFactory : public GameAbstractFactory
{
public:
    /*!
     * \brief FirstStageFactory constructor
     */
    FirstStageFactory();
    virtual ~FirstStageFactory();

    /*!
     * \brief CreateBall constructorfor new ball
     * \param color
     * \param xPos
     * \param yPos
     * \param xVel
     * \param yVel
     * \param mass
     * \param radius
     * \return pointer to new Ball
     */
    virtual Ball * CreateBall(QColor color, double xPos, double yPos, double xVel, double yVel, double mass, double radius);


    /*!
     * \brief CreateTable constructor for new table
     * \param color
     * \param xSize
     * \param ySize
     * \param friction
     * \return pointer to new Table
     */
    virtual Table * CreateTable(QColor color, double xSize, double ySize, double friction);
};



#endif // FIRSTSTAGEFACTORY_H
