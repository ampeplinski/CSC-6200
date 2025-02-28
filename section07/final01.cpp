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

vector<int> decToBinary(int num){
    int binaryNum[16];
    vector<int> reversedBin;

    int i = 0;
    while (num > 0){
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    };

    cout << sizeof(binaryNum)<< endl;
    //for (int i = 0;  i < sizeof(binaryNum); ++i){
    //    cout << binaryNum[i];
    //};
    for (int n = 0;  n < i; ++n){
        //cout << binaryNum[n];
        reversedBin.insert(reversedBin.begin(), binaryNum[n]);
    };

    while (reversedBin.size() < 64){
        reversedBin.insert(reversedBin.begin(), 0);
    }
    //for ( int j = i -1; j >= 0; j--){
    //    cout<< binaryNum[j];
    //    reversedBin[]
    //}
    for (int i = 0;  i < reversedBin.size(); ++i){
        cout << reversedBin[i];
    };
    cout << endl;
    return reversedBin;
}

vector<int>  preprocess(vector<int> binList){
    int messageLength = binList.size();
    // append the bit "1" followed by k zero bits
    //string lastLetter = "10000000";
    binList.push_back(1);
    //where k is the smalles non-negative solution to the equation
    int k = 351;
    // l + 1 + k = 448 mod512
    int checker = messageLength + 1 + k + 64;
    cout << "checker: " << checker << endl;
    //int remainder = checker % 512;
    //cout << "remainder: " << checker << endl;
    //cout << binList.size() << endl;

    //for (int i = 0;  i < 43; ++i){
    //    binList.push_back("00000000");
    //};
    // 64 bit block equal to the number l expressed using binary representation
    //for (int i = 0;  i < 7; ++i){
    //    binList.push_back("00000000");
    //};
    //string binMsgLength = "01100000";
    //binList.push_back(binMsgLength);
    vector<int> lengthbits = decToBinary(messageLength);

    return binList;
    
}

int main(){
    string inputvalue = "Hello Worlds";
    vector<int> binList = strToBinary(inputvalue);
    int messageLength = binList.size();
    cout << messageLength << endl;
    vector<int> proccessedBinList = preprocess(binList);

    int msgAndBufferLength = proccessedBinList.size();
    cout << msgAndBufferLength << endl;
    //for (int i = 0;  i < proccessedBinList.size(); i++){
     //   cout << proccessedBinList[i] << endl;
    //}
}