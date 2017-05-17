#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fanupdater.h>
#include <cpuupdater.h>
#include <cputempupdater.h>

#include <QThread>
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
     min = 0;
     max = 0;

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

void updateSensorValues (QTextBrowser* current, QTextBrowser* min, QTextBrowser* max, QTextBrowser* maxAllowed, QTextBrowser* critical, int inputTemp, int maxTemp, int criticalTemp) {
    int _min, _max = 0;

    current->setText(QString::number(inputTemp/1000));

    //minimum
    if(min->toPlainText().toStdString().length() == 0) {
        min->setText(QString::number(inputTemp/1000));
    } else {
        _min = std::stoi (min->toPlainText().toStdString(), NULL);
    }

    if((inputTemp/1000) < _min) {
        min->setText(QString::number(inputTemp/1000));
    }

    //maximum
    if(max->toPlainText().toStdString().length() == 0) {
        max->setText(QString::number(inputTemp/1000));
    } else {
        _max = std::stoi (max->toPlainText().toStdString(), NULL);
    }

    if((inputTemp/1000) > _max) {
        max->setText(QString::number(inputTemp/1000));
    }

    maxAllowed->setText(QString::number(maxTemp/1000));
    critical->setText(QString::number(criticalTemp/1000));
}


void MainWindow::cpuChanged(std::map<std::string, std::string> map) {
    updateSensorValues(ui->cpu0_current, ui->cpu0_min, ui->cpu0_max, ui->cpu0_max_allowed, ui->cpu0_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq"]));

    updateSensorValues(ui->cpu1_current, ui->cpu1_min, ui->cpu1_max, ui->cpu1_max_allowed, ui->cpu1_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_min_freq"]));

    updateSensorValues(ui->cpu2_current, ui->cpu2_min, ui->cpu2_max, ui->cpu2_max_allowed, ui->cpu2_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_min_freq"]));

    updateSensorValues(ui->cpu3_current, ui->cpu3_min, ui->cpu3_max, ui->cpu3_max_allowed, ui->cpu3_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_min_freq"]));

    updateSensorValues(ui->cpu4_current, ui->cpu4_min, ui->cpu4_max, ui->cpu4_max_allowed, ui->cpu4_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_min_freq"]));

    updateSensorValues(ui->cpu5_current, ui->cpu5_min, ui->cpu5_max, ui->cpu5_max_allowed, ui->cpu5_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_min_freq"]));

    updateSensorValues(ui->cpu6_current, ui->cpu6_min, ui->cpu6_max, ui->cpu6_max_allowed, ui->cpu6_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_min_freq"]));

    updateSensorValues(ui->cpu7_current, ui->cpu7_min, ui->cpu7_max, ui->cpu7_max_allowed, ui->cpu7_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_min_freq"]));

    updateSensorValues(ui->cpu8_current, ui->cpu8_min, ui->cpu8_max, ui->cpu8_max_allowed, ui->cpu8_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_min_freq"]));

    updateSensorValues(ui->cpu9_current, ui->cpu9_min, ui->cpu9_max, ui->cpu9_max_allowed, ui->cpu9_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_min_freq"]));

    updateSensorValues(ui->cpu10_current, ui->cpu10_min, ui->cpu10_max, ui->cpu10_max_allowed, ui->cpu10_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_min_freq"]));

    updateSensorValues(ui->cpu11_current, ui->cpu11_min, ui->cpu11_max, ui->cpu11_max_allowed, ui->cpu11_min_allowed,
        std::stoi(map["/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_cur_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_max_freq"]),
        std::stoi(map["/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_min_freq"]));
}

void MainWindow::cpuTempChanged(std::map<std::string, std::string> map) {
    updateSensorValues(ui->package_current, ui->package_min, ui->package_max, ui->package_max_allowed, ui->package_critical,
        std::stoi(map["/sys/class/hwmon/hwmon0/temp1_input"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp1_max"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp1_crit"]));

    updateSensorValues(ui->cpu0_temp_current, ui->cpu0_temp_min, ui->cpu0_temp_max, ui->cpu0_temp_max_allowed, ui->cpu0_temp_critical,
        std::stoi(map["/sys/class/hwmon/hwmon0/temp2_input"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp2_max"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp2_crit"]));

    updateSensorValues(ui->cpu1_temp_current, ui->cpu1_temp_min, ui->cpu1_temp_max, ui->cpu1_temp_max_allowed, ui->cpu1_temp_critical,
        std::stoi(map["/sys/class/hwmon/hwmon0/temp3_input"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp3_max"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp3_crit"]));

    updateSensorValues(ui->cpu2_temp_current, ui->cpu2_temp_min, ui->cpu2_temp_max, ui->cpu2_temp_max_allowed, ui->cpu2_temp_critical,
        std::stoi(map["/sys/class/hwmon/hwmon0/temp4_input"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp4_max"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp4_crit"]));

    updateSensorValues(ui->cpu3_temp_current, ui->cpu3_temp_min, ui->cpu3_temp_max, ui->cpu3_temp_max_allowed, ui->cpu3_temp_critical,
        std::stoi(map["/sys/class/hwmon/hwmon0/temp5_input"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp5_max"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp5_crit"]));

    updateSensorValues(ui->cpu4_temp_current, ui->cpu4_temp_min, ui->cpu4_temp_max, ui->cpu4_temp_max_allowed, ui->cpu4_temp_critical,
        std::stoi(map["/sys/class/hwmon/hwmon0/temp6_input"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp6_max"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp6_crit"]));

    updateSensorValues(ui->cpu5_temp_current, ui->cpu5_temp_min, ui->cpu5_temp_max, ui->cpu5_temp_max_allowed, ui->cpu5_temp_critical,
        std::stoi(map["/sys/class/hwmon/hwmon0/temp7_input"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp7_max"]),
        std::stoi(map["/sys/class/hwmon/hwmon0/temp7_crit"]));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QThread* thread = new QThread;
    FanUpdater* worker = new FanUpdater();
    worker->moveToThread(thread);
    connect(thread, SIGNAL (started()), worker,
                      SLOT (process()));
    connect(worker, SIGNAL (progressChanged(const std::map<std::string, std::string>&)),
                      SLOT (onProgressChanged(const std::map<std::string, std::string>&)));
    thread->start();


    QThread* cpuThread = new QThread;
    CpuUpdater* cpuWorker = new CpuUpdater();
    cpuWorker->moveToThread(cpuThread);
    connect(cpuThread, SIGNAL (started()), cpuWorker,
                         SLOT (process()));
    connect(cpuWorker, SIGNAL (cpuChanged(const std::map<std::string, std::string>&)),
                         SLOT (cpuChanged(const std::map<std::string, std::string>&)));
    cpuThread->start();


    QThread* cpuTempThread = new QThread;
    CpuTempUpdater* cpuTempWorker = new CpuTempUpdater();
    cpuTempWorker->moveToThread(cpuTempThread);
    connect(cpuTempThread, SIGNAL (started()), cpuTempWorker,
                             SLOT (process()));
    connect(cpuTempWorker, SIGNAL (cpuTempChanged(const std::map<std::string, std::string>&)),
                             SLOT (cpuTempChanged(const std::map<std::string, std::string>&)));
    cpuTempThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
