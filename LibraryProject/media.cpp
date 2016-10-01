#include<iostream>
#include<string>
#include<vector>
#include"media.h"
#include "boost/algorithm/string.hpp"

using namespace std;
using namespace boost;

Media::Media(const string& a,const string& b,const string& c,const string& d)
{
    call_number = a;
    title = b;
    subjects = c;
    notes = d;
}

Media::~Media()
{

}

void Media::display() const
{

}

bool Media::compare_title(const string& searchby) const
{
    size_t found = title.find(searchby);
    if(found!=string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Media::compare_call_number(const string& searchby) const
{
    size_t found = call_number.find(searchby);
    if(found!=string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Media::compare_subject(const string& searchby) const
{
    size_t found = subjects.find(searchby);
    if(found!=string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Media::compare_other(const string& x) const
{

}
