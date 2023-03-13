#ifndef SHAPE_H
#define SHAPE_H
#include <QRect>
#include <QLine>
#include <QPainter>
#include <iostream>


enum class ShapeType{
    LINE,
    RECT
};


class Shape
{
public:  
    virtual void drawShape(QPainter *_qp) =0;
    virtual ~Shape() {}

private:
};


class Rect :public Shape, public QRect
{
public:

   Rect(const QPoint &atopLeft, const QPoint &abottomRight) noexcept
   {

       // setRect(x1, y1, x2, y2);
        setCoords(atopLeft.x(), atopLeft.y(), abottomRight.x(), abottomRight.y());

    }

    void drawShape(QPainter *_qp) override{
        _qp->drawRect(*this);
    };

private:
};


class Line :public Shape, public QLine
{
public:
    Line(const QPoint &pt1_, const QPoint &pt2_) : pt1(pt1_), pt2(pt2_) {

        setP1(pt1_);
        setP2(pt2_);
    }

    void drawShape(QPainter *_qp) override{
        _qp->drawLine(*this);
    };

private:
    QPoint pt1, pt2;
};



#endif // SHAPE_H
