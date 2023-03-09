#ifndef SHAPE_H
#define SHAPE_H

enum class ShapeType{
    Line,
    Rectangle
};


class Shape
{
public:
    Shape();
    virtual ~Shape();

private:

    ShapeType shapeType;

};



class Rect :public Shape
{


};

class Line :public Shape
{


};











#endif // SHAPE_H
