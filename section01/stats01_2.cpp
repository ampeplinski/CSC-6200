#include <iostream>
#include <vector>
#include <cassert>
#include "stats01.h"
using namespace std;

//double sum(vector<double> v);
// Doubles can take up 8 bytes
// integers can take up 4 bytes

//atomic objects known as primitive
// int double char
// pointer

// arrays( homogeneous)

// class type objets

double sum(vector<double> &v, int *n, double *s, double *target, int *iter1, int *iter2){
    cout << *n << endl;
    double sum = 0;
    double multiplier = 0;
    cout << "v.size() = " << v.size() << endl;
    for (int i = 0; i < v.size(); i++){
        if (i == *n){
            continue;
        }
        sum =v[*n] + v[i];
        cout << "v[*n] = " << v[*n] <<  " + v[i]" << v[i] << endl;
        cout << "sum = " << sum << endl;
        if (*target == sum){
            cout << "Found " << *n << "and" << i << endl;
            *s = sum;
            *iter1 = *n;
            *iter2 = i;

            break;
        }
        int multiplier = i;
    }
    return sum, n, multiplier;
}

int sum(vector<int> input, int position = 0) {
    if (position >= input.size())
        return 0;
    
    return input[position] + sum(input, position+1);
}

struct Node {
    int Item;
    Node* Next;
};

int sum(Node input) {
    if (input.Next == NULL)
        return input.Item;

    return sum(*input.Next) + input.Item;
}
