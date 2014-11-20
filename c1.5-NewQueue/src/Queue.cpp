#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int MaxSize)
{
    //ctor
    this->MaxSize = MaxSize;
    this->Size = 0;
    this->MainStack = new Stack(this->MaxSize);
    this->BufferStack = new Stack(this->MaxSize);

}

Queue::~Queue()
{
    //dtor
    delete this->MainStack;
    delete this->BufferStack;
    this->MainStack = NULL;
    this->BufferStack = NULL;
}

void Queue::EnQueue(int a) {
    if(this->MainStack->Size() > 0) {    //»¹ÓÐ¿Õ¼ä
        this->MainStack->Push(a);
    }
}

int Queue::DeQueue(void) {

}

