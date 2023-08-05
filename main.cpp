//
// Project 3 - Erik Companhone and Liam McKenna.
//

#include "bptree.h"
#include "iostream"

int main() {

    //Create tree
    bptree node(1001); //nodes have size deg - 1

    for(int i = 0; i < 100000; i++)
    {
        node.insert(gameData(i));
    }
    std::cout << "\nfinished inserting\n";
    //node.displayTree(node.getRoot());
    std::vector<gameData> top10 = node.getTop10(node.getRoot());
    std::cout << "\n";
    std::cout << "Top 10 game reccomendations based on your Steam profile: \n\n";
    int i = 1;
    for(auto member : top10)
    {
        std::cout << i << " - Name: " << member.getName() << " Genres: " << member.getGenre() << " Rating: " << member.getRating() << std::endl;
        i++;
    }

    //Create tree (TESTING INSERTS)
//    bptree node(4); //nodes have size deg - 1
//    //Insert into tree
//    node.insert(gameData(5)); //Normal insert.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(15)); //Normal insert.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(25)); //Normal insert.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(35)); //This triggers first full root split.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(45)); //Normal insert.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(55)); //This triggers split with parent not full.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(40)); //Normal insert.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(30)); //This triggers split with parent not full.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(20)); //Normal insert.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(27)); //Normal insert.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(29)); //This triggers internal node split.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(6)); //This triggers split with parent not full.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(7)); //Normal insert.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.insert(gameData(8)); //This triggers internal node split.
//    std::cout << std::endl;
//    node.displayTree(node.getRoot());
//    node.getTop10(node.getRoot());

    return 0;
}
