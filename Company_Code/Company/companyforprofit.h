#ifndef COMPANYFORPROFIT_H
#define COMPANYFORPROFIT_H

#include "company.h"

class CompanyForProfit : public Company
{
    Q_OBJECT
    Q_PROPERTY(int employees READ getEmployees WRITE setEmployees)
public:
    CompanyForProfit(QString n, QDate d, int e);
    QString toString() const;

private:
    int employees;

    int getEmployees() const;
    void setEmployees(int e);
};

#endif // COMPANYFORPROFIT_H
