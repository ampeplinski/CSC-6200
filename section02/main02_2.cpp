#include <iostream>

using namespace std;

class Element {
    int row;
    int column;
    int data;

    // This works like git stash
    void push(Element e) {

    };

    // this works like git stash pop
    Element pop() {

    }
};

void outputElements(Element input) {
    cout << "Something cool";

}

Element promptMatrix() {
    Element result = Element{}; // make it not set
    Element current = result;
    while(/*until they want to stop*/) {
        int row;
        cout << "Some Insttuctions" << endl;
        cin >> row;
        // get all info you need about an element

        Element next = current;
        if (next.item != NULL) {
            next.Next = Element{};
            next = next.Next;
        }

        // Take all info from the CIN stuff and put it into next

        if (current == NULL) // instead of this, check to see if the element result is not set
            current = next;
        else
            current.Next = next
    }

    return &result;
}

int main() {
    return 0;
}