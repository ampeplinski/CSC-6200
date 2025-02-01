#include <iostream>
#include <map>
#include <string>
#include <list>
#include <set>
#include <iterator>
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
    std::map<std::string, std::map<std::string, string>> edgesFormalDescription;

    edgesFormalDescription["A,B"]["starting_vertex"] = "A";
    edgesFormalDescription["A,B"]["ending_vertex"] = "B";
    edgesFormalDescription["A,B"]["edge_weight"] = "10";

    edgesFormalDescription["B,E"]["starting_vertex"] = "B";
    edgesFormalDescription["B,E"]["ending_vertex"] = "E";
    edgesFormalDescription["B,E"]["edge_weight"] = "4";

    edgesFormalDescription["A,E"]["starting_vertex"] = "A";
    edgesFormalDescription["A,E"]["ending_vertex"] = "E";
    edgesFormalDescription["A,E"]["edge_weight"] = "3";

    edgesFormalDescription["E,B"]["starting_vertex"] = "E";
    edgesFormalDescription["E,B"]["ending_vertex"] = "B";
    edgesFormalDescription["E,B"]["edge_weight"] = "1";

    edgesFormalDescription["B,C"]["starting_vertex"] = "B";
    edgesFormalDescription["B,C"]["ending_vertex"] = "C";
    edgesFormalDescription["B,C"]["edge_weight"] = "2";

    edgesFormalDescription["E,C"]["starting_vertex"] = "E";
    edgesFormalDescription["E,C"]["ending_vertex"] = "C";
    edgesFormalDescription["E,C"]["edge_weight"] = "8";

    edgesFormalDescription["E,D"]["starting_vertex"] = "E";
    edgesFormalDescription["E,D"]["ending_vertex"] = "D";
    edgesFormalDescription["E,D"]["edge_weight"] = "2";
    
    edgesFormalDescription["C,D"]["starting_vertex"] = "C";
    edgesFormalDescription["C,D"]["ending_vertex"] = "D";
    edgesFormalDescription["C,D"]["edge_weight"] = "9";

    edgesFormalDescription["D,C"]["starting_vertex"] = "D";
    edgesFormalDescription["D,C"]["ending_vertex"] = "C";
    edgesFormalDescription["D,C"]["edge_weight"] = "7";
    //verticiesFormalDescription

    map<string, int> edges;

    edges["A,B"]= 10;
    edges["B,E"]= 4;
    edges["A,E"]= 3;
    edges["E,B"]= 1;
    edges["B,C"]= 2;
    edges["E,C"]= 8;
    edges["E,D"]= 2;
    edges["C,D"]= 9;
    edges["D,C"]= 7;


    std::map<std::string, std::map<std::string, string>> verticiesFormalDescription;

    verticiesFormalDescription["A"]["shortest_distance_form_start"] = "9999999";
    verticiesFormalDescription["A"]["previous_vertex"] = "None";

    verticiesFormalDescription["B"]["shortest_distance_form_start"] = "9999999";
    verticiesFormalDescription["B"]["previous_vertex"] = "None";

    verticiesFormalDescription["C"]["shortest_distance_form_start"] = "9999999";
    verticiesFormalDescription["C"]["previous_vertex"] = "None";

    verticiesFormalDescription["D"]["shortest_distance_form_start"] = "9999999";
    verticiesFormalDescription["D"]["previous_vertex"] = "None";

    verticiesFormalDescription["E"]["shortest_distance_form_start"] = "9999999";
    verticiesFormalDescription["E"]["previous_vertex"] = "None";

    //for (const auto& edge : edgesFormalDescription){
    //    cout << "edge: " << edge.first << endl;
    //    for (auto vertex : edge.second)
    //    cout << "key: " << vertex.first  << ", value: " << vertex.second << endl;
    // }
    // get all info you need about an element
    string startVertexString;
    cout << "which vertex do you want to start at?: " << endl;
    cin >> startVertexString;

    string endVertexString;
    cout << "which vertex do you want to end at?: " << endl;
    cin >> endVertexString;

    //string unvisitedNodes[5] = {"A","B","C","D","E"};

    std::set<string> visitedNodes;
    //string visitedNodes[5] = {};

    //std::list<string> unvisitedVerticies = {"A","B","C","D","E"};

    std::map<std::string, std::map<std::string, string>> distances;
    //for (int n = 0; n < 5; n++){
    //    distances[unvisitedNodes[n]]["shortest_distance_form_start"] = "9999999";
    //}

    distances["A"]["shortest_distance_form_start"] = "9999999";
    distances["A"]["previous_vertex"] = "None";

    distances["B"]["shortest_distance_form_start"] = "9999999";
    distances["B"]["previous_vertex"] = "None";

    distances["C"]["shortest_distance_form_start"] = "9999999";
    distances["C"]["previous_vertex"] = "None";

    distances["D"]["shortest_distance_form_start"] = "9999999";
    distances["D"]["previous_vertex"] = "None";

    distances["E"]["shortest_distance_form_start"] = "9999999";
    distances["E"]["previous_vertex"] = "None";

    distances[startVertexString]["shortest_distance_form_start"] = "0";
    int previous_distance = 999999999;
    string current;
    set<string, greater<int> >:: iterator itr;
    //set<int, greater<int> > distance;

    map<string, int> distance;

    distance["A"] = 999999999;
    distance["B"] = 999999999;
    distance["C"] = 999999999;
    distance["D"] = 999999999;
    distance["E"] = 999999999;
    distance[startVertexString] = 0;
    
    map<string, std::list<string>> neighbors;

    neighbors["A"]= {"B","E"};
    neighbors["B"]= {"E","C"};
    neighbors["E"]= {"B","C","D"};
    neighbors["C"]= {"D"};
    neighbors["D"]= {"C"};

    map<string, string> previous_vertex;

    previous_vertex["A"]= {};
    previous_vertex["B"]= {};
    previous_vertex["E"]= {};
    previous_vertex["C"]= {};
    previous_vertex["D"]= {};

    previous_vertex[startVertexString] = "0";

    //start
    cout << startVertexString << "->";
    for (const auto& vertex : distance){
        //cout <<"checking:" << vertex.first << ":" << vertex.second<< endl;
        if (vertex.first == startVertexString) {

            distance["A"] = 999999999;
            distance["B"] = 999999999;
            distance["C"] = 999999999;
            distance["D"] = 999999999;
            distance["E"] = 999999999;
            distance[startVertexString] = 0;

            std::set<string> unvisitedNodes;
            if (startVertexString == "A"){
                unvisitedNodes.insert("A");
                unvisitedNodes.insert("B");
                unvisitedNodes.insert("C");
                unvisitedNodes.insert("D");
                unvisitedNodes.insert("E");
            }

            if (startVertexString == "B"){
                unvisitedNodes.insert("E");
                unvisitedNodes.insert("C");
                unvisitedNodes.insert("D");
            }

            if (startVertexString == "E"){
                unvisitedNodes.insert("B");
                unvisitedNodes.insert("C");
                unvisitedNodes.insert("D");
            }
            if (startVertexString == "C"){
                unvisitedNodes.insert("D");
            }
            if (startVertexString == "D"){
                unvisitedNodes.insert("C");
            }

            

            int tentativeDistance = 0;

            string edgeString;
            string comma = ",";

            current = startVertexString;

            while (!unvisitedNodes.empty()){
                //if (!unvisitedNodes.empty()){
                //    visitedNodes.insert(startVertexString)
                //}
                previous_distance = 999999999;
                //cout << "unvisited Nodes:";
                for (itr = unvisitedNodes.begin(); itr != unvisitedNodes.end(); itr++){
                    //cout << *itr;
                }
                //cout << endl;
                for (itr = unvisitedNodes.begin(); itr != unvisitedNodes.end(); itr++){
                    //cout << "selected: " << *itr << endl;
                    if (distance[*itr] < previous_distance){
                        //cout << "previous_distance: " << previous_distance << endl;
                        //cout << "checking: " << distance[*unvisitedNodes.begin()] << endl;
                        
                        current = *itr;
                        //cout << "current: " << current << endl;
                        previous_distance = distance[*itr];
                    }
                }
                    for (const auto& vertex : neighbors){
                        //cout << "iterating through vertex: " << vertex.first << endl;
                        if (vertex.first == current){
                            for(const string& neighbor : vertex.second){
                                //cout << "neighbor: " << neighbor << endl;
                                edgeString = current + comma + neighbor;
                                //cout << "edgeString: " << edgeString << endl;
                                tentativeDistance = distance[current] + edges[edgeString];
                                if (tentativeDistance < distance[neighbor]){
                                    distance[neighbor] = tentativeDistance;
                                        
                                }
                            }

                        }

                    }
                    //cout << "deleting :"<< current << endl;
                    unvisitedNodes.erase(current);
                    visitedNodes.insert(current);

            }
            for (itr = visitedNodes.begin(); itr != visitedNodes.end(); itr++){
                if (distance[*itr] == 0){
                }
                else if (distance[*itr] < previous_distance){
                    //cout << "previous_distance: " << previous_distance << endl;
                    //cout << "checking: " << distance[*unvisitedNodes.begin()] << endl;
                    
                    previous_vertex[*itr] = startVertexString;
                    startVertexString = *itr;
                    //cout << "step: " << *itr << endl;
                    cout << *itr << "->";
                }
            }

        }
    }
    cout << endl;
    for (const auto& vertex : previous_vertex){
        cout << vertex.first << ":" << vertex.second<< endl;
    }
    //for (itr = visitedNodes.begin(); itr != visitedNodes.end(); itr++){
    //        cout << *itr;
    //        if (endVertexString == *itr){
    //            break;
    //        } 
    //    }
        

        //for nieghbor in graph_g1.get_neighbors(current):
        //    print(f"current nieghbor: {nieghbor}")
        //
        //    tentative_distance = distances[current]["shortest_distance_form_start"] + int(graph_g1.get_edge(current, nieghbor)["edge_weight"])
        //    if tentative_distance < distances[nieghbor]["shortest_distance_form_start"]:
        //        distances[nieghbor]["shortest_distance_form_start"] = tentative_distance
        
        // cout << "selected: "<< unvisitedVerticies.front() << endl;
        //unvisitedNodes
        //std::map<std::string, string> selectedVertex = distances[unvisitedVerticies.front()];
        
        //for (const auto& unvisitedDetails : verticiesFormalDescription){
        //    std::map<std::string, string> selectedVertex = unvisitedDetails["shortest_distance_form_start"];
        
        //    if unvisitedDetails.first
        //}
        //for (const auto& vertex : verticiesFormalDescription){
        //    if (vertex.first == unvisitedVerticies.front()){
        //        cout << "vertex: " << vertex.first << endl;
        //        cout << "vertex: " << vertex.second["shortest_distance_form_start"] << endl;
        //        for (auto details : vertex.second)
        //            if (details.first == 'shortest_distance_form_start'){
        //    
        //            }
        //            cout << "key: " << details.first  << ", value: " << details.second << endl;
        //            if (details.first == 'shortest_distance_form_start'){
        //
        //            }
        //        }
        //    }

        //unvisitedVerticies.pop_front();
    //}
    //for (int n = 0; n < 5; n++){
    //   if (unvisitedNodes[n] == startVertexString){
    //        cout << "starting Vertex: " << unvisitedNodes[n] << endl;
    //    }
    // }
    //for (const auto& edge : edgesFormalDescription){
    //    cout << "edge: " << edge.first << endl;
    //}

}