#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QScrollArea>
#include <QDebug>
#include <QPixmap>
#include<QMessageBox>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QProgressDialog>
#include <QIcon>
#include <QLabel>
#include <QClipboard>
#include <vector>
#include <QVector>
#include "CodeEditor.h"
#include "clickablelabel.h"
#include "inputdialog.h"
#include "./ui_mainwindow.h"
#include "./XMLformatting.h"
#include "./xml_minifying.h"
#include "./Error_detection.h"
#include "./compression.h"
#include "./decompression.h"
#include "./json_Conversion.h"
#include "Graph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QString read_file(QString&);
    void write_file(QString&,QString&);
    QString read_codeeditor(CodeEditor*);
    void write_codeeditor(CodeEditor*,QString&);
    void saveFile(QString&,QString);
    QString getFile();
    void show_progress(QString);
    ~MainWindow();

private slots:
    void on_pushButton_Browse_clicked();

    void on_pushButton_Validate_clicked();

    void on_pushButton_Format_clicked();

    void on_pushButton_Minify_clicked();

    void on_pushButton_JSON_clicked();

    void on_pushButton_MostActive_clicked();

    void on_pushButton_MostInfluncer_clicked();

    void on_pushButton_SaveAs_clicked();

    void on_pushButton_Compress_clicked();

    void on_pushButton_Decompress_clicked();

    void LeftCopy_clicked();

    void RightCopy_clicked();

    void Sample_clicked();

    void Delete_clicked();

    void on_pushButton_MutualFollowers_clicked();

    void on_pushButton_2ndDegreeFollowers_clicked();

    void on_pushButton_PostSearch_clicked();

private:
    Ui::MainWindow *ui;
    ClickableLabel* Copy[2];
    ClickableLabel* sample;
    ClickableLabel* Delete;
    CodeEditor* XMLInput;
    CodeEditor* XMLOutput;
    QWidget* Buttons[13];
    QGraphicsDropShadowEffect* effect[13];
    QGraphicsDropShadowEffect* gEffect;
    QGraphicsDropShadowEffect* XMLInputEffect;
    QGraphicsDropShadowEffect* XMLOutputEffect;
    QString fileName;
    QClipboard *clip;
    Graph* graph;
};
#endif // MAINWINDOW_H
