#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <map>
#include <string>


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
    Ui::MainWindow *ui;
    void alertWhenOverMaxMhz();

public slots:
    void onProgressChanged(std::map<std::string, std::string> map);
    void cpuFrqChanged(std::map<std::string, std::string> map);
    void cpuTempChanged(std::map<std::string, std::string> map);
};

#endif // MAINWINDOW_H
