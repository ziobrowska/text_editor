// Joanna Ziobrowska

#ifndef KMPTEXTITERATOR_H
#define KMPTEXTITERATOR_H

#include <string>

#include "textiterator.h"

class KMPTextIterator : public TextIterator{

public:
    int getNext(const std::string & text, const std::string & term, int start_pos = 0);
};

#endif // KMPTEXTITERATOR_H
