#include <iostream>
#include <string>
using namespace std;

int main()
{
    string strCmd;
    cout<<"input command:"<<endl;
    getline(cin, strCmd);
    //#n0  #2012
    //can not be null
        //at least has 3 char #n0 when n = 0
    if(strCmd.length() >= 3) {
        //if the first char is not #, return N
        if(strCmd.at(0) != '#') {
            char c = 'N';
            cout<<c<<endl;
            return 0;
        } else if(strCmd.at(1) < 48 || strCmd.at(1) > 57) {
            cout<<"M"<<endl;
            return 0;
        }
        //get decimal
        string strOutput;
        int n = strCmd.at(1) - '0';
        if(strCmd.length() - 3 >= n) {
            strOutput = strCmd.substr(2, n + 1);
            cout<<strOutput<<endl;
        } else {
            strOutput = strCmd.substr(2, strCmd.length() - 2);
            cout<<strOutput<<endl;
        }
    }
    return 0;
}
