#include "fileoperations.h"

FileOperations::FileOperations()
{

}

//reading file using QJsonDocment object

QJsonDocument FileOperations::ReadConfigFile(QString fileName)
{
    QFile configFile(fileName);

    //opening file in readonly mode
    configFile.open(QIODevice::ReadOnly | QIODevice::Text);

    //read config file
    auto fileContents = configFile.readAll();

    //closing config file stream as all data has been retrieved in filecontents variable
    configFile.close();

    //returning filecontents contents in json format document
    return QJsonDocument::fromJson(fileContents);
}
