/*
The MIT License (MIT)

Copyright (c) <2014> <oliver-lxtech2013@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef STACK_H
#define STACK_H

typedef struct node{
    node* next;       //指向下一个节点
    node* pre;        //指向前一个节点
    int value;        //值
    node* next_min;   //不包含自己的到栈底的最小值
}tsNode;


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
        tsNode* current_min;    //当前的最小值的节点
        tsNode* top;
        tsNode* bottom;
        int Size;
        int isEmpty(void);      //判断栈是否为空
};

#endif // STACK_H
