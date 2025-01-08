#include <iostream>
#include <vector>
#include <cassert>
#include "stats01.h"
//#include "p1_library.h"
using namespace std;


// Requires: assert everything that is in here
//double test_sum_basic(){
//    std::vector<double> data = {2, 7, 11, 15};
//    double target = 9;
//    int n = 0;
//    double actual, n = sum(data, n);
//    assert(target == actual);
//    return n;
//}

int main(){
    //vector<double> v = extract_column(filename, column_name);
    // put data in v
    //vector<double> v = {2, 7, 11, 15};
    //vector<double> v = {3, 2, 4};
    vector<double> v = {3, 3, 110};
    //double target = 9;
    double target = 6;
    assert(!v.empty()); // sound the alarms!
    assert(v.size() >= 2); // sound the alarms!
    assert(v.size() <= 104); // sound the alarms!
    for (int i = 0; i < v.size(); i++){
        assert(v[i] <= 109); // sound the alarms!
        assert(v[i] >= -109); // sound the alarms!
    }

    //int test = test_sum_basic();

    for (int n = 0; n < v.size(); n++){
        int *ptr1 = &n;
        int iter1 = 0;
        int iter2 = 0;
        double s = 0;
        double *ptrs = &s;
        double *ptrtarget = &target;
        int *ptriter1 = &iter1;
        int *ptriter2 = &iter2;
        sum(v, ptr1, ptrs, ptrtarget, ptriter1, ptriter2);
        if (s == target){
            cout << "Found " << n << "with " << iter1 << "and " << iter2 << endl;
            break;
        }
        cout << s << endl;
        cout << iter1 << endl;
    }

}