#include <iostream>
#include <Stack.h>
#include <stdlib.h>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Stack* iStack = new Stack(100);
    int i;
    for(i = 0; i < 99; i++) {
        int _random = 1 + rand() % 100;
        cout<< "raw" << i << ":" << _random << endl;
        iStack->Push(_random);
    }

    for(i = 0; i < 99; i++) {
        cout << "Pop" << i << ":" << iStack->Pop() << endl;
    }

    return 0;
}
