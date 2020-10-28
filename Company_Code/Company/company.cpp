#include "company.h"

Company::Company(QString n, QDate d): name(n), date(d)
{
}

Company::~Company()
{
}

QString Company::toString() const
{
    QString output;
    output = name + "," + date.toString("yyyy-MM-dd");
    return output;
}

QString Company::getName() const
{
    return name;
}

void Company::setName(QString n)
{
    name = n;
}

QDate Company::getDate() const
{
    return date;
}

void Company::setDate(QDate d)
{
    date = d;
}
