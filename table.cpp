#include "table.h"

Table::Table(QColor color, double xSize, double ySize, double friction)
{
    m_color = color;
    m_size.setX(xSize);
    m_size.setY(ySize);
    m_friction=friction;
}

void Table::SetTableColor(QColor color)
{
    m_color = color;
}

void Table::SetTableFriction(double friction)
{
    m_friction = friction;
}

void Table::SetTabSize(double x, double y)
{
    m_size.setX(x);
    m_size.setY(y);
}

QColor Table::GetTableColor() const
{
    return m_color;
}

double Table::GetTableFriction() const
{
    return m_friction;
}

QVector2D Table::GetTableSize() const
{
    return m_size;
}
