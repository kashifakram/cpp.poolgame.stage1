#ifndef TABLE_H
#define TABLE_H

#include <QColor>
#include <QString>
#include <QVector2D>


//creating new table constructor, getters and setters

class Table
{
public:
    /*!
     * \brief Table construcotr
     * \param color
     * \param xSize
     * \param ySize
     * \param friction
     */
    Table(QColor color, double xSize, double ySize, double friction);

    /*!
     * \brief SetTableColor to set table color of existing table
     * \param color
     */
    void SetTableColor(QColor color);

    /*!
     * \brief SetTableFriction to set friction of existing table
     * \param friction
     */
    void SetTableFriction(double friction);

    /*!
     * \brief SetTabSize to set table size
     * \param x
     * \param y
     */
    void SetTabSize(double x, double y);

    /*!
     * \brief GetTableColor to get table color of existing table
     * \return color
     */
    QColor GetTableColor() const;

    /*!
     * \brief GetTableFriction to get friction table of existing table
     * \return double
     */
    double GetTableFriction() const;

    /*!
     * \brief GetTableSize to get table size of existing table
     * \return vector2d
     */
    QVector2D GetTableSize() const;


private:
    QColor m_color;
    QVector2D m_size;
    double m_friction;
};

#endif // TABLE_H
