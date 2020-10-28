#include "companylist.h"
#include <QMetaObject>

CompanyList::CompanyList()
{
}

CompanyList::~CompanyList()
{
    qDeleteAll(forProfitList);
    qDeleteAll(notForProfitList);
    forProfitList.clear();
    notForProfitList.clear();
}

void CompanyList::addCompany(Company *c)
{
    const QMetaObject *meta = c->metaObject();
    if (meta->className() == QString("CompanyForProfit"))
        forProfitList.append(c);
    else if (meta->className() == QString("CompanyNotForProfit"))
        notForProfitList.append(c);

    //alternative approach
    /*
    const QMetaObject *meta = c->metaObject();
    if (meta->className() == QString("CompanyForProfit"))
        forProfitList.append(qobject_cast<CompanyForProfit *>(c));
    else if (meta->className() == QString("CompanyNotForProfit"))
        notForProfitList.append(qobject_cast<CompanyNotForProfit*>(c));
    */
}


QStringList CompanyList::getList(QString type) const
{
    QStringList templist;
    if (type == "fp")
    {
        for (int i=0; i<forProfitList.size(); i++)
            templist.append(forProfitList.at(i)->toString());
        return templist;
    }
    if (type == "nfp")
    {
        for (int i=0; i<notForProfitList.size(); i++)
            templist.append(notForProfitList.at(i)->toString());
        return templist;
    }
    return templist;
}

int CompanyList::size(QString type) const
{
    if (type == "fp")
        return forProfitList.size();
    else if (type == "nfp")
        return notForProfitList.size();
    return 0;
}

QList<Company *> CompanyList::getCompanies(QString type) const
{
    if (type == "fp")
        return forProfitList;
    if (type == "nfp")
        return notForProfitList;
    return QList<Company *>();
}

// alternative approach
/*
QList<CompanyForProfit *> CompanyList::getCompaniesForProfit() const
{
    return forProfitList;
}

QList<CompanyNotForProfit *> CompanyList::getCompaniesNotForProfit() const
{
    return NotForProfitList;
}
*/
