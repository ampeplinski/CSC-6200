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
    
    def scan_for_specific_vertex(self, vertexName):
        """
        scans for vertex using adjacent and neighbors
        """
        for edge in self._edges_formal_description:
            #edge.print_edge_points()
            for vertex in edge.get_edge_points():
                if str(vertex) == str(vertexName):
                    print(edge.get_edge_points())
    
    def set_vertex(self, vertex_object):
        """
        sets a vertex...
        """
        self._verticies_formal_description[vertex_object.get_name()] = vertex_object

    def get_vertex(self, vertex_name):
        """
        get a vertex...
        """
        return self._verticies_formal_description[vertex_name]

    def set_edge(self, edge_object):
        """
        sets a edge...
        """
        print(type(edge_object.get_edge_points()))
        self._edges_formal_description[edge_object] = edge_object

    def get_edge(self, edge_name):
        """
        get a edge...
        """
        return self._edges_formal_description[edge_name]





class Vertex[T](Graph):
    """
    Provides operations to interact with verticies
    """

    def __init__(self, vertexName):
        """
        Initializes a new instance of the vertex class
        """
        self._vertex_name = vertexName
        self._vertex: dict[int,int] = {}
    
    def get_name(self):
        """
        Effects: returns the vertext name
        """
        return self._vertex_name

    def print_name(self):
        """
        Effects: prints the vertext name
        """
        print(self._vertex_name)

class Edge(Graph):
    """
    Provides operations to interact with Edges
    """

    def __init__(self, starting_vertex, ending_vertex):
        """
        Initializes a new instance of the edge class
        """
        self._edge_points = { starting_vertex , ending_vertex }
        self._edge: dict[int,int] = {}
    
    def get_edge_points(self):
        """
        Effects: returns the edge verticies
        """
        return self._edge_points

    def print_edge_points(self):
        """
        Effects: prints the edge points
        """
        print(self._edge_points)




def main():
    graph_g1 = Graph()

    while True:
        vertex_name = input("Enter the Vertex Name: ")
        vertex = Vertex(vertex_name)
        vertex.print_name()
        graph_g1.set_vertex(vertex)
        graph_g1.print_graph()

        has_connection = input("Enter a connection?(y/n): ")
        if has_connection == 'y':
            connected_vertex = input("Enter a connected Vertex: ")
            edge = Edge(vertex.get_name(), connected_vertex)
            edge.print_edge_points()
            graph_g1.set_edge(edge)
            graph_g1.print_graph()

        loop_again = input("Enter another vertex?(y/n): ")
        if loop_again == 'n':
            break

    vertex_check = input("which vertex do you want to check?: ")
    selected_vertex = graph_g1.get_vertex(vertex_check)
    selected_vertex.print_name()

    graph_g1.scan_for_specific_vertex(selected_vertex.get_name())


if __name__ == "__main__":
    main()



