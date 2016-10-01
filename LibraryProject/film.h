#ifndef FILM_H
#define FILM_H
#include<string>
#include"media.h"

using namespace std;

class Film:public Media
{
private:
    string director,year;
public:
    Film(const string&,const string&,const string&,const string&,const string&,const string&);
    void display() const;
    bool compare_other(const string&) const;
};
#endif

