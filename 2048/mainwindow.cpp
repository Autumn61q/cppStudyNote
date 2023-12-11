#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initialized
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            grid[i][j]=0;
        }
    }

    initializeButton=new QPushButton("Start Game", this);
    initializeButton->setGeometry(60,400,200,50);

    // slots and signals
    connect(initializeButton, SIGNAL(clicked()), this, SLOT(slotStart()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    painter.setFont(QFont("Microsoft YaHei",20,700,false));

    painter.drawText(QPoint(20,60),"SCORES: "+QString::number(scores));


    //implementation of tiles
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            painter.setPen(Qt::transparent);
            painter.drawRect(j*60+40,i*60+120,55,55);//position coordinates of different squares
            if(grid[i][j]==0){
                //color of blank squares
                painter.setBrush(Qt::gray);
            }
            else if(grid[i][j]==2){
//                painter.setBrush(Qt::red);
//                painter.setPen(Qt::black);
//                painter.setFont(QFont("Microsoft YaHei",10,700,false));
//                // mark number 2 in the middle of the square
//                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(2),QTextOption(Qt::AlignCenter));
                painter.setBrush(Qt::red);
                //painter.drawRect(j*60+40, i*60+120, 55, 55); // 绘制红色方格

                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei", 10, 700, false));
                painter.drawText(QRectF(j*60+40, i*60+120, 55, 55), QString::number(2), QTextOption(Qt::AlignCenter)); // 在方格中心绘制数字2
            }
            else if(grid[i][j]==4){
                painter.setBrush(Qt::red);
                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei",10,700,false));
                // mark number 2 in the middle of the square
                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(4),QTextOption(Qt::AlignCenter));
            }
            else if(grid[i][j]==8){
                painter.setBrush(Qt::red);
                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei",10,700,false));
                // mark number 2 in the middle of the square
                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(8),QTextOption(Qt::AlignCenter));
            }
            else if(grid[i][j]==16){
                painter.setBrush(Qt::red);
                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei",10,700,false));
                // mark number 2 in the middle of the square
                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(16),QTextOption(Qt::AlignCenter));
            }
            else if(grid[i][j]==32){
                painter.setBrush(Qt::red);
                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei",10,700,false));
                // mark number 2 in the middle of the square
                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(32),QTextOption(Qt::AlignCenter));
            }
            else if(grid[i][j]==64){
                painter.setBrush(Qt::red);
                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei",10,700,false));
                // mark number 2 in the middle of the square
                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(64),QTextOption(Qt::AlignCenter));
            }
            else if(grid[i][j]==128){
                painter.setBrush(Qt::red);
                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei",10,700,false));
                // mark number 2 in the middle of the square
                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(128),QTextOption(Qt::AlignCenter));
            }
            else if(grid[i][j]==256){
                painter.setBrush(Qt::red);
                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei",10,700,false));
                // mark number 2 in the middle of the square
                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(256),QTextOption(Qt::AlignCenter));
            }
            else if(grid[i][j]==512){
                painter.setBrush(Qt::red);
                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei",10,700,false));
                // mark number 2 in the middle of the square
                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(512),QTextOption(Qt::AlignCenter));
            }
            else if(grid[i][j]==1024){
                painter.setBrush(Qt::red);
                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei",10,700,false));
                // mark number 2 in the middle of the square
                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(1024),QTextOption(Qt::AlignCenter));
            }
            else if(grid[i][j]==2048){
                painter.setBrush(Qt::red);
                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei",10,700,false));
                // mark number 2 in the middle of the square
                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(2048),QTextOption(Qt::AlignCenter));
            }
            else{
                painter.setBrush(Qt::red);
                painter.setPen(Qt::black);
                painter.setFont(QFont("Microsoft YaHei",10,700,false));
                // mark number 2 in the middle of the square
                painter.drawText(QRectF(j*60+40,i*60+120,55,55),QString::number(grid[i][j]),QTextOption(Qt::AlignCenter));
            }
        }
    }
}

bool MainWindow::whetherGameOver(){
    // find whether there are tiles can be merged in each row
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(grid[i][j]==grid[i][j+1]){
                return false;
            }
        }
    }

    // find whether there are tiles can be merged in each column
    for(int j=0;j<4;j++){
        for(int i=0;i<3;i++){
            if(grid[i][j]==grid[i+1][j]){
                return false;
            }
        }
    }

    return true;
}

void MainWindow::RandomlyGenerate(){
    QVector<QVector<int> > blank;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid[i][j]==0){
                blank.push_back({i,j});
            }
        }
    }
    if(blank.size()==0){
        if(whetherGameOver()){
            QMessageBox::about(this, "Game Over","\nYour socres is "+QString::number(scores)+" ");
            return;
        }
        int num=randomGenerator.bounded(blank.size());
        int i=blank[num][0];
        int j=blank[num][1];
        int value=randomGenerator.bounded(10);
        if(value==9) grid[i][j]=4;
        else grid[i][j]=2;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!state) return;
    switch(event->key()){
    case Qt::Key_Up:
        pressUp();
        break;
    case Qt::Key_Down:
        pressDown();
        break;
    case Qt::Key_Left:
        pressLeft();
        break;
    case Qt::Key_Right:
        pressRight();
        break;
    default:
        return;
    }

    // check whether the game is over & (if not) generate a new tile
    RandomlyGenerate();
    update();
}


void MainWindow::findNonBlank(int i,int j,int hdir,int vdir,int &times)
{
    if(i>=4||j>=4||i<0||j<0) return;
    if(grid[i][j]==0){
        times++;
        findNonBlank(i+vdir,j+hdir,hdir,vdir,times);
    }
    return;
}

bool MainWindow::findSameValue(int i,int j,int hdir,int vdir,int &times,int value)
{
    if(i>=4||j>=4||i<0||j<0) return false;
    times++;
    if(grid[i][j]==0){
        findSameValue(i+vdir,j+hdir,hdir,vdir,times, value);
    }
    else{
        if(grid[i][j]==value) return true;
        else return false;
    }
}

void MainWindow::pressUp()
{
    //Firstly, merge the squares having the same value
    for(int j=0;j<4;j++){
        for(int i=0;i<4;i++){
            int times=0;
            if(findSameValue(i+1,j,0,1,times,grid[i][j])){
                grid[i][j]+=grid[i+times][j];
                scores+=grid[i][j];
                grid[i+times][j]=0;
            }
        }
    }

    //Secondly, rearrange all squares in this direction
    for(int j=0;j<4;j++){
        for(int i=0;i<4;i++){
            int times=0;
            findNonBlank(i,j,0,1,times);
            grid[i][j]=grid[i+times][j];
            grid[i+times][j]=0;
        }
    }

    //    record another kind of implementation:

    // firstly, rearrange the tiles
    //    for(int j=0;j<4;j++){
    //        for(int i=1;i<4;i++){
    //            if(grid[i][j]==0) continue;
    //            for(int p=0;p<i;p++){
    //                if(grid[p][j]==0){
    //                    grid[p][j]==grid[i][j];
    //                    grid[i][j]==0;
    //                    break;
    //                }
    //            }
    //        }
    //    }
    // secondly, merge
//    for(int j=0;j<4;j++){
//        for(int i=0;i<3;i++){
//            if(grid[i][j]==grid[i+1][j]){
//                grid[i][j]+=grid[i][j];
//                grid[i+1][j]=0;
//            }
//            for(int p=i+1;p<3;p++){
//                grid[p][j]=grid[p+1][j];
//                grid[p+1][j]=0;
//            }
//        }
//    }
}

void MainWindow::pressDown()
{
    //Firstly, merge the squares having the same value
    for(int j=0;j<4;j++){
        for(int i=3;i>=0;i--){
            int times=0;
            if(findSameValue(i-1,j,0,-1,times,grid[i][j])){
                grid[i][j]+=grid[i-times][j];
                scores+=grid[i][j];
                grid[i-times][j]=0;
            }
        }
    }

    //Secondly, rearrange all squares in this direction
    for(int j=0;j<4;j++){
        for(int i=3;i>=0;i--){
            int times=0;
            findNonBlank(i,j,0,-1,times);
            grid[i][j]=grid[i-times][j];
            grid[i-times][j]=0;
        }
    }
}

void MainWindow::pressLeft()
{
    //Firstly, merge the squares having the same value
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int times=0;
            if(findSameValue(i,j+1,1,0,times,grid[i][j])){
                grid[i][j]+=grid[i][j+times];
                scores+=grid[i][j];
                grid[i][j+times]=0;
            }
        }
    }

    //Secondly, rearrange all squares in this direction
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int times=0;
            findNonBlank(i,j,1,0,times);
            grid[i][j]=grid[i][j+times];
            grid[i][j+times]=0;
        }
    }
}

void MainWindow::pressRight()
{
    //Firstly, merge the squares having the same value
    for(int i=0;i<4;i++){
        for(int j=3;j>=0;j--){
            int times=0;
            if(findSameValue(i,j-1,-1,0,times,grid[i][j])){
                grid[i][j]+=grid[i][j-times];
                scores+=grid[i][j];
                grid[i][j-times]=0;
            }
        }
    }

    //Secondly, rearrange all squares in this direction
    for(int i=0;i<4;i++){
        for(int j=3;j>=0;j--){
            int times=0;
            findNonBlank(i,j,-1,0,times);
            grid[i][j]=grid[i][j-times];
            grid[i][j-times]=0;
        }
    }
}

void MainWindow::slotStart()
{
    QMessageBox::about(this,"Rules","...haven't written yet");
    scores=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            grid[i][j]=0;
        }
    }
    initializeButton->setText("New Game");

    int numberText1=randomGenerator.bounded(10);
    int numberText2=randomGenerator.bounded(10);
    int i1=randomGenerator.bounded(4);
    int j1=randomGenerator.bounded(4);
    int i2=randomGenerator.bounded(4);
    int j2=randomGenerator.bounded(4);
    if(numberText1==9) grid[i1][j1]=4;
    else grid[i1][j1]=2;
    if(numberText2==9) grid[i2][j2]=4;
    else grid[i2][j2]=2;
    state=true;
    update();
}
