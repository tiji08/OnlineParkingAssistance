#include<stdio.h>


#ifndef __GSTACK_H__
#define __GSTACK_H__

struct Queue {
    void *data;
    struct Queue *next;
};

struct StackNode
{
    void *data;
    struct StackNode *next;
    struct StackNode *prev;
};

class Queue_t {
  struct Queue *frontQ = NULL;
  struct Queue *rearQ = NULL;
  public:
  void InsertInQ(void *data);
  void * GetFromQ();
  void destroyQ();
};

void insertInStack(void *data);
void* popFromStack();
void destroyStack();

void * GetFromQ();
void InsertInQ(void *data);
void destroyQ();

#endif
