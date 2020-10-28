#ifndef COMPANYNOTFORPROFIT_H
#define COMPANYNOTFORPROFIT_H

#include "company.h"

class CompanyNotForProfit : public Company
{
    Q_OBJECT
    Q_PROPERTY(bool charitable READ getCharitable WRITE setCharitable)
public:
    CompanyNotForProfit(QString n, QDate d, bool c);
    QString toString() const;
private:
    bool charitable;

    bool getCharitable() const;
    void setCharitable(bool c);
};

#endif // COMPANYNOTFORPROFIT_H
