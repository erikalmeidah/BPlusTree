//
// Project 3 - Erik Companhone and Liam McKenna.
//

#include "node.h"
#include "gameData.h"

#ifndef BPTREE_BPTREE_H
#define BPTREE_BPTREE_H


class bptree
{
    node* root;
    int maxDegree;

public:
    bptree(int deg);
    node* getRoot();
    int getDegree();
    void insert(gameData myGame);
    std::vector<gameData> getTop10(node* root);
};


#endif //BPTREE_BPTREE_H
