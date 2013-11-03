#ifndef WORDRECORD_H
#define WORDRECORD_H

#include <QString>

class WordRecord
{

public:
    WordRecord();
    ~WordRecord();

    unsigned int artikel;
    unsigned int suffix;

    QString word;
    QString meaning;

    bool isSuccefullySelected;
};

#endif // WORDRECORD_H
