#include "productgameengine.h"
#include <QDateTime>
#include <iostream>

ProductGameEngine::ProductGameEngine()
{
    m_table = nullptr;
    m_prevRunTime = 0;
}

void ProductGameEngine::AddBall(Ball * ball)
{
    m_balls.push_back(ball);
}

void ProductGameEngine::SetTable(Table *table)
{
    m_table = table;
}

std::list<Ball*>& ProductGameEngine::GetBalls()
{
    return m_balls;
}

Table * ProductGameEngine::GetTable()
{
    return m_table;
}

void ProductGameEngine::StartGame()
{
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    if (currentTime > m_prevRunTime)
    {
        if (m_prevRunTime > 0)
        {
            for(auto  i = m_balls.begin(); i != m_balls.end(); ++i)
            {
                Ball *  ball1 = *i;
                auto ball2 = i;
                ball2++;

                for(; ball2 != m_balls.end(); ++ball2)
                {
                    Ball * ballB = *ball2;
                    if (ball1 != ballB)
                    {
                        if (WereBallsCollided(ball1, ballB))
                        {
                            QVector2D dBallA;
                            QVector2D dBallB;
                            BallToBallCollision(dBallA, dBallB, ball1, ballB);

                            ball1->AddVelocity(dBallA);
                            ballB->AddVelocity(dBallB);

                        }
                    }
                }

                BallToTableCollision(m_table, ball1);

            } // end of outer loop


            // calculating friction

            for (auto i = m_balls.begin(); i != m_balls.end(); ++i)
            {
                (*i)->MoveBall(m_prevRunTime, currentTime);

                CalculateFriction(*i, m_table->GetTableFriction(), m_prevRunTime, currentTime);

            }

        }
         m_prevRunTime = currentTime;
    } // if prev runtime is zero then nothing to do
}


void ProductGameEngine::BallToBallCollision(QVector2D &deltaVA, QVector2D &deltaVB, Ball *ballA, Ball *ballB)
{
    //Properties of two colliding balls,
    //ball A
    QVector2D posA = ballA->GetPosition();
    QVector2D velA = ballA->GetVelocity();
    float massA = ballA->GetMass();
    //and ball B
    QVector2D posB = ballB->GetPosition();
    QVector2D velB = ballB->GetVelocity();
    float massB = ballB->GetMass();

    //calculate their mass ratio
    float mR = massB / massA;

    //calculate the axis of collision
    QVector2D collisionVector = posB - posA;
    collisionVector.normalize();

   //the proportion of each balls velocity along the axis of collision
    double vA = QVector2D::dotProduct(collisionVector, velA);
    double vB = QVector2D::dotProduct(collisionVector, velB);
    //the balls are moving away from each other so do nothing
    if (vA <= 0 && vB >= 0) {
     return;
    }

    //The velocity of each ball after a collision can be found by solving the quadratic equation
    //given by equating momentum and energy before and after the collision and finding the velocities
    //that satisfy this
    //-(mR+1)x^2 2*(mR*vB+vA)x -((mR-1)*vB^2+2*vA*vB)=0
    //first we find the discriminant
    double a = -(mR + 1);
    double b = 2 * (mR * vB + vA);
    double c = -((mR - 1) * vB * vB + 2 * vA * vB);
    double discriminant = sqrt(b * b - 4 * a * c);
    double root = (-b + discriminant)/(2 * a);
    //only one of the roots is the solution, the other pertains to the current velocities
    if (root - vB < 0.01) {
      root = (-b - discriminant)/(2 * a);
    }


    //The resulting changes in velocity for ball A and B
    deltaVA = mR * (vB - root) * collisionVector;
    deltaVB = (root - vB) * collisionVector;

}



void ProductGameEngine::BallToTableCollision(Table *table, Ball *ballA)
{
    if (ballA->GetPosition().x() <= ballA->GetRadius() )    // collision happend on left side of table
            ballA->SetVelocity(ballA->GetVelocity().x() * -1, ballA->GetVelocity().y());

    if ((ballA->GetPosition().x() + ballA->GetRadius()) >= table->GetTableSize().x() )    // collision happend on right side of table
            ballA->SetVelocity(ballA->GetVelocity().x() * -1, ballA->GetVelocity().y());

    if (ballA->GetPosition().y() <= ballA->GetRadius() )    // collision happend on top side of table
            ballA->SetVelocity(ballA->GetVelocity().x(), ballA->GetVelocity().y() * -1);

    if ((ballA->GetPosition().y() + ballA->GetRadius()) >= table->GetTableSize().y() )    // collision happend on bottom side of table
            ballA->SetVelocity(ballA->GetVelocity().x(), ballA->GetVelocity().y() * -1);

}



void ProductGameEngine::CalculateFriction(Ball *ball, double friction, qint64 prevTime, qint64 currTime)
{
    auto changeInXVelocity = ball->GetVelocity().x() * (1-friction * ((currTime - prevTime))/1000  );
    auto changeInYVelocity = ball->GetVelocity().y() * (1-friction * ((currTime - prevTime))/1000 );

    ball->SetVelocity(changeInXVelocity, changeInYVelocity);
}



double ProductGameEngine::GetDistanceBetweenPositions(QVector2D positionA, QVector2D positionB)
{
    double distance = 0;
    double deltaX = positionA.x() - positionB.x();
    double deltaY = positionA.y() - positionB.y();
    distance = sqrt((deltaX*deltaX) + (deltaY*deltaY));
    return distance;
}

bool ProductGameEngine::WereBallsCollided(Ball *ballA, Ball *ballB)
{
    if(ProductGameEngine::GetDistanceBetweenPositions(ballA->GetPosition(), ballB->GetPosition()) <= (ballA->GetRadius() + ballB->GetRadius()))
        return true;

    return false;
}

bool ProductGameEngine::IsGameFinished()
{
    if (m_table == nullptr || m_balls.empty())
        return true;

    return false;
}
