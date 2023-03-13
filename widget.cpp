#include "widget.hpp"
#include <QMouseEvent>
#include "shape.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(300, 600);
    setMouseTracking(true);  

}

Widget::~Widget(){}

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



    if(m_shapeType == ShapeType::LINE){
        m_shape.push_back(new Line(m_coord.first.toPoint(), m_coord.second.toPoint()));
    } else if (m_shapeType == ShapeType::RECT){
        m_shape.push_back(new Rect(m_coord.first.toPoint(), m_coord.second.toPoint()));

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

    drawShape();
    //drowLine();
    //drowRect();
}


void Widget::drawShape()
{
    QPainter *qp = new QPainter(this);

    for(size_t i = 0; i < m_shape.size(); ++i){
        m_shape[i]->drawShape(qp);
    }




    QPen p(Qt::red);
    p.setStyle(Qt::DashLine);
    qp->setPen(p);

    //naxnakan patker
    if (!m_coord.first.isNull() && m_shapeType==ShapeType::RECT)
    {
        qp->drawRect(Rect(m_coord.first.toPoint(), m_coord.second.toPoint()));
    } else if(!m_coord.first.isNull() && m_shapeType==ShapeType::LINE){
        qp->drawLine(Line(m_coord.first.toPoint(), m_coord.second.toPoint()));
    }

}



void Widget::clearObjects()
{
    for (auto shp : m_shape){
        delete shp;
    }

    m_shape.clear();

    update();
}

void Widget::selectRect()
{
    m_shapeType = ShapeType::RECT;
}

void Widget::selectLine()
{
    m_shapeType = ShapeType::LINE;
}


 /*
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
    if (!m_coord.first.isNull() && m_shapeType==ShapeType::LINE)
    {
        qp.drawLine(Line(m_coord.first.toPoint(), m_coord.second.toPoint()));
    }
}

void Widget::drowRect()
{
    QPainter qp(this);
    for (auto it:m_shape)
    {
        it.drowShape();
    }

    QPen p(Qt::red);
    p.setStyle(Qt::DashLine);
    qp.setPen(p);

    //naxnakan patker
    if (!m_coord.first.isNull() && m_shapeType==ShapeType::RECT)
    {
        qp.drawRect(Rect(m_coord.first.toPoint(), m_coord.second.toPoint()));
    }
}
*/
