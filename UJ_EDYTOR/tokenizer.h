// Joanna Ziobrowska

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>

class WordPosition{

public:
    WordPosition(std::string word, int position) : word(word), position(position) {}

    std::string getWord() { return word; }
    int getPosition() { return position; }

private:
    std::string word;
    int position;
};


class Tokenizer{

public:
    Tokenizer(std::string text) : text(text), position(0) {}

    bool hasNext();
    WordPosition nextWordPosition();


private:
    int getFirstAlphaIndex(int from);
    int getFirstNonAlphaIndex(int from);

private:
    std::string text;
    int position;
};

#endif // TOKENIZER_H
