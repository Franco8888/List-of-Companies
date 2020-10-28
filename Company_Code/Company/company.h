#ifndef COMPANY_H
#define COMPANY_H

#include <QString>
#include <QDate>
#include <QObject>

class Company: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QDate date READ getDate WRITE setDate)
public:
    Company(QString n, QDate d);
    ~Company();
    virtual QString toString() const = 0;

private:
    QString name;
    QDate date;

    QString getName() const;
    void setName(QString n);
    QDate getDate() const;
    void setDate(QDate d);
};

#endif // COMPANY_H
