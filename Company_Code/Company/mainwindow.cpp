#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringList>
#include "company.h"
#include "companyforprofit.h"
#include "companynotforprofit.h"
#include "filewriter.h"
#include "filereader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    list = new CompanyList;
    // get data from file
    FileReader reader1;
    reader1.read("backupFP.txt", list);
    reader1.read("backupNFP.txt", list);
    updateDisplay();

    // set up default company for GUI
    ui->radioForProfit->setChecked(true);
    ui->charitableLabel->setEnabled(false);
    ui->charitable->setEnabled(false);

    // handle change in company type
    connect(ui->radioForProfit, SIGNAL(toggled(bool)), this, SLOT(radioChanged()));

    // handle add button pressed
    connect(ui->addCompany, SIGNAL(clicked()), this, SLOT(addCompany()));
}

MainWindow::~MainWindow()
{
    writeFile();
    delete ui;
}

void MainWindow::writeFile()
{
    // save lists to files
    if (list->size("fp")>0)
    {
        FileWriter writer("backupFP.txt");
        writer.write(list->getCompanies("fp"));
    }
    if (list->size("nfp")>0)
    {
        FileWriter writer("backupNFP.txt");
        writer.write(list->getCompanies("nfp"));
    }
}

void MainWindow::addCompany()
{
    // get data from GUI and create appropriate object type
    if (ui->name->text().size() > 0)  // prevent adding a blank name
    {
        QString name = ui->name->text();
        QDate date = ui->date->date();
        Company *c;
        if (ui->radioForProfit->isChecked())
        {
            int employees = ui->employees->value();
            c = new CompanyForProfit(name, date, employees);
        }
        else
        {
            bool charitable = ui->charitable->isChecked();
            c = new CompanyNotForProfit(name, date, charitable);
        }
        ui->name->clear();
        ui->date->setDate(QDate::currentDate());
        ui->employees->setValue(0);
        ui->charitable->setChecked(false);

        list->addCompany(c);
        updateDisplay();
    }
}

void MainWindow::updateDisplay()
{
    // display list in alphabetic order
    ui->displayForProfit->clear();
    QStringList displayList = list->getList("fp");
    displayList.sort();
    foreach (QString company, displayList)
        ui->displayForProfit->append(company);
    ui->displayNotForProfit->clear();
    displayList = list->getList("nfp");
    displayList.sort();
    foreach (QString company, displayList)
        ui->displayNotForProfit->append(company);
}

void MainWindow::radioChanged()
{
    if (ui->radioForProfit->isChecked())
    {
        ui->employeesLabel->setEnabled(true);
        ui->employees->setEnabled(true);
        ui->charitableLabel->setEnabled(false);
        ui->charitable->setEnabled(false);
    }
    else
    {
        ui->employeesLabel->setEnabled(false);
        ui->employees->setEnabled(false);
        ui->charitableLabel->setEnabled(true);
        ui->charitable->setEnabled(true);
    }
}
