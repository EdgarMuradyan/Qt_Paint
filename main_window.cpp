#include "main_window.h"
#include "qstatusbar.h"

#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include "widget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent},
      m_widget(new Widget(this))
{
    setCentralWidget(m_widget);
    createToolbar();
    createFileMenu();
    setMinimumSize(600, 600);
    statusBar()->showMessage("Status Bar");
}

void MainWindow::saveWidget()
{
    constexpr const char* fileName = "canvas.png";
    const QPixmap pm = m_widget->grab();
    pm.save(fileName);
}

void MainWindow::createFileMenu()
{
    //name of Menu bar
    QMenu* fileMenu = new QMenu("File");

    ///Menus actions
    //save action for save widget in png
    m_SaveAction = new QAction("Save", this);
    QObject::connect(m_SaveAction, &QAction::triggered, this, &MainWindow::saveWidget);
    //exit is app
    m_ExitAction = new QAction("Exit", this);
    QObject::connect(m_ExitAction, &QAction::triggered, this, &MainWindow::close);

    //adding actions in File menu bar
    fileMenu->addAction(m_SaveAction);
    fileMenu->addAction(m_ExitAction);

    //set icons for Actions
    QIcon _exitIcon("C:/Users/home_/Desktop/Synopsys/Qt/Qt_Paint/Icons/Exit.png");
    m_ExitAction->setIcon(_exitIcon);
    QIcon _saveIcon("C:/Users/home_/Desktop/Synopsys/Qt/Qt_Paint/Icons/Save.png");
    m_SaveAction->setIcon(_saveIcon);

    //add menu in menu bar
    QMenuBar *mb = menuBar();
    mb->addMenu(fileMenu);

    this->setMinimumSize(600, 600);
    this->setCentralWidget(m_widget);
}

void MainWindow::createToolbar()
{
    //creat actions
    QAction* _line = new QAction(QString("Line"), this);
    QAction* _rect = new QAction(QString("Rectangle"), this);
    QAction* _clear = new QAction(QString("Clear"), this);

    //set icons for Actions
    QIcon _lineIcon("C:/Users/home_/Desktop/Synopsys/Qt/Qt_Paint/Icons/Line.png");
    _line->setIcon(_lineIcon);
    QIcon _rectIcon("C:/Users/home_/Desktop/Synopsys/Qt/Qt_Paint/Icons/Rectangle.png");
    _rect->setIcon(_rectIcon);
    QIcon _clearIcon("C:/Users/home_/Desktop/Synopsys/Qt/Qt_Paint/Icons/Clear.png");
    _clear->setIcon(_clearIcon);

    m_toolBar = new QToolBar(this);
    m_toolBar->addAction(_line);
    m_toolBar->addAction(_rect);
    m_toolBar->addAction(_clear);

    //connections tool bar
    QObject::connect(_line, &QAction::triggered, m_widget, &Widget::selectLine);
    QObject::connect(_rect, &QAction::triggered, m_widget, &Widget::selectRect);
    QObject::connect(_clear, &QAction::triggered, m_widget, &Widget::clearObjects);
    addToolBar(m_toolBar);
}




