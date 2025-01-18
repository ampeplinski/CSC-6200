#include <iostream>
#include <vector>
using namespace std;

//test

int main(){
    //int element01[4];
    //int element02[4];
    //int element03[4];
    //int element04[4];
    //int element05[4];
    //int element06[4];

    struct list06 {
        int element06[3] = {3, 2, 6};
    };

    struct list06 g;

    struct list05 {
        int element05[3] = {3, 1, 2};
        struct list06 *ptr06;
    };

    struct list05 g2;

    struct list04 {
        int element04[3] = {3, 1, 2};
        struct list05 *ptr05;

    };

    cout << "element06 = " << *g.element06 << endl;
    cout << "list05 = " << *g2.element05 << endl;
    cout << "list05 = " << &g2.ptr06 << endl;
    cout << "ptr = " << g2.ptr06 << endl;

    vector<vector<int>> linkedlist = {
        {0, 2, 3, 0},
        {0, 4, 4, 0},
        {1, 2, 5, 0},
        {1, 3, 7, 0},
        {3, 1, 2, 0},
        {3, 2, 6, 0}
    };
    cout << "linkedlist = " << linkedlist[0][1] << endl;

    for (int n = 0; n < 6; n++){
        cout << linkedlist[n][1];
        if ((n+1) % 5 == 0){
            cout << endl;
        }
        cout << "linkedlist = " << linkedlist[n][1] << endl;
     }

    // int elements[25] = {0, 2, 3, 0, 0, 4, 4, 0, 1, 2, 5, 0, 1, 3, 7, 0, 3, 1, 2, 0, 3, 2, 6, 0};

    // int element01[4] = {0, 2, 3, 0};
    // int element02[4] = {0, 4, 4, 0};
    // int element03[4] = {1, 2, 5, 0};
    // int element04[4] = {1, 3, 7, 0};
    // int element05[4] = {3, 1, 2, 0};
    // int element06[4] = {3, 2, 6, 0};

    // int *ptr02 =element02;
    // int *ptr03 =element03;
    // int *ptr04 =element04;
    // int *ptr05 =element05;
    // int *ptr06 =element06;
    // int *ptr07 =element06;

    // element06[4] = ptr02;
    // ptr03 =element03;
    // ptr04 =element04;
    // ptr05 =element05;
    // ptr06 =element06;
    // element06[4] = ptr07;

    int sparsematrix[19] = {};


    int len = 18;
    int max = sparsematrix[0];
    int *end = sparsematrix + len;

    int *ptr = sparsematrix;

    // for (int n = 0; n < 6; n++){
    //     cout << "element01 = " << element01 << endl;
    //     cout << "ptr02 = " << &ptr02 << endl;
    // }

}