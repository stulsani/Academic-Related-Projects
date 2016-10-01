#include "schedule.h"
#include <stdlib.h>
#include <stdio.h>

/*
Name: Sumeet Tulsani	
Id: stulsani
*/

struct node 
{
    int value;
    struct node* next;
    struct node* prev;
};

struct node* root;
struct node* tail;
struct node* cur;

/**
 * Function to initialize any global variables for the scheduler.
 */
void init()
{  
    root = (struct node*) malloc( sizeof(struct node));
    cur = root;
    root-> value = -1;
    tail = (struct node*) malloc( sizeof(struct node));
    root-> next = tail;
    root-> prev = tail;
    tail-> prev = root;
    tail-> next = root;
}

/**
 * Function to add a process to the scheduler
 * @Param pid - the ID for the process/thread to be added to the
 *      scheduler queue
 * @return true/false response for if the addition was successful
 */
int addProcess(int pid)
{	
	if(root-> value != -1)
	{  	
		if(root-> next == tail)
		{ 
			cur = tail;
			cur-> value = pid;
			cur-> next = (struct node*) malloc( sizeof(struct node));
			tail = tail-> next;
			cur -> next = tail;
			tail-> prev = cur;
			cur-> prev = root;
			root-> next = cur;
			tail -> next = root;
			root-> prev = tail;
			return 1;			
		}
		else if(cur-> next == tail)
		{  
			cur = cur-> next;
			cur-> value = pid;
			tail -> next = root;
			root-> prev = tail;
			cur -> next = root;
			root-> prev = cur;
			return 1;
		}
		else
		{   
			cur-> next = (struct node*) malloc( sizeof(struct node));
        		tail = cur-> next;
			tail-> prev = cur;
			cur-> next = tail;
			cur = tail;
			cur-> value = pid;
			tail -> next = root;
			root-> prev = tail;
			return 1;
		}
	}
	else
	{  
		cur-> value = pid;
		return 1;
	}	
}


/**
 * Function to remove a process from the scheduler queue
 * @Param pid - the ID for the process/thread to be removed from the
 *      scheduler queue
 * @Return true/false response for if the removal was successful
 */
int removeProcess(int pid)
{
	struct node* del;
	if(root != NULL)
	{
		del = root;
	}
	else
	{
		return 0;
	}
	struct node* temp;	
	while(del != NULL || del->next != root)
	{ 			
		if(del-> value == pid)          //check where the element is present in the list
		{
			if(root == tail)     //if there is only 1 element present in the list
			{									
				free(root);
				root = NULL;	
			}
			else if(del == root)   //if element is found at head
			{
				del = root;
				root = root-> next;
				free(del);
				root-> prev = tail;
				tail-> next = root;				
			}
			else if(del == tail)       //if element is found at tail
			{
				del = tail;
				tail = tail-> prev;
				free(del);
				tail-> next = root;
				root-> prev = tail;
			}
			else    //if element is found anywhere in list execpt root and tail
			{
				temp = del;				
				temp = temp-> next;
				temp-> prev = del-> prev;
				del-> prev-> next = temp; 
				free(del);					
			}
		return 1;
		}
		del = del-> next; 
	}
	return 0;
}
/**
 * Function to get the next process from the scheduler
 * @Param time - pass by pointer variable to store the quanta of time
 * 		the scheduled process should run for
 * @Return returns the thread id of the next process that should be
 *      executed, returns -1 if there are no processes
 */
int nextProcess(int *time)
{
	*time = 4; 	
	int result;
	while(cur)
	{
	        cur = cur->next;
		result = cur-> value;
		return result;
    	}
	return -1;

}

/**
 * Function that returns a boolean 1 True/0 False based on if there are any
 * processes still scheduled
 * @Return 1 if there are processes still scheduled 0 if there are no more
 *		scheduled processes
 */
int hasProcess()
{
   if(root != NULL)
   {
	return 1;
   }
   else
   {
	return 0;
   }
}
