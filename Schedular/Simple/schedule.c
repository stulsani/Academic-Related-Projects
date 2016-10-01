#include "schedule.h"
#include <stdlib.h>

/*
Name: Sumeet Tulsani
Id: stulsani
*/

struct node 
{
    int value;
    struct node* next;
};

struct node* root;
struct node* cur;

/**
 * Function to initialize any global variables for the scheduler.
 */
void init()
{
    root = (struct node*) malloc( sizeof(struct node));
    root-> value = -1;
    cur = root;
}

/**
 * Function to add a process to the scheduler
 * @Param pid - the ID for the process/thread to be added to the
 *      scheduler queue
 * @return true/false response for if the addition was successful
 */
int addProcess(int pid)
{       
 	if(root-> value != -1)           //if list is empty
	{	
		cur-> next = (struct node*) malloc( sizeof(struct node));
        	cur = cur-> next;
		cur-> value = pid;
		return 1;
	}
	else            //if list already contents some elements
	{
		cur-> value = pid;
		cur -> next = NULL;
		return 1;
	}
}




/**
 * Function to get the next process from the scheduler
 *
 * @Return returns the thread id of the next process that should be
 *      executed, returns -1 if there are no processes
 */
int nextProcess(){
	int result;
	while(root)
	{
	        cur = root;
	        root = root-> next;
		result = cur-> value;
	        free(cur);
		cur = NULL;
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
