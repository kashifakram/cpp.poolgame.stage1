//Ball Header File
#ifndef BALL_H
#define BALL_H

#include <QColor>
#include <QVector2D>
#include <QString>

class Ball
{
public:
    /*!
     * \brief Ball constructor
     * \param color ball color
     * \param xPos ball initial xpos
     * \param yPos ball initial ypos
     * \param xVel ball initial x velocity
     * \param yVel ball initial y velocity
     * \param mass ball initial mass
     * \param radius ball initial radius
     */
    Ball(QColor color, double xPos, double yPos, double xVel, double yVel, double mass, double radius); // Constructor

    /*!
     * \brief SetColor to set ball color
     * \param ballColor
     */
    void SetColor(QColor ballColor);

    /*!
     * \brief SetMass to set ball mass
     * \param mass
     */
    void SetMass(double mass);

    /*!
     * \brief SetRadius to set radius
     * \param radius
     */
    void SetRadius(double radius);

    /*!
     * \brief SetVelocity to set x and y velocities
     * \param xVelocity
     * \param yVelocity
     */
    void SetVelocity(double xVelocity, double yVelocity);

    /*!
     * \brief SetPosition to set x and y positions
     * \param xPosition
     * \param yPosition
     */
    void SetPosition(double xPosition, double yPosition);


    // Getters, to get color, mass, radius, velocity and position of ball

    /*!
     * \brief GetColor to get color
     * \return color
     */
    QColor GetColor() const;

    /*!
     * \brief GetVelocity to get current velocity in qvector 2d format
     * \return qvector2d
     */
    QVector2D& GetVelocity();

    /*!
     * \brief GetPosition to get current position in qvector 2d format
     * \return qvector2d
     */
    QVector2D& GetPosition();

    /*!
     * \brief GetRadius to get radius
     * \return double
     */
    double GetRadius() const;


    /*!
     * \brief GetMass to get mass
     * \return double
     */
    double GetMass() const;


    /*!
     * \brief AddVelocity add x and y velocities to current x, y velocities
     * \param velocity
     */
    void AddVelocity(QVector2D velocity);

    /*!
     * \brief MoveBall will be implemented in source file to move ball in each frame
     * \param prevTime
     * \param currentTime
     */
    void MoveBall(qint64 prevTime, qint64 currentTime);


    ~Ball();




private:
    //private member variables
    QColor m_ballColor;
    QVector2D m_position;
    QVector2D m_velocity;
    double m_mass;
    double m_radius;
};

#endif // BALL_H
