#ifndef PRODUCTGAMEENGINE_H
#define PRODUCTGAMEENGINE_H

#include <QVector2D>
#include "ball.h"
#include "table.h"



class ProductGameEngine
{
public:
    /*!
     * \brief ProductGameEngine responsiblefor create new game, adding objects to game,
     * stating game and handling ball to ball, ball to collision, calculate frictions
     * validating if game is running or stopped
     */
    ProductGameEngine();


    void AddBall(Ball * ball);
    void SetTable(Table * table);
    std::list<Ball*>& GetBalls();
    Table * GetTable();

    void StartGame();
    void BallToBallCollision(QVector2D & ballAVelocity, QVector2D & ballBVelocity, Ball * ballA, Ball * ballB);
    void BallToTableCollision(Table * table, Ball * ballA);
    void CalculateFriction(Ball * ball, double friction, qint64 prevTime, qint64 currTime);

    double GetDistanceBetweenPositions(QVector2D positionA, QVector2D positionB);
    bool WereBallsCollided(Ball * ballA, Ball * ballB);
    bool IsGameFinished();



private:
    std::list<Ball*> m_balls;
    Table * m_table;
    qint64 m_prevRunTime;
};

#endif // PRODUCTGAMEENGINE_H
