
#include <QApplication>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QString>
#include "dialog.h"
#include "gameabstractfactory.h"
#include "ballfactory.h"
#include "tablefactory.h"
#include "gamebuilder.h"
#include "director.h"
#include "Windows.h"
#include "fileoperations.h"
#include <iostream>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileOperations fileOperations;
    QJsonDocument gameSettings = fileOperations.ReadConfigFile("../Asssign1/config.json");
    GameBuilder * gameBuilder = new GameBuilder();
    Director director;
    director.Construct(gameBuilder, gameSettings);
    ProductGameEngine * game = gameBuilder->GetGame();

    Dialog w;

    if (game!=nullptr && !game->IsGameFinished())
        w.SetGame(game);
    w.show();
    if (gameBuilder != nullptr)
        delete gameBuilder;
    return a.exec();
}
