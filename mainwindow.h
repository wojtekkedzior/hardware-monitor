#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <map>
#include <string>

#include <QTextBrowser>

#include <fanupdater.h>
#include <cpufrqupdater.h>
#include <cputempupdater.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    FanUpdater* worker;
    CpuFrqUpdater* cpuFrqWorker;
    CpuTempUpdater* cpuTempWorker;


    Ui::MainWindow *ui;
    void alertWhenOverMaxMhz();
    void updateSensorValues(QTextBrowser* current,
                            QTextBrowser* min,
                            QTextBrowser* max,
                            QTextBrowser* extraReadingOne,
                            QTextBrowser* extraReadingTwo,
                            std::string str_reading,
                            std::string str_extraReadingOne_value,
                            std::string str_extraReadingTwo_value,
                            bool useOffset);

public slots:
    void onProgressChanged(std::map<std::string, std::string> map);
    void cpuFrqChanged(std::map<std::string, std::string> map);
    void cpuTempChanged(std::map<std::string, std::string> map);
private slots:
    void on_temp_offset_value_textChanged();
    void on_update_frequency_textChanged();
};

#endif // MAINWINDOW_H
