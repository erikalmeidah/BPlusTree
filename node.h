//
// Project 3 - Erik Companhone and Liam McKenna.
//

#include "gameData.h"
#include "vector"

#ifndef BPTREE_NODE_H
#define BPTREE_NODE_H


class node
{
    bool leaf;
    int* dataArray; //FIXME change to gameData later
    int size;
    int degree;
    node** child = nullptr;

public:
    node(int maxNodes);
    int getDegree();
    int simpleInsert(int rating);
    int internalInsert(int rating);

    friend class bptree; //No need for setters and getters.
};


#endif //BPTREE_NODE_H
