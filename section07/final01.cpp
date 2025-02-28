//#include <bits/stdc++.h>
#include <bitset>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void strToBinary(string inputvalue){
    vector<string> binlist;
    for (std::size_t i = 0;  i < inputvalue.size(); ++i){
        binlist.push_back(bitset<8>(inputvalue[i]).to_string());
        //cout << typeid(bitset<8>(inputvalue[i])).name() << endl;
        //cout << bitset<8>(inputvalue[i]).to_string() << endl;
    };
    cout << binlist.size() * 8 << endl;
    for (std::size_t i = 0;  i < binlist.size(); i++){
        cout << binlist[i] << endl;
    }

}

int main(){
    string inputvalue = "Hello Worlds";
    strToBinary(inputvalue);
}