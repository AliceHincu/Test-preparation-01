//
// Created by Sakura on 5/23/2021.
//

#ifndef PREGATEST_GUI_H
#define PREGATEST_GUI_H

#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include "Service.h"


class GUI: public QWidget {
    //Q_OBJECT
private:
    Service& service;
    QListWidget* ObjectsListWidget{};
    QLineEdit* manufacturerLineEdit{};
    QLineEdit* nrObjectsLineEdit{};
    QPushButton* manufacturerButton{};
public:
    GUI(Service& service, QWidget *parent = nullptr);
    ~GUI();
    void initGUI();
    void populateObjectList();

    void getNumberOfObjects();
};


#endif //PREGATEST_GUI_H
