/*
Author: Sumeet Tulsani
*/
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"hash.h"

using namespace std;

Hash::Hash()
{

}

double currentAvgListLen = 0,count1=0,count2=0;

/*
/////////////////////////////////////////////////////////////////////////
Description: processFile function takes input from a file i.e. reads the
             the file (declared as test1) and prints the file in a hash
             table format
In: reads File(Test)
Out: Prints file contains in table format
/////////////////////////////////////////////////////////////////////////
*/

void Hash::processFile(string test)
{
    avgLength = 0;
    ifstream myFile;   //file to open file passed from main.cpp
    string word,line;
    vector<int> findingmax;//vector to store size for calculating long length
    collisions = 0;  //initialize collisions to 0
    longestList = 0;  //initialize longest length to 0
    istringstream iss; //to break line
    int index,longest;
    if(!myFile)
    {

    }
    else
    {
    myFile.open(test);
    {
    while(getline(myFile, line)) //till there is line to read from file
    {
        istringstream iss(line);
        iss >> word;
        index = hf(word);
        hashTable[index].push_back(word);
        if(hashTable[index].size() > 0)
        {
            count1++;
        }
        if(hashTable[index].size() > 0 && hashTable[index].size() < 2)
        {
            count2++;
        }
        currentAvgListLen = count1/count2;
        avgLength = (currentAvgListLen + avgLength)/2.0;
        if(hashTable[index].size() > 1)
        {
            collisions++;
        }
        //list to store size of particular index in hash table
        findingmax.push_back(hashTable[index].size());
    }
    longest = 0;
        for(unsigned int i = 0;i < findingmax.size();i++)
        {
            if(findingmax[i] > longest)//to find longest list
            {
                longest = findingmax[i];
            }

        }
        longestList = longest;
    }
    }
}

/*
//////////////////////////////////////////////////////////////////
Description: This function is used to find the desired string from
             the hash table,if the string is fount it returns true
             or else it returns false
In: It takes key that needs to be found
Out: It returns either true or false as bool function is used
//////////////////////////////////////////////////////////////////
*/

bool Hash::search(string word)
{
    int index;   //to find index in hashing table
    bool find = false;
    index = hf(word);
    list<string>::iterator it = hashTable[index].begin();
    while(it != hashTable[index].end())
    {
        if(*it == word)
        {
            find = true;
            break;
        }
        it++;
    }
    return find;  //returns true if element is found in the list
}

/*
/////////////////////////////////////////////////////////////////////
Description: Prints the empty hash table
In: NA
Out: NA
////////////////////////////////////////////////////////////////////
*/

 void Hash::print()
 {
    //traverse the hash table from index 0 to n
    for(int i = 0;i < HASH_TABLE_SIZE; i++)
    {
        cout << i << ":" << "\t";
        list<string>::iterator it = hashTable[i].begin();
        while(it != hashTable[i].end())
        {
            cout << *it << "," << " ";
            it++;
        }
        cout << endl;
    }
 }

/*
///////////////////////////////////////////////////////////////
Description: This function is used to remove a particular
             function from the hash table
In: The key which is the element to be removed is send from
    main.cpp
Out: NA
//////////////////////////////////////////////////////////////
*/

 void Hash::remove(string word)
 {
     int index;
     bool found = false;  //first found is set to false
     index = hf(word);
     found = search(word);
     hashTable[index].remove(word);
     if(found == true)
     {
        count1--;
     }
     if(hashTable[index].empty())
     {
         count2--;
     }
    // will enter this loop if actual remove was made
     if(found == true || hashTable[index].empty())
     {
        currentAvgListLen = count1/count2;
        avgLength = (currentAvgListLen + avgLength)/2.0;
     }
 }

/*
/////////////////////////////////////////////////////////////////////////////
Description: this function prints the hash table in file created named
output
In: NA
Out: NA
/////////////////////////////////////////////////////////////////////////////
*/

 void Hash::output(string word)
 {
     ofstream filename;  //to copy table in outfile
     filename.open(word);
     //to traverse the hash table indexes
     for(int i = 0;i < HASH_TABLE_SIZE; i++)
    {
        filename << i << ":" << "\t";
        list<string>::iterator it = hashTable[i].begin();
        // print till entire list is not over
        while(it != hashTable[i].end())
        {
            filename << *it << "," << " ";
            it++;
        }
        filename << endl;
    }
    filename.close();
 }

/*
/////////////////////////////////////////////////////////////////////////
Description: This function is used to print stats of number of collisions
              and print the longest list in the hash table and print the
              average list length
In: It gets collisions,longest length,average length from other functions
Out: Displays the stats
/////////////////////////////////////////////////////////////////////////
*/

 void Hash::printStats()
 {
     cout << "Total Collisions = " << collisions << endl;
     cout << "Longest List Ever = " << longestList << endl;
     cout << "Average List Length Over Time = " << avgLength << endl;
     double loadfactor = 0;  //make loadfactor equal to 0
     loadfactor = count1/HASH_TABLE_SIZE;  //calculating load factor
     cout << "Load Factor = " << loadfactor << endl;
 }
