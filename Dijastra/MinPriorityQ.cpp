/*
AUTHOR - Sumeet Tulsani
*/

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include"MinPriorityQ.h"

using namespace std;

/*
/////////////////////////////////////////////////////////////////////////////
Default type Constructor for minPriorityQ
/////////////////////////////////////////////////////////////////////////////
*/

MinPriorityQ::MinPriorityQ()
{

}

/*
/////////////////////////////////////////////////////////////////////////////
Default type destructor for minPriorityQ
/////////////////////////////////////////////////////////////////////////////
*/

MinPriorityQ::~MinPriorityQ()
{

}

/*
/////////////////////////////////////////////////////////////////////////////
Default type Constructor for inner class element
/////////////////////////////////////////////////////////////////////////////
*/

MinPriorityQ::Element::Element()
{

}

/*
/////////////////////////////////////////////////////////////////////////////
Default type destructor for inner class element
/////////////////////////////////////////////////////////////////////////////
*/

MinPriorityQ::Element::~Element()
{

}

/*
/////////////////////////////////////////////////////////////////////////////
This function is used to insert the id and key in the element field.
decrease key is called from this function which sets the key
/////////////////////////////////////////////////////////////////////////////
*/

void MinPriorityQ::inserting(string id,int key)
{
    Element obj;
    obj.id = id;
    obj.key = key;
    forinsert.push_back(obj);
    minHeap = minHeap + 1;
    forinsert[minHeap - 1].key = 100;
    decreaseKey(id,key);
}

/*
/////////////////////////////////////////////////////////////////////////////
This function is used to decrease the key in the element field if
there is a match found in vector of same id
/////////////////////////////////////////////////////////////////////////////
*/

void MinPriorityQ::decreaseKey(string id,int key)
{
   for(unsigned int i = 0;i < forinsert.size();i++)
    {
        string id1 = forinsert[i].id;
        int key1 = forinsert[i].key;
        if(id1 == id)
        {
            if(key1 < key)
            {

            }
            else
            {
                forinsert[i].key = key;
                int j = i;
                while(j > 0 && forinsert[parent(j)].key > forinsert[j].key)
                {
                    swap(forinsert[j],forinsert[parent(j)]);
                    j = parent(j);
                }
            }
        }
    }
}

/*
/////////////////////////////////////////////////////////////////////////////
This function is used to extract the minimum key id from the tree we
have build. The minimum key id is found at the top of the tree, that
is at the 0th position of the vector
/////////////////////////////////////////////////////////////////////////////
*/

string MinPriorityQ::extractMin()
{
    string min;
    if(minHeap < 1)
    {

    }
    else
    {
        min = forinsert[0].id;
        forinsert[0].id = forinsert[minHeap - 1].id;
        forinsert[0].key = forinsert[minHeap - 1].key;
        forinsert.erase(forinsert.end());
        minHeap = minHeap - 1;
        minHeapify(0);
    }
    return min;
}

/*
/////////////////////////////////////////////////////////////////////////////
This function is used by extractmin function to create a tree with
minimum value at the top. This function uses the parent, left and right
functions to adjust the tree
/////////////////////////////////////////////////////////////////////////////
*/

void MinPriorityQ::minHeapify(int i)
{
    int smallest;
    int l = left(i);
    int r = right(i);
    if(l < minHeap && forinsert[l].key < forinsert[i].key)
    {
        smallest = l;
    }
    else
    {
        smallest = i;
    }
   if(r < minHeap && forinsert[r].key < forinsert[smallest].key)
    {
        smallest = r;
    }
    if(smallest != i)
    {
        swap(forinsert[i],forinsert[smallest]);
        minHeapify(smallest);
    }
}

/*
/////////////////////////////////////////////////////////////////////////////
This function returns the parent of any particular node
/////////////////////////////////////////////////////////////////////////////
*/

int MinPriorityQ::parent(int i)
{
    return i/2;
}

/*
/////////////////////////////////////////////////////////////////////////////
This function returns the left child of any particular node
/////////////////////////////////////////////////////////////////////////////
*/

int MinPriorityQ::left(int i)
{
    return 2*i;
}

/*
/////////////////////////////////////////////////////////////////////////////
This function returns the right child of any particular node
/////////////////////////////////////////////////////////////////////////////
*/

int MinPriorityQ::right(int i)
{
    return 2*i + 1;
}

void MinPriorityQ::buildminHeap()
{
    for(int i = minHeap/2;i > 0;i--)
    {
        minHeapify(i);
    }
}
