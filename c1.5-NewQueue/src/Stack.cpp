#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int MaxSize)
{
    //ctor
    this->StackArray = new int[MaxSize];
    this->Size = 0;
    this->Top = 0;
    this->MaxSize = MaxSize;
}

Stack::~Stack()
{
    //dtor
    delete this->StackArray;
    this->StackArray = NULL;
}

void Stack::Push(int a) {
    if(this->Top > this->MaxSize - 1) {
        throw;
    }
    this->Top++;
    this->StackArray[this->Top] = a;
    this->Size++;
}

int Stack::Pop() {
    int val = 0;
    if(!isEmpty()) {
        val = this->StackArray[this->Top];
        this->Top--;
        this->Size--;
    }
    else {
        throw;
    }
    return val;
}

int Stack::isEmpty() {
    if(this->Top == 0) {
        return true;
    }
    else {
        return false;
    }
}

int Stack::Size() {
    return this->Size;
}
