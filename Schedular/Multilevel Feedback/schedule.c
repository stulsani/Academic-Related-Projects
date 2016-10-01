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
    struct node* prev;
    int age;
};

struct node* root1;
struct node* cur1;

struct node* root2;
struct node* tail2;
struct node* cur2;

struct node* root3;
struct node* tail3;
struct node* cur3;

/**
 * Function to initialize any global variables for the scheduler.
 */
void init()
{
	root1 = NULL;
	root2 = NULL;
	root3 = NULL;
}

/**
 * Function called every simulated time period to provide a mechanism
 * to age the scheduled processes and trigger feedback if needed.
 */
void age()
{
	if(root2 != NULL)
	{
		struct node* temp;
		temp = root2;
		int global;
		while(temp != tail2)
		{
			global = 0;
			temp-> age = temp->age + 1;    
			if(temp-> age == 1004)
			{   
				int store = temp-> value;
				int i = removeProcess(temp-> value);
				addProcess(store,0);
				temp = root2;
				global = 1;
				i--;
			}
			if(global != 1)
			{
				temp = temp-> next;
			}
		}
		if(temp == tail2)
		{
			temp-> age = temp->age + 1;    
			if(temp-> age == 1004)
			{   
				int store = temp-> value;
				int i = removeProcess(temp-> value);
				addProcess(store,0);
				i--;
			}	
		}
	}

	if(root3 != NULL)
	{   
		struct node* temp;
		temp = root3;
		int global;
		while(temp != tail3)
		{
			global = 0;
			temp-> age = temp->age + 1;    
			if(temp-> age > 1000)
			{   
				int store = temp-> value;
				int i = removeProcess(temp-> value);
				addProcess(store,1);
				temp = root3;
				global = 1;
				i--;
			}
			if(global != 1)
			{
				temp = temp-> next;
			}
		}
		if(temp == tail3)
		{
			temp-> age = temp->age + 1;    
			if(temp-> age > 1000)
			{   
				int store = temp-> value;
				int i = removeProcess(temp-> value);
				addProcess(store,1);
				i--;
			}	
		}
	}
}

/**
 * Function to add a process to the scheduler
 * @Param pid - the ID for the process/thread to be added to the
 *      scheduler queue
 * @Param priority - priority of the process being added
 * @return true/false response for if the addition was successful
 */
int addProcess(int pid, int priority)
{
	if(priority == 0)
	{
		if(root1 != NULL)
		{	
			cur1-> next = (struct node*) malloc( sizeof(struct node));
			cur1 = cur1-> next;
			cur1-> value = pid;
			cur1-> age = 0;
			cur1-> next = NULL;
			return 1;
		}
		else
		{
			root1 = (struct node*) malloc( sizeof(struct node));
			//cur1 = root1;
			root1-> value = pid;
			root1-> age = 0;
			root1 -> next = NULL;
			cur1 = root1;
			return 1;
		}
	}
	if(priority == 1)
	{   
		if(root2 == NULL)
		{  
			root2 = (struct node*) malloc( sizeof(struct node));
			root2-> value = pid;
			root2-> age = 0;
			root2-> next = root2;
			root2-> prev = root2;
			cur2 = root2;
			tail2 = root2;    
			return 1;
		}	
		else
		{    
			cur2-> next = (struct node*) malloc( sizeof(struct node));
			cur2 = cur2-> next;
			cur2-> value = pid; 
			cur2-> age = 0;     
			cur2-> prev = tail2;
			cur2-> next = root2;
			root2-> prev = cur2;
			tail2-> next = cur2;
			tail2 = cur2;      
			return 1;	
		}
	}

	if(priority == 2)
	{  
		if(root3 == NULL)
		{  
			root3 = (struct node*) malloc( sizeof(struct node));
			root3-> value = pid;
			root3-> age = 0;
			root3-> next = root3;
			root3-> prev = root3;
			cur3 = root3;
			tail3 = root3;     
			return 1;
		}	
		else
		{   
			cur3-> next = (struct node*) malloc( sizeof(struct node));
			cur3 = cur3-> next;
			cur3-> value = pid;
			cur3-> age = 0;
			cur3-> prev = tail3;
			cur3-> next = root3;
			root3-> prev = cur3;
			tail3-> next = cur3;
			tail3 = cur3;     
			return 1;	
		}
	}	
	return 0;
}


/**
 * Function to remove a process from the scheduler queue
 * @Param pid - the ID for the process/thread to be removed from the
 *      scheduler queue
 * @Return true/false response for if the removal was successful
 */
int removeProcess(int pid)
{
	if(root2 != NULL)     //if 2nd list is not empty
	{
		struct node* del2;
		struct node* temp2;
		del2 = root2;
		do
		{
			if(del2-> value == pid)
			{
				if(root2 == tail2)
				{
					free(root2);
					root2 = NULL;
					tail2 = NULL;
					cur2 = NULL;
					return 1;
				}
				else if(del2 == root2)
				{
				
					del2 = root2;
					root2 = root2-> next;
					root2-> prev = del2-> prev;
					tail2-> next = root2;
					free(del2);
					return 1;
				}
				else
				{  
					temp2 = del2;				
					temp2 = temp2-> next;
					temp2-> prev = del2-> prev;
					del2-> prev-> next = temp2; 
					free(del2);
					return 1;
				}
			}
		del2 = del2-> next;
		}while(del2 != root2);
	}	

	if(root3 != NULL)   //check if element is in 3rd list
	{
		
		struct node* del3;
		struct node* temp3;
		del3 = root3;
		do
		{
			if(del3-> value == pid)
			{			
				if(root3 == tail3)
				{     
					free(root3);
					root3 = NULL;
					tail3 = NULL;
					cur3 = NULL;
					return 1;
				}
				else if(del3 == root3)
				{    
					del3 = root3;
					root3 = root3-> next;
					root3-> prev = del3-> prev;
					tail3-> next = root3;
					free(del3);
					return 1;
				}
				else
				{      
					temp3 = del3;
					temp3 = temp3-> next;
					temp3-> prev = del3-> prev;
					del3-> prev-> next = temp3; 
					free(del3);
					return 1;
				}
			}
		del3 = del3-> next;
		}while(del3 != root3);
	}
return 0;
}
/**
 * Function to get the next process from the scheduler
 * @Param time - pass by pointer variable to store the quanta of time
 * 		the scheduled process should run for, returns -1 if should run to completion.
 * @Return returns the thread id of the next process that should be
 *      executed, returns -1 if there are no processes
 */
int nextProcess(int *time)
{
  	if(root1 != NULL)      //if fcfs list is not empty
	{
		int result;
		while(root1)
		{
			struct node* del1;
			del1 = root1;      
			if(root1-> next != NULL)
			{
				root1 = root1-> next;
				result = del1-> value;
				free(del1);
				del1 = NULL;
				return result; 	
			}
			else
			{
				result = root1-> value;
				free(root1);
				root1 = NULL;
				cur1 = NULL;
				return result;
			}		
    		}
	return -1;
	}
	else if(root2 != NULL)    //if priority 1 list is not empty
	{
		*time = 4;
		int i,result2;
		struct node *move2;
		move2 = root2;
		result2 = move2-> value;
		i = addProcess(result2,1);
		removeProcess(move2-> value);
		i--;
		return result2;
	}
	else    //priority 2 list execution
	{
		*time = 1;
		int i,result3;
		struct node *move3;
		move3 = root3;
		result3 = move3-> value;
		i = addProcess(result3,2);
		removeProcess(move3-> value);
		i--;
		return result3;
	}
}

/**
 * Function that returns a boolean 1 True/0 False based on if there are any
 * processes still scheduled
 * @Return 1 if there are processes still scheduled 0 if there are no more
 *		scheduled processes
 */
int hasProcess()
{
   if((root1 != NULL) || (root2 != NULL) || (root3 != NULL))
   {
	return 1;
   }
   else
   {	
	return 0;
   }  
}
