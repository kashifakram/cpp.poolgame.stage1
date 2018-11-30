#ifndef GAMEABSTRACTFACTORY_H
#define GAMEABSTRACTFACTORY_H

#include "ball.h"
#include "table.h"
#include <QString>

//Game Abstract factory interface to be implemented by first stage factory

class GameAbstractFactory
{
public:
    /*!
     * \brief GameAbstractFactory constructor
     */
    GameAbstractFactory(){}
    virtual ~GameAbstractFactory(){}

    /*!
     * \brief CreateBall create new ball
     * \param color
     * \param xPos
     * \param yPos
     * \param xVel
     * \param yVel
     * \param mass
     * \param radius
     * \return pointer to new ball
     */
    virtual Ball * CreateBall(QColor color, double xPos, double yPos, double xVel, double yVel, double mass, double radius) = 0;

    /*!
     * \brief CreateTable creates new table
     * \param color
     * \param xSize
     * \param ySize
     * \param friction
     * \return pointer to new table
     */
    virtual Table * CreateTable(QColor color, double xSize, double ySize, double friction) = 0;

};



#endif // GAMEABSTRACTFACTORY_H
