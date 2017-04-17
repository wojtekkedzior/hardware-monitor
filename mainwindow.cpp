#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <fanupdater.h>

void MainWindow::onProgressChanged(QString info) {
    ui->textBrowser->setText(info);
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
