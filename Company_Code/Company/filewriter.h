#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QString>
#include "company.h"

class FileWriter
{
public:
    FileWriter(QString f);
    void write(QList<Company *> list) const;

private:
    QString filename;
};

#endif // FILEWRITER_H
