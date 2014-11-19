#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        virtual ~Stack();
        int Pop();
        void Push(int a);
        int Min();

    protected:
    private:
        //�ڵ�ṹ
        typedef struct {
            int* next;
            int* pre;
            int value;
            int next_min;
        }tsNode;
    tsNode* top;
    tsNode* bottom;
};

#endif // STACK_H
