//
// Created by Sakura on 5/23/2021.
//

#include <iostream>
#include "GUI.h"

void GUI::initGUI() {
    this->service.readFile();

    auto* mainLayout = new QVBoxLayout{this};
    // list
    this->ObjectsListWidget = new QListWidget{};
    this->ObjectsListWidget->setMinimumWidth(300);
    this->ObjectsListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    mainLayout->addWidget(this->ObjectsListWidget);

    // label + textedit
    auto* manufacturerWidget = new QWidget{};
    auto* manufacturerLayout = new QFormLayout{ manufacturerWidget };
    auto* manufacturerLabel = new QLabel{"&Manufacturer: "};
    this->manufacturerLineEdit = new QLineEdit{};
    manufacturerLabel->setBuddy(this->manufacturerLineEdit);
    manufacturerLayout->addRow(manufacturerLabel, this->manufacturerLineEdit);
    mainLayout->addWidget(manufacturerWidget);

    // button
    auto* buttonsWidget = new QWidget{};
    auto* buttonsLayout = new QHBoxLayout{buttonsWidget};
    this->manufacturerButton = new QPushButton("Search");
    buttonsLayout->addWidget(this->manufacturerButton);
    mainLayout->addWidget(buttonsWidget);
    QObject::connect(this->manufacturerButton, &QPushButton::clicked, this, &GUI::getNumberOfObjects);

    // labels
    auto* nrObjectsWidget = new QWidget{};
    auto* nrObjectsLayout = new QFormLayout{ nrObjectsWidget };
    auto* nrObjectsLabel = new QLabel{"Number of Objects: "};
    this->nrObjectsLineEdit = new QLineEdit{};
    nrObjectsLabel->setBuddy(this->nrObjectsLineEdit);
    nrObjectsLayout->addRow(nrObjectsLabel, this->nrObjectsLineEdit);
    mainLayout->addWidget(nrObjectsWidget);

    this->populateObjectList();
}

void GUI::getNumberOfObjects() {
    std::string manufacturer = this->manufacturerLineEdit->text().toStdString();
    int nr = this->service.getManufacturerObjects(manufacturer);
    this->nrObjectsLineEdit->setText(QString::fromStdString(std::to_string(nr)));
}

void GUI::populateObjectList() {
    if(this->ObjectsListWidget->count() > 0)
        this->ObjectsListWidget->clear();
    auto Objects = this->service.sortObjects();

    for (auto &c: Objects){
        // fromStdString() -> Returns a copy of the str string
        QString itemInList = QString::fromStdString(c.getName()+" "+c.getModel());
        QFont font{"Verdana", 10};

        auto* item = new QListWidgetItem{itemInList};
        item->setFont(font);
        auto colorString = QString::fromStdString(c.getColor());
        item->setForeground(QColor(colorString));
        this->ObjectsListWidget->addItem(item);
    }

    // set the selection on the first item in the list if it's not empty
    if (!Objects.empty())
        this->ObjectsListWidget->setCurrentRow(0);
}

GUI::GUI(Service &service, QWidget *parent): QWidget{parent}, service{service} {
    this->initGUI();
}


GUI::~GUI() = default;
