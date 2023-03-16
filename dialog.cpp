#include "dialog.h"

#include <QLabel>
#include <QFileDialog>
#include <iostream>

Dialog::Dialog(QPixmap* pixmap, QWidget* parent) : QDialog(parent) , m_pixmap(pixmap){
    m_checkBox = new QCheckBox;
    m_lineEdit = new QLineEdit;
    m_saveButton = new QPushButton("Save", this);
    m_cancelButton = new QPushButton("Cancel", this);

    QLabel* _overwrite = new QLabel("Overwrite: ");
    QLabel* _fileName = new QLabel("Filename: ");

    QGridLayout* _gridLayout = new QGridLayout(this);
    _gridLayout->addWidget(_overwrite, 0, 0, 1, 1);
    _gridLayout->addWidget(_fileName, 1, 0, 1, 1);
    _gridLayout->addWidget(m_checkBox, 0, 1, 1, 2);
    _gridLayout->addWidget(m_lineEdit, 1, 1, 1, 2);
    _gridLayout->addWidget(m_saveButton, 2, 1, 1, 1);
    _gridLayout->addWidget(m_cancelButton, 2, 2, 1, 1);

    QObject::connect(m_cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    QObject::connect(m_saveButton, &QPushButton::clicked, this, &Dialog::saveImage);

}



void Dialog::saveImage(){

    //QFileDialog *fileDialog = new QFileDialog(this);

    QString folderPath = QFileDialog::getExistingDirectory(this,
                                tr("Save File"), "");

    QString fileName = "esiminch.gpeg";
    QString filePath = folderPath + "/" + fileName;


    //QString filePath = m_lineEdit->displayText();
    m_pixmap->save(filePath);

    this->reject();

//"C:/Users/home_/Desktop/Synopsys/Qt/Qt_Paint/Icons/canvas.png"

}
