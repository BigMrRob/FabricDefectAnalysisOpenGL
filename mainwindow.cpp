#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widgetframes.h"
#include <iostream>
#include <QStyle>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setGeometry(QStyle::alignedRect(
                     Qt::LeftToRight,
                     Qt::AlignCenter,
                     size(),
                     qApp->desktop()->availableGeometry()
                 ));

    this->widgetFrames = new WidgetFrames();

    connect(ui->pushButtonStart, SIGNAL(clicked()), this, SLOT(handlerPushButtonStart()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handlerPushButtonStart()
{
    this->widgetFrames->show();

    this->hide();
}

