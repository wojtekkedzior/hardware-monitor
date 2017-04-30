#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <fanupdater.h>
#include <string>
#include <iostream>


using namespace std;

void MainWindow::onProgressChanged(QString info) {
    double currentMax = 0;

     if (ui->fan2_max->toPlainText().toStdString().length() != 0) {
         currentMax = std::stod (ui->fan2_max->toPlainText().toStdString(), NULL);
     }

     double currentTemp = std::stod (info.toStdString(), NULL);

     if(currentTemp > currentMax) {
         ui->fan2_max->setText(info);
     } else {

     }

     ui->fan2_current->setText(info);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QThread* thread = new QThread;
    FanUpdater* worker = new FanUpdater();
    worker->moveToThread(thread);
    connect(thread, SIGNAL (started()), worker, SLOT (process()));
    connect(worker, SIGNAL (progressChanged(const QString&)), SLOT (onProgressChanged(const QString&)));
    thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
