#include"searchengine.h"
#include<iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
#include<sstream>
#include<cstdlib>
#include <vector>


using namespace std;

Searchengine::Searchengine()
{
    Book* bk;
    Film* fm;
    Periodic* per;
    Video* vid;
    ifstream infile( "book.txt" );
    while (infile)
    {
        int num = 0;
        string call_number,title,subjects,author,description,publisher,city,year,series,notes,s,display;
        if (!getline( infile, s )) break;

        istringstream ss( s );

        while (ss)
        {
            if (!getline( ss, s, '|' ))  break;
            num = num + 1;
            if(num == 11)
            {
                num = 1;
            }
            if(num == 1)
            {
                call_number = s;
            }
            if(num == 2)
            {
                title = s;
            }
            if(num == 3)
            {
                subjects = s;
            }
            if(num == 4)
            {
                author = s;
            }
            if(num == 5)
            {
                description = s;
            }
            if(num == 6)
            {
                publisher = s;
            }
            if(num == 7)
            {
                city = s;
            }
            if(num == 8)
            {
                year = s;
            }
            if(num == 9)
            {
                series = s;
            }
            if(num == 10)
            {
                notes = s;
            }
        }
         bk = new Book(call_number,title,subjects,author,description,publisher,city,year,series,notes);
        cardcatalog.push_back(bk);
    }
    if (!infile.eof())
    {
        cout << "Unable to read the file!!!" << endl;
    }

     ifstream infile1( "periodic.txt" );
    while (infile1)
    {

        int num = 0;
        string call_number,title,subjects,author,description,other_forms_of_title,
        gov_doc_number,publisher,series,notes,publishing_history,related_titles,s,display;;
        if (!getline( infile1, s )) break;

        istringstream ss( s );

        while (ss)
        {
            if (!getline( ss, s, '|' ))  break;
            num = num + 1;
            if(num == 13)
            {
                num = 1;
            }
            if(num == 1)
            {
                call_number = s;
            }
            if(num == 2)
            {
                title = s;
            }
            if(num == 3)
            {
                subjects = s;
            }
            if(num == 4)
            {
                author = s;
            }
            if(num == 5)
            {
                description = s;
            }
            if(num == 6)
            {
                publisher = s;
            }
            if(num == 7)
            {
                publishing_history = s;
            }
            if(num == 8)
            {
                series = s;
            }
            if(num == 9)
            {
                notes = s;
            }
            if(num == 10)
            {
                related_titles = s;
            }
            if(num == 11)
            {
                other_forms_of_title = s;
            }
            if(num == 12)
            {
                gov_doc_number = s;
            }
        }
         per = new Periodic(call_number,title,subjects,author,description,publisher,publishing_history,
                   series,notes,related_titles,other_forms_of_title,gov_doc_number);
        cardcatalog.push_back(per);
    }
        if (!infile1.eof())
    {
        cout << "Unable to read the file!!!" << endl;
    }

    ifstream infile2( "video.txt" );
    while (infile2)
    {
        int num = 0;
        string subjects,title,call_number,description,distributor,series,label,notes,s,display;
        if (!getline( infile2, s )) break;

        istringstream ss( s );

        while (ss)
        {
            if (!getline( ss, s, '|' ))  break;
            num = num + 1;
            if(num == 9)
            {
                num = 1;
            }
            if(num == 1)
            {
                call_number = s;
            }
            if(num == 2)
            {
                title = s;
            }
            if(num == 3)
            {
                subjects = s;
            }
            if(num == 4)
            {
                description = s;
            }
            if(num == 5)
            {
                distributor = s;
            }
            if(num == 6)
            {
                notes = s;
            }
            if(num == 7)
            {
                series = s;
            }
            if(num == 8)
            {
                label = s;
            }
        }
         vid = new Video(call_number,title,subjects,description,distributor,notes,series,label);
        cardcatalog.push_back(vid);
    }
    if (!infile2.eof())
    {
        cout << "Unable to read the file!!!" << endl;
    }

    ifstream infile3( "film.txt" );
    while (infile3)
    {
        int num = 0;
        string call_number,title,subjects,director,notes,year,s,display;
        if (!getline( infile3, s )) break;

        istringstream ss( s );

        while (ss)
        {
            if (!getline( ss, s, '|' ))  break;
            num = num + 1;
            if(num == 7)
            {
                num = 1;
            }
            if(num == 1)
            {
                call_number = s;
            }
            if(num == 2)
            {
                title = s;
            }
            if(num == 3)
            {
                subjects = s;
            }
            if(num == 4)
            {
                director = s;
            }
            if(num == 5)
            {
                notes = s;
            }
            if(num == 6)
            {
                year = s;
            }
        }
         fm = new Film(call_number,title,subjects,director,notes,year);
        cardcatalog.push_back(fm);
    }
    if (!infile3.eof())
    {
        cout << "Unable to read the file!!!" << endl;
    }
}

Searchengine::~Searchengine()
{
    for(int i=0; i<cardcatalog.size(); ++i)
        {
            delete cardcatalog[i];
        }
}

vector<Media *> Searchengine::search_by_title(const string& str_search) const
{
     vector<Media *> result;
     vector<Media *>::const_iterator it;
      for(it = cardcatalog.begin(); it != cardcatalog.end(); it++)
        {
            bool found = (*it)->compare_title(str_search);
            if(found == true)
            {
                result.push_back(*it);
            }
        }
    return result;
}

vector<Media *> Searchengine::search_by_call_number(const string& str_search) const
{
     vector<Media *> result;
     vector<Media *>::const_iterator it;
      for(it = cardcatalog.begin(); it != cardcatalog.end(); it++)
        {
            bool found = (*it)->compare_call_number(str_search);
            if(found == true)
            {
                result.push_back(*it);
            }
        }
    return result;
}


vector<Media *> Searchengine::search_by_subjects(const string& str_search) const
{
     vector<Media *> result;
     vector<Media *>::const_iterator it;
      for(it = cardcatalog.begin(); it != cardcatalog.end(); it++)
        {
            bool found = (*it)->compare_subject(str_search);
            if(found == true)
            {
                result.push_back(*it);   //returns result <Media *> vector
            }
        }
    return result;
}

vector<Media *> Searchengine::search_by_other(const string& str_search) const
{
     vector<Media *> result;
     vector<Media *>::const_iterator it;
      for(it = cardcatalog.begin(); it != cardcatalog.end(); it++)
        {
            bool found = (*it)->compare_other(str_search);
            if(found == true)
            {
                result.push_back(*it);
            }
        }
    return result;
}
