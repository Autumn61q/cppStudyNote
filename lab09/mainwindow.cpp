// mainwindow.cpp

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    createMenu();
}

void MainWindow::createMenu() {
    QMenuBar *menuBar = new QMenuBar(this); // Create a menu bar

    // Create menus to be added to the menu bar
    QMenu *fileMenu = menuBar->addMenu("File");
    // TODO: Add Edit to menu bar
    QMenu *editMenu = menuBar->addMenu("Edit");
    // Add actions to the 'File' menu
    QAction *openAction = new QAction("Open", this);

    fileMenu->addAction(openAction);
    // TODO: Add Save item
    QAction *saveAction = new QAction("Save",this);
    fileMenu->addAction(saveAction);
    // TODO: Add actions to the 'Edit' menu
    editMenu->addAction(openAction);
    editMenu->addAction(saveAction);
    // Set the menu bar for the main window
    setMenuBar(menuBar);
}

