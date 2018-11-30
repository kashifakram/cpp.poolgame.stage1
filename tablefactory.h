#ifndef TABLEFACTORY_H
#define TABLEFACTORY_H

#include "gameabstractfactory.h"

class TableFactory : public GameAbstractFactory
{
public:
    TableFactory();
    virtual ~TableFactory();
    virtual Table* CreateTable();
};

#endif // TABLEFACTORY_H
