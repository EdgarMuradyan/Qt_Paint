#ifndef WIDGET_H
#define WIDGET_H

//#include "shape.h"
#include <QWidget>
#include <QString>
#include <vector>
#include <QLine>
#include <QRect>
#include <QPainter>
#include <QPen>

enum class ShapeType{
    Line,
    Rectangle
};



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    ~Widget();

    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;



private:


    std::pair<QPointF, QPointF> m_coord;
    std::vector<QLine> m_lines;
    std::vector<QRect> m_rects;
    ShapeType m_shape;
    void drowLine();
    void drowRect();

signals:
    void eventHappened(const QString&);

public slots:

    void clearObjects();
    void selectRect();
    void selectLine();


};

#endif // WIDGET_H

