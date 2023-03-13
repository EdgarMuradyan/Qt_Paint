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
    virtual void drawShape(QPainter *_qp){
        _qp->drawRect(1,2,3,5);
        //QWidget *ww = new Q;
        std::cout<<"bbbbbbbbbbbbbbbbbbbbbbbbb";
    };

private:
};


class Rect :public Shape, public QRect
{
public:
    Rect(const QPoint &atopLeft, const QPoint &abottomRight) noexcept
        : x1(atopLeft.x()), y1(atopLeft.y()), x2(abottomRight.x()), y2(abottomRight.y()) {

        setCoords(x1, y1, x2, y2);

        QPainter qp;
        qp.drawRect(x1, y1, x2, y2);


    }

    void drawShapee(QPainter *_qp){
        _qp->drawRect(x1, y1, x2, y2);
    };

private:
    int x1;
    int y1;
    int x2;
    int y2;
};


class Line :public Shape, public QLine
{
public:
    Line(const QPoint &pt1_, const QPoint &pt2_) : pt1(pt1_), pt2(pt2_) {

        setP1(pt1_);
        setP2(pt2_);
    }

    void drawShapee(QPainter *_qp){
        _qp->drawLine(pt1, pt2);
        std::cout<<"aaaaaaaaaaaaaaaaaaa";
    };

private:
    QPoint pt1, pt2;
};



#endif // SHAPE_H
