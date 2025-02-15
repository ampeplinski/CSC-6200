#include <iostream>
#include <vector>
#include <map>
#include <string>
//#include <list>
//#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

//       5
//     /  \
//    9    12
//   / \   /  
// 13  16 45    

class Node {
    Node *head;
    public: Node() : head(NULL){}
    public: string letter_number;
    Node *Left;
    Node *Right;

    // This works like git stash
    void push_left(string letter_number) {
        Node *nextNode = new Node();
        nextNode->letter_number = letter_number;
        nextNode->Left = NULL;
        nextNode->Right = NULL;
        if (!head){
            head = nextNode;
            return;
        }
        //Node *iter = head;
        //while (iter->Next) {
        //    iter = iter->Next;
        //}
        //iter->Next = nextNode;
    };
    void push_right(string letter_number) {
        Node *nextNode = new Node();
        nextNode->letter_number = letter_number;
        nextNode->Left = NULL;
        nextNode->Right = NULL;
        if (!head){
            head = nextNode;
            return;
        }
        //Node *iter = head;
        //while (iter->Next) {
        //    iter = iter->Next;
        //}
        //iter->Next = nextNode;
    };

    // this works like git stash pop
    //Element pop() {
    //return;
    //}
    
    
    
};

int main(){
    //int minHeap[6] = {5, 9, 12, 13, 16, 45};
    //map<int, string> minHeaptree;
    //["5"]= {};
    string smallest_left = "z/9999";
    string smallest_right = "z/9999";
    int new_node;
    int smallest;
    int second_smallest;

    vector<string> linkedlist = {
        {"a/5", "b/9", "c/12", "d/13", "e/16", "f/45"}
    };
    //string minHeapArray[6] = {"a/5", "b/9", "c/12", "d/13", "e/16", "f/45"};
    for (int n = 0; n < 6; n++){
        int slash = linkedlist[n].find('/');
        int selected = stoi(linkedlist[n].substr(slash + 1));
        cout << "selected: " << linkedlist[n] << endl;

        if (selected < stoi(smallest_left.substr(slash + 1))){
            smallest_left = linkedlist[n];
            continue;
        };
        if (selected < stoi(smallest_right.substr(slash + 1))){
                smallest_right = linkedlist[n];
            }
    }
    cout << "Two min frequ nodes: " << smallest_left << ", " << smallest_right << endl;
    //auto itr = find(linkedlist.begin(), linkedlist.end(), smallest_left);
    linkedlist.erase(find(linkedlist.begin(), linkedlist.end(), smallest_left));
    linkedlist.erase(find(linkedlist.begin(), linkedlist.end(), smallest_right));
    
    int slash = smallest_left.find('/');
    new_node = stoi(smallest_left.substr(slash + 1)) + stoi(smallest_right.substr(slash + 1));
    cout << "new_node: " << new_node << endl;
    Node current = Node(); // make it not set
    current.push_left(smallest_left);
    current.push_left(smallest_right);



    //for (int i = 0; i < 6; i++){
    //        if (stoi(linkedlist[i+1].substr(slash + 1)) > new_node){
    //            if (stoi(linkedlist[i].substr(slash + 1)) < new_node) {
    //                cout << "larger: " << linkedlist[i+1] << " smaller: " << linkedlist[i] << endl;
    //                cout << "i: " << i << endl;
    //                linkedlist.insert( linkedlist.begin() + i, current);
    //                break;
    //            }
    //        }
    //   }

    for (int z = 0; z < 6; z++){
        cout << linkedlist[z] << endl;
    }

}