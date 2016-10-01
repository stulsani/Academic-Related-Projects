/*
AUTHOR - Sumeet Tulsani
*/

#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

#include"graph.h"

using namespace std;

/*
/////////////////////////////////////////////////////////////////////////////
IN: This function takes string vertex as input
DESC: The string received from command line is added into the map vertices
      in this function
OUT: NA
/////////////////////////////////////////////////////////////////////////////
*/

 void Graph::addVertex(string ch)
 {
    Vertex v;
    v.pi = "nil";
    v.key = 100;
    map<string,Vertex>::iterator it;
    vertices.insert(pair<string,Vertex>(ch,v));
 }

/*
/////////////////////////////////////////////////////////////////////////////
IN: This function takes string vertex to,from and weight as input
DESC: The to string received from command line is added into the map
      string field, and to and to and weight is pushed back in vector
      Neighbor, which is then added into the map
OUT: NA
/////////////////////////////////////////////////////////////////////////////
*/

void Graph::addEdge(string v1,string v2,int e)
{
    Neighbor n;
    Neighbor display;
    n.name = v2;
    n.weight = e;
    map<string,vector <Neighbor>>::iterator it;
         it = adjList.find(v1);
         if(it != adjList.end())
         {
             it-> second.push_back(n);
         }
         else
         {
             neighbor.push_back(n);
             adjList.insert(std::pair<string,vector<Neighbor> >(v1,neighbor));
             neighbor.clear();
         }
    vector<Neighbor> coping;
    vector<Neighbor>:: iterator iter;
    vector<string> sorting;
    vector<string>:: iterator it1;
    if(!adjList.empty())
    {
        for(it = adjList.begin(); it != adjList.end(); it++)
        {
            for(iter = it-> second.begin();iter != it-> second.end();iter++)
            {
                display = *iter;
                sorting.push_back(display.name);
                sort(sorting.begin(),sorting.end());
            }
            for(unsigned int i = 0; i < sorting.size();i++)
            {
                string d = sorting[i];
            for(iter = it-> second.begin();iter != it-> second.end();iter++)
                {
                    Neighbor dis = *iter;
                    if(dis.name == d)
                    {
                        coping.push_back(dis);
                    }
                }
            }
            int i = 0;
            for(iter = it-> second.begin();iter != it-> second.end();iter++)
            {
                *iter = coping[i];
                i++;
            }
           sorting.clear();
           coping.clear();
        }
    }
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: This function takes string to and from as input
DESC: This function is used to find find shortest path between two nodes
      which is done by calling buildSSPtree function. This function also
      displays the path returned from the buildSSPtree function
OUT: This function returns the to string
/////////////////////////////////////////////////////////////////////////////
*/

string Graph::getShortestPath(string st,string en)
{
    if(currentSource == st)
    {
        string display1;
        vector<string> d;
        map<string,Vertex>::iterator it;
        map<string,Vertex>::iterator it1;
        it = vertices.find(en);
        string display = it-> second.pi;
        cout << st << "->";
        while(display != st)
        {
            d.push_back(display);
            it1 = vertices.find(display);
            display1 = it1-> second.pi;
            display = display1;
        }
        for(int i = d.size()-1;i >= 0;i--)
        {
            string dd = d[i];
            cout << dd << "->";
        }
        int wt = it-> second.key;
        cout << en << " with length " << wt << endl;
        d.clear();
    }
    else
    {
        currentSource = st;
        buildSSPTree(st);
        string display1;
        vector<string> d;
        map<string,Vertex>::iterator it;
        map<string,Vertex>::iterator it1;
        it = vertices.find(en);
        string display = it-> second.pi;
        cout << st << "->";
        while(display != st)
        {
            d.push_back(display);
            it1 = vertices.find(display);
            display1 = it1-> second.pi;
            display = display1;
        }
        for(int i = d.size()-1;i >= 0;i--)
        {
            string dd = d[i];
            cout << dd << "->";
        }
        int wt = it-> second.key;
        cout << en << " with length " << wt << endl;
    }
    return en;
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: This function takes string vertex as input
DESC: This function is used to build the shortest path graph, it uses
      relax function and minPriority Q to build the shortest path tree.
      Initially vertex are passed into priority Q with parent = nil and
      weight = 100 for all vertices expect the source vertex, for which
      parent = nil and weight = 0
OUT: NA
/////////////////////////////////////////////////////////////////////////////
*/

void Graph::buildSSPTree(string vertex)
{
    Neighbor display;
    map<string,Vertex>::iterator it;
    map<string,vector <Neighbor>>::iterator it1;
    vector<Neighbor>::iterator iter;
    for(it = vertices.begin(); it != vertices.end(); it++)
    {
        if(it-> first == vertex)
        {
            it-> second.pi = "nil";
            it-> second.key = 0;
            myQ.inserting(it-> first,it-> second.key);
        }
        else
        {
            it-> second.pi = "nil";
            it-> second.key = 100;
            myQ.inserting(it-> first,it-> second.key);
        }
    }
    while(!myQ.forinsert.empty())
    {
        string u = myQ.extractMin();
        for(it1 = adjList.begin(); it1 != adjList.end(); it1++)
        {
            if(it1-> first == u)
            {
            for(iter = it1-> second.begin();iter != it1-> second.end();iter++)
                {
                    display = *iter;
                    relax(u,display.name,display.weight);
                }
            }
        }
    }
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: This function takes string vertex from, to and weight
    between those two vertex as input
DESC: It checks if v.key < u.key, if yes it changes its key
OUT: NA
/////////////////////////////////////////////////////////////////////////////
*/

void Graph::relax(string u,string v,int w)
{
    map<string,Vertex>::iterator it;
    map<string,Vertex>::iterator it1;
    it = vertices.find(u);
    it1 = vertices.find(v);
    if((it1-> second.key) > (it-> second.key + w))
    {
        it1-> second.key = it-> second.key + w;
        it1-> second.pi = u;
        myQ.decreaseKey(v,it1-> second.key);
    }
}
