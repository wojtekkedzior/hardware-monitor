#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fanupdater.h>
#include <cpufrqupdater.h>
#include <cputempupdater.h>

#include <QThread>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void MainWindow::onProgressChanged(std::map<std::string, std::string> map) {
    //fan2
    int fanRpm = stoi(map["/sys/class/hwmon/hwmon1/fan2_input"]);

     int min, max;

     if (ui->fan2_max->toPlainText().toStdString().length() != 0) {
         max = stoi (ui->fan2_max->toPlainText().toStdString());
     } else {
          ui->fan2_max->setText(QString::number(fanRpm));
     }

     //first check
     if(ui->fan2_min->toPlainText().toStdString().length() == 0) {
         ui->fan2_min->setText(QString::number(fanRpm));
     } else {
         min = stoi (ui->fan2_min->toPlainText().toStdString());
     }

     if(fanRpm > max) {
         ui->fan2_max->setText(QString::number(fanRpm));
     }

     if (fanRpm < min) {
          ui->fan2_min->setText(QString::number(fanRpm));
     }

     ui->fan2_current->setText(QString::number(fanRpm));

     //fan 6
     fanRpm = stoi(map["/sys/class/hwmon/hwmon1/fan6_input"]);

     min = 0;
     max = 0;

     if (ui->fan6_max->toPlainText().toStdString().length() != 0) {
         max = stoi (ui->fan6_max->toPlainText().toStdString());
     }

     //first check
     if(ui->fan6_min->toPlainText().toStdString().length() == 0) {
         ui->fan6_min->setText(QString::number(fanRpm));
     } else {
         min = stoi (ui->fan6_min->toPlainText().toStdString());
     }

     if(fanRpm > max) {
         ui->fan6_max->setText(QString::number(fanRpm));
     }

     if (fanRpm < min) {
          ui->fan6_min->setText(QString::number(fanRpm));
     }

     ui->fan6_current->setText(QString::number(fanRpm));
}

void updateSensorValues (QTextBrowser* current, QTextBrowser* min, QTextBrowser* max, QTextBrowser* extraReadingOne, QTextBrowser* extraReadingTwo,
                         string str_reading, string str_extraReadingOne_value, string str_extraReadingTwo_value) {
    int _min, _max;
    int reading = stoi(str_reading);
    int extraReadingOne_value = stoi(str_extraReadingOne_value);
    int extraReadingTwo_value = stoi(str_extraReadingTwo_value);

    current->setText(QString::number(reading/1000));

    //minimum
    if(min->toPlainText().toStdString().length() == 0) {
        min->setText(QString::number(reading/1000));
    } else {
        _min = stoi (min->toPlainText().toStdString(), NULL);
    }

    if((reading/1000) < _min) {
        min->setText(QString::number(reading/1000));
    }

    //maximum
    if(max->toPlainText().toStdString().length() == 0) {
        max->setText(QString::number(reading/1000));
    } else {
        _max = stoi (max->toPlainText().toStdString(), NULL);
    }

    if((reading/1000) > _max) {
        max->setText(QString::number(reading/1000));
    }

    extraReadingOne->setText(QString::number(extraReadingOne_value/1000));
    extraReadingTwo->setText(QString::number(extraReadingTwo_value/1000));
}


void MainWindow::cpuFrqChanged(std::map<std::string, std::string> map) {
    updateSensorValues(ui->cpu0_current, ui->cpu0_min, ui->cpu0_max, ui->cpu0_max_allowed, ui->cpu0_min_allowed,
        map["/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq"]);

    updateSensorValues(ui->cpu1_current, ui->cpu1_min, ui->cpu1_max, ui->cpu1_max_allowed, ui->cpu1_min_allowed,
        map["/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_min_freq"]);

    updateSensorValues(ui->cpu2_current, ui->cpu2_min, ui->cpu2_max, ui->cpu2_max_allowed, ui->cpu2_min_allowed,
        map["/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_min_freq"]);

    updateSensorValues(ui->cpu3_current, ui->cpu3_min, ui->cpu3_max, ui->cpu3_max_allowed, ui->cpu3_min_allowed,
        map["/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_min_freq"]);

    updateSensorValues(ui->cpu4_current, ui->cpu4_min, ui->cpu4_max, ui->cpu4_max_allowed, ui->cpu4_min_allowed,
        map["/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_min_freq"]);

    updateSensorValues(ui->cpu5_current, ui->cpu5_min, ui->cpu5_max, ui->cpu5_max_allowed, ui->cpu5_min_allowed,
        map["/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_min_freq"]);

    updateSensorValues(ui->cpu6_current, ui->cpu6_min, ui->cpu6_max, ui->cpu6_max_allowed, ui->cpu6_min_allowed,
        map["/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_min_freq"]);

    updateSensorValues(ui->cpu7_current, ui->cpu7_min, ui->cpu7_max, ui->cpu7_max_allowed, ui->cpu7_min_allowed,
        map["/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_min_freq"]);

    updateSensorValues(ui->cpu8_current, ui->cpu8_min, ui->cpu8_max, ui->cpu8_max_allowed, ui->cpu8_min_allowed,
        map["/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_min_freq"]);

    updateSensorValues(ui->cpu9_current, ui->cpu9_min, ui->cpu9_max, ui->cpu9_max_allowed, ui->cpu9_min_allowed,
        map["/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_min_freq"]);

    updateSensorValues(ui->cpu10_current, ui->cpu10_min, ui->cpu10_max, ui->cpu10_max_allowed, ui->cpu10_min_allowed,
        map["/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_min_freq"]);

    updateSensorValues(ui->cpu11_current, ui->cpu11_min, ui->cpu11_max, ui->cpu11_max_allowed, ui->cpu11_min_allowed,
        map["/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_cur_freq"],
        map["/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_max_freq"],
        map["/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_min_freq"]);
}

void MainWindow::cpuTempChanged(std::map<std::string, std::string> map) {
    updateSensorValues(ui->package_current, ui->package_min, ui->package_max, ui->package_max_allowed, ui->package_critical,
        map["/sys/class/hwmon/hwmon0/temp1_input"],
        map["/sys/class/hwmon/hwmon0/temp1_max"],
        map["/sys/class/hwmon/hwmon0/temp1_crit"]);

    updateSensorValues(ui->cpu0_temp_current, ui->cpu0_temp_min, ui->cpu0_temp_max, ui->cpu0_temp_max_allowed, ui->cpu0_temp_critical,
        map["/sys/class/hwmon/hwmon0/temp2_input"],
        map["/sys/class/hwmon/hwmon0/temp2_max"],
        map["/sys/class/hwmon/hwmon0/temp2_crit"]);

    updateSensorValues(ui->cpu1_temp_current, ui->cpu1_temp_min, ui->cpu1_temp_max, ui->cpu1_temp_max_allowed, ui->cpu1_temp_critical,
        map["/sys/class/hwmon/hwmon0/temp3_input"],
        map["/sys/class/hwmon/hwmon0/temp3_max"],
        map["/sys/class/hwmon/hwmon0/temp3_crit"]);

    updateSensorValues(ui->cpu2_temp_current, ui->cpu2_temp_min, ui->cpu2_temp_max, ui->cpu2_temp_max_allowed, ui->cpu2_temp_critical,
        map["/sys/class/hwmon/hwmon0/temp4_input"],
        map["/sys/class/hwmon/hwmon0/temp4_max"],
        map["/sys/class/hwmon/hwmon0/temp4_crit"]);

    updateSensorValues(ui->cpu3_temp_current, ui->cpu3_temp_min, ui->cpu3_temp_max, ui->cpu3_temp_max_allowed, ui->cpu3_temp_critical,
        map["/sys/class/hwmon/hwmon0/temp5_input"],
        map["/sys/class/hwmon/hwmon0/temp5_max"],
        map["/sys/class/hwmon/hwmon0/temp5_crit"]);

    updateSensorValues(ui->cpu4_temp_current, ui->cpu4_temp_min, ui->cpu4_temp_max, ui->cpu4_temp_max_allowed, ui->cpu4_temp_critical,
        map["/sys/class/hwmon/hwmon0/temp6_input"],
        map["/sys/class/hwmon/hwmon0/temp6_max"],
        map["/sys/class/hwmon/hwmon0/temp6_crit"]);

    updateSensorValues(ui->cpu5_temp_current, ui->cpu5_temp_min, ui->cpu5_temp_max, ui->cpu5_temp_max_allowed, ui->cpu5_temp_critical,
        map["/sys/class/hwmon/hwmon0/temp7_input"],
        map["/sys/class/hwmon/hwmon0/temp7_max"],
        map["/sys/class/hwmon/hwmon0/temp7_crit"]);
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


    QThread* cpuFrqThread = new QThread;
    CpuFrqUpdater* cpuFrqWorker = new CpuFrqUpdater();
    cpuFrqWorker->moveToThread(cpuFrqThread);
    connect(cpuFrqThread, SIGNAL (started()), cpuFrqWorker,
                         SLOT (process()));
    connect(cpuFrqWorker, SIGNAL (cpuFrqChanged(const std::map<std::string, std::string>&)),
                         SLOT (cpuFrqChanged(const std::map<std::string, std::string>&)));
    cpuFrqThread->start();


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
