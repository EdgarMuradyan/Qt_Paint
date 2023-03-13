#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <vector>
#include <QLine>
#include <QRect>
#include <QPainter>
#include <QPen>
#include <iostream>
#include <sstream>
#include "shape.h"


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
    std::vector<Shape> m_shape;
    ShapeType m_shapeType;
    void drowLine();
    void drowRect();
    void drawShape();

signals:
    void eventHappened(const QString&);

public slots:
    void clearObjects();
    void selectRect();
    void selectLine();

};

#endif // WIDGET_H

