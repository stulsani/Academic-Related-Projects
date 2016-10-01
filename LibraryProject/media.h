#ifndef MEDIA_H
#define MEDIA_H
#include<string>

using namespace std;

class Media
{
protected:
    string call_number,title,subjects,notes;
public:
    Media(const string&,const string&,const string&,const string&);
    virtual ~Media();
    virtual void display() const;
    bool compare_title(const string&) const;
    bool compare_call_number(const string&) const;
    bool compare_subject(const string&) const;
    virtual bool compare_other(const string&) const;
};
#endif
