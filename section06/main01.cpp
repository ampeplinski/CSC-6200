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

struct binaryTreeNode {
    string value;
    int frequency;
    binaryTreeNode* llink;
    binaryTreeNode* rlink;
};

struct simpleTreeNode {
    string value;
    int frequency;
    simpleTreeNode(string v, int f) : value(v), frequency(f)
    {}
};

class binaryTree{

};

//binaryTree:binaryTree(){
//    root = NULL;
//}

//const binaryTree& binaryTree::operator=(const binaryTree& otherTree);

class bSearchTree : public binaryTree
{
    //binaryTreeNode *root;
    public:
        //bool search(const int& searchItem) const{
        //binaryTreeNode* current;
        //bool found = false;


        //if (root == NULL){
        //    cout << "cant search empty tree"<< endl; 
        //}
        //else {
        //    current = root;
        //    while ( curren is not Null and not found)
        //        if(current->info is the same as the search item)
        //            set found to true;
        //        else    
        //}
        //}
        //void bSearchTree::insert(const int& insertItem);//{
            // stuff
            //binaryTreeNode* current;
            //binaryTreeNode* tailCurrent;
            //binaryTreeNode* newNode;
            //newNode = new binaryTreeNode;
            //newNode->info = insertItem;
            //newNode->llink = NULL;
            //newNode->rlink = NULL;
            //if(root == NULL)
            //    root = newNode;
            //else{
            //    current = root;
            //}
            //return
            //};
        void deleteNode(const int& deleteItem);
            // other things
    private:
        void deleteFromTree(binaryTreeNode*& p);


};

class Node {
    Node *root;
    public: Node() : root(NULL){}
    public: string letter_number;
    Node *Left;
    Node *Right;
    

    // This works like git stash
    void push(const string& insertItem) {
        Node* current;
        Node* tailCurrent;
        Node* newNode;
        //Node *newNode = new Node();
        //nextNode->letter_number = letter_number;
        //nextNode->Left = NULL;
        //nextNode->Right = NULL;
        //if (!head){
        //    head = nextNode;
        //    return;
        // }
        // Node *iter = head;
         // while (iter->Next) {
        //    iter = iter->Next;
        //}
        //iter->Next = nextNode;
    };
    void push_right(string letter_number) {
        Node *nextNode = new Node();
        nextNode->letter_number = letter_number;
        nextNode->Left = NULL;
        nextNode->Right = NULL;
        //if (!head){
        //    head = nextNode;
        //    return;
        // }
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
int parent (int i) {
    //cout << "parent: " << (i -1)/2 << endl;
    return (i -1)/2;

};

//void swap_items(vector<simpleTreeNode> minHeap, int child, int parent){
    //vector<simpleTreeNode> temp = minHeap[child];
    //child =
//}


vector<simpleTreeNode> heapify(vector<simpleTreeNode> minHeap){
    int i = minHeap.size() - 1;
    cout << i << endl;
    //cout << minHeap[i].frequency << endl;
    //cout << minHeap[parent(i)].frequency << endl;
    cout << "next: " << endl;
    // Step 3 Compare the value of this child node with its parent
    while( i  > 0){
        // Step 4 If value of parent is more than child, then swap them.
        //cout << minHeap[i].frequency << endl;
        //cout << minHeap[parent(i)].frequency << endl;
        if (minHeap[parent(i)].frequency > minHeap[i].frequency ){
            cout <<"swaping: "<< minHeap[i].frequency;
            cout << " with: " << minHeap[parent(i)].frequency << endl;
            int parent_frequency_temp = minHeap[parent(i)].frequency;
            string parent_value_temp = minHeap[parent(i)].value;
            minHeap[parent(i)].frequency = minHeap[i].frequency;
            minHeap[parent(i)].value = minHeap[i].value;
            minHeap[i].frequency = parent_frequency_temp;
            minHeap[i].value = parent_value_temp;


        }  
        i = parent(i); 
        // Step 5 Reapeat step 3 & 4 until Heap properly holds.
    }
    return minHeap;
}

int main(){
    //int minHeap[6] = {5, 9, 12, 13, 16, 45};
    //map<int, string> minHeaptree;
    //["5"]= {};
    //string smallest_left = "z/9999";
    //string smallest_right = "z/9999";
    int new_node;
    int smallest;
    int second_smallest;

    vector<string> linkedlist = {
        {"a/5", "b/9", "c/12", "d/13", "e/16", "f/45"}
    };
    int two = 2;
    int subtract = 1;
    int sum = two - subtract;
    int divide = sum /2;
    cout << divide << endl;
    
    vector<simpleTreeNode> minHeap;
    minHeap.push_back(simpleTreeNode("a",5));
    // heapify up
    //heapify(minHeap);
    minHeap.push_back(simpleTreeNode("b",9));
    minHeap = heapify(minHeap);
    minHeap.push_back(simpleTreeNode("c",12));
    minHeap = heapify(minHeap);
    minHeap.push_back(simpleTreeNode("d",13));
    minHeap = heapify(minHeap);
    minHeap.push_back(simpleTreeNode("e",16));
    minHeap = heapify(minHeap);
    minHeap.push_back(simpleTreeNode("f",45));
    minHeap = heapify(minHeap);

    for (int n = 0; n < minHeap.size(); n++){
        cout << minHeap[n].value << "/" << minHeap[n].frequency << endl;
    }

    simpleTreeNode smallest_left = minHeap[0];
    simpleTreeNode smallest_right = minHeap[1];

    for (int n = 0; n < minHeap.size(); n++){
       cout << "selected: " << minHeap[n].frequency << endl;
    
        if (minHeap[n].frequency < smallest_left.frequency){
            smallest_left = minHeap[n];
            if (minHeap[n].frequency < smallest_right.frequency){
                smallest_right = minHeap[n];
            }
        };
    }
    cout << "Two min freq nodes: " << smallest_left.frequency << ", " << smallest_right.frequency << endl;
    int new_frequency = smallest_left.frequency + smallest_right.frequency;
    cout << "sum: " << new_frequency << endl;

    simpleTreeNode new_internal_node = simpleTreeNode("null",new_frequency);
    
    //       5
    //     /  \
    //    9    12
    //   / \   /  
    // 13  16 45 

    for (int i = 0; i < minHeap.size(); i++){
            if (minHeap[i+1].frequency > new_internal_node.frequency){
                if (minHeap[i].frequency < new_internal_node.frequency) {
                    cout << "larger: " << minHeap[i+1].frequency << " smaller: " << minHeap[i].frequency << endl;
                    cout << "i: " << i << endl;
                    minHeap.insert( minHeap.begin() + i, new_internal_node);
                    break;
                }
            }
        }

    for (int n = 0; n < minHeap.size(); n++){
        cout << minHeap[n].value << "/" << minHeap[n].frequency << endl;
    }
    
    //      12 
    //     /  \
    //    13   14
    //   / \   / \ 
    //  16 45 5   9

    //minHeap.erase(find(minHeap.begin(), minHeap.end(), smallest_left));
    //minHeap.erase(find(minHeap.begin(), minHeap.end(), smallest_right));
    
    //for (int n = 0; n < minHeap.size(); n++){
    //    cout << minHeap[n].value << "/" << minHeap[n].frequency << endl;
    //}
    //minHeap.push_back(simpleTreeNode("a",5));
    // heapify up
    //heapify(minHeap);
    //minHeap.push_back(simpleTreeNode("b",9));


    //string minHeapArray[6] = {"a/5", "b/9", "c/12", "d/13", "e/16", "f/45"};
    //for (int n = 0; n < 6; n++){
    //    int slash = linkedlist[n].find('/');
    //    int selected = stoi(linkedlist[n].substr(slash + 1));
    //    cout << "selected: " << linkedlist[n] << endl;
    //
    //     if (selected < stoi(smallest_left.substr(slash + 1))){
    //         smallest_left = linkedlist[n];
    //         continue;
    //     };
    //     if (selected < stoi(smallest_right.substr(slash + 1))){
    //             smallest_right = linkedlist[n];
    //         }
    // }
    // cout << "Two min frequ nodes: " << smallest_left << ", " << smallest_right << endl;
    // //auto itr = find(linkedlist.begin(), linkedlist.end(), smallest_left);
    // linkedlist.erase(find(linkedlist.begin(), linkedlist.end(), smallest_left));
    // linkedlist.erase(find(linkedlist.begin(), linkedlist.end(), smallest_right));
    
    // int slash = smallest_left.find('/');
    // new_node = stoi(smallest_left.substr(slash + 1)) + stoi(smallest_right.substr(slash + 1));
    // cout << "new_node: " << new_node << endl;
    // Node current = Node(); // make it not set
    // //current.push_left(smallest_left);
    // //current.push_left(smallest_right);

    

    // for (int i = 0; i < 6; i++){
    //         if (stoi(linkedlist[i+1].substr(slash + 1)) > new_node){
    //             if (stoi(linkedlist[i].substr(slash + 1)) < new_node) {
    //                 cout << "larger: " << linkedlist[i+1] << " smaller: " << linkedlist[i] << endl;
    //                 cout << "i: " << i << endl;
    //                 linkedlist.insert( linkedlist.begin() + i, to_string(new_node));
    //                 break;
    //             }
    //         }
    //     }

    // for (int z = 0; z < 6; z++){
    //     cout << linkedlist[z] << endl;
    // }

}