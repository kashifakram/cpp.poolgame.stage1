#include "gamebuilder.h"

GameBuilder::GameBuilder()
{
    m_product = new ProductGameEngine();
}

// Product game enging
ProductGameEngine * GameBuilder::GetGame()
{
    return m_product;
}

void GameBuilder::CreateTable(QColor color, double xSize, double ySize, double friction, GameAbstractFactory * absFactory)
{
    Table * table = absFactory->CreateTable(color, xSize, ySize, friction);

    m_product->SetTable(table);
}

void GameBuilder::CreateBall(QColor color, double xPos, double yPos, double xVel, double yVel, double mass, double radius, GameAbstractFactory *absFactory)
{
    Ball * ball = absFactory->CreateBall(color, xPos, yPos, xVel, yVel, mass, radius);

    m_product->AddBall(ball);
}
