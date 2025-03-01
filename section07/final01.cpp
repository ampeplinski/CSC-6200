//#include <bits/stdc++.h>
#include <bitset>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> strToBinary(string inputValue){
    vector<int> binList;
    for (std::size_t i = 0;  i < inputValue.size(); ++i){
        string byte = bitset<8>(inputValue[i]).to_string();
        //cout << byte << endl;
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

vector<int> decToBinary32(long int num){
    int binaryNum[32];
    vector<int> reversedBin;

    int i = 0;
    while (num > 0){
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    };

    //cout << sizeof(binaryNum)<< endl;
    //for (int i = 0;  i < sizeof(binaryNum); ++i){
    //    cout << binaryNum[i];
    //};
    for (int n = 0;  n < i; ++n){
        //cout << binaryNum[n];
        reversedBin.insert(reversedBin.begin(), binaryNum[n]);
    };

    while (reversedBin.size() < 32){
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
    //cout << reversedBin.size() << endl;

    return reversedBin;
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

    //cout << sizeof(binaryNum)<< endl;
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
    //cout << reversedBin.size() << endl;

    return reversedBin;
}

vector<int> decToBin(int num){
    int iterator;
    vector<int> binarynum;

    for(int i = 0; i < 32; i++){
        //cout << num % 2<< endl;
        binarynum.push_back(num % 2);
        num = num/2;
        //cout << num << endl;
    }
    return binarynum;
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
    vector<int> lengthbits = decToBinary(messageLength);
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
vector<int> rotateright(vector<int> binArray, int num){
    //for(int i = 0; i < num; i++){
    //    int tmp = binArray[i+1];
    //    binArray[i+1] = binArray[i];
    //    for(int n = 2; n < binArray.size(); n++){
    //        binArray[n] = tmp;
    //        int tmp = binArray[n+1];
    //        //binArray[n+1] = binArray[n];  
    //       }
    //      }
    vector<int> result;
    //for(auto i = num-1; i< binArray.size(); i++){
    //    result.push_back(binArray.at(i));
    //}
    for(int i = 0; i < num; ++i){
        //cout << binArray[i];
        result.push_back(binArray[32-num+i]);
    }
    for(int i = num; i < 32; ++i){
        //cout << binArray[i];
        result.push_back(binArray[i-num]);
    }
    //result.push_back(binArray.at(32-num));
    return result;
}

vector<int> shiftright(vector<int> binArray, int num){
    vector<int> result;
    for(int i = 0; i < num; ++i){
        //cout << binArray[i];
        result.push_back(0);
    }
    for(int i = num; i < 32; ++i){
        //cout << binArray[i];
        result.push_back(binArray[i-num]);
    }
    return result;
}

vector<int> xoring(vector<int> a,vector<int> b, vector<int>c){
    vector<int> xoringresult;
    //cout << a[0];
    //cout << "modding:" << endl;
    for (int i = 0; i < 32; i++){
        //cout << a[i] << "+" << b[i] << "+" << c[i] << "% 2" << endl;
        int sum = a[i] + b[i];
        int modded = sum % 2;
        int sum2 = modded + c[i];
        int modded2 = sum2 % 2;
        //cout << sum;
        xoringresult.push_back(modded2);
    }
    return xoringresult;

}

vector<int> sigma0(vector<int> wt_15){
    //cout << "before rotateright 7: "<< endl;
    //for (int i = 0;  i < wt_15.size(); i++){
    //           cout << wt_15[i];
    //}
    //cout << endl;
    //cout << "after: "<< endl;
    vector<int> rotatedwt_15_7 = rotateright(wt_15, 7);
    
    //for (int i = 0;  i < rotatedwt_15_7.size(); i++){
    //            cout << rotatedwt_15_7[i];
    //}
    //cout << endl;
    //cout << "before rotateright 18: "<< endl;
    //for (int i = 0;  i < wt_15.size(); i++){
    //            cout << wt_15[i];
    //}
    //cout << endl;
    //cout << "after: "<< endl;
    vector<int> rotatedwt_15_18 = rotateright(wt_15, 18);
    
    //for (int i = 0;  i < rotatedwt_15_18.size(); i++){
    //            cout << rotatedwt_15_18[i];
    //}
    //cout << endl;
    //cout << "before shiftright 3: "<< endl;
    //for (int i = 0;  i < wt_15.size(); i++){
    //            cout << wt_15[i];
    // }
    //cout << endl;
    //cout << "after: "<< endl;
    vector<int> shiftedwt_15_3 = shiftright(wt_15, 3);
    
    //for (int i = 0;  i < shiftedwt_15_3.size(); i++){
    //            cout << shiftedwt_15_3[i];
    //}
    //cout << endl;

    vector<int> sigma0ModdedResult = xoring(rotatedwt_15_7,rotatedwt_15_18, shiftedwt_15_3);
    //cout << "after modding: "<< endl;
    
    //for (int i = 0;  i < sigma0ModdedResult.size(); i++){
    //            cout << sigma0ModdedResult[i];
    //}
    //cout << endl;
    return sigma0ModdedResult;
}

vector<int> sigma1(vector<int> wt_2){
    //cout << "before rotateright 17: "<< endl;
    //for (int i = 0;  i < wt_2.size(); i++){
    //            cout << wt_2[i];
    //}
    //cout << endl;
    //cout << "after: "<< endl;
    vector<int> rotatedwt_2_17 = rotateright(wt_2, 17);
    
    //for (int i = 0;  i < rotatedwt_2_17.size(); i++){
    //            cout << rotatedwt_2_17[i];
    //}
    //cout << endl;
    //cout << "before rotateright 19: "<< endl;
    //for (int i = 0;  i < wt_2.size(); i++){
    //            cout << wt_2[i];
    //}
    //cout << endl;
    //cout << "after: "<< endl;
    vector<int> rotatedwt_2_19 = rotateright(wt_2, 19);
    
    //for (int i = 0;  i < rotatedwt_2_19.size(); i++){
    //            cout << rotatedwt_2_19[i];
    //}
    //cout << endl;
    //cout << "before shiftright 10: "<< endl;
    //for (int i = 0;  i < wt_2.size(); i++){
    //            cout << wt_2[i];
    //}
    //cout << endl;
    //cout << "after: "<< endl;
    vector<int> shiftedwt_2_10 = shiftright(wt_2, 10);
    
    //for (int i = 0;  i < shiftedwt_2_10.size(); i++){
    //            cout << shiftedwt_2_10[i];
    //}
    //cout << endl;

    vector<int> sigma1ModdedResult = xoring(rotatedwt_2_17,rotatedwt_2_19, shiftedwt_2_10);
    //cout << "after modding: "<< endl;
    
    //for (int i = 0;  i < sigma1ModdedResult.size(); i++){
    //            cout << sigma1ModdedResult[i];
    //}
    //cout << endl;
    return sigma1ModdedResult;
}

vector<int> additionMod32(vector<int> w_i_16,vector<int> s0, vector<int>w_i_7, vector<int> s1){
    vector<int> mod32result;
    for (int i = 0; i < 32; i++){
        int sum = w_i_16[i] + s0[i] + w_i_7[i] + s1[i];
        int modded3 = sum % (32);

        //int modded4 = modded3 % 2;
        ////int modded = sum % (2^32);
        //int sum2 = modded + w_i_7[i];
        //int modded2 = sum2 % (2^32);
        //int sum3 = modded + s1[i];
        //int modded3 = sum3 % (2^32);
        //cout << modded4;
        mod32result.push_back(modded3);
    }
    return mod32result;
}

long int binToDecimal(vector<int> number){
    //cout<< endl;
    // so if i do int decimal; then i get a strange number
    // but if i use int decimal=0; its correct
    int decimal = 0;
    //string stringa = number.to_string()

    //stringstream binary;
    //std::string str(number.begin(), number.end());
    //for (int i : number){
    //    binary << i;
    //}
    //cout << "string: " << str;

    int total = 0;
    int iterator = 31;
    for (int i = 0; i < 32; i++){
        if (number[i]== 1){
            int sum = pow(2, iterator);

            //cout << 1 * sum;
            decimal += 1 * sum;;
        }
        if (number[i]== 0){
            int sum = pow(2, iterator);
            //cout << 0 * sum;
            decimal += 0 * sum;
        }
        //cout <<number[i]<<"* 2" << "^"<< iterator <<endl;
        iterator--;
        //cout<< endl;
    }
    //auto rit = str.rbegin();
    //unsigned bit =1;
    //unsigned decimal = 0;
    //while (rit != str.rend()){
    //for (int i = 0; )
    //    if(*(rit++)== '1'){
    //        decimal += bit;
    //    }
    //    bit <<= 1;
    //    }
    return decimal;
}
void compressFunction(vector<int> proccessedBinList){
    int msgAndBufferLength = proccessedBinList.size();
    vector<vector<int>> entryMessage;
    for (int i = 0;  i < msgAndBufferLength; i = i+ 512){
        //cout << proccessedBinList[i];
        for(int z =0; z< 16; z++){
            vector<int> M;
            for(int n = 0; n < 32; ++n){
                M.push_back(proccessedBinList[0]);
                proccessedBinList.erase(proccessedBinList.begin());
            };
            //cout << endl;
            //for (int i = 0;  i < M.size(); i++){
            //    cout << M[i];
            //}
            entryMessage.push_back(M);
        }
        for (int i = 0;  i < entryMessage.size(); i++){
                for (int n = 0;  n < entryMessage[i].size(); n++){
                cout << entryMessage[i][n];
            }
            cout << endl;
            }

        //cout << "w: " << endl;
        //sigma0(entryMessage[16-15]);
        vector<int> Mt= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for (int i = 16; i < 18; i++){
            
            entryMessage.push_back(Mt);
            vector<int> sigma1ModdedResult = sigma1(entryMessage[i-2]);
            vector<int> sigma0ModdedResult = sigma0(entryMessage[i-15]);
            cout << "w" << i-16 << ": ";
            for (int n = 0;  n < entryMessage[i-16].size(); n++){
                       cout << entryMessage[i-16][n];
            }
            cout << endl;
            long int w_i_16_decimal = binToDecimal(entryMessage[i-16]);
            cout << w_i_16_decimal;
            cout << endl << "+ " << endl;
            cout << "s0: ";
            for (int n = 0;  n < sigma0ModdedResult.size(); n++){
                       cout << sigma0ModdedResult[n];
            }
            cout << endl;
            long int s0_decimal = binToDecimal(sigma0ModdedResult);
            cout << s0_decimal;
            cout << endl << "+ " << endl;
            cout << "w" << i-7 << ": ";
            for (int n = 0;  n < entryMessage[i-7].size(); n++){
                       cout << entryMessage[i-7][n];
            }
            cout << endl;
            long int w_i_7_decimal = binToDecimal(entryMessage[i-7]);
            cout << w_i_7_decimal;
            cout << endl << "+ " << endl;
            cout<<"s0: ";
            for (int n = 0;  n < sigma1ModdedResult.size(); n++){
                       cout << sigma1ModdedResult[n];
            }
            cout << endl;
            long int s1_decimal = binToDecimal(sigma1ModdedResult);
            cout << s1_decimal <<endl;
            // I exceeded the maximum number the integer can store
            long int sum = w_i_16_decimal + s0_decimal + w_i_7_decimal + s1_decimal;
            cout<< "sum: "<< sum;
            //vector<int> addedbin = decToBinary(sum);
            //vector<int> wn = additionMod32(entryMessage[i-16], sigma0ModdedResult, entryMessage[i-7], sigma1ModdedResult);
            vector<int> wn = decToBinary32(sum);
            //cout<< endl<< sum;
            cout << endl;
            cout << "w"<<i<<":";
            for (int n = 0;  n < wn.size(); n++){
                       cout << wn[n];
            }
            cout <<endl;
            //vector<int> Wt = sigma1(entryMessage[i-2]) + entryMessage[i-7] + sigma0(entryMessage[i-15]) + entryMessage[i-16]
        }      
    };

}

//H0 = "01101010 00001001 11100110 01100111"
//H1 = "10111011 01100111 10101110 10000101"
//H2 = "00111100 01101110 11110011 01110010"
//H3 = "10100101 01001111 11110101 00111010"
//H4 = "01010001 00001110 01010010 01111111"
//H5 = "10011011 00000101 01101000 10001100"
//H6 = "00011111 10000011 11011001 10101011"
//H7 = "01011011 11100000 11001101 00011001"

int main(){
    string inputvalue = "hello world";
    vector<int> binList = strToBinary(inputvalue);
    int messageLength = binList.size();
    cout << messageLength << endl;
    //for (int i = 0;  i < binList.size(); i++){
    //   cout << binList[i];
    //}
    
    vector<int> proccessedBinList = preprocess(binList);

    int msgAndBufferLength = proccessedBinList.size();
    cout << msgAndBufferLength << endl;
    //for (int i = 0;  i < proccessedBinList.size(); i++){
    //   cout << proccessedBinList[i];
    // }

    compressFunction(proccessedBinList);
    
}