// Joanna Ziobrowska

#ifndef TEXTITERATOR_H
#define TEXTITERATOR_H

#include <string>

class TextIterator{

public:
    virtual int getNext(const std::string & text, const std::string & term, int start_pos = 0) = 0;
};

#endif // TEXTITERATOR_H
