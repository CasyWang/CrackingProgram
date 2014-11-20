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
    //����һ��ͷ�ڵ�
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
    tsNode* node = new tsNode;                    //ʵ����һ���ڵ�
    node->next_min = this->current_min;           //��¼�Լ���ջ�׽ڵ�֮����С��һ���ڵ�λ��(�������Լ�)

    if(isEmpty()) {
        this->current_min = node;                 //���Ϊ��ջ,��ǰ����С�ڵ㼴Ϊ��һ��push�����Ľڵ�
    }
    else {
        if(a < current_min->value) {              //�����Ϊ��ջ,����push������ֵͬ��ǰ��¼����Сֵ�ڵ�Ƚ�
            this->current_min = node;             //��С,����
        }
    }

    node->value = a;                              //��ֵ���ڵ�
    node->pre = this->top;                        //����ǰ��ָ��
    node->next = NULL;                            //�������ָ��

    this->top->next = node;                       //����֮ǰtop��nextָ��
    this->top = node;                             //���µ���topָ��

}

int Stack::Pop() {
    int val = 0;
    if(!isEmpty()) {
        this->current_min = this->top->next_min;   //�������ڶ�С�Ľڵ���µ�current_min
        val = this->top->value;                    //����ֵ
        this->top = this->top->pre;                //top����

        delete this->top->next;                    //����pop��ȥ�Ľڵ��ڴ�
        this->top->next = NULL;                    //��ֹҰָ��
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
