#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widget.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);



signals:
    void clearWidget();

public slots:
    void saveWidget();


private:
    void createFileMenu();
    void createToolbar();
private:
    Widget* m_widget = nullptr;
    QToolBar* m_toolBar = nullptr;
    QAction* m_SaveAction = nullptr;
    QAction* m_ClearAction = nullptr;
    QAction* m_ExitAction = nullptr;

};

#endif // MAINWINDOW_H
