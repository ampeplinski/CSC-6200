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
    vector< vector<int> > table(s1.length() + 1, vector<int>(s2.length()+ 1, 0));
    vector< vector<string> > printTable(s1.length() + 2, vector<string>(s2.length()+ 2, "X"));
    
    //string *ptr = dp;
    int maxLength = 0;
    int endIndex = 0;

    cout << s1 << endl;
    for (int i = 0; i < table.size(); i++){
        if (i == 0){
            continue;
        }
        
        for ( int j = 0; j < table[i].size(); j++){
            if (j == 0) {
                printTable[i][j] = s1[i];
                continue;
            }
            //cout << "table: "<< table[i][j] << endl;
            if (s1[i-1]== s2[j-1]){
                cout << "string1: "<< s1[i-1] << endl;
                cout << "string2: "<< s2[j-1] << endl;

                table[i][j] = table[i-1][j-1] +1;

                if(table[i][j] > maxLength) {
                    maxLength = table[i][j];
                    endIndex = i;
                }
            }
            else{
                table[i][j] = 0;
            }
            //cout << "type a string"<< dp[i][j] << endl;
            }
        }
    for (int i = 0; i < printTable.size(); i++){
        cout << endl;
        //if (i == 0){
        //    continue;
        //   }
        for ( int j = 0; j < printTable[i].size(); j++){
            //if (j == 0){
            //continue;
            //}
            cout << printTable[i][j];
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