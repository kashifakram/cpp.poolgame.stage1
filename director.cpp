#include "director.h"
#include "tablefactory.h"
#include "ballfactory.h"
#include "firststagefactory.h"
#include <iostream>

Director::Director()
{

}

// construct function in director is responsible of building new game based on confgiurations provided in config file

void Director::Construct(GameBuilder *gameBuilder, QJsonDocument configFile)
{
    //proceeding if config file is not null
    if (!configFile.isNull())
    {

        //sanity check to check if file is in proper json format i.e. object

        if (configFile.isObject())
        {
            //creating new instance of firststage factory and passing to game abstract factory which is responsible to create proper required game objects
            GameAbstractFactory * factory = new FirstStageFactory();

            //reading root element of json file
            QJsonObject configDocRoot = configFile.object();

            //sanity check if the element is table
            if (configDocRoot.contains("table"))
            {
                //if object is table, reading all properties of table

                QJsonValue tableConfigs = configDocRoot.take("table");
                if (tableConfigs.isObject())
                {
                    QJsonObject table = tableConfigs.toObject();

                    QString color = table.take("colour").toString();

                    double xSize = 0;
                    double ySize = 0;

                    if (table.contains("size"))
                    {
                        QJsonObject sizeJson = table.take("size").toObject();
                        xSize = sizeJson.take("x").toDouble();
                        ySize = sizeJson.take("y").toDouble();
                    }
                    double friction = 0;

                    if (table.contains("friction"))
                    {
                        friction = table.take("friction").toDouble();
                    }

                    //creating new instance of table based on values read from config file
                    gameBuilder->CreateTable(color, xSize, ySize, friction, factory);
                }
            }


            // config if next object is balls
            if (configDocRoot.contains("balls"))
            {
                //reading all balls objects in balls array and passing to QJsonArray to process
                QJsonArray ballsConfigs = configDocRoot.take("balls").toArray();
                for (int i=0;i<ballsConfigs.size();i++)
                {
                    // reading each balls properties

                    QJsonObject ball = ballsConfigs.at(i).toObject();

                    QString color = ball.take("colour").toString();
                    double xPos, yPos, xVel, yVel, mass, rad = 0;

                        QJsonObject position = ball.take("position").toObject();
                        xPos = position.take("x").toDouble();
                        yPos = position.take("y").toDouble();

                        QJsonObject velocity = ball.take("velocity").toObject();
                        xVel = velocity.take("x").toDouble();
                        yVel = velocity.take("y").toDouble();

                        mass = ball.take("mass").toDouble();
                        rad = ball.take("radius").toDouble();

                        //creating instances of each ball read from config file
                    gameBuilder->CreateBall(color, xPos, yPos, xVel, yVel, mass, rad, factory);
                }

            }

            //deleting first stage factory
            delete factory;


        }


    } // config document is not null


} // Director Construct
