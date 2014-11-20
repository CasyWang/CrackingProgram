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

#include <iostream>
#include <Stack.h>
#include <stdlib.h>
using namespace std;

int TEST_SUIT_SIZE  =  100;

int main()
{
    cout << "Hello world!" << endl;
    Stack* iStack = new Stack();

    int i;
    for(i = 0; i < TEST_SUIT_SIZE; i++) {
        int _random = 1 + rand() % 100;
        cout << "raw" << i << ":" << _random << endl;
        iStack->Push(_random);
    }
    for(i = 0; i < 50; i++) {
        cout << "Pop" << i << ":" << iStack->Pop() << endl;
    }

    cout << "Min:" << iStack->Min() << endl;
    return 0;
}
