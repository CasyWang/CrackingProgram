#ifndef STACK_H
#define STACK_H

class Stack
{
    public:
        Stack(int MaxSize);
        virtual ~Stack();
        int Pop();
        void Push(int a);
    protected:
    private:
        int Size;
        int MaxSize;
        int *StackArray;
        int Top;           //Õ»¶¥ÏÂ±ê
        int isEmpty();
        int Size();
};

#endif // STACK_H
