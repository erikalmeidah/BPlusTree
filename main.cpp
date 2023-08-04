//
// Project 3 - Erik Companhone and Liam McKenna.
//

#include "bptree.h"

int main() {

    //Create tree
    bptree node(4); //nodes have size deg - 1

    //Insert into tree
    node.insert(gameData(5));
    node.insert(gameData(15));
    node.insert(gameData(25));
    //node.insert(gameData(35));
    //node.insert(gameData(45));
    //node.insert(gameData(55));
    //node.insert(gameData(40));
    //node.insert(gameData(30));
    //node.insert(gameData(20));
    //node.insert(gameData(27));
    //node.insert(gameData(29)); //This triggers internal node split

    //Display tree
    //FIXME

    return 0;
}