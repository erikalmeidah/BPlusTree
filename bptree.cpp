//
// Project 3 - Erik Companhone and Liam McKenna.
//

#include "bptree.h"
#include <algorithm>

bptree::bptree(int deg)
{
    //This is the tree constructor.
    root = nullptr;
    maxDegree = deg;
}

node *bptree::getRoot()
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
    int rating = myGame.getRating(); //FIXME tree is currently only inserting the game rating

    //Base case: root is empty.
    if(root == nullptr)
    {
        root = new node(maxNodes);
        root->leaf = true;
        root->size = 1;
        root->dataArray[0] = rating;
    }
    //Root is not empty.
    else
    {
        //Go to the correct leaf node.
        node* currentNode = root;
        node* parentNode = nullptr;
        while (!currentNode->leaf)
        {
            parentNode = currentNode;
            for(int i = 0; i < currentNode->size; i++)
            {
                //Check left child.
                if(rating < currentNode->dataArray[i])
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
            currentNode->dataArray[1] = 15;
            //currentNode->simpleInsert(rating); //FIXME
        }
        //Case 2: Leaf is full, insert and split.
        else
        {
            //Temp insert.
            int tempData[maxNodes + 1];
            int midPos = maxNodes/2, midValue;

            //Populate temp array.
            for(int i = 0 ; i < maxNodes; i++)
            {
                tempData[i] = currentNode->dataArray[i];
                if(i == midPos)
                {
                    midValue = currentNode->dataArray[i];
                }
            }

            //Get position to insert in.
            int tempPos = 0;
            for(int i = 0; i < maxNodes; i++)
            {
                if(tempData[i] < rating)
                {
                    tempPos++;
                    continue;
                }
                else
                {
                    break;
                }
            }

            //Shift array to make space for new rating.
            for(int i = tempPos + 1; i < maxNodes; i++)
            {
                tempData[i] = tempData[i - 1];
            }

            //Insert.
            tempData[tempPos] = rating;

            //Split.
            node* newLeftLeaf = new node(maxNodes);
            node* newRightLeaf = new node(maxNodes);
            for(int i = 0; i < maxNodes/2; i++)
            {
                newLeftLeaf->dataArray[i] = tempData[i];
                newLeftLeaf->size++;
            }
            for(int i = maxNodes/2; i < maxNodes + 1; i++)
            {
                newRightLeaf->dataArray[i] = tempData[i];
                newRightLeaf->size++;
            }
            newLeftLeaf->leaf = true;
            newRightLeaf->leaf = true;

            //Add to parent.
            //Case 1: parent is not full, add and update pointers.
            if(parentNode->size < maxNodes)
            {
                //Add to parent
                int pos = parentNode->simpleInsert(midValue);

                //Update pointers FIXME does this make sense?
                parentNode->child[pos - 1] = newLeftLeaf;
                parentNode->child[pos] = newRightLeaf;
                newLeftLeaf->child[newLeftLeaf->size - 1] = newRightLeaf;
            }
            //Case 2: parent is full, insert and split parent recursively until parent is not full or reached root node.
            else
            {
                //FIXME CALL RECURSIVE METHOD HERE
                //Base case: parent is root.
                if(parentNode == root)
                {
                    //Temp insert.
                    int rootTempData[maxNodes + 1];
                    int rootMidPos = maxNodes/2, rootMidValue;
                    for(int i = 0 ; i < maxNodes; i++)
                    {
                        rootTempData[i] = parentNode->dataArray[i];
                        if(i == rootMidPos)
                        {
                            rootMidValue = parentNode->dataArray[i];
                        }
                    }

                    //Get position to insert in.
                    int tempRootPos = 0;
                    for(int i = 0; i < maxNodes; i++)
                    {
                        if(rootTempData[i] < midValue)
                        {
                            tempRootPos++;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }

                    //Shift array to make space for new rating.
                    for(int i = tempRootPos + 1; i < maxNodes; i++)
                    {
                        rootTempData[i] = rootTempData[i - 1];
                    }

                    //Insert.
                    rootTempData[tempRootPos] = midValue;

                    //Split root.
                    node* newRoot = new node(maxNodes);
                    int rootPos = newRoot->simpleInsert(rootMidValue);
                    node* newRootLeftInternalNode = new node(maxNodes);
                    node* newRootRightInternalNode = new node(maxNodes);
                    for(int i = 0; i < maxNodes/2; i++)
                    {
                        newRootLeftInternalNode->dataArray[i] = rootTempData[i];
                        newRootLeftInternalNode->size++;
                    }
                    for(int i = maxNodes/2; i < maxNodes + 1; i++)
                    {
                        newRootRightInternalNode->dataArray[i] = rootTempData[i];
                        newRootRightInternalNode->size++;
                    }
                    newRootLeftInternalNode->leaf = false;
                    newRootRightInternalNode->leaf = false;

                    //Reorganize pointers.
                    newRoot->child[rootPos - 1] = newRootLeftInternalNode; //FIXME AND VERSION ABOVE, WHAT IF POS IS 0
                    newRoot->child[rootPos] = newRootRightInternalNode;
                    newRoot->size = 1;
                    newRoot->leaf = false;
                    root = newRoot;
                }
                //Case 2: parent is internal node.
                else
                {
                    //recursive call here.
                    currentNode->internalInsert(0);
                    node* newParent = new node(maxNodes);
                    newParent->simpleInsert(midValue);
                }
            }
        }
    }
}
