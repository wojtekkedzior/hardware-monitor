#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <fanupdater.h>
#include <cpuupdater.h>
#include <string>
#include <iostream>


#include <map>
#include <string>


using namespace std;

void MainWindow::onProgressChanged(std::map<std::string, std::string> map) {
//     double currentTemp = std::stod (map.toStdString(), NULL);

    //fan2
     string temp = map["/sys/class/hwmon/hwmon1/fan2_input"];

     double fan2Input_currentTemp = stod (temp, NULL);
     double min, max = 0;

     if (ui->fan2_max->toPlainText().toStdString().length() != 0) {
         max = std::stod (ui->fan2_max->toPlainText().toStdString(), NULL);
     }

     //first check
     if(ui->fan2_min->toPlainText().toStdString().length() == 0) {
         ui->fan2_min->setText(QString::fromUtf8(temp.c_str()));
     } else {
         min = std::stod (ui->fan2_min->toPlainText().toStdString(), NULL);
     }

     if(fan2Input_currentTemp > max) {
         ui->fan2_max->setText(QString::fromUtf8(temp.c_str()));
     }

     if (fan2Input_currentTemp < min) {
          ui->fan2_min->setText(QString::fromUtf8(temp.c_str()));
     }

     ui->fan2_current->setText(QString::fromUtf8(temp.c_str()));


     //fan 6

     temp = map["/sys/class/hwmon/hwmon1/fan6_input"];

     fan2Input_currentTemp = stod (temp, NULL);
     min, max = 0;

     if (ui->fan6_max->toPlainText().toStdString().length() != 0) {
         max = std::stod (ui->fan6_max->toPlainText().toStdString(), NULL);
     }

     //first check
     if(ui->fan6_min->toPlainText().toStdString().length() == 0) {
         ui->fan6_min->setText(QString::fromUtf8(temp.c_str()));
     } else {
         min = std::stod (ui->fan6_min->toPlainText().toStdString(), NULL);
     }

     if(fan2Input_currentTemp > max) {
         ui->fan6_max->setText(QString::fromUtf8(temp.c_str()));
     }

     if (fan2Input_currentTemp < min) {
          ui->fan6_min->setText(QString::fromUtf8(temp.c_str()));
     }

     ui->fan6_current->setText(QString::fromUtf8(temp.c_str()));
}


void MainWindow::cpuChanged(std::map<std::string, std::string> map) {

    int min, max = 0;


    //CPU 0
    int mhz = std::stoi(map["/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu0_current->setText(QString::number(mhz/1000));

    //minimum
    if(ui->cpu0_min->toPlainText().toStdString().length() == 0) {
        ui->cpu0_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu0_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu0_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu0_max->toPlainText().toStdString().length() == 0) {
        ui->cpu0_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu0_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu0_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq"]);
    ui->cpu0_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq"]);
    ui->cpu0_min_allowed->setText(QString::number(mhz/1000));


    //CPU 1
    mhz = std::stoi(map["/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu1_current->setText(QString::number(mhz/1000));

    //minimum
    if(ui->cpu1_min->toPlainText().toStdString().length() == 0) {
        ui->cpu1_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu1_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu1_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu1_max->toPlainText().toStdString().length() == 0) {
        ui->cpu1_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu1_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu1_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_max_freq"]);
    ui->cpu1_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_min_freq"]);
    ui->cpu1_min_allowed->setText(QString::number(mhz/1000));


    //CPU 2
    mhz = std::stoi(map["/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu2_current->setText(QString::number(mhz/1000));

    //minimum
    if(ui->cpu2_min->toPlainText().toStdString().length() == 0) {
        ui->cpu2_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu2_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu2_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu2_max->toPlainText().toStdString().length() == 0) {
        ui->cpu2_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu2_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu2_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_max_freq"]);
    ui->cpu2_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_min_freq"]);
    ui->cpu2_min_allowed->setText(QString::number(mhz/1000));


    //CPU 3
    mhz = std::stoi(map["/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu3_current->setText(QString::number(mhz/1000));

    //minimum
    if(ui->cpu3_min->toPlainText().toStdString().length() == 0) {
        ui->cpu3_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu3_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu3_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu3_max->toPlainText().toStdString().length() == 0) {
        ui->cpu3_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu3_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu3_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_max_freq"]);
    ui->cpu3_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_min_freq"]);
    ui->cpu3_min_allowed->setText(QString::number(mhz/1000));


    //CPU 4
    mhz = std::stoi(map["/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu4_current->setText(QString::number(mhz/1000));

    //minimum
    if(ui->cpu4_min->toPlainText().toStdString().length() == 0) {
        ui->cpu4_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu4_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu4_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu4_max->toPlainText().toStdString().length() == 0) {
        ui->cpu4_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu4_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu4_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_max_freq"]);
    ui->cpu4_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_min_freq"]);
    ui->cpu4_min_allowed->setText(QString::number(mhz/1000));


    //CPU 5
    mhz = std::stoi(map["/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu5_current->setText(QString::number(mhz/1000));

    //minimum
    if(ui->cpu5_min->toPlainText().toStdString().length() == 0) {
        ui->cpu5_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu5_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu5_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu5_max->toPlainText().toStdString().length() == 0) {
        ui->cpu5_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu5_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu5_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_max_freq"]);
    ui->cpu5_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_min_freq"]);
    ui->cpu5_min_allowed->setText(QString::number(mhz/1000));


    //CPU 6
    mhz = std::stoi(map["/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu6_current->setText(QString::number(mhz/1000));

    //minimum
    if(ui->cpu6_min->toPlainText().toStdString().length() == 0) {
        ui->cpu6_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu6_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu6_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu6_max->toPlainText().toStdString().length() == 0) {
        ui->cpu6_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu6_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu6_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_max_freq"]);
    ui->cpu6_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_min_freq"]);
    ui->cpu6_min_allowed->setText(QString::number(mhz/1000));


    //CPU 7
    mhz = std::stoi(map["/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu7_current->setText(QString::number(mhz/1000));

    //minimum
    if(ui->cpu7_min->toPlainText().toStdString().length() == 0) {
        ui->cpu7_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu7_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu7_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu7_max->toPlainText().toStdString().length() == 0) {
        ui->cpu7_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu7_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu7_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_max_freq"]);
    ui->cpu7_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_min_freq"]);
    ui->cpu7_min_allowed->setText(QString::number(mhz/1000));


    //CPU 8
    mhz = std::stoi(map["/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu8_current->setText(QString::number(mhz/1000));

    //minimum
    if(ui->cpu8_min->toPlainText().toStdString().length() == 0) {
        ui->cpu8_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu8_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu8_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu8_max->toPlainText().toStdString().length() == 0) {
        ui->cpu8_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu8_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu8_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_max_freq"]);
    ui->cpu8_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_min_freq"]);
    ui->cpu8_min_allowed->setText(QString::number(mhz/1000));


    //CPU 9
    mhz = std::stoi(map["/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu9_current->setText(QString::number(mhz/1000));

    //minimum
    if(ui->cpu9_min->toPlainText().toStdString().length() == 0) {
        ui->cpu9_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu9_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu9_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu9_max->toPlainText().toStdString().length() == 0) {
        ui->cpu9_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu9_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu9_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_max_freq"]);
    ui->cpu9_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_min_freq"]);
    ui->cpu9_min_allowed->setText(QString::number(mhz/1000));


    //CPU 10
    mhz = std::stoi(map["/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu10_current->setText(QString::number(mhz/1000));


    //minimum
    if(ui->cpu10_min->toPlainText().toStdString().length() == 0) {
        ui->cpu10_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu10_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu10_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu10_max->toPlainText().toStdString().length() == 0) {
        ui->cpu10_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu10_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu10_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_max_freq"]);
    ui->cpu10_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_min_freq"]);
    ui->cpu10_min_allowed->setText(QString::number(mhz/1000));


    //CPU 11
    mhz = std::stoi(map["/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_cur_freq"]);
    ui->cpu11_current->setText(QString::number(mhz/1000));

    //minimum
    if(ui->cpu11_min->toPlainText().toStdString().length() == 0) {
        ui->cpu11_min->setText(QString::number(mhz/1000));
    } else {
        min = std::stoi (ui->cpu11_min->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) < min) {
        ui->cpu11_min->setText(QString::number(mhz/1000));
    }

    //maximum
    if(ui->cpu11_max->toPlainText().toStdString().length() == 0) {
        ui->cpu11_max->setText(QString::number(mhz/1000));
    } else {
        max = std::stoi (ui->cpu11_max->toPlainText().toStdString(), NULL);
    }

    if((mhz/1000) > max) {
        ui->cpu11_max->setText(QString::number(mhz/1000));
    }

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_max_freq"]);
    ui->cpu11_max_allowed->setText(QString::number(mhz/1000));

    mhz = std::stoi(map["/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_min_freq"]);
    ui->cpu11_min_allowed->setText(QString::number(mhz/1000));














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
    connect(worker, SIGNAL (progressChanged(const std::map<std::string, std::string>&)), SLOT (onProgressChanged(const std::map<std::string, std::string>&)));
    thread->start();


    QThread* cpuThread = new QThread;
    CpuUpdater* cpuWorker = new CpuUpdater();
    cpuWorker->moveToThread(cpuThread);
    connect(cpuThread, SIGNAL (started()), cpuWorker, SLOT (process()));
    connect(cpuWorker, SIGNAL (cpuChanged(const std::map<std::string, std::string>&)), SLOT (cpuChanged(const std::map<std::string, std::string>&)));
    cpuThread->start();





}

MainWindow::~MainWindow()
{
    delete ui;
}
