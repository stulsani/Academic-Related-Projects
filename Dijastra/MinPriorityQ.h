/*
AUTHOR - Sumeet Tulsani
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class MinPriorityQ
{
private:
    void buildminHeap();
    void minHeapify(int);
    int parent(int);
    int left(int);
    int right(int);
    class Element
    {
        public:
        string id;
        int key;
        Element();
        ~Element();
    };
public:
    MinPriorityQ();
    ~MinPriorityQ();
    int minHeap = 0;
    void inserting(string,int);
    void decreaseKey(string,int);
    string extractMin();
    vector<Element> forinsert;
};
