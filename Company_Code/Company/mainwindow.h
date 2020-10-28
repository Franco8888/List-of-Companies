#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "companylist.h"

class Company;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void radioChanged();
    void addCompany();

private:
    void updateDisplay();
    void writeFile();

    Ui::MainWindow *ui;
    CompanyList *list;
};

#endif // MAINWINDOW_H
