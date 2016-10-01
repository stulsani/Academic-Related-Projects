/*
AUTHOR - Sumeet Tulsani
*/

#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include"sspapp.h"

using namespace std;

/*
/////////////////////////////////////////////////////////////////////////////
This is the entry point for the program
/////////////////////////////////////////////////////////////////////////////
*/

int main()
{
    SSPapp obj;
    obj.processQueries();
    return 0;
}

/*
/////////////////////////////////////////////////////////////////////////////
This function is used to process the input from command line.
/////////////////////////////////////////////////////////////////////////////
*/

void SSPapp::processQueries()
{
    string s,line,v1,v2,st,en,ch;
    int num,e,num1 = 0,no1 = 0,no;
    getline(cin,s);
    istringstream iss(s);
    iss >> num;
    //run until n number of vertex are in inputed
    while(num1 < num)
    {
       getline(cin,line);
       istringstream iss1(line);
        while(iss1 >> ch)
        {
            callgraph.addVertex(ch);
            num1++;
        }
    }
    getline(cin,s);
    istringstream iss2(s);
    iss2 >> no;
    while(no1 < no)
    {
       getline(cin,line);
       istringstream iss3(line);
       iss3 >> v1;
       iss3 >> v2;
       iss3 >> e;
       callgraph.addEdge(v1,v2,e);
       no1++;
    }
    //read to to from
    while(getline(cin,line))
    {
        istringstream iss4(line);
        iss4 >> st;
        iss4 >> en;
        callgraph.getShortestPath(st,en);
    }
}
