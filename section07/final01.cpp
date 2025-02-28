//#include <bits/stdc++.h>
#include <bitset>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> strToBinary(string inputValue){
    vector<int> binList;
    for (std::size_t i = 0;  i < inputValue.size(); ++i){
        string byte = bitset<8>(inputValue[i]).to_string();
        for (int n = 0;  n < 8; ++n){
            
            binList.push_back(byte[n]);
        };
        //binList.push_back(bitset<8>(inputValue[i]).to_string());
        //cout << typeid(bitset<8>(inputvalue[i])).name() << endl;
        //cout << bitset<8>(inputvalue[i]).to_string() << endl;
    };
    //for (std::size_t i = 0;  i < binList.size(); i++){
    //    cout << binList[i] << endl;
    //}
    return binList;

}

vector<int>  preprocess(vector<int> binList){
    int messageLength = binList.size() * 8;
    // append the bit "1" followed by k zero bits
    //string lastLetter = "10000000";
    binList.push_back(1);
    //where k is the smalles non-negative solution to the equation
    int k = 448;
    // l + 1 + k = 448mod512
    int checker = messageLength + 1 + k ;
    cout << "checker: " << checker << endl;
    int remainder = checker % 512;
    cout << "remainder: " << checker << endl;
    cout << binList.size() * 8 << endl;

    for (int i = 0;  i < 43; ++i){
        binList.push_back("00000000");
    };
    // 64 bit block equal to the number l expressed using binary representation
    for (int i = 0;  i < 7; ++i){
        binList.push_back("00000000");
    };
    string binMsgLength = "01100000";
    binList.push_back(binMsgLength);

    return binList;
    
}

int main(){
    string inputvalue = "Hello Worlds";
    vector<int> binList = strToBinary(inputvalue);
    int messageLength = binList.size() * 8;
    cout << messageLength << endl;
    vector<string> proccessedBinList = preprocess(binList);

    int msgAndBufferLength = proccessedBinList.size() * 8;
    cout << msgAndBufferLength << endl;
    //for (int i = 0;  i < proccessedBinList.size(); i++){
     //   cout << proccessedBinList[i] << endl;
    //}
}