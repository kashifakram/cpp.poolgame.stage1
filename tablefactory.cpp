#include "tablefactory.h"

TableFactory::TableFactory()
{

}

TableFactory::~TableFactory()
{

}

Table* TableFactory::CreateTable()
{
    return new Table();
}
