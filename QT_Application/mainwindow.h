#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clickablelabel.h"
#include "CodeEditor.h"
#include <QGraphicsDropShadowEffect>>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void myfunction();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Browse_clicked();

private:
    Ui::MainWindow *ui;
    ClickableLabel* Copy[2];
    CodeEditor* XMLInput;
    CodeEditor* XMLOutput;
    QGraphicsDropShadowEffect* effect[13];
    QWidget* Buttons[13];
};
#endif // MAINWINDOW_H
