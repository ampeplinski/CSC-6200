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
    vector< vector<int> > printTable(s1.length() + 2, vector<int>(s2.length()+ 2, 0));
    
    //string *ptr = dp;
    int maxLength = 0;
    int endIndex = 0;

    cout << s1 << endl;
    for (int i = 0; i < table.size(); i++){
        if (i == 0){
            continue;
        }
        cout << "string1: "<< s1[i] << endl;
        
        for ( int j = 0; j < table[i].size(); j++){
            if (j == 0) {
                continue;
            }
            //cout << "table: "<< table[i][j] << endl;
            //cout << "string2: "<< s2[j] << endl;
            //cout << "string2: "<< s2[j-1] << endl;
            if (s1[i-1]== s2[j-1]){

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