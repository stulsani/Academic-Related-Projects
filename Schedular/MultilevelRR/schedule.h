#ifndef _schedule_h_
#define _schedule_h_


void init();
int addProcess(int pid, int priority);
int removeProcess(int pid);
int nextProcess(int *time);
int hasProcess();
//void print();
#endif
