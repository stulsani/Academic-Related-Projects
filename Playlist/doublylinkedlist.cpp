/*
Author: Sumeet Tulsani
Doubly Linked List cpp File
*/

#include "playlist.h"
#include"doublylinkedlist.h"

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

/*DoublyLinkedList Constructor, setting head,tail
and current to NULL*/

DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}

/*DoublyLinkedList destructor*/

DoublyLinkedList::~DoublyLinkedList()
{
    Node *n = head;
    Node *temp;
    while(n)
    {
        temp = n -> next;
        delete n;
        n = temp;
    }
}

/*Parameterized Node constructor*/

DoublyLinkedList::Node::Node(const string &s)
{
    data = new string(s);
}

/*Node constructor without parameters*/

DoublyLinkedList::Node::Node()
{

}

/*Node destructor*/

DoublyLinkedList::Node::~Node()
{

}

/*
IN: This function takes string as an input which is to be inserted
DESC: The string to be inserted is added in a node n then it is
inserted into the list before the current pointer in the list
OUT: NA
*/

void DoublyLinkedList::insertBefore(string &h)
{
    Node* n = new Node(h);
    /*Check if list is empty*/
    if(head == NULL && tail == NULL)
    {
        head = n;
        tail = n;
        current = n;
        n -> prev = NULL;
        n -> next = NULL;
        current -> data = n -> data;
    }
    else
    {
        /*if it is is the first element in the list*/
        if(current -> prev == NULL)
        {
            current -> prev = n;
            n -> next = current;
            n -> prev = NULL;
            current = n;
            head = n;
            current -> data = n -> data;
        }
        else
        {
            /*It is not first element in the list*/
            current -> prev -> next = n;
            n -> prev = current -> prev;
            n -> next = current;
            current -> prev = n;
            current = n;
            current -> data = n -> data;
        }
    }
}

/*
IN: This function takes string as an input which is to be inserted
DESC: The string to be inserted is added in a node n then it is
inserted into the list after the current pointer in the list
OUT: NA
*/

void DoublyLinkedList::insertAfter(string &h)
{
    Node* n = new Node(h);
     /*Check if list is empty*/
    if(head == NULL && tail == NULL)
    {
        head = n;
        tail = n;
        current = n;
        n -> prev = NULL;

        n -> next = NULL;
        current -> data = n -> data;
    }
    else
    {
         /*if it is is the last element in the list*/
        if(current -> next == NULL)
        {
            current -> next = n;
            n -> prev = current;
            n -> next = NULL;
            current = n;
            tail = n;
            current -> data = n -> data;
        }
        /*if it is is not the last element in the list*/
        else
        {
            current -> next -> prev = n;
            n -> next = current -> next;
            n -> prev = current;
            current -> next = n;
            current = n;
            current -> data = n -> data;
        }
    }
}

/*
IN: This function takes string as an input which is to be deleted
DESC: The string to be deleted is added in a node n then it is
deleted from the list.The current pointer in the list is know the
element after the node which is deleted or previous of deleted node
if there is no next node or current pointer does't point to anything
if there is no element in the list
OUT: NA
*/

void DoublyLinkedList::remove(string &s)
{
    if(!empty())
    {
        /*If there is only one element in the list which is to be deleted*/
        if(head == tail)
        {
            Node *n = new Node();
            head = n;
            tail = n;
            current = n;
            n -> prev = NULL;
            n -> next = NULL;
            delete n;
            head = NULL;
            tail = NULL;
            current = NULL;
        }
        else
        {
            Node *temp = new Node();
            temp = head;
            Node *temp1 = new Node(s);
            while(temp != NULL) //for traversing the list
            {
                if(*(temp -> data) == *(temp1 -> data))
                {
                    if(temp == tail) //if it is the last element in the list
                    {
                        current = temp -> prev;
                        tail = temp -> prev;
                        temp -> prev -> next = NULL;
                        delete temp;
                    }
                    /*If the element found is head*/
                    else if(temp == head)
                    {
                        head = temp -> next;
                        current = temp -> next;
                        temp -> next -> prev = NULL;
                        delete temp;
                    }
                    /*if element found is neither first nor last element
                    in the list*/
                    else
                    {
                        current = temp -> next;
                        Node* temp2 = temp -> prev;
                        temp2 -> next = temp -> next;
                        temp -> next -> prev = temp2;
                        delete temp;
                    }
                }
                temp = temp -> next;
            }
        }
    }
}

/*
IN: NA
DESC: This function checks if the list is empty, if yes it returns true
or it returns false
OUT: This functions returns true or false
*/

bool DoublyLinkedList::empty()
{
    if(head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
IN: This function takes string as an input which is to be inserted
DESC: The string to be inserted is added in a node n then it is
inserted into the list as a tail element as the element inserted is
the last element in the list
OUT: NA
*/

void DoublyLinkedList::append(string &h)
{
    Node* n1 = new Node(h);
    /*If no element in the list*/
    if(head == NULL && tail == NULL)
    {
        head = n1;
        tail = n1;
        current = n1;
        n1 -> prev = NULL;
        n1 -> next = NULL;
        current -> data = n1 -> data;
    }
    else
    {
        n1 -> prev = tail;
        tail -> next = n1;
        n1 -> next = NULL;
        tail = n1;
        current = n1;
        current -> data = n1 -> data;
    }
}

/*
IN: NA
DESC: This function is used to make the current pointer point to
the last element in  the list
OUT: NA
*/

void DoublyLinkedList::end()
{
    /*If no element in the list*/
    if(head == NULL && tail == NULL)
    {

    }
    else
    {
        Node *temp = new Node();
        temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        current = temp;
    }
}

/*
IN: NA
DESC: This function is used to make the current pointer point to
the first element in  the list
OUT: NA
*/

void DoublyLinkedList::begin()
{
    /*If no element in the list*/
    if(head == NULL && tail == NULL)
    {

    }
    else
    {
        Node *temp = new Node();
        temp = tail;
        while(temp -> prev != NULL)
        {
            temp = temp -> prev;
        }
        current = temp;
    }
}

/*
IN: NA
DESC: This function is used to print the entire list from the current
 pointer to the end of the list
OUT: NA
*/

bool DoublyLinkedList::next()
{
   while(current != tail)
   {
      current = current -> next;
       return true;
   }
    return false;
}

/*
IN: NA
DESC: This function is used to print the entire list from the current
 pointer to the start of the list
OUT: NA
*/

bool DoublyLinkedList::prev()
{
    while(current != head)
   {
      current = current -> prev;
       return true;
   }
    return false;
}

/*
IN: This function takes string as an input which is to be found
in the list
DESC: The string to be found in a node is added in a node n then
it is checked by all the list contains, if match is found it returns
true or else it returns false
OUT: It returns either true or false
*/

bool DoublyLinkedList::find(string &s)
{
    Node* temp = new Node();
    Node* temp1 = new Node(s);
    temp = head;
    do
    {
        if(*(temp1 -> data) == *(temp -> data)) //comparing strings
        {
            current = temp;
            return true;   //if element is found return true
        }
            temp = temp -> next;
    }while(temp != NULL);
    return false;
}

/*
IN: NA
DESC: This function is used to return the contains of current pointer
OUT: This function is used to return the data in current pointer
*/

const string& DoublyLinkedList::getdata()
{
        return *(current -> data);
}
