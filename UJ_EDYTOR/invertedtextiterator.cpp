// Joanna Ziobrowska

#include "classinvertedtextiterator.h"
#include "tokenizer.h"
#include "bst.h"

int InvertedTextIterator::getNext(const std::string & text, const std::string & term, int start_pos) {
    BST tree;
    Tokenizer tokenizer(text);

    // wszystkie slowa z tekstu wkladamy do drzewa
    while (tokenizer.hasNext()) {
        WordPosition wordPosition = tokenizer.nextWordPosition();
        tree.insert(wordPosition.getWord(), wordPosition.getPosition());
    }

    // wyszukiwanie
    PositionListIterator iterator = tree.getPositionIterator(term);
    while (iterator.hasNext()) {
        if (iterator.getValue() >= start_pos) {
            return iterator.getValue() + 1;
        }
        iterator.next();
    }

    return -1;
}
