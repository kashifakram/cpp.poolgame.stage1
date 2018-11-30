#ifndef DIALOG_H
#define DIALOG_H

#include "productgameengine.h"
#include <QDialog>
#include <QPainter>
#include <QTimer>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void SetGame(ProductGameEngine * product);

public slots:
    void nextFrame();

protected:
    void paintEvent(QPaintEvent *event);
    void DrawTable(Table* table, QPainter& painter);
    void DrawBall(Ball* ball, QPainter& painter);

private:
    Ui::Dialog* ui;
    ProductGameEngine* m_product;
};

#endif // DIALOG_H
