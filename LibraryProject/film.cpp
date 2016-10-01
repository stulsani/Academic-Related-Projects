#include"film.h"
#include<iostream>
#include<string>
#include<vector>
#include "boost/algorithm/string.hpp"


using namespace std;
using namespace boost;

Film::Film(const string& call_number,const string& title,const string& subjects,
           const string& director,const string& notes,const string& year):
           Media(call_number,title,subjects,notes),director(director),year(year)
{

}

void Film::display() const
{
    cout << "-----------FILM----------" << endl;
    cout << "CALL NUMBER::" << call_number << endl << "TITLE::" << title << endl << "SUBJECTS::"
     << subjects << endl << "DIRECTOR::" << director << endl << "NOTES::" <<notes << endl <<
      "YEAR::" << year << endl;
}

bool Film::compare_other(const string& searchby) const
{
    size_t found = notes.find(searchby);
    size_t found1 = director.find(searchby);
    size_t found2 = year.find(searchby);
    if((found!=string::npos) || (found1!=string::npos) || (found2!=string::npos))
    {
        return true;
    }
    else
    {
        return false;
    }
}

