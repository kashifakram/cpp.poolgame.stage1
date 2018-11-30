#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include "gamebuilder.h"
#include "gameabstractfactory.h"
#include "tablefactory.h"
#include "ballfactory.h"

class Director
{
public:
    /*!
     * \brief Director constructor
     */
    Director();

    ~Director(){}

    /*!
     * \brief Construct responsible to construct game using builder and config file settings
     * \param gameBuilder
     * \param configFile
     */
    void Construct(GameBuilder * gameBuilder, QJsonDocument configFile);
};

#endif // DIRECTOR_H
