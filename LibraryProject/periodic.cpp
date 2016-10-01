#include<iostream>
#include<string>
#include<vector>
#include"periodic.h"
#include "boost/algorithm/string.hpp"

using namespace std;
using namespace boost;

Periodic::Periodic(const string& call_number,const string& title,const string& subjects,
                   const string& author,const string& description,const string& publisher,
                   const string& publishing_history,const string& series,const string& notes,
                   const string& related_titles,const string& other_forms_of_title,
                   const string& gov_doc_number): Media(call_number,title,subjects,notes),
                   author(author),description(description),publisher(publisher),
                   publishing_history(publishing_history),series(series),related_titles(related_titles),
                   other_forms_of_title(other_forms_of_title),gov_doc_number(gov_doc_number)
{

}

void Periodic::display() const
{
    cout << "-----------PERIODIC----------" << endl;
    cout << "CALL NUMBER::" << call_number << endl << "TITLE::" << title << endl
    << "SUBJECTS::" << subjects << endl<< "AUTHOR::" << author << endl << "DESCRIPTION::" <<
    description << endl << "PUBLISHER::" << publisher << endl <<  "PUBLISHING HISTORY::" <<
    publishing_history << endl << "SERIES::" << series << endl <<  "NOTES::"
     << notes << endl << "RELATED TITLES::" << related_titles << endl << "OTHER FORMS OF TITLE::"
     << other_forms_of_title << endl << "GOV DOC NUMBER::" << gov_doc_number << endl;
}

bool Periodic::compare_other(const string& searchby) const
{
    size_t found = description.find(searchby);
    size_t found1 = notes.find(searchby);
    size_t found2 = series.find(searchby);
    size_t found3 = related_titles.find(searchby);
    if((found!=string::npos) || (found1!=string::npos) || (found2!=string::npos) || (found3!=string::npos))
    {
        return true;
    }
    else
    {
        return false;
    }
}

