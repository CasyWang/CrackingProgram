#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    int cnt;
    string strCnt;
    getline(cin, strCnt);
    cnt = atoi(strCnt.c_str());    //get menu number

    string strUsrCmd;
    getline(cin, strUsrCmd);      //get user command

    int i;
    int cursor = 1;               //ָ��ڼ����˵�,��Χ[1,,cnt]
    int cursorPos = 1;            //ָ����Ļ����ʾ�ĵڼ����˵�,��Χ[1,4]
    for(i = 0; i < strUsrCmd.length(); i++) {
        if(strUsrCmd[i] == 'D') {
            cursor++;
            cursorPos++;
            if(cursorPos > 4) {
                cursorPos = 4;
            }
            if(cursor > cnt) {    //�����½�
                cursor = 1;
                cursorPos = 1;
            }
        }
        else if(strUsrCmd[i] == 'U') {
            cursor--;
            cursorPos--;
            if(cursorPos < 1) {
                cursorPos = 1;
            }
            if(cursor < 1) {     //�����Ͻ�
                cursor = cnt;
                cursorPos = 4;
            }
        }

    }

    int k = cursor - cursorPos;            //���Թ�ϵ����ϵ��
    int j;
    int menuLength = cnt > 4 ? 4 : cnt;
    for(j = 1; j <= menuLength; j++) {
        if(j == cursorPos) {
            cout<<"["<<j+k<<"]"<<endl;
        } else {
            cout<<j+k<<endl;
        }
    }

    return 0;
}
