#ifndef bOOK_H
#define BOOK_H
#include<string>
#include"media.h"


using namespace std;

class Book: public Media
{
private:
    string author,description,publisher,city,year,series;
public:
    Book(const string& call_number,const string& title,const string& subjects,const string& author,
         const string& description,const string& publisher,const string& city,const string& year,
         const string& series,const string& notes);
    void display() const;
    bool compare_other(const string&) const;
};
#endif

