//
// Project 3 - Erik Companhone and Liam McKenna.
//

#include "gameData.h"

int gameData::getRating()
{
    return rating;
}

void gameData::setRating(int score)
{
    rating = score;
}

gameData::gameData(int rating)
{
    this->rating = rating;
}
