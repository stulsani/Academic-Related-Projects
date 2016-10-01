/*
AUTHOR - Sumeet Tulsani
*/

#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include"MinPriorityQ.h"

using namespace std;

class Graph
{
private:
    string currentSource;
    void buildSSPTree(string);
    void relax(string,string,int);
     class Vertex
    {
        public:
        string pi;
        int key;
    };
     class Neighbor
    {
        public:
        string name;
        int weight;
    };
    vector<Neighbor> neighbor;
    vector <Neighbor> sorting;
    map<string,Vertex> vertices;
    map<string,vector<Neighbor> > adjList;

public:
    MinPriorityQ myQ;
    void addVertex(string);
    void addEdge(string,string,int);
    string getShortestPath(string,string);
};
