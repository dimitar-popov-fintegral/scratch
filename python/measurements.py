import sys

##################################################
def add_conversion(graph, orig, dest, ratio):
    """make a connection to existing node else creates a new node"""

    if orig not in graph:
        graph[orig] = {}
        
    graph[orig][dest] = ratio

    if dest not in graph:
        graph[dest] = {}

    graph[dest][orig] = 1.0 / ratio

    return graph


##################################################
def get_neighbours(graph, node):
    """returns the neighbours of a given node"""
    if node not in graph:
        return None
    return graph[node].items()



##################################################
def __without_keys(dictionary, ex_keys):
    return {x: dictionary[x] for x in dictionary.keys() if x not in ex_keys}


##################################################
def get_valid_neighbours(graph, node, visited):
    """returns the neighbours which have not been visited"""
    neighbours = graph[node]
    result = __without_keys(graph[node], visited)
    return result.items()


##################################################
def get_nodes(graph):
    """get all nodes in the graph"""
    return graph.items()


##################################################
def __dfs_with_state(graph, node, end, rate_origin, visited):
    """performs dpeth first search while  keeping state i.e. via rate_origin"""
    print("[%s]" %node)
    if node == end:
        return rate_origin

    visited.add(node)

    neighbours = graph.get(node, {})
    if neighbours:
        print("my neighbours [%s]" %", ".join(neighbours.keys()))
        print("have visited [%s]" %", ".join(visited))
        for neighbour, ratio in neighbours.items():
            if neighbour not in visited:                
                print("trying [%s]" %neighbour)
                ratio = __dfs_with_state(graph, neighbour, end, rate_origin * ratio, visited)
                if ratio is not None:
                    return ratio

    print("dead end at [%s]" %node)
    return None


##################################################
def recursive_dfs(graph, origin, end):
    return __dfs_with_state(graph, origin, end, 1.0, set())


##################################################
def conduit_convert(graph, start, end):
    """convert from start -> end using conduit graph method"""
    


##################################################
def conduit_graph(graph):
    """prepares the conduit graph for search"""
    conduit = {}
    for node in graph:
        if node not in conduit:
            conduit = convert_conduit_graph(graph, node, conduit)

    return conduit


##################################################
def convert_conduit_graph(graph, origin, conduit_graph):
    """computes the 'conduit' node solution to measurement problem w/ BFS"""
    q = deque()
    q.appendleft((origin, 1.0))

    while q:
        node, rate_origin = q.pop()        
        graph[origin].update({node: rate_origin})

        adjacent = graph.get(node, {})
        if adjacent:
            for neighbour, ratio in adjacent.items():
                if neighbour not in conduit_graph:
                    q.appendleft((neighbour, ratio * rate_origin))

    return conduit_graph


##################################################
def breadth_first_search(graph, origin, end):
    """
    1  procedure BFS(G, start_v) is
    2      let Q be a queue
    3      label start_v as discovered
    4      Q.enqueue(start_v)
    5      while Q is not empty do
    6          v := Q.dequeue()
    7          if v is the goal then
    8              return v
    9          for all edges from v to w in G.adjacentEdges(v) do
    10             if w is not labeled as discovered then
    11                 label w as discovered
    12                 w.parent := v
    13                 Q.enqueue(w)
    """
    from collections import deque
    visited = set()
    visited.add(origin)

    q = deque()
    q.appendleft((origin, 1.0))


    while q:
        node, rate_origin = q.pop()
        print("[%s]" %node)

        if node == end:
            return rate_origin
        
        visited.add(nde)

        adjacent = graph.get(node, {})
        print("adjacent [%s]" %adjacent)
        if adjacent:
            for neighbour, ratio in adjacent.items():
                if neighbour not in visited:
                    q.appendleft((neighbour, ratio * rate_origin))
                    
            
    print("dead end - no path found [%s] -> [%s]" %(origin, end))
    return None



##################################################
def __generate_example():
    return [
        "foot i 12",
        "i hand 0.25",
        "i cm 2.54",
        "m cm 100",
        "km m 1000",
        "mile km 1.6",
        "mile foot 5280",
        "LY km 9.461e12"
    ]


##################################################
if __name__ == "__main__":
    graph = dict()

    for measure in __generate_example():
        orig, dest, ratio =  measure.split(' ')
        graph = add_conversion(graph, orig, dest, float(ratio))

    print(graph)

    num_units = 1
    if len(sys.argv) > 1:
        num_units = float(sys.argv[1])
        conv_from = str(sys.argv[2])
        conv_to = str(sys.argv[3])
    else:
        raise IOError("didn't specify enough command line parametes")

    for node in graph:
        print("[%s]" %node, get_neighbours(graph, node))

    """recursive depth first seearch (DFS)"""
    res = recursive_dfs(graph, conv_from, conv_to)
    if res is not None:
        out = num_units * res
    else:
        print("No conversion found - aborting")
        raise Exception("No coversion found")

    print("resulting rates = [%s]" %out)


    """iterative / queue based breadth first search (BFS)"""
    res = breadth_first_search(graph, conv_from, conv_to)
    if res is not None:
        out = num_units * res
    else:
        print("No conversion found - aborting")
        raise Exception("No coversion found")

    print("resulting rates = [%s]" %out)
    
