#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <QString>
#include <QJsonDocument>
#include <QFile>

// to defind all file related functions
class FileOperations
{
public:
    /*!
     * \brief FileOperations constructor
     */
    FileOperations();

    /*!
     * \brief ReadConfigFile will read given file
     * convert to json format
     * and return jsoondocument
     * \param fileName
     * \return
     */
    QJsonDocument ReadConfigFile(QString fileName);

};



#endif // FILEOPERATIONS_H
