#include <iostream>
using namespace std;



int main(){
    //vector<double> v = extract_column(filename, column_name);
    // put data in v
    //int rowarray[6];
    //int columnarray[6];
    //int valuearray[6];
    int rowarray[6] = {0, 0, 1, 1, 3, 3};
    int columnarray[6] = {2, 4, 2, 3, 1, 2};
    int valuearray[6] = {3, 4, 5, 7, 2, 6};
    int sparsematrix[20] = {};


    int len = 18;
    int max = sparsematrix[0];
    int *end = sparsematrix + len;

    int *ptr = sparsematrix;

    for (int n = 0; n < 6; n++){
        //int *ptr = rowarray;
        //int *ptr2 = &rowarray[2];
        //int *ptr3 = rowarray + 2; // 0x1000 + 2 spaces in memory = 0x1008
        // usually 8 bytes on a 64 bit machine
        // operators +, -, +=, -=, ++, --
        // sizeof computes the number of bytes in the array
        // can use sentinel values at the end of the array
        int rowiterator = 0;


        int coliterator = columnarray[n];

        if (rowarray[n] == 0) {
            rowiterator = 0;
        }
        else if (rowarray[n] == 1) {
            rowiterator = 6;
            coliterator = coliterator-1;
        }
        else if (rowarray[n] == 2) {
            rowiterator = 12;
            coliterator = coliterator-2;
        }
        else if (rowarray[n] == 3) {
            rowiterator = 18;
            coliterator = coliterator-3;
        }
        cout << "rowiterator = " << rowiterator << "+ coliterator = " << coliterator << endl;
        cout << "rowiterator + coliterator = " << rowiterator + coliterator << endl;

        cout << "ptr = " << *ptr << endl;

        //while (*ptr < (coliterator)) {
        //    cout << "ptr = " << *ptr << endl;
        //    sparsematrix[*ptr] = 0;
        //    cout << "sparsematrix = " << sparsematrix[*ptr] << endl;
        //    ptr++;
        //}

        //for(int *ptr = sparsematrix; ptr < end ;++ptr) {
        //if(*ptr > max) {
        //   max = *ptr;
        //}
        //cout << *ptr << endl;
        //}

        sparsematrix[coliterator + rowiterator] = valuearray[n];
        cout << "n = " << n << endl;
        cout << "rowarray = " << rowarray[n] << endl;
        cout << "columnarray = " << columnarray[n] << endl;
        cout << "valuearray = " << valuearray[n] << endl;
        cout << "sparsematrix = " << sparsematrix[n] << endl;
        
    }
    cout << "printing sparsematrix = " << endl;
    
    //while (*ptr < (len)) {
    //        cout << "ptr = " << *ptr << endl;
    //        sparsematrix[*ptr] = 0;
    //       cout << "sparsematrix = " << sparsematrix[*ptr] << endl;
    //        ptr++;
    //   }
    
    for (int i = 0; i < 20; i++){
        cout << sparsematrix[i];
        if ((i+1) % 5 == 0){
            cout << endl;
        }
    }

}