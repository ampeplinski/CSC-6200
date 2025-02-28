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
        //cout << byte;
        for (char c : byte){
            if (c == '1'){
                binList.push_back(1);
            }
            else{
                binList.push_back(0);
            }
        };
        //binList.push_back(bitset<8>(inputValue[i]).to_string());
        //cout << typeid(bitset<8>(inputvalue[i])).name() << endl;
        //cout << bitset<8>(inputvalue[i]).to_string() << endl;
    };
    //for (std::size_t i = 0;  i < binList.size(); i++){
    //    cout << binList[i] << endl;
    //}

    //for (int i = 0;  i < binList.size(); i++){
    //   cout << binList[i];
    // }
    
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
    //for (int i = 0;  i < reversedBin.size(); ++i){
    //    cout << reversedBin[i];
    //};
    //cout << endl;
    cout << reversedBin.size() << endl;

    return reversedBin;
}

vector<int>  preprocess(vector<int> binList){
    int messageLength = binList.size();
    
    // append the bit "1" followed by k zero bits
    //string lastLetter = "10000000";
    //where k is the smalles non-negative solution to the equation
    int mod1 = (messageLength % 512 +1);
    int k = (512 + 448 - mod1) % 512;
    cout << "k: "<< k << endl;
    //int k = 351;
    // l + 1 + k = 448 mod 512
    vector<int> lengthbits = decToBinary(120000);
    int checker = messageLength + 1 + k + lengthbits.size();
    cout << "checker: " << checker << endl;
    binList.push_back(1);

    for (int i = 0;  i < k; ++i){
        binList.push_back(0);
    };

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

    cout << "binList size: "<< binList.size() << endl;

    

    for (int i = 0;  i < 64; ++i){
        binList.insert(binList.end(), lengthbits[i]);
    };

    cout << "binList size: "<< binList.size() << endl;


    return binList;
    
}


int main(){
    string inputvalue = "Hello Worlds";
    vector<int> binList = strToBinary(inputvalue);
    int messageLength = binList.size();
    cout << messageLength << endl;
    //for (int i = 0;  i < binList.size(); i++){
    //   cout << binList[i];
    //}
    
    vector<int> proccessedBinList = preprocess(binList);

    int msgAndBufferLength = proccessedBinList.size();
    cout << msgAndBufferLength << endl;
    for (int i = 0;  i < proccessedBinList.size(); i++){
       cout << proccessedBinList[i];
    }
    
}