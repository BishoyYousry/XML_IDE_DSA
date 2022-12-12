#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QScrollArea>
#include "CodeEditor.h"
#include "clickablelabel.h"
#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle("XML Tool");
    setWindowIcon(QIcon(":/icon/Icons/MainWindow.jpg"));

    setStyleSheet("MainWindow{background-color:rgb(255,255,255);}");

    for(int i=0;i<13;i++)
    {
        effect[i] = new QGraphicsDropShadowEffect();
        effect[i]->setBlurRadius(2);
        effect[i]->setXOffset(0.5);
        effect[i]->setYOffset(1);
        effect[i]->setColor(qRgba(0,0,0,1));
    }

    Buttons[0] = ui->pushButton_Browse
    Buttons[1] = ui->pushButton_Validate;
    Buttons[2] = ui->pushButton_Format;
    Buttons[3] = ui->pushButton_JSON;
    Buttons[4] = ui->pushButton_Minify;
    Buttons[5] = ui->pushButton_Compress;
    Buttons[6] = ui->pushButton_Decompress;
    Buttons[7] = ui->pushButton_MostActive;
    Buttons[8] = ui->pushButton_MostInfluncer;
    Buttons[9] = ui->pushButton_MutualFollowers;
    Buttons[10] = ui->pushButton_2ndDegreeFollowers;
    Buttons[11] = ui->pushButton_PostSearch;
    Buttons[12] = ui->pushButton_Save;
    for(int i=0;i<13;i++)
    {
        Buttons[i]->setStyleSheet(
                                    "QPushButton"
                                    "{"
                                     "background-color:rgb(100,200,255);border:none;"
                                     "margin-left: 0;"
                                     "float: none;"
                                     "font-weight: bolder;"
                                     "line-height: 20px;"
                                     "color: #333;"
                                     "text-align: center;"
                                     "vertical-align: middle;"
                                     "background-color: #f5f5f5;"
                                     "background-image: linear-gradient(to bottom,#fff,#e6e6e6);"
                                     "background-repeat: repeat-x;"
                                     "border: 1px solid #ccc;"
                                     "border-color: rgba(0,0,0,.1) rgba(0,0,0,.1) rgba(0,0,0,.25);"
                                     "border-bottom-color: #b3b3b3;"
                                     "border-radius: 4px;"
                                    "}"
                                    "QPushButton:hover,focus,active,disabled"
                                    "{"
                                        "background-color: #e6e6e6;"
                                     "}"
                                    "QPushButton:hover,focus"
                                    "{"
                                       "color: #333;"
                                       "text-decoration: none;"
                                       "background-position: 0 -15px;"
                                    "}"
                                    "QPushButton:focus"
                                    "{"
                                      "outline-offset: -2px;"
                                    "}"
                                   );
        Buttons[i]->setGraphicsEffect(effect[i]);
        Buttons[i]->setCursor(Qt::PointingHandCursor);

    }
    QGraphicsDropShadowEffect* gEffect = new QGraphicsDropShadowEffect();
    gEffect->setBlurRadius(5);
    gEffect->setXOffset(0);
    gEffect->setYOffset(1);
    gEffect->setColor(qRgba(34,25,25,4));
    ui->groupBox->setGraphicsEffect(gEffect);
    ui->groupBox->setStyleSheet("GroupBox{background-color:rgb(255,255,255);}");

    XMLInput = new CodeEditor();
    ui->formLayout_Input->addWidget(XMLInput);

    XMLOutput = new CodeEditor();
    ui->formLayout_Output->addWidget(XMLOutput);


    QPixmap pix(":/icon/Icons/copy.png");
    for(int i=0;i<2;i++)
    {
        Copy[i] = new ClickableLabel();
        Copy[i]->setStyleSheet(
                             "ClickableLabel"
                             "{"
                                   "margin-right: 5px;"
                             "}"
                             );
        Copy[i]->setMouseTracking(true);
        Copy[i]->setCursor(Qt::PointingHandCursor);
        Copy[i]->setPixmap(pix.scaled(20,20,Qt::KeepAspectRatio));
        Copy[i]->setToolTip("Copy");
    }


    ClickableLabel* sample = new ClickableLabel();
    sample->setText("sample");
    sample->setStyleSheet(
                         "ClickableLabel"
                         "{"
                               "margin-right: 5px;"
                               "color: #08c;"
                               "text-align: center;"
                               "font-weight: bold;"
                               "font-size: 14px;"
                               "line-height: 20px;"
                               "font: 700 14pt \"Constantia\";"
                         "}"
                         );
    sample->setMouseTracking(true);
    sample->setCursor(Qt::PointingHandCursor);

    ClickableLabel* Delete = new ClickableLabel();
    Delete->setStyleSheet(
                         "ClickableLabel"
                         "{"
                               "margin-right: 5px;"
                         "}"
                         );
    Delete->setMouseTracking(true);
    Delete->setCursor(Qt::PointingHandCursor);
    QPixmap pic(":/icon/Icons/delete.png");
    Delete->setPixmap(pic.scaled(20,20,Qt::KeepAspectRatio));
    Delete->setToolTip("Delete");

    ui->horizontalLayout_16->addWidget(Copy[0]);
    ui->horizontalLayout_16->addWidget(sample);
    ui->horizontalLayout_16->addWidget(Delete);
    ui->horizontalLayout_17->addWidget(Copy[1]);

    connect(Copy[0],SIGNAL(clicked()),this,SLOT(myfunction()));
    connect(sample,SIGNAL(clicked()),this,SLOT(myfunction()));
    connect(Delete,SIGNAL(clicked()),this,SLOT(myfunction()));
    connect(Copy[1],SIGNAL(clicked()),this,SLOT(myfunction()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myfunction()
{
    qDebug() << "Hello";
}

void MainWindow::on_pushButton_Browse_clicked()
{

}

