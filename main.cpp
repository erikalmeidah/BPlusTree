//
// Project 3 - Erik Companhone and Liam McKenna.
//

#include "bptree.h"
#include "iostream"

int main() {

    //Create tree
    bptree node(4); //nodes have size deg - 1

    //Insert into tree
    node.insert(gameData(5)); //Normal insert.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(15)); //Normal insert.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(25)); //Normal insert.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(35)); //This triggers first full root split.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(45)); //Normal insert.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(55)); //This triggers split with parent not full.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(40)); //Normal insert.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(30)); //This triggers split with parent not full.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(20)); //Normal insert.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(27)); //Normal insert.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(29)); //This triggers internal node split.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(6)); //This triggers split with parent not full.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(7)); //Normal insert.
    std::cout << std::endl;
    node.display(node.getRoot());
    node.insert(gameData(8)); //This triggers internal node split.
    std::cout << std::endl;
    node.display(node.getRoot());

    return 0;
}
