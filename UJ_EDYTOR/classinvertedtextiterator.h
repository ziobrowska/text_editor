#ifndef CLASSINVERTEDTEXTITERATOR_H
#define CLASSINVERTEDTEXTITERATOR_H

#include <string>

#include "textiterator.h"

class InvertedTextIterator : public TextIterator{

public:
    int getNext(const std::string & text, const std::string & term, int start_pos = 0);
};

#endif // CLASSINVERTEDTEXTITERATOR_H
