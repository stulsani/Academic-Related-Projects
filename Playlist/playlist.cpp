/**
 * @file playlist.cpp   Implementation of a Playlist for music.
 *
 * @brief
 *    Implementation of a Playlist for music. A doubly linked list is
 *    used to store the song names.
 *
 * @author Judy Challinger
 * @date 2/1/13
 */

#include "playlist.h"
#include "doublylinkedlist.h"
#include <iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
#include<sstream>
#include<cstdlib>

using namespace std;

using std::string;
using std::cin;
using std::cout;
using std::endl;
/*
Playlist::Playlist()
{

}

Playlist::~Playlist()
{

}
*/
/**
 * Process a playlist command.
 *
 * Gets an entire line from std::cin, extracts the first word as the command,
 * and calls the appropriate processing function. Invalid commands are
 * ignored.
 */

void Playlist::processCommand()
{
    string s;
    while(getline(cin,s))   //get line from std:cin
    {
        string command,song;
        command = s.substr(0,s.find(" "));//to find first space in i/p string
        size_t pos = s.find(" ")+1;
        song = s.substr(pos); //after space is found string added in song
        if(command == "appendSong")
        {
            dll.append(song);
        }
        else if(command == "removeSong")
        {
            dll.remove(song);
        }
        else if(command == "playCurrent")
        {
            if(dll.empty())
        {
            cout << endl << "playing current: ";
        }
        else
        {
            string current = dll.getdata();
            cout << endl << "playing current: " << current << endl;
        }
    }
    else if(command == "playReverse")
    {
       if(dll.empty())
       {
           cout << endl << "playing reverse: ";
       }
      else
      {
          cout << endl << "playing reverse: " << endl;
          do
          {
             string current;   //to store data returned by getdata function
             current = dll.getdata();
             cout << current << endl;
          }while(dll.prev() == true);
      }

    }
    else if(command == "playForward")
    {
       if(dll.empty())
       {
           cout << endl << "playing forward: ";
       }
      else
      {
           cout << endl << "playing forward: "<<endl;
          do
          {
             string current;
             current = dll.getdata();
             cout << current << endl;
          }while(dll.next() == true);
      }
    }
    else if(command == "gotoSong")
    {
        if(dll.empty())
        {

        }
        else
        {
            bool result;
            result = dll.find(song);
            if(result == true)
            {

            }
            else
            {

            }
        }
    }
    else if(command == "gotoFirstSong")
    {
        dll.begin();
    }
    else if(command == "insertAfter")
    {
        dll.insertAfter(song);
    }
    else if(command == "insertBefore")
    {
        dll.insertBefore(song);
    }
    else if(command == "gotoLastSong")
    {
        dll.end();
    }
    else
    {

    }

}

}

/**
 * The Playlist main loop will process command lines until eof.
 */
void Playlist::mainLoop() {
    while (!cin.eof()) processCommand();   // process all commands
}


/**
 * The main entry point for the program.
 */
int main()
{
   Playlist myPlaylist;
   myPlaylist.mainLoop();
   return 0;
}

