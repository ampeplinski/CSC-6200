#include <iostream>
#include <map>
#include <string>
using namespace std;

//{'A': {'shortest_distance_form_start': 999999999, 'previous_vertex': None},
// 'B': {'shortest_distance_form_start': 999999999, 'previous_vertex': None},
// 'E': {'shortest_distance_form_start': 999999999, 'previous_vertex': None},
// 'C': {'shortest_distance_form_start': 999999999, 'previous_vertex': None},
// 'D': {'shortest_distance_form_start': 999999999, 'previous_vertex': None}}

//{'A,B': {'starting_vertex': 'A', 'ending_vertex': 'B', 'edge_weight': '10'},
// 'B,E': {'starting_vertex': 'B', 'ending_vertex': 'E', 'edge_weight': '4'},
// 'A,E': {'starting_vertex': 'A', 'ending_vertex': 'E', 'edge_weight': '3'},
// 'E,B': {'starting_vertex': 'E', 'ending_vertex': 'B', 'edge_weight': '1'},
// 'B,C': {'starting_vertex': 'B', 'ending_vertex': 'C', 'edge_weight': '2'},
// 'E,C': {'starting_vertex': 'E', 'ending_vertex': 'C', 'edge_weight': '8'},
// 'E,D': {'starting_vertex': 'E', 'ending_vertex': 'D', 'edge_weight': '2'},
// 'C,D': {'starting_vertex': 'C', 'ending_vertex': 'D', 'edge_weight': '9'},
// 'D,C': {'starting_vertex': 'D', 'ending_vertex': 'C', 'edge_weight': '7'}}

int main(){
    std::map<std::string, std::map<std::string, string>> verticiesFormalDescription;

    verticiesFormalDescription["A,B"]["starting_vertex"] = "A";
    verticiesFormalDescription["A,B"]["ending_vertex"] = "B";
    verticiesFormalDescription["A,B"]["edge_weight"] = "10";

    verticiesFormalDescription["B,E"]["starting_vertex"] = "B";
    verticiesFormalDescription["B,E"]["ending_vertex"] = "E";
    verticiesFormalDescription["B,E"]["edge_weight"] = "4";

    verticiesFormalDescription["A,E"]["starting_vertex"] = "A";
    verticiesFormalDescription["A,E"]["ending_vertex"] = "E";
    verticiesFormalDescription["A,E"]["edge_weight"] = "3";

    verticiesFormalDescription["E,B"]["starting_vertex"] = "E";
    verticiesFormalDescription["E,B"]["ending_vertex"] = "B";
    verticiesFormalDescription["E,B"]["edge_weight"] = "1";

    verticiesFormalDescription["B,C"]["starting_vertex"] = "B";
    verticiesFormalDescription["B,C"]["ending_vertex"] = "C";
    verticiesFormalDescription["B,C"]["edge_weight"] = "2";

    verticiesFormalDescription["E,C"]["starting_vertex"] = "E";
    verticiesFormalDescription["E,C"]["ending_vertex"] = "C";
    verticiesFormalDescription["E,C"]["edge_weight"] = "8";

    verticiesFormalDescription["E,D"]["starting_vertex"] = "E";
    verticiesFormalDescription["E,D"]["ending_vertex"] = "D";
    verticiesFormalDescription["E,D"]["edge_weight"] = "2";
    
    verticiesFormalDescription["C,D"]["starting_vertex"] = "C";
    verticiesFormalDescription["C,D"]["ending_vertex"] = "D";
    verticiesFormalDescription["C,D"]["edge_weight"] = "9";

    verticiesFormalDescription["D,C"]["starting_vertex"] = "D";
    verticiesFormalDescription["D,C"]["ending_vertex"] = "C";
    verticiesFormalDescription["D,C"]["edge_weight"] = "7";

    for (const auto& edge : verticiesFormalDescription){
        cout << "edge: " << edge.first << endl;
        for (auto vertex : edge.second)
        cout << "key: " << vertex.first  << ", value: " << vertex.second << endl;
    }
    // get all info you need about an element
    string startVertexString;
    cout << "which vertex do you want to start at?: " << endl;
    cin >> startVertexString;
}