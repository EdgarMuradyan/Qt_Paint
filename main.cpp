#include "widget.hpp"
#include "logger.hpp"

#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QAbstractButton>
#include <QCheckBox>
#include <QSizePolicy>
#include <QTextEdit>
#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QDockWidget>
#include <QStatusBar>
#include <QIcon>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *wid = new QWidget;
    Widget *w = new Widget(wid); ; //for peinting
    Logger *l = new Logger;
    l-> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
    w->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    //set background
    wid->setStyleSheet("background-color: white+3;");

    //        obj,     Signal Type,     esim, func name to do
    //connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    QPushButton *clearButton = new QPushButton("clear");
    QObject::connect(clearButton, &QPushButton::clicked, w, &Widget::clearObjects);


    QPushButton *rectangleButton = new QPushButton("rectangle");
    QObject::connect(rectangleButton, &QPushButton::clicked, w, &Widget::selectRect);

    QPushButton *lineButton = new QPushButton("line");
    QObject::connect(lineButton, &QPushButton::clicked, w, &Widget::selectLine);

    QCheckBox *visibilityLogger =new QCheckBox("visibility");
    visibilityLogger->setChecked(true);


    //buttons layout
    QHBoxLayout *hLayoutButtons = new QHBoxLayout;
    hLayoutButtons->addWidget(clearButton);
    hLayoutButtons->addWidget(rectangleButton);
    hLayoutButtons->addWidget(lineButton);
    hLayoutButtons->addWidget(visibilityLogger);

    QObject::connect(visibilityLogger, &QAbstractButton::toggled, l, &Logger::updateVisibility);

    //vertical layout for widget and buttons group
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(w);
    vLayout->addLayout(hLayoutButtons);


    //horizontal layout for connect logger and vertical layot
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addLayout(vLayout);
    hLayout->addWidget(l);


    wid->setLayout(hLayout);
    //wid->show();

    QMainWindow mainWindow;
    QMenu* _file = new QMenu(QString("File"));
    QMenu* _shape = new QMenu("Tools");

    auto menuBar = mainWindow.menuBar();
    menuBar->addMenu(_file);
    menuBar->addMenu(_shape);


    QAction* _exit = new QAction(QString("Exit"), &mainWindow);
    _file->addAction(_exit);

    //creat actions
    QAction* _line = new QAction(QString("Line"), &mainWindow);
    QAction* _rect = new QAction(QString("Rectangle"), &mainWindow);
    QAction* _clear = new QAction(QString("Clear"), &mainWindow);


    //set icons for Actions
    QIcon _lineIcon("C:/Users/home_/Desktop/Synopsys/Qt/Qt_Paint/Line.png");
    _line->setIcon(_lineIcon);    
    QIcon _rectIcon("C:/Users/home_/Desktop/Synopsys/Qt/Qt_Paint/Rectangle.png");
    _rect->setIcon(_rectIcon);
    QIcon _clearIcon("C:/Users/home_/Desktop/Synopsys/Qt/Qt_Paint/Clear.png");
    _clear->setIcon(_clearIcon);

    QObject::connect(_line, &QAction::triggered, w, &Widget::selectLine);
    QObject::connect(_rect, &QAction::triggered, w, &Widget::selectRect);
    QObject::connect(_clear, &QAction::triggered, w, &Widget::clearObjects);

    _shape->addAction(_line);
    _shape->addAction(_rect);
    _shape->addAction(_clear);



    //conects
    QObject::connect(_exit, &QAction::triggered, &mainWindow, &QMainWindow::close);



    mainWindow.setMinimumSize(600, 600);
    mainWindow.setCentralWidget(wid);
    //mainWindow.addDockWidget(Qt::TopDockWidgetArea, l);
    //mainWindow.addToolBar(new QToolBar);

    QToolBar *toolBar = new QToolBar();
    toolBar->addAction(_line);
    toolBar->addAction(_rect);
    toolBar->addAction(_clear);

    mainWindow.addToolBar(toolBar);

    mainWindow.statusBar()->showMessage("Status Bar");
    mainWindow.show();









    return a.exec();
}

