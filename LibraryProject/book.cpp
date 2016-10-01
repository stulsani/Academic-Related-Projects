#include<iostream>
#include<string>
#include<vector>
#include "boost/algorithm/string.hpp"
#include"book.h"

using namespace std;
using namespace boost;

Book::Book(const string& call_number,const string& title,const string& subjects,const string& author,
           const string&description,const string& publisher,const string& city,const string& year,
           const string& series,const string& notes):Media(call_number,title,subjects,notes),
           author(author),description(description),publisher(publisher),city(city),year(year),series(series)
{

}

void Book::display() const
{
    cout << "-----------BOOK----------" << endl;
    cout << "CALL NUMBER::" << call_number << endl << "TITLE::" << title << endl << "SUBJECTS::"
     << subjects << endl << "AUTHOR::"
    << author << endl << "DESCRIPTION::" << description << endl <<
     "PUBLISHER::" << publisher << endl <<  "CITY::" << city << endl << "YEAR::" << year << endl <<  "SERIES::"
     << series << endl << "NOTES::" << notes << endl;
}

bool Book::compare_other(const string& searchby) const
{
    size_t found = description.find(searchby);
    size_t found1 = notes.find(searchby);
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
