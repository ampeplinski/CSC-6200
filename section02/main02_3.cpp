#include <iostream>

using namespace std;

class Element {
    Element *head;
    public: Element() : head(NULL){}
    
    public: int row;
    int column;
    int value;
    Element *Next;

    // This works like git stash
    void push(int row, int column, int value) {
        Element *nextElement = new Element();
        nextElement->row = row;
        nextElement->column = column;
        nextElement->value = value;
        nextElement->Next = NULL;
        if (!head){
            head = nextElement;
            return;
        }
        Element *iter = head;
        while (iter->Next) {
            iter = iter->Next;
        }
        iter->Next = nextElement;
    };

    // this works like git stash pop
    //Element pop() {
    //return;
    //}
};

void outputElements(Element input) {
    cout << "Something cool";

}

Element promptMatrix() {
    Element current = Element(); // make it not set
    //Element current = result;
    while(true/*until they want to stop*/) {
        int row;
        cout << "type a row" << endl;
        cin >> row;
        //current.row = row;
        // get all info you need about an element
        int column;
        cout << "type a column" << endl;
        cin >> column;
        //current.column = column;
        int value;
        cout << "type a value" << endl;
        cin >> value;
        //current.value = value; 

        int continueflag;
        cout << "type a 0 for continue and 1 to stop" << endl;
        cin >> continueflag;

        if (continueflag == 1){
            break;
        };



        //Element next = current;

        current.push(row, column, value);

        cout << current.value << endl;



        //Element next = current;
        //if (next.row != NULL) {
            //next.Next = Element{};
            //next = next.Next;
        //}

        // Take all info from the CIN stuff and put it into next

        //if (current == NULL) // instead of this, check to see if the element result is not set
        //    current = next;
        //else
        //    current.Next = next
    }

    //return &result;
    return current;
}

int main() {
    return 0;
}