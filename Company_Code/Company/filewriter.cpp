#include "filewriter.h"

#include <QFile>
#include <QTextStream>
#include <QMetaProperty>

FileWriter::FileWriter(QString f): filename(f)
{
}

void FileWriter::write(QList<Company *> list) const
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream output(&file);

        foreach(Company *c, list)
        {
            const QMetaObject *meta = c->metaObject();
            for (int i=1; i<meta->propertyCount(); i++)
            {
                const QMetaProperty prop = meta->property(i);
                output << prop.read(c).toString();
                if (i<meta->propertyCount()-1)
                    output << ",";
            }
            output << "\n";
        }

        file.close();
    }
}
