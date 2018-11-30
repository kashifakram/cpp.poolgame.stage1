#include "ball.h"

//ball constructor

Ball::Ball(QColor color, double xPos, double yPos, double xVel, double yVel, double mass, double radius)
{
    m_ballColor = color;
    m_position.setX(xPos);
    m_position.setY(yPos);
    m_velocity.setX(xVel);
    m_velocity.setY(yVel);
    m_mass = mass;
    m_radius = radius;
}

//Setters to set member variables of existing ball objects

void Ball::SetColor(QColor ballColor)
{
    m_ballColor = ballColor;
}

void Ball::SetMass(double mass)
{
    m_mass = mass;
}

void Ball::SetRadius(double radius)
{
    m_radius = radius;
}

void Ball::SetVelocity(double xVelocity, double yVelocity)
{
    m_velocity.setX(xVelocity);
    m_velocity.setY(yVelocity);
}

void Ball::SetPosition(double xPosition, double yPosition)
{
    m_position.setX(xPosition);
    m_position.setY(yPosition);
}


// Getters to get member variables existing ball objects

QColor Ball::GetColor() const
{
    return m_ballColor;
}

QVector2D& Ball::GetVelocity()
{
    return m_velocity;
}

QVector2D& Ball::GetPosition()
{
    return m_position;
}

double Ball::GetRadius() const
{
    return m_radius;
}

double Ball::GetMass() const
{
    return m_mass;
}

// utility methods
void Ball::AddVelocity(QVector2D velocity)
{
    m_velocity += velocity;
}


// moving ball in each time farame by getting velocity multiply with change in time and dividing to number according to required position

void Ball::MoveBall(qint64 prevTime, qint64 currentTime)
{
    if (currentTime > prevTime)
    {
        auto deltaTime = currentTime - prevTime;
        auto deltaX = (m_velocity.x() * deltaTime) / 300;
        auto deltaY = (m_velocity.y() * deltaTime) / 300;
        m_position.setX(deltaX + m_position.x());
        m_position.setY(deltaY + m_position.y());
    }

}
