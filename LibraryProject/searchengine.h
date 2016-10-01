#include"book.h"
#include"periodic.h"
#include"film.h"
#include"video.h"
#include<string>
#include<vector>

using namespace std;

class Searchengine
{
private:
    vector<Media *> cardcatalog;
public:
    Searchengine();
    ~Searchengine();
    vector<Media *>search_by_title(const string&) const;
    vector<Media *>search_by_call_number(const string&) const;
    vector<Media *>search_by_subjects(const string&)const;
    vector<Media *>search_by_other(const string&)const;
};
