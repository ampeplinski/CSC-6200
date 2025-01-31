import typing

class Graph(object):
    def __init__(self):
        """
        Initializes a new instance of the Graph class
        """
        self._verticies_formal_description = {}

        self._edges_formal_description = {}

        self.is_finished = False
        
    def print_graph(self):
        """
        return a list of vertexts.
        """
        print(self._verticies_formal_description)
        print(self._edges_formal_description)

    def get_verticies(self):
        """
        return a list of vertexts.
        """
        return self._verticies_formal_description

    """

    def scan_for_vertex(self, desired_vertex):
        '''
        scans for vertex using a String
        '''
        for vertex_string, vertex_object in self._verticies_formal_description.items():
            print(f"checking vertex: {vertex_string}")
            #vertex_object.print_name()
            if vertex_string == desired_vertex:
                vertex_object.print_name()
                return vertex_object
    """

    
    def scan_for_edge(self, starting_vertex, ending_vertex):
        """
        scans for edge using adjacent and neighbors
        """
        for edge_string, edge_object in self._edges_formal_description.items():
            #print(f"checking edge: {edge_string}")
            #edge_object.print_edge_points()
            desired_edge = starting_vertex + " , " + ending_vertex
            if edge_string == desired_edge:
                edge_object.print_edge_points()
                
            return edge_object

    def get_neighbors(self, starting_vertex, ending_vertex):
        """
        scans for edge using adjacent and neighbors
        """
        for edge_string, edge_object in self._edges_formal_description.items():
            #print(f"checking edge: {edge_string}")
            #edge_object.print_edge_points()
            desired_edge = starting_vertex + " , " + ending_vertex
            if edge_string == desired_edge:
                edge_object.print_edge_points()
                
            return edge_object
    
    def set_vertex(self, vertex_name):
        """
        sets a vertex...
        """
        vertex_dict = { "shortest_distance_form_start" :  999999999 
                        , "previous_vertex" : None }
        self._verticies_formal_description[vertex_name] = vertex_dict

    def get_vertex(self, vertex_name):
        """
        get a vertex...
        """
        return self._verticies_formal_description[vertex_name]

    def set_edge(self, starting_vertex, ending_vertex, edge_weight):
        """
        sets a edge...
        """
        edge_dict= { "starting_vertex": starting_vertex , "ending_vertex": ending_vertex, "edge_weight": edge_weight }

        edge_string = starting_vertex + " , " + ending_vertex
        
        self._edges_formal_description[edge_string] = edge_dict

    def get_edge(self, edge_name):
        """
        get a edge...
        """
        return self._edges_formal_description[edge_name]



def main():
    graph_g1 = Graph()

    while True:
        vertex_name = input("Enter the Vertex Name: ")
        graph_g1.set_vertex(vertex)
        graph_g1.print_graph()

        has_connection = input("Enter a connection?(y/n): ")
        if has_connection == 'y':
            connected_vertex = input("Enter a connected Vertex: ")
            
            edge_weight = input("Enter an edge weight: ")
            graph_g1.set_vertex(connected_vertex)
            graph_g1.set_edge(vertex_name, connected_vertex, edge_weight)
            graph_g1.print_graph()

        loop_again = input("Enter another vertex?(y/n): ")
        if loop_again == 'n':
            break

    start_vertex_string = input("which vertex do you want to start at?: ")
    selected_starting_vertex = graph_g1.get_vertex(start_vertex_string)

    print(selected_starting_vertex)

    end_vertex_check = input("which vertex do you want to end at?: ")
    selected_ending_vertex = graph_g1.get_vertex(end_vertex_check)
    print(selected_ending_vertex)

    #selected_edge = graph_g1.scan_for_edge(start_vertex_string, end_vertex_check)
    #selected_edge.print_edge_weight()

    #def dijkstras(graph_g1, start_vertex_string):
    
    unvisited_nodes =  graph_g1.get_verticies()
    visited_nodes = {}
    distances = {}

    for vertex_string, vertex_object in unvisited_nodes.items():
            distance = vertex_object.get_distance()
            print(f"vertex string:{vertex_string} distance: {distance}")
            distances[vertex_string] = distance
    
    distances[start_vertex_string] = 0

    while unvisited_nodes:
        min_distance = 999999999
        for unvisited_node in unvisited_nodes:
            if distances[unvisited_node.get_name()] < min_distance:
                min_distance = distances[unvisited_node]
                current = unvisited_node
        
        for current_string, current_object in current.items():
            print(f"current_string: {current_string}")
            current_object.get_neighbors()
            #graph_g1.get_neighbors(current_string)


        
        #current = graph_g1.get_vertex(start)


if __name__ == "__main__":
    main()



