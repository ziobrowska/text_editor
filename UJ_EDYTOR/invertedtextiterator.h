// Joanna Ziobrowska

#ifndef INVERTEDTEXTITERATOR_H
#define INVERTEDTEXTITERATOR_H

#include "textiterator.h"

class InvertedTextIterator : public TextIterator{

public:
    int getNext(const std::string & text, const std::string & term, int start_pos = 0);

};

#endif // INVERTEDTEXTITERATOR_H
