#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H

#include "productgameengine.h"
#include "gameabstractfactory.h"
#include<QString>

// Game Builder will be used to build game objeccts using abstract factory

class GameBuilder
{
public:

    /*!
     * \brief GameBuilder constructor
     */
    GameBuilder();

    ~GameBuilder(){}

    /*!
     * \brief GetGame return pointer to game engine
     * \return
     */
    ProductGameEngine * GetGame();

    /*!
     * \brief CreateTable create new concrete table
     * \param color
     * \param xSize
     * \param ySize
     * \param friction
     * \param absFactory
     */
    void CreateTable(QColor color, double xSize, double ySize, double friction, GameAbstractFactory * absFactory);

    /*!
     * \brief CreateBall create new concrete ball
     * \param color
     * \param xPos
     * \param yPos
     * \param xVel
     * \param yVel
     * \param mass
     * \param radius
     * \param absFactory
     */
    void CreateBall(QColor color, double xPos, double yPos, double xVel, double yVel, double mass, double radius, GameAbstractFactory * absFactory);

private:
    ProductGameEngine * m_product;
};

#endif // GAMEBUILDER_H
