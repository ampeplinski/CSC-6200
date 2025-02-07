#include <iostream>
#include <vector>
//#include <map>
#include <string>
//#include <list>
//#include <set>
//#include <iterator>
using namespace std;

int main(){
    string s1;
    cout << "type a string" << endl;
    cin >> s1;

    string s2;
    cout << "type a string" << endl;
    cin >> s2;
    vector< vector<int> > table(s1.length()+1, vector<int>(s2.length()+ 1, 0));
    //string *ptr = dp;
    int maxLength = 0;
    int endIndex = 0;

    cout << s1 << endl;
    for (int i = 0; i < dp.size(); i++){
        //cout << "type a string"<< dp[i] << endl;
        for ( int j = 0; j < dp[i].size(); j++){
            if (s1[i-1]== s2[j-1]){
                table[i][j] = table[i-1][j-1] +1;
                if(table[i][j] > maxLength) {
                    maxLength = table[i][j];
                    endIndex = i;
                }
            }
            if (j == 0){
                cout << s2[i] << endl;
            }
            //cout << "type a string"<< dp[i][j] << endl;
            }
        }
        //if (i == *n){
        //    continue;
        //}
    //for(int *ptr = dp; ptr < end ;++ptr) {
        //if(*ptr > max) {
        //   max = *ptr;
        //}
        //cout << *ptr << endl;
        //}

}