//
// Project 3 - Erik Companhone and Liam McKenna.
//

#include "bptree.h"
#include "iostream"
#include "vector"

bptree::bptree(int deg)
{
    //This is the tree constructor.
    root = nullptr;
    maxDegree = deg;
}

node* bptree::getRoot()
{
    //This method returns the root of the tree.
    return root;
}

int bptree::getDegree()
{
    //This method returns the degree of the tree.
    return maxDegree;
}

void bptree::insert(gameData myGame)
{
    //This method inserts data on the tree, balancing it if necessary.
    int maxNodes = maxDegree - 1;
    int rating = myGame.getRating();

    //Base case: root is empty.
    if(root == nullptr)
    {
        root = new node(maxNodes);
        root->leaf = true;
        root->size = 1;
        root->dataArray[0] = myGame;
    }
    //Root is not empty.
    else
    {
        //Go to the correct leaf node.
        node* currentNode = root;
        node* parentNode = nullptr;
        std::vector<node*> parentVector;
        while (!currentNode->leaf)
        {
            parentNode = currentNode;
            parentVector.push_back(parentNode);
            for(int i = 0; i < currentNode->size; i++)
            {
                //Check left child.
                if(rating < currentNode->dataArray[i].getRating())
                {
                    currentNode = currentNode->child[i];
                    break;
                }
                //Check right child at end of children array.
                else if(i == currentNode->size - 1)
                {
                    currentNode = currentNode->child[i + 1];
                    break;
                }
            }
        }

        //Insert into leaf node.
        //Case 1: Leaf is not full, insert.
        if(currentNode->size < maxNodes)
        {
            currentNode->simpleInsert(myGame);
        }
        //Case 2: Leaf is full, insert and split.
        else
        {
            //Temp insert.
            gameData tempData[maxNodes + 1];
            int midPos = maxNodes/2;
            gameData midValue;

            //Populate temp array.
            for(int i = 0 ; i < maxNodes; i++)
            {
                tempData[i] = currentNode->dataArray[i];
            }

            //Get position to insert in.
            int tempPos = 0;
            for(int i = 0; i < maxNodes; i++)
            {
                if(tempData[i].getRating() < rating)
                {
                    tempPos++;
                }
                else
                {
                    break;
                }
            }

            //Shift array to make space for new rating.
            for(int i = maxNodes; i > tempPos; i--)
            {
                tempData[i] = tempData[i - 1];
            }

            //Insert in temp array.
            tempData[tempPos] = myGame;
            midValue = tempData[maxDegree/2];

            //Split.
            node* newLeftLeaf = new node(maxNodes);
            node* newRightLeaf = new node(maxNodes);
            for(int i = 0; i < maxDegree/2; i++)
            {
                newLeftLeaf->dataArray[i] = tempData[i];
                newLeftLeaf->size++;
            }
            int j = 0;
            for(int i = maxDegree/2; i < maxDegree; i++)
            {
                newRightLeaf->dataArray[j] = tempData[i];
                newRightLeaf->size++;
                j++;
            }
            newLeftLeaf->leaf = true;
            newRightLeaf->leaf = true;

            //Add to parent.
            //Base case: current node is full root.
            if(currentNode == root)
            {
                //Create new root.
                node* newRoot = new node(maxNodes);
                int pos = newRoot->simpleInsert(midValue);
                newRoot->size = 1;
                newRoot->leaf =false;
                //Update pointers.
                newRoot->child[0] = newLeftLeaf;
                newRoot->child[1] = newRightLeaf;
                newLeftLeaf->child[newLeftLeaf->size - 1] = newRightLeaf;
                root = newRoot;
            }
            //Case 1: parent is not full, add and update pointers.
            else if(parentNode->size < maxNodes)
            {
                //Add to parent.
                int pos = parentNode->simpleInsert(midValue);
                //Update pointers.
                parentNode->child[pos] = newLeftLeaf;
                //Check for right leaf.
                if(parentNode->child[pos + 1] == nullptr)
                {
                    parentNode->child[pos + 1] = newRightLeaf;
                }
                //There is a leaf at the right of pos.
                else
                {
                    //shift child pointers to insert correctly
                    for(int i = parentNode->size; i > pos; i--)
                    {
                        parentNode->child[i + 1] = parentNode->child[i];
                    }
                    parentNode->child[pos + 1] = newRightLeaf;
                    newRightLeaf->child[newRightLeaf->size] = parentNode->child[pos + 2];
                }
                newLeftLeaf->child[newLeftLeaf->size - 1] = newRightLeaf;
            }
            //Case 2: parent is full, insert and split parent recursively until parent is not full or reached root node.
            else
            {
                parentVector.pop_back();
                root = currentNode->internalInsert(root, parentNode, newLeftLeaf, newRightLeaf, myGame, midValue, parentVector);
            }
        }
    }
}
