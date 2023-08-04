//
// Project 3 - Erik Companhone and Liam McKenna.
//

#include "node.h"
#include "vector"

node::node(int maxNodes)
{
    //This is the constructor for a node.
    degree = maxNodes + 1;
    dataArray = new int[maxNodes];
    child = new node*[degree];
    size = 0;
}

int node::getDegree()
{
    //This returns the degree of the node.
    return degree;
}

int node::simpleInsert(int rating)
{
    //This method inserts a game into the node's dataArray based on ascending rating order.
    int pos = 0;
    int maxNodes = degree - 1;

    //Get position to insert in.
    for(int i = 0; i < size; i++)
    {
        if(dataArray[i] < rating)
        {
            pos++;
        }
        else
        {
            break;
        }
    }

    //Shift array to make space for new rating.
    for(int i = maxNodes - 1; i > pos; i--)
    {
        dataArray[i] = dataArray[i - 1];
    }

    //Insert.
    this->dataArray[pos] = rating; //FIXME NOT INSERTING FOR SOME REASON
    size++;
    return pos;
}

int node::internalInsert(int rating) //FIXME not implemented yet
{
    //This method is used to recursively insert when internal nodes are full.
    return 0;
}
