#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QWidget>

class Dialog : public QDialog{
    Q_OBJECT
public:
    Dialog(QPixmap* pixmap, QWidget* parent = nullptr);
private slots:
    void saveImage();
private:
    //QGridLayout* m_gridLayout{nullptr};
    QCheckBox* m_checkBox{nullptr};
    QLineEdit* m_lineEdit{nullptr};
    QPushButton* m_saveButton{nullptr};
    QPushButton* m_cancelButton{nullptr};
    QPixmap* m_pixmap{nullptr};


};

#endif // DIALOG_H
