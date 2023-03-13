#ifndef LOGGER_H
#define LOGGER_H


#include <QTextEdit>
#include <QWidget>
#include <QTextStream>
#include <QVBoxLayout>
#include <QDockWidget>
#include <QFile>
#include <QDate>
#include <QTime>
#include <iostream>


class Logger : public QWidget
{
    Q_OBJECT

public:
    Logger(QWidget *parent = nullptr);
    ~Logger() = default;

public slots:
    void log(const QString&);
    void updateVisibility(bool);

private:
    QTextEdit* mTextEdit;
    QString mLog;

};

#endif // LOGGER_H

