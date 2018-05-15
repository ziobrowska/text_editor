// Joannn Ziobrowska

#include "tokenizer.h"

#include <cctype>  // daje dostep do isalpha

using namespace std;

bool Tokenizer::hasNext() {
    return position != text.size() && getFirstAlphaIndex(position) != -1;
}

int Tokenizer::getFirstAlphaIndex(int from){
    for (size_t i = from; i < text.size(); ++i) {
        if (::isalpha(text[i])) {
            return i;
        }
    }
    return -1;
}

int Tokenizer::getFirstNonAlphaIndex(int from){
    for (size_t i = from; i < text.size(); ++i) {
        if (!::isalpha(text[i])) {
            return i;
        }
    }
    return -1;
}


WordPosition Tokenizer::nextWordPosition() {
    int begin = getFirstAlphaIndex(position);
    int end = getFirstNonAlphaIndex(begin);
    if (end == -1) {
        end = text.size();
    }
    string word = text.substr(begin, end - begin);
    position = end;
    return WordPosition(word, begin);
}
