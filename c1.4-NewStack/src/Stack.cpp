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

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    //ctor
    //创建一个头节点
    tsNode* root = new tsNode;
    if(!root) {
        throw;
    }
    root->next = NULL;
    root->pre = NULL;
    this->top = this->bottom = root;
    this->current_min = root;
}

Stack::~Stack()
{
    //dtor
}

void Stack::Push(int a) {
    tsNode* node = new tsNode;                    //实例化一个节点
    node->next_min = this->current_min;           //记录自己到栈底节点之间最小的一个节点位置(不包含自己)

    if(isEmpty()) {
        this->current_min = node;                 //如果为空栈,当前的最小节点即为第一次push进来的节点
    }
    else {
        if(a < current_min->value) {              //如果不为空栈,则拿push进来的值同当前记录的最小值节点比较
            this->current_min = node;             //更小,更新
        }
    }

    node->value = a;                              //赋值到节点
    node->pre = this->top;                        //操作前驱指针
    node->next = NULL;                            //操作后继指针

    this->top->next = node;                       //连接之前top的next指针
    this->top = node;                             //重新调整top指针

}

int Stack::Pop() {
    int val = 0;
    if(!isEmpty()) {
        this->current_min = this->top->next_min;   //将倒数第二小的节点更新到current_min
        val = this->top->value;                    //读出值
        this->top = this->top->pre;                //top更新

        delete this->top->next;                    //回收pop出去的节点内存
        this->top->next = NULL;                    //防止野指针
    }
    else {
        throw;
    }
    return val;
}

int Stack::Min() {
    int val = 0;
    if(!isEmpty()) {
        val = this->current_min->value;
    }
    else {
        throw;
    }
    return val;
}

int Stack::isEmpty(void) {
    if(this->bottom == this->top) {
        return true;
    }
    else {
        return false;
    }
}
