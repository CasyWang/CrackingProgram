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

/*
  问题描述: 一块固定的buf,长度为length,要求实现一个动态内存分配功能的模块,
  每次固定分配Size长度的内存块,请设计数据结构并实现Init Get Free三个方法.
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define BufferLength      256
#define BlockSize         20
#define BlockSum          (BufferLength / BlockSize + 1)

char Buf[BufferLength] = { 0 };
bool isOccupied[BlockSum] = { false };      //is occupied

void Init();
void Free(char *p);
char* Get();
char **container;

int main()
{
    cout << "Dynamic Memory Manager" << endl;
    Init();

    container = (char**)malloc(BlockSum*sizeof(char*));
    int i = 0;
    for(; i < BlockSum; i++) {
        container[i] = Get();                           //run out of all the blocks
    }
    Free(container[5]);                                 //free a random one

    char* p = Get();                                    //malloc(20)
    memcpy(p, "hello world, i am the source", 20);      //use it

    for(i = 0; i < 20; i++) {
        cout << *(p++);
    }
    Free(p);                                            //free it
    return 0;
}

void Init() {
    memset(Buf, 0, BufferLength);
}

void Free(char *p) {
    if(NULL == p)                                      //don't free the Null Block
        return;

    int blockId = (p - Buf) / BlockSize - 1;           //calculate which block the pointer belongs to
    if(isOccupied[blockId] == false)                   //if this block is not occupied, no need to free
        return;

    isOccupied[blockId] = false;                       //mark to occupied
    memset(p, 0, BlockSize);                           //clear
}

char* Get() {
    int blockId = 0;
    while(isOccupied[blockId] == true) {
        blockId++;
        if(blockId > BlockSum - 1) {
            //overflow
            return NULL;
        }
    }
    isOccupied[blockId] = true;

    return Buf + blockId*BlockSize;
}
