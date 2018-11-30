#include "dialog.h"
#include "ui_dialog.h"
#include "table.h"
#include "ball.h"
#include <iostream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    m_product = nullptr;
    ui->setupUi(this);

    this->resize(1000, 600);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(30);
}

Dialog::~Dialog()
{
    if (m_product!=nullptr)
        delete m_product;

    delete ui;
}
void Dialog::SetGame(ProductGameEngine* product)
{

    m_product = product;
}
void Dialog::nextFrame()
{
    if (m_product!=nullptr){
        m_product->StartGame();
    }

    update();
}

void Dialog::paintEvent(QPaintEvent *event)
{
    if (m_product != nullptr)
    {
        QPainter painter(this);
        DrawTable(m_product->GetTable(), painter);
        for (auto balls = m_product->GetBalls().begin(); balls != m_product->GetBalls().end(); ++balls)
        {
            Ball* i = *balls;
            DrawBall(i, painter);
        }
    }
}

void Dialog::DrawTable(Table* table, QPainter &painter)
{
    QPen pen;
    //pen.setWidth(2);
    pen.setColor(table->GetTableColor());
    QBrush brush(table->GetTableColor());
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0, 0, static_cast<int>(table->GetTableSize().x()), static_cast<int>(table->GetTableSize().y()));
    //this->update();
}

void Dialog::DrawBall(Ball* ball, QPainter &painter)
{
    QPen pen;
    pen.setColor(ball->GetColor());
    QBrush brush(ball->GetColor());
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(ball->GetPosition().x() - static_cast<int>(ball->GetRadius()),
                        ball->GetPosition().y() - static_cast<int>(ball->GetRadius()),
                        ball->GetRadius() * 2,
                        ball->GetRadius() * 2);

}
