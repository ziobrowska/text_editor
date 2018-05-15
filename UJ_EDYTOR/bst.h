#ifndef BST_H
#define BST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "positionlist.h"

using namespace std;

class BST {
    private:

    struct node {
        string key;
        PositionList positionList;
        node *left = NULL;
        node *right = NULL;
        node *parent = NULL;
    };
    node *root;

    node* stworzWezel(string key, int position) {
        node* n = new node;
        n -> key = key;
        n -> left = NULL;
        n -> right = NULL;
        n -> parent = NULL;
        n -> positionList.append(position);
        return n;
    }

    void insertPriv (string key, int position, node* Ptr) {
        if (root == NULL) {
            root = stworzWezel(key, position);
        }
        else if(key < Ptr -> key) {
            if ( Ptr -> left != NULL) {
                insertPriv (key, position, Ptr -> left);
            }
            else {
                node* n = new node;
                n -> key = key;
                n ->positionList.append(position);
                n -> left = NULL;
                n -> right = NULL;
                n -> parent = Ptr;
                Ptr -> left = n;
            }
        }
        else if(key > Ptr->key) {
            if (Ptr -> right != NULL) {
                insertPriv(key, position, Ptr->right);
            }
            else {
                node* n = new node;
                n -> key = key;
                n -> positionList.append(position);
                n -> left = NULL;
                n -> right = NULL;
                n -> parent = Ptr;
                Ptr -> right = n;
            }
        }
        else {
            Ptr->positionList.append(position);
        }
    }

    node* ReturnNodePrivate(string key, node* Ptr){
        if (Ptr != NULL) {
            if ( Ptr -> key == key) {
                return Ptr;
            } else {
                if (key<Ptr->key) return ReturnNodePrivate(key, Ptr->left);
                else return ReturnNodePrivate(key, Ptr->right);
            }
        } else return NULL;
    }

public:
    BST(){
        root = NULL;
    }

    void insert(string key, int position){
        insertPriv(key, position, root);
    }

    PositionListIterator getPositionIterator(string key) {
        if (root == NULL) {
            return PositionListIterator();
        }

        node * n = ReturnNodePrivate(key, root);

        if (n == NULL) {
            return PositionListIterator();
        }

        return PositionListIterator(n->positionList);
    }
};

#endif // BST_H
