#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRandomGenerator>
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <QVector>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent *event);

    QPushButton* initializeButton;
    int scores=0;
    bool state;
    int grid[4][4];

    //random number seed
    QRandomGenerator randomGenerator;

    void pressUp();
    void pressDown();
    void pressRight();
    void pressLeft();
    void findNonBlank(int i,int j,int hdir,int vdir,int &times);
    bool findSameValue(int i,int j,int hdir,int vdir,int &times,int value);
    void RandomlyGenerate();
    bool whetherGameOver();

public slots:
           void slotStart();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
