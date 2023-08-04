//
// Project 3 - Erik Companhone and Liam McKenna.
//

#include "string"

#ifndef BPTREE_GAMEDATA_H
#define BPTREE_GAMEDATA_H


class gameData
{
    int rating;
    std::string genre = "Action-Adventure";
    std::string name = "Shadow of the Colossus";

public:
    gameData(int rating);
    int getRating();
    void setRating(int score);
};


#endif //BPTREE_GAMEDATA_H
