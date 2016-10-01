#include"video.h"
#include<iostream>
#include<string>
#include<vector>
#include "boost/algorithm/string.hpp"


using namespace std;
using namespace boost;

Video::Video(const string& call_number,const string& title,const string& subjects,
             const string& description,const string& distributor,const string& notes,
             const string& series,const string& label):Media(call_number,title,subjects,notes),
           description(description),distributor(distributor),series(series),label(label)
{

}

void Video::display() const
{
    cout << "-----------VIDEO----------" << endl;
    cout << "CALL NUMBER::" << call_number << endl << "TITLE::" << title << endl << "SUBJECTS::"
     << subjects << endl << "DESCRIPTION::" << description << endl << "DISTRIBUTOR::" <<
     distributor << endl << "NOTES::" << notes << endl << "SERIES::" << series << endl
    << "LABEL::" << label << endl;
}

bool Video::compare_other(const string& searchby) const
{
    size_t found = description.find(searchby);
    size_t found1 = notes.find(searchby);
    size_t found2 = distributor.find(searchby);
    if((found!=string::npos) || (found1!=string::npos) || (found2!=string::npos))
    {
        return true;
    }
    else
    {
        return false;
    }
}
