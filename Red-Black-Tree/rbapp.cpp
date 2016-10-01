/*
Author - Sumeet Tulsani
*/
#include <iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
#include<sstream>
#include<cstdlib>
#include"rbapp.h"
#include"rbtree.h"

using namespace std;

RBapp::RBapp()
{

}

int main()
{
    RBapp app;
    app.mainLoop();
    return 0;
}

void RBapp::mainLoop()
{
    while (!cin.eof() && !done)
    processCommand();
}

/*
/////////////////////////////////////////////////////////////////////////////
Processcommand to process the input from standard input output
/////////////////////////////////////////////////////////////////////////////
*/

void RBapp::processCommand()
{
     string s,line,str1;
    //while(getline(cin,s))   //get line from std:cin
    //{
        getline(cin,s);
        string command,key,value;
        command = s.substr(0,s.find(" "));//to find first space in i/p string
         if(command == "insert")
        {
            size_t pos = s.find(" ")+1;
            line = s.substr(pos);
            key = line.substr(0,line.find(" "));//key obtained
            pos = line.find(" ")+1;
            value = line.substr(pos);//value obtained
            str1 = key + " " + value;
            processInsert(str1);
        }
        else if(command == "print")
        {
            processPrint();
        }
        else if(command == "find")
        {
            size_t pos = s.find(" ")+1;
            line = s.substr(pos);
            key = line.substr(0,line.find(" ")); //key obtained
            processFind(key);
        }
        else if(command == "delete")
        {
            size_t pos = s.find(" ")+1;
            line = s.substr(pos);
            key = line.substr(0,line.find(" ")); //key obtained
            pos = line.find(" ")+1;
            value = line.substr(pos); //value string obtained
            str1 = key + " " + value;
            processDelete(str1);
        }
        else if(command == "quit")
        {
            processQuit();
        }
    //}
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Takes string as input
DESC: If command is equal to input this function is called,it breaks the
      input string into key and value and sends it to rbinsert function
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/

void RBapp::processInsert(string& str1)
{
    string key,value;
    key = str1.substr(0,str1.find(" "));//to find first space in i/p string
    size_t pos = str1.find(" ")+1;
    value = str1.substr(pos); //value string obtained
    myRBT.rbInsert(key, value);
}

/*
For printing the tree
*/

void RBapp::processPrint()
{
    myRBT.rbPrintTree();
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Takes string as input
DESC: If command is equal to input this function is called,it breaks the
      input string into key and sends it to rbfind function
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/

void RBapp::processFind(string& key)
{
    string key1,value;
    vector<const string*> found1;
    found1 = myRBT.rbFind(key);
    //to print found elements
    for(unsigned int i = 0;i < found1.size();i++)
    {
        value = *found1[i];
        key1 = key + " " + value;
        cout << key1 << endl;
    }
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Takes string as input
DESC: If command is equal to input this function is called,it breaks the
      input string into key and value and sends it to rbdelete function
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/

void RBapp::processDelete(string& str1)
{
    string key,value;
    key = str1.substr(0,str1.find(" "));//to find first space in i/p string
    size_t pos = str1.find(" ")+1; //string key obtained
    value = str1.substr(pos); //string value obtained
    myRBT.rbDelete(key,value);
}

void RBapp::processQuit()
{
    done = true;
}
