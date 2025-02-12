#include <iostream>
//#include <vector>
#include <map>
#include <string>
//#include <list>
//#include <set>
#include <iterator>
using namespace std;

//       5
//     /  \
//    9    12
//   / \   /  
// 13  16 45     

int main(){
    int minHeap[6] = {5, 9, 12, 13, 16, 45};
    //map<int, string> minHeaptree;
    //["5"]= {};
    int smallest_left = 0;
    int smallest_right = 0;
    string minHeapArray[6] = {"a/5", "b/9", "c/12", "d/13", "e/16", "f,45"};
    for (int n = 0; n < 6; n++){
        int slash = minHeapArray[n].find('/');
        int selected = stoi(minHeapArray[n].substr(slash + 1));

        if (selected < smallest_left){
            smallest_left = selected;
            if (selected < smallest_right){
                smallest_left = selected;
            }
        };
        cout << "selected: " << minHeapArray[n] << endl;
        
    }
}