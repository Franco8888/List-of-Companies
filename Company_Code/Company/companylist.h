#ifndef COMPANYLIST_H
#define COMPANYLIST_H

#include <QList>
#include <QStringList>
#include "company.h"
//#include "companyforprofit.h"
//#include "companynotforprofit.h"

// note that there is an alternative to the solution given here
// some of the code is provided; you will have to add some yourself

class CompanyList
{
public:
    CompanyList();
    ~CompanyList();
    void addCompany(Company *c);
    QStringList getList(QString type) const;
    int size(QString type) const;

    QList<Company *> getCompanies(QString type) const;
    // alternative approach
    //QList<CompanyForProfit *> getCompaniesForProfit() const;
    //QList<CompanyNotForProfit *> getCompaniesNotForProfit() const;
private:
    QList<Company *> forProfitList;
    QList<Company *> notForProfitList;

    // alternative approach
    //QList<CompanyForProfit *> forProfitList;
    //QList<CompanyNotForProfit *> notForProfitList;
};

#endif // COMPANYLIST_H
