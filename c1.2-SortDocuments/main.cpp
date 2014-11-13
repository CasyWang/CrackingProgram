#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

void Swap(string *a, string *b);
void BubbleSort(vector<string> &vct);

int main()
{
    int cnt;
    string strCnt;
    vector<string> vctDoc;
    getline(cin, strCnt);
    cnt = atoi(strCnt.c_str());

    int i;
    for(i = 0; i < cnt; i++) {
        string strTmp;
        getline(cin, strTmp);
        vctDoc.push_back(strTmp);
    }

    BubbleSort(vctDoc);
    int j;
    for(j = 0; j < vctDoc.size(); j++) {
        cout<<vctDoc[j]<<endl;
    }
    return 0;
}

void BubbleSort(vector<string> &vct) {
    int n = vct.size();
    int i, j;
    for (i = 0; i < n; i++){
          for (j = 1; j < n - i; j++) {
             if (vct[j - 1].compare(vct[j]) > 0) {
                Swap(&vct[j - 1], &vct[j]);
             }
          }
    }
}

void Swap(string *a, string *b) {
    string tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
