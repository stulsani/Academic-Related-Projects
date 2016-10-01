/*
Author: Sumeet Tulsani
Doubly Linked List Header File
*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include<string>


using std::string;

/*Declaration of DoublyLinkedList class with node class as a
internal class*/
class DoublyLinkedList
{
    private:
        class Node
        {
	public:
            Node* next;
            Node* prev;
            string* data;
            Node();
            Node(const string&);
            ~Node();
        };

        Node* head;
        Node* tail;
        Node* current;

	public:
	    DoublyLinkedList();
        ~DoublyLinkedList();
        bool empty();
        void append(string &);
        void insertBefore(string &);
        void insertAfter(string &);
        void remove(string &);
        void begin();
        void end();
        bool next();
        bool prev();
        bool find(string &);
        const string& getdata();
};

#endif // DOUBLYLINKEDLIST_H
