/*
NAME: Sumeet Tulsani
Project Name: Library Project
*/

#include<iostream>
#include <string>
#include<cstdlib>
#include<vector>
#include "searchengine.h"


using namespace std;

int main()
{
    string searchby,searchthis;
    Searchengine obj;
    char choice;
    vector<Media*> matches;  //to store returned result
    do
    {
    cout << "What type of search would you like to do::" << endl;
    cout << "1. Search by Title" << endl << "2. Search by Call Number" << endl <<
    "3. Search by Subject" << endl << "4. Search by Other" << endl << "5.Exit" << endl;
    cin >> searchby;
    if(searchby >= "1" && searchby <= "4")
    {
        cout << "Enter the string you would like to search" << endl;
        cin >> searchthis;
    }
    if(searchby == "1")
    {
        matches = obj.search_by_title(searchthis);
        for(int i=0; i<matches.size(); ++i)
        {
            Media* mp;
            mp=matches[i];
            mp->display();
        }
        int total = matches.size();
        cout << "--------TOTAL SEARCHES-------" << endl;
        cout << "Total number of searches:" << total << endl;
    }
    else if(searchby == "2")
    {
        matches = obj.search_by_call_number(searchthis);
        for(int i=0; i<matches.size(); ++i)
        {
            Media* mp;
            mp=matches[i];
            mp->display();
        }
        int total = matches.size();
        cout << "--------TOTAL SEARCHES-------" << endl;
        cout << "Total number of searches:" << total << endl;
    }
    else if(searchby == "3")
    {
        matches = obj.search_by_subjects(searchthis);
        for(int i=0; i<matches.size(); ++i)
        {
            Media* mp;
            mp=matches[i];
            mp->display();
        }
        int total = matches.size();
        cout << "--------TOTAL SEARCHES-------" << endl;
        cout << "Total number of searches:" << total << endl;
    }
    else if(searchby == "4")
    {
        matches = obj.search_by_other(searchthis);
        for(int i=0; i<matches.size(); ++i)
        {
            Media* mp;
            mp=matches[i];
            mp->display();
        }
        int total = matches.size();
        cout << "--------TOTAL SEARCHES-------" << endl;
        cout << "Total number of searches:" << total << endl;
    }
    else if(searchby == "5")
    {
        return(0);
    }
    else
    {
        cout << "Invalid Choice!!!!" << endl;
    }
    cout << "Do you wish to make another search(Y/N)??" << endl;
    cin >> choice;
    cout << "\033[2J\033[1;1H";   //to clear the screen
    }while(choice == 'y' || choice == 'Y');
return 0;
}
