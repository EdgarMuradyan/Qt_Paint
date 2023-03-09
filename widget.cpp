#include "widget.hpp"
#include <iostream>
#include <sstream>
#include <QMouseEvent>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(300, 600);
    setMouseTracking(true);

}

Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent* e)
{

    if (e->button() != Qt::LeftButton)
        return;
    emit eventHappened(QString("Mouse pressed: ") + QString::number(e->pos().x()) + " " +  QString::number(e->pos().y()));
    if (m_coord.first.isNull()) {
        m_coord.first = e->pos();
        return;
    }
    m_coord.second = e->pos();

    if(m_shape == ShapeType::Line){
        m_lines.push_back(QLine(m_coord.first.toPoint(), m_coord.second.toPoint()));
    } else if (m_shape == ShapeType::Rectangle){
        m_rects.push_back(QRect(m_coord.first.toPoint(), m_coord.second.toPoint()));
    }





    m_coord.first = QPointF();
    m_coord.second = QPointF();

    update();
}

void Widget::mouseMoveEvent(QMouseEvent* e)
{
    if (!m_coord.first.isNull())
    {
        m_coord.second = e->pos();
        update();
    }
}

void Widget::paintEvent(QPaintEvent*)
{
   // if(m_shape == Shape::Line){
    //    drowLine();
   // } else if (m_shape == Shape::Rectangle){
    ////    drowRect();
   // }

    drowLine();
    drowRect();
}



void Widget::drowLine()
{
    QPainter qp(this);
    for (auto it:m_lines)
    {
        qp.drawLine(it);
    }

    QPen p(Qt::red);
    p.setStyle(Qt::DashLine);
    qp.setPen(p);

    //naxnakan patker
    if (!m_coord.first.isNull() && m_shape==ShapeType::Line)
    {

        qp.drawLine(QLine(m_coord.first.toPoint(), m_coord.second.toPoint()));
    }

}

void Widget::drowRect()
{
    QPainter qp(this);
    for (auto it:m_rects)
    {
        qp.drawRect(it);
    }

    QPen p(Qt::red);
    p.setStyle(Qt::DashLine);
    qp.setPen(p);

    //naxnakan patker
    if (!m_coord.first.isNull() && m_shape==ShapeType::Rectangle)
    {
        qp.drawRect(QRect(m_coord.first.toPoint(), m_coord.second.toPoint()));
    }

}

void Widget::clearObjects()
{
    while(!m_lines.empty()){
        m_lines.pop_back();
    }

    while(!m_rects.empty()){
        m_rects.pop_back();
    }

    update();
}

void Widget::selectRect()
{
    m_shape = ShapeType::Rectangle;
}

void Widget::selectLine()
{
    m_shape = ShapeType::Line;
}




