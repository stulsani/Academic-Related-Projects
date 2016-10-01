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
};

struct node* root1;
struct node* tail1;
struct node* cur1;
struct node* next1;
int p = 1;

struct node* root2;
struct node* tail2;
struct node* cur2;
struct node* next2;

struct node* root3;
struct node* tail3;
struct node* cur3;
struct node* next3;

struct node* root4;
struct node* tail4;
struct node* cur4;
struct node* next4;

/**
 * Function to initialize any global variables for the scheduler.
 */
void init()
{
	root1 = (struct node*) malloc( sizeof(struct node));
	root1-> value = -1;
	tail1 = root1;
	cur1 = root1;
	root2 = (struct node*) malloc( sizeof(struct node));
	root2-> value = -1;
	tail2 = root2;
	cur2 = root2;
	root3 = (struct node*) malloc( sizeof(struct node));
	root3-> value = -1;
	tail3 = root3;
	cur3 = root3;
	root4 = (struct node*) malloc( sizeof(struct node));
	root4-> value = -1;
	tail4 = root4;
	cur4 = root4;  
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
	if(priority == 1)
	{	
		if(root1-> value == -1)    //if list is empty
		{  
			root1-> value = pid;
			root1-> next = root1;
			root1-> prev = root1;
			cur1 = root1;
			tail1 = root1;   
			return 1;
		}	
		else     //if there is some element in the list
		{   
			cur1-> next = (struct node*) malloc( sizeof(struct node));
			cur1 = cur1-> next;
			cur1-> value = pid;
			cur1-> prev = tail1;
			cur1-> next = root1;
			root1-> prev = cur1;
			tail1-> next = cur1;
			tail1 = cur1;		
			return 1;	
		}
	}	

	if(priority == 2)
	{
		if(root2-> value == -1)     //if list is empty
		{  
			root2-> value = pid;
			root2-> next = root2;
			root2-> prev = root2;
			cur2 = root2;
			tail2 = root2;    
			return 1;
		}	
		else     //if there is some element in the list
		{   
			cur2-> next = (struct node*) malloc( sizeof(struct node));
			cur2 = cur2-> next;
			cur2-> value = pid;
			cur2-> prev = tail2;
			cur2-> next = root2;
			root2-> prev = cur2;
			tail2-> next = cur2;
			tail2 = cur2;      
			return 1;	
		}
	}

	if(priority == 3)
	{  
		if(root3-> value == -1)     //if list is empty
		{  
			root3-> value = pid;
			root3-> next = root3;
			root3-> prev = root3;
			cur3 = root3;
			tail3 = root3;     
			return 1;
		}	
		else      //if there is some element in the list
		{   
			cur3-> next = (struct node*) malloc( sizeof(struct node));
			cur3 = cur3-> next;
			cur3-> value = pid;
			cur3-> prev = tail3;
			cur3-> next = root3;
			root3-> prev = cur3;
			tail3-> next = cur3;
			tail3 = cur3;     
			return 1;	
		}
	}	

	if(priority == 4)
	{
		if(root4-> value == -1)     //if list is empty
		{  
			root4-> value = pid;
			root4-> next = root4;
			root4-> prev = root4;
			cur4 = root4;
			tail4 = root4;     
			return 1;
		}	
		else         //if there is some element in the list
		{   
			cur4-> next = (struct node*) malloc( sizeof(struct node));
			cur4 = cur4-> next;
			cur4-> value = pid;
			cur4-> prev = tail4;
			cur4-> next = root4;
			root4-> prev = cur4;
			tail4-> next = cur4;
			tail4 = cur4;      
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
	int x;
	x = pid % 4 + 1;      //to check in which linked list element is present
	if(x == 1)
	{
		struct node* del1;
		del1 = root1;
		do
		{
			if(del1-> value == pid)
			{
				if(root1 == tail1)   //for 1 element
				{
					free(root1);
					root1 = NULL;
					tail1 = NULL;
					cur1 = NULL;
					return 1;
				}
				else if(del1 == root1)      //if element is found at root
				{
				
					del1 = root1;
					root1 = root1-> next;
					del1-> prev = root1-> prev;
					tail1-> next = root1;
					free(del1);
					return 1;
				}
				else        //if element is found at tail
				{  
					del1 = tail1;
					tail1 = tail1-> prev;
					del1-> next = tail1-> next;
					root1-> prev = tail1;
					free(del1);
					return 1;
				}
			}
		del1 = del1-> next;
		}while(del1 != root1);
	}

	if(x == 2)
	{
		struct node* del2;
		del2 = root2;
		do
		{
			if(del2-> value == pid)
			{			
				if(root2 == tail2)     //for 1st element
				{     
					free(root2);
					root2 = NULL;
					tail2 = NULL;
					cur2 = NULL;
					return 1;
				}
				else if(del2 == root2)     //if element is found at root
				{    
					del2 = root2;
					root2 = root2-> next;
					del2-> prev = root2-> prev;
					tail2-> next = root2;
					free(del2);
					return 1;
				}
				else            //if element is found at tail
				{      
					del2 = tail2;
					tail2 = tail2-> prev;
					del2-> next = tail2-> next;
					root2-> prev = tail2;
					free(del2);
					return 1;
				}
			}
		del2 = del2-> next;
		}while(del2 != root2);
	}

	if(x == 3)
	{
		struct node* del3;
		del3 = root3;
		do
		{
			if(del3-> value == pid)
			{
				if(root3 == tail3)            //only 1 element in the list
				{
					free(root3);
					root3 = NULL;
					tail3 = NULL;
					cur3 = NULL;
					return 1;
				}
				else if(del3 == root3)         //if element is found at root
				{ 
					del3 = root3;
					root3 = root3-> next;
					del3-> prev = root3-> prev;
					tail3-> next = root3;
					free(del3);
					return 1;
				}
				else                  //if element is found at tail
				{
					del3 = tail3;
					tail3 = tail3-> prev;
					del3-> next = tail3-> next;
					root3-> prev = tail3;
					free(del3);
					return 1;
				}
			}
		del3 = del3-> next;
		}while(del3 != root3);
	}
		
	if(x == 4)
	{
		struct node* del4;
		del4 = root4;
		do
		{
			if(del4-> value == pid)
			{
				if(root4 == tail4)               //if there is only 1 element present in the list
				{
					free(root4);
					root4 = NULL;
					tail4 = NULL;
					cur4 = NULL;
					return 1;
				}
				else if(del4 == root4)                //if element is found at root
				{	
					del4 = root4;
					root4 = root4-> next;
					del4-> prev = root4-> prev;
					tail4-> next = root4;
					free(del4);
					return 1;
				}
				else                             //if element is found at tail
				{
					del4 = tail4;
					tail4 = tail4-> prev;
					del4-> next = tail4-> next;
					root4-> prev = tail4;
					free(del4);
					return 1;
				}
			}
		del4 = del4-> next;
		}while(del4 != root4);
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
	struct node* temp;
	int result;	
	if(root1==NULL && p == 1)     //if 1st list is empty
	{  
		p = 2;
	}	
	if(root1 && p == 1)         //if 1st list
	{      
		*time = 4;
		int i;
		temp = root1;
		result = root1-> value;
		i = addProcess(result,1);
		removeProcess(temp-> value);
		p++;
		i--;
		return result;
	}  

	if(root2==NULL && p == 2)        //if 2st list is empty
	{    
		p = 3;
	}
	if(root2 && p == 2)          //if 2nd list
	{	
		*time = 3;
		int i;
		temp = root2;
		result = root2-> value;   
		i = addProcess(result,2);
		removeProcess(temp-> value);
		p++; 
		i--;
		return result;
	} 
 
	if(root3==NULL && p == 3)         //if 1st list is empty
	{     
		p = 4;
	}
	if(root3 && p == 3)         //if 3rd list
	{	
		*time = 2;
		int i;
		temp = root3;
		result = temp-> value;
		i = addProcess(result,3);
		removeProcess(temp-> value);
		p++;
		i--;
		return result;
	} 
 
	if(root4==NULL && p == 4)           //if 4st list is empty
	{     
		p = 1;
	}
	if(root4 && p == 4)             //if 4th
	{	
		*time = 1;
		int i;
		temp = root4;
		result = temp-> value;
		i = addProcess(result,4);
		removeProcess(temp-> value);
		p = 1;
		i--;
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
   if((root1 != NULL) || (root2 != NULL) || (root3 != NULL) || (root4 != NULL))
   {
	return 1;
   }
   else
   {	
	return 0;
   }  		
}

