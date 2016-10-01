#ifndef PERIODIC_H
#define PERIODIC_H
#include<string>
#include"media.h"

using namespace std;

class Periodic: public Media
{
    private:
    string author,description,publisher,publishing_history,
    series,related_titles,other_forms_of_title,gov_doc_number;
    public:
        Periodic(const string&,const string&,const string&,const string&,const string&,
                 const string&,const string&,const string&,const string&,const string&,
                 const string&,const string&);
    void display() const;
    bool compare_other(const string&) const;
};
#endif

