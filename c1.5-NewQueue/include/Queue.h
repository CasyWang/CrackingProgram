#ifndef QUEUE_H
#define QUEUE_H
#include <Stack.h>

class Queue
{
    public:
        Queue(int MaxSize);
        virtual ~Queue();
        void EnQueue(int a);
        int DeQueue(void);
    protected:
    private:
        Stack* MainStack;
        Stack* BufferStack;
        int MaxSize;
        int Size;
};

#endif // QUEUE_H
