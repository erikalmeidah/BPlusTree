//
// Project 3 - Erik Companhone and Liam McKenna.
//

#include "string"

#ifndef BPTREE_GAMEDATA_H
#define BPTREE_GAMEDATA_H


class gameData
{
    int rating;
    std::string genre;
    std::string name;

public:
    gameData();
    gameData(int rating, std::string name, std::string genre);
    gameData(int rating);
    int getRating();
    std::string getName();
    std::string getGenre();
};


#endif //BPTREE_GAMEDATA_H
