#ifndef VIDEO_H
#define VIDEO_H
#include<string>
#include"media.h"

using namespace std;

class Video:public Media
{
private:
    string description,distributor,series,label;
public:
    Video(const string&,const string&,const string&,const string&,const string&,
          const string&,const string&,const string&);
    void display() const;
    bool compare_other(const string&) const;
};
#endif
