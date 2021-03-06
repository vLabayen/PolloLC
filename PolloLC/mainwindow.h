#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <snap7.h>
#include "hexbits.h"
#include "plcdata.h"
#include "scadata.h"

#define GLED_ON "background-color:rgb(0,255,0);border-radius:10;border:2px solid black"
#define GLED_OFF "background-color:rgb(0,0,0);border-radius:10;border:2px solid rgb(0,255,0)"
#define RLED_ON "background-color:rgb(255,0,0);border-radius:10;border:2px solid black"
#define RLED_OFF "background-color:rgb(0,0,0);border-radius:10;border:2px solid rgb(255,0,0)"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PLCData* plcd;
    Scadata* scad;

    //QTimer* animation_timer;
    //int frameRate = 60;

private slots:
    void updatePLCState(void);
    void update_UI_1(void);
//    void update_UI_2(void);
//    void update_animations(void);

    void decrementM1OnClick(void);
    void decrementM2OnClick(void);
    void decrementM3OnClick(void);
    void decrementMDOnClick(void);
};
#endif // MAINWINDOW_H
