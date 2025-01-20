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
    void printList(){
        Element *iteration = head;
        while(iteration){
            cout << '{'<< iteration->row << ","
                       << iteration->column << ","
                       << iteration->value <<  "}" << endl;
            iteration = iteration->Next;
        }
    }
    void printMatrix(int matrixWidth, int matrixlength){
        int boolean = 0;
        for (int row = 0; row < matrixlength-1; row++){
          
            //Element *iteration = head;
            //cout << "checking row:" << row << endl; 
            
            for (int columncounter = 0; columncounter < matrixWidth; columncounter++){
                boolean = 0;
                //cout << "checking column:" << (columncounter) << endl; 
                Element *iteration = head;
                //cout << "pointer: " << iteration << endl;
                while(iteration){
                    //cout << "pointer: " << iteration << endl;
                                        
                    if (row == iteration->row){
                        //for (int column = 0; column < matrixWidth; column++){
                            //cout << "columncounter" << (columncounter) << endl;
                            
                            //cout << "datacolumn"<< iteration->column << endl;
                            if (columncounter== iteration->column){
                                cout << iteration->value <<  " ";
                                boolean = 1;
                            }
                        //}
                    
        
                    }
                    else{
                    }
                    iteration = iteration->Next;
                    
                };
                if(boolean == 0){
                    cout << "0 ";
                } 
            };
            cout << endl;
            
            //if ((i+1) % 5 == 0){
            //    cout << endl;
        }
    }
    
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

        //Element next = current;

        current.push(row, column, value);

        current.printList();
        if (continueflag == 1){
            break;
        };

        //cout << current.value << endl;



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
    int matrixSize;
    cout << "type the size of the matrix" << endl;
    cin >> matrixSize;
    int matrixlength;
    cout << "type the height of the matrix" << endl;
    cin >> matrixlength;
    current.printMatrix(matrixSize, matrixlength);

    //return &result;
    return current;
}

int main() {
    promptMatrix();
    return 0;
}