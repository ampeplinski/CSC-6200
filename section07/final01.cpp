//#include <bits/stdc++.h>
#include <bitset>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> complement(vector<int> v){
    int n = v.size();
    int i;
    for (i = n-1 ; i >= 0 ; i--){
        if(v[i] == 1){
            break;
        }
    }
    if (i == -1){
        v.insert(v.begin(),1);
        return v;
    }
    for (int n = i-1; n>= 0; n--){
        if(v[n]== 1){
            v[n]= 0;
        }else{
            v[n]= 1;
        }
    }
    while (v.size()> 32){
        v.erase(v.begin());
    }
    return v;
}

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

vector<int> decToBinary32(long long int num2){
    int binaryNum[32];
    vector<int> reversedBin;

    long long int num = abs(num2);

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
    while (reversedBin.size()> 32){
        reversedBin.erase(reversedBin.begin());
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
        int sum = a[i] + b[i] +c[i];
        int modded = sum % 2;
        //int sum2 = modded + c[i];
        //int modded2 = sum2 % 2;
        //cout << sum;
        xoringresult.push_back(modded);
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

long long int binToDecimal(vector<int> number){
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

vector<int> s1(vector<int>e){
    vector<int> rotatede_7 = rotateright(e, 6);
    vector<int> rotatede_18 = rotateright(e, 11);
    vector<int> rotatede_25 = rotateright(e, 25);
    vector<int> sigma1 = xoring(rotatede_7,rotatede_18, rotatede_25);

    return sigma1;

}

vector<int>  s0(vector<int>e){
    vector<int> rotatede_2 = rotateright(e, 2);
    vector<int> rotatede_13 = rotateright(e, 13);
    vector<int> rotatede_22 = rotateright(e, 22);
    vector<int> sigma0 = xoring(rotatede_2,rotatede_13, rotatede_22);

    return sigma0;

}

vector<int> ch(vector<int>e, vector<int>f, vector<int>g){
    vector<int> result;
    for(int i = 0; i < 32; i++){
       if(e[i]== 0){
           result.push_back(g[i]);
       }else if (e[i]== 1){
           result.push_back(f[i]);
       }
    }
    //for(int i = 0; i < 32; i++){
    //    if(e[i]== 1 && f[i] == 1){
    //       result.push_back(1);
    //       cout << "1";
    //    }else{
    //        result.push_back(0);
    //        cout<< "0";
    //       }
    
    //for(int i = 0; i < 32; i++){{
    //    if(e[i]== 0){
    //        result.push_back(g[i]);
    //    }else if (e[i]= 1){
    //        result.push_back(f[i]);
    //    }
    //}
    //}
    return result;

}
vector<int> maj(vector<int>a,vector<int>b,vector<int>c){
    vector<int> result1;
    for(int i = 0; i < 32; i++){
       if(a[i]== 1 && b[i] == 1){
          result1.push_back(1);
          //cout << "1";
       }else{
           result1.push_back(0);
           //cout<< "0";
          }
    }
    vector<int> result2;
    for(int i = 0; i < 32; i++){
       if(a[i]== 1 && c[i] == 1){
          result2.push_back(1);
          //cout << "1";
       }else{
           result2.push_back(0);
           //cout<< "0";
          }
    }
    vector<int> result3;
    for(int i = 0; i < 32; i++){
       if(b[i]== 1 && c[i] == 1){
          result3.push_back(1);
          //cout << "1";
       }else{
           result3.push_back(0);
           //cout<< "0";
          }
    }
    // cout<<"result1: ";
    // for (int i = 0;  i < result1.size(); i++){
    //   cout << result1[i];
    // }
    // cout<<endl;
    // cout<<"result2: ";
    // for (int i = 0;  i < result2.size(); i++){
    //   cout << result2[i];
    // }
    // cout<<endl;
    // cout<<"result3: ";
    // for (int i = 0;  i < result3.size(); i++){
    //   cout << result3[i];
    // }
    // cout<<endl;
    vector<int> result = xoring(result1,result2, result3);

    return result;

}

//vector<int> push_back(vector<int>){
//
//}
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
        for (int i = 16; i < 64; i++){
            
            //entryMessage.push_back(Mt);
            vector<int> sigma1ModdedResult = sigma1(entryMessage[i-2]);
            vector<int> sigma0ModdedResult = sigma0(entryMessage[i-15]);
            // cout << "w" << i-16 << ": ";
            // for (int n = 0;  n < entryMessage[i-16].size(); n++){
            //           cout << entryMessage[i-16][n];
            // }
            // cout << endl;
            long long int w_i_16_decimal = binToDecimal(entryMessage[i-16]);
            // cout << w_i_16_decimal;
            // cout << endl << "+ " << "M"<< i-15 <<endl;
            // cout << "s0: ";
            // for (int n = 0;  n < sigma0ModdedResult.size(); n++){
            //            cout << sigma0ModdedResult[n];
            // }
            // cout << endl;
            long long int s0_decimal = binToDecimal(sigma0ModdedResult);
            // cout << s0_decimal;
            // cout << endl << "+ " << endl;
            // cout << "w" << i-7 << ": ";
            // for (int n = 0;  n < entryMessage[i-7].size(); n++){
            //            cout << entryMessage[i-7][n];
            // }
            // cout << endl;
            long long int w_i_7_decimal = binToDecimal(entryMessage[i-7]);
            // cout << w_i_7_decimal;
            // cout << endl << "+ " << endl;
            // cout<<"s0: ";
            // for (int n = 0;  n < sigma1ModdedResult.size(); n++){
            //            cout << sigma1ModdedResult[n];
            // }
            // cout << endl;
            long long int s1_decimal = binToDecimal(sigma1ModdedResult);
            // cout << s1_decimal <<endl;
            // I exceeded the maximum number the integer can store
            long long int sum = w_i_16_decimal + s0_decimal + w_i_7_decimal + s1_decimal;
            // cout<< "w_i_16_decimal: "<< w_i_16_decimal << endl;
            // cout<< "s0_decimal: "<< s0_decimal << endl;
            // cout<< "w_i_7_decimal: "<< w_i_7_decimal << endl;
            // cout<< "s1_decimal: "<< s1_decimal << endl;
            //cout<< "sum: "<< sum << endl;
            vector<int> wn;
            if (0 >= sum){
                wn = decToBinary32(sum);
                wn = complement(wn);

            }else{
                wn = decToBinary32(sum);
            }
            //vector<int> addedbin = decToBinary(sum);
            //vector<int> wn = additionMod32(entryMessage[i-16], sigma0ModdedResult, entryMessage[i-7], sigma1ModdedResult);
            // cout << endl;
            cout << "w"<<i<<":";
            for (int n = 0;  n < wn.size(); n++){
                       cout << wn[n];
            }
            cout <<endl;
            entryMessage.push_back(wn);
            //vector<int> Wt = sigma1(entryMessage[i-2]) + entryMessage[i-7] + sigma0(entryMessage[i-15]) + entryMessage[i-16]
        }
        // for (int i = 0;  i < entryMessage.size(); i++){
        //         for (int n = 0;  n < entryMessage[i].size(); n++){
        //         cout << entryMessage[i][n];
        //     }
        //     cout << endl;
        //     } 
    };

    vector<int> H0 = {0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1};
    vector<int> H1 = {1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,1};
    vector<int> H2 = {0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0,1,0};
    vector<int> H3 = {1,0,1,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,1,1,0,1,0};
    vector<int> H4 = {0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,1,1,1,1,1,1};
    vector<int> H5 = {1,0,0,1,1,0,1,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,0,0,1,0,0,0,1,1,0,0};
    vector<int> H6 = {0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,0,1,0,1,0,1,1};
    vector<int> H7 = {0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,1};
    
    vector<int> a = H0;
    vector<int> b = H1;
    vector<int> c = H2;
    vector<int> d = H3;
    vector<int> e = H4;
    vector<int> f = H5;
    vector<int> g = H6;
    vector<int> h = H7;
    vector<int> k0 = {0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,1,0,0,0};
    vector<int> k1 = {0,1,1,1,0,0,0,1,0,0,1,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1};
    vector<int> k2 = {1,0,1,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1};
    vector<int> k3 = {1,1,1,0,1,0,0,1,1,0,1,1,0,1,0,1,1,1,0,1,1,0,1,1,1,0,1,0,0,1,0,1};
    vector<int> k4 = {0,0,1,1,1,0,0,1,0,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0,1,0,1,1,0,1,1};
    vector<int> k5 = {0,1,0,1,1,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,1};
    vector<int> k6 = {1,0,0,1,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0};
    vector<int> k7 = {1,0,1,0,1,0,1,1,0,0,0,1,1,1,0,0,0,1,0,1,1,1,1,0,1,1,0,1,0,1,0,1};
    vector<int> k8 = {1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,1,1,0,0,0};
    vector<int> k9 = {0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1};
    vector<int> k10 = {0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,0,1,1,0,1,1,1,1,1,0};
    vector<int> k11 = {0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1,1};
    vector<int> k12 = {0,1,1,1,0,0,1,0,1,0,1,1,1,1,1,0,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,0};
    vector<int> k13 = {1,0,0,0,0,0,0,0,1,1,0,1,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0};
    vector<int> k14 = {1,0,0,1,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1,1,1};
    vector<int> k15 = {1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,1,0,0};
    vector<int> k16 = {1,1,1,0,0,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,1,0,0,1,1,1,0,0,0,0,0,1};
    vector<int> k17 = {1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,1,1,0};
    vector<int> k18 = {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0};
    vector<int> k19 = {0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,1,1,0,0};
    vector<int> k20 = {0,0,1,0,1,1,0,1,1,1,1,0,1,0,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,1,1,1};
    vector<int> k21 = {0,1,0,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0};
    vector<int> k22 = {0,1,0,1,1,1,0,0,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,1,1,0,1,1,1,0,0};
    vector<int> k23 = {0,1,1,1,0,1,1,0,1,1,1,1,1,0,0,1,1,0,0,0,1,0,0,0,1,1,0,1,1,0,1,0};
    vector<int> k24 = {1,0,0,1,1,0,0,0,0,0,1,1,1,1,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0};
    vector<int> k25 = {1,0,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,1,1,0,1,1,0,1};
    vector<int> k26 = {1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0};
    vector<int> k27 = {1,0,1,1,1,1,1,1,0,1,0,1,1,0,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1};
    vector<int> k28 = {1,1,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,0,1,1};
    vector<int> k29 = {1,1,0,1,0,1,0,1,1,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1};
    vector<int> k30 = {0,0,0,0,0,1,1,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0,1,1,0,1,0,1,0,0,0,1};
    vector<int> k31 = {0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,1,0,0,1,1,1};
    vector<int> k32 = {0,0,1,0,0,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1};
    vector<int> k33 = {0,0,1,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0};
    vector<int> k34 = {0,1,0,0,1,1,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,0,0};
    vector<int> k35 = {0,1,0,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,0,0,1,0,0,1,1};
    vector<int> k36 = {0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,1,1,0,0,1,1,0,1,0,1,0,1,0,0};
    vector<int> k37 = {0,1,1,1,0,1,1,0,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,1,1,0,1,1};
    vector<int> k38 = {1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0};
    vector<int> k39 = {1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,0,0,0,1,0,1,1,0,0,1,0,0,0,0,1,0,1};
    vector<int> k40 = {1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1};
    vector<int> k41 = {1,0,1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,0,1,1};
    vector<int> k42 = {1,1,0,0,0,0,1,0,0,1,0,0,1,0,1,1,1,0,0,0,1,0,1,1,0,1,1,1,0,0,0,0};
    vector<int> k43 = {1,1,0,0,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,0,0,1,1,0,1,0,0,0,1,1};
    vector<int> k44 = {1,1,0,1,0,0,0,1,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,0,0,1};
    vector<int> k45 = {1,1,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,0,0};
    vector<int> k46 = {1,1,1,1,0,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,1,0,1,1,0,0,0,0,1,0,1};
    vector<int> k47 = {0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0};
    vector<int> k48 = {0,0,0,1,1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,0,1,1,0};
    vector<int> k49 = {0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,0,0,0,0,1,0,0,0};
    vector<int> k50 = {0,0,1,0,0,1,1,1,0,1,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,1,0,0,1,1,0,0};
    vector<int> k51 = {0,0,1,1,0,1,0,0,1,0,1,1,0,0,0,0,1,0,1,1,1,1,0,0,1,0,1,1,0,1,0,1};
    vector<int> k52 = {0,0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,1,0,1,1,0,0,1,1};
    vector<int> k53 = {0,1,0,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0};
    vector<int> k54 = {0,1,0,1,1,0,1,1,1,0,0,1,1,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,1,1,1,1};
    vector<int> k55 = {0,1,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1};
    vector<int> k56 = {0,1,1,1,0,1,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,1,1,1,0,1,1,1,0};
    vector<int> k57 = {0,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1};
    vector<int> k58 = {1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,1,0,0};
    vector<int> k59 = {1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0};
    vector<int> k60 = {1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0};
    vector<int> k61 = {1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,0,1,1,0,0,1,1,1,0,1,0,1,1};
    vector<int> k62 = {1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,0,1,0,0,0,1,1,1,1,1,1,0,1,1,1};
    vector<int> k63 = {1,1,0,0,0,1,1,0,0,1,1,1,0,0,0,1,0,1,1,1,1,0,0,0,1,1,1,1,0,0,1,0};
    vector<vector<int>> kn = {k0,k1,k2,k3,k4,k5,k6,
                            k7,k8,k9,k10,k11,k12,k13,
                            k14,k15,k16,k17,k18,k19,k20,
                            k21,k22,k23,k24,k25,k26,k27,
                            k28,k29,k30,k31,k32,k33,k34,
                            k35,k36,k37,k38,k39,k40,k41,
                            k42,k43,k44,k45,k46,k47,k48,
                            k49,k50,k51,k52,k53,k54,k55,
                            k56,k57,k58,k59,k60,k61,k62,
                            k63};
    for (int i = 0; i < 1; i++){
        //vector<int> tn = h + s1(e) + ch(e,f,g)+ kn[i] + entryMessage[i];
        long long int h_decimal = binToDecimal(h);
        //vector<int> hbin;
        // if (0 >= h_decimal){
        //         hbin = decToBinary32(h_decimal);
        //         hbin = complement(hbin);

        //     }else{
        //         hbin = decToBinary32(h_decimal);
        //     }
        // cout << endl<< "hbin: ";
        //     for (int n = 0;  n < hbin.size(); n++){
        //                cout << hbin[n];
        //     }
        //     cout <<endl;
        long long int s1_decimal = binToDecimal(s1(e));
        //vector<int> sibin;
        // if (0 >= s1_decimal){
        //         sibin = decToBinary32(s1_decimal);
        //         sibin = complement(sibin);

        //     }else{
        //         sibin = decToBinary32(s1_decimal);
        //     }
        // cout << endl<< "sibin: ";
        //     for (int n = 0;  n < sibin.size(); n++){
        //                cout << sibin[n];
        //     }
        //     cout <<endl;
        long long int ch_decimal = binToDecimal(ch(e,f,g));
        //vector<int> chbin;
        // if (0 >= ch_decimal){
        //         chbin = decToBinary32(ch_decimal);
        //         chbin = complement(chbin);

        //     }else{
        //         chbin = decToBinary32(ch_decimal);
        //     }
        // cout << endl<< "chbin: ";
        //     for (int n = 0;  n < chbin.size(); n++){
        //                cout << chbin[n];
        //     }
        //     cout <<endl;
        long long int kn_decimal = binToDecimal(kn[i]);
        //vector<int> knbin;
        // if (0 >= kn_decimal){
        //         knbin = decToBinary32(kn_decimal);
        //         knbin = complement(knbin);

        //     }else{
        //         knbin = decToBinary32(kn_decimal);
        //     }
        // cout << endl<< "knbin: ";
        //     for (int n = 0;  n < knbin.size(); n++){
        //                cout << knbin[n];
        //     }
        //     cout <<endl;
        long long int wn_decimal = binToDecimal(entryMessage[i]);
        //vector<int> wnbin;
        // if (0 >= wn_decimal){
        //         wnbin = decToBinary32(wn_decimal);
        //         wnbin = complement(wnbin);

        //     }else{
        //         wnbin = decToBinary32(wn_decimal);
        //     }
        // cout << endl<< "wnbin: ";
        //     for (int n = 0;  n < wnbin.size(); n++){
        //                cout << wnbin[n];
        //     }
        //     cout <<endl;
        long long int sum = h_decimal + s1_decimal + ch_decimal + kn_decimal + wn_decimal;
        vector<int> t1;
        //cout << sum;
        if (0 >= sum){
                t1 = decToBinary32(sum);
                t1 = complement(t1);

            }else{
                t1 = decToBinary32(sum);
            }
        // cout << endl<< "t"<<1<<":";
        //     for (int n = 0;  n < t1.size(); n++){
        //                cout << t1[n];
        //     }
        //     cout <<endl;
        vector<int> t2;
        long long int t2s0_decimal = binToDecimal(s0(a));
        //vector<int> t2s0bin;
        // if (0 >= t2s0_decimal){
        //         t2s0bin = decToBinary32(t2s0_decimal);
        //         t2s0bin = complement(t2s0bin);

        //     }else{
        //         t2s0bin = decToBinary32(t2s0_decimal);
        //     }
        // cout << endl<< "t2s0bin: ";
        //     for (int n = 0;  n < t2s0bin.size(); n++){
        //                cout << t2s0bin[n];
        //     }
        //     cout <<endl;
        long long int maj_decimal = binToDecimal(maj(a,b,c));
        vector<int> majbin;
        // if (0 >= maj_decimal){
        //         majbin = decToBinary32(maj_decimal);
        //         majbin = complement(majbin);

        //     }else{
        //         majbin = decToBinary32(maj_decimal);
        //     }
        // cout << endl<< "majbin: ";
        //     for (int n = 0;  n < majbin.size(); n++){
        //                cout << majbin[n];
        //     }
        //     cout <<endl;
        sum = t2s0_decimal + maj_decimal;
        //cout << sum;
        if (0 >= sum){
                t2 = decToBinary32(sum);
                t2 = complement(t2);

            }else{
                t2 = decToBinary32(sum);
            }
        // cout << endl<< "t"<<2<<":";
        //     for (int n = 0;  n < t2.size(); n++){
        //                cout << t2[n];
        //     }
        //     cout <<endl;
        h = g;
        g = f;
        long long int t1_decimal = binToDecimal(t1);
        long long int t2_decimal = binToDecimal(t2);
        long long int d_decimal = binToDecimal(d);
        e = decToBinary32(d_decimal + t1_decimal);
        cout << "e:";
        for (int n = 0;  n < e.size(); n++){
                    cout << e[n];
        }
        cout << endl;
        d = c;
        cout << "d:";
        for (int n = 0;  n < d.size(); n++){
                    cout << d[n];
        }
        cout << endl;
        c = b;
        cout << "c:";
        for (int n = 0;  n < c.size(); n++){
                    cout << c[n];
        }
        cout << endl;
        b = a;
        cout << "b:";
        for (int n = 0;  n < b.size(); n++){
                    cout << b[n];
        }
        cout <<endl;
        a = decToBinary32(t1_decimal + t2_decimal);
        cout << "a:";
        for (int n = 0;  n < a.size(); n++){
                    cout << a[n];
        }
        cout <<endl;
    }
    //return entryMessage;
}

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