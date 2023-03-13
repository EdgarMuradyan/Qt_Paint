
#include "logger.hpp"



Logger::Logger(QWidget* p) //: QDockWidget(p)
{
    mTextEdit = new QTextEdit;
    QVBoxLayout* l = new QVBoxLayout(this);
    l->addWidget(mTextEdit);
    mTextEdit->setText("Label");
    //setWidget(mTextEdit);
    setWindowTitle("Event Logger");
    //setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    //setFeatures(QDockWidget::DockWidgetMovable);

}

void Logger::log(const QString& l)
{
    mLog.append("[" + QTime::currentTime().toString() + "] ");
    mLog.append(l);
    mLog.append('\n');
    mTextEdit->setText(mLog);

    static const QString filename = "log.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "EventLogger.exe\n";
        stream << "Log file generated in ";
        stream << QDate::currentDate().toString() << " ";
        stream << QTime::currentTime().toString() << "\n\n";
        stream << mLog;
    }
}

void Logger::updateVisibility(bool vs)
{
    if(!vs){
        this->hide();
    } else {
        this->show();
    }
}
