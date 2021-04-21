## 11.14 Depth First Search over a sparse graph.

Implement a recursive depth-first search using the definition for a Graph node below.

```
// DO NOT MODIFY GRAPH NODE DEFINITION
class Graph {
  // This class represents a single node

public:
  std::string name;     // name of the node

  list<Graph*> adjList; // adjacency list for the node

  using iterator = list<Graph*>;  

  // constructor requires a name, so that we can print out the
  // nodes by name.
  Graph(std::string n, list<Graph*> adj={}):name(n),adjList(adj) {}

  // Add an edge to adjacency list; add to both nodes
  void addEdge(Graph *g)
  {
    adjList.push_back(g);
    g->adjList.push_back(this);
  }  
};
```

Note, Graph represents a single node of the graph, not the entire Graph as we did in class. That means there's no object that knows about the entire graph. You have to discover the graph by traversing adjacent edges. We will use a hash table to track which nodes have been visited rather than a visited array.

The implementation must be a recursive function. The arguments to the function are passed as references to allow you to pass them recursively and keep them updated without worrying about making copies. The argument Graph *g is the start node for the traversal.

```
// DO NOT MODIFY FUNCTION ARGUMENTS OR RETURN TYPE
// dfs_search:
//    Graph *g          : a pointer to the node where you should begin DFS
//    list<Graph*> &dfs : list of visited nodes; append to this list
//                        as you traverse.  Use push_back() member function.
//    unordered_set<Graph*> &visited:
//                        this is basically a hash table provided by the std library.
//                        Use insert(g) member function to add to it. Use find()
//                        member function to search if a node has been visited.
//
//    You must implement this as a recursive function.
void dfs_search(Graph *g, std::list<Graph*> &dfs, std::unordered_set<Graph*> &visited)
{
  // IMPLEMENT AS RECURSIVE FUNCTION
}
```

The unordered_set<Graph> is basically a hash table that tracks Graph. To test if a node is inside this set, you need to use the find function and compare it against an iterator. For example, to test if node g (Graph*) is in the visited set, you might do it like this:

```
Graph *g = ...;
if ( visited.find(g) != visited.end() )
   return ;  // found the node
```

To iterate over the adjacency list, do it like this:

```
for(auto i = g->adjList.begin(); i!=g->adjList.end(); i++)
{
   Graph * adj = *i; // get adjacent node
}
```
