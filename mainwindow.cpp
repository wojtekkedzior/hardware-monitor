#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <fanupdater.h>
#include <string>
#include <iostream>


using namespace std;

void MainWindow::onProgressChanged(QString rpm) {
     double currentTemp = std::stod (rpm.toStdString(), NULL);

     double min, max = 0;

     if (ui->fan2_max->toPlainText().toStdString().length() != 0) {
         max = std::stod (ui->fan2_max->toPlainText().toStdString(), NULL);
     }

     //first check
     if(ui->fan2_min->toPlainText().toStdString().length() == 0) {
         ui->fan2_min->setText(rpm);
     } else {
         min = std::stod (ui->fan2_min->toPlainText().toStdString(), NULL);
     }

     if(currentTemp > max) {
         ui->fan2_max->setText(rpm);
     }

     if (currentTemp < min) {
          ui->fan2_min->setText(rpm);
     }

     ui->fan2_current->setText(rpm);
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
