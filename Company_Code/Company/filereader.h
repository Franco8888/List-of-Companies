#ifndef FILEREADER_H
#define FILEREADER_H

#include <QString>
#include "companylist.h"

class FileReader
{
public:
    FileReader();
    void read(QString filename, CompanyList *list);
};

#endif // FILEREADER_H
