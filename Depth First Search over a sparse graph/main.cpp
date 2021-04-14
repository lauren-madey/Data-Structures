#include <iostream>
#include <fstream>
#include <list>
#include <unordered_set>
#include <vector>
#include <random>
#include <string>

using std::list;
using std::unordered_set;

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
  dfs.push_back(g);
  visited.insert(g);
      for(auto it = g->adjList.cbegin(); it != g->adjList.cend(); it++)
    {
        if(visited.find(*it) == visited.end())
        {
            dfs_search((*it), dfs, visited);
        }
    }
  
}

// DO NOT MODIFY FUNCTIONS AFTER THIS POINT
std::ostream& operator << (std::ostream& out, const std::list<Graph*> &dfs)
{
  out << "DFS order: \n";
  for(auto i = dfs.cbegin(); i!=dfs.cend(); i++)
    {
      if (i!=dfs.cbegin())
	out << ", ";
      out << (*i)->name;
    }
  out << std::endl;
  return out;
}

Graph *random_graph(int nodes)
{
  std::vector<Graph*> graph;
  for(auto i = 0;  i<nodes; i++)
    {
      graph.push_back( new Graph( std::to_string(i) ) );
    }
  
  std::default_random_engine generator;
  std::uniform_int_distribution<int> dist(0,nodes-1);

  for(auto i = 0; i<nodes; i++)
    {
      auto r = dist(generator);
      graph[i]->addEdge( graph[r] );
      if (i>0)
	       graph[i]->addEdge( graph[i-1] );
    }

  return graph[0];
}

int main()
{
  {
    Graph *a = new Graph("a");
    Graph *b = new Graph("b");
    Graph *c = new Graph("c");
    Graph *d = new Graph("d");
    Graph *e = new Graph("e");
    
    a->addEdge(b);
    a->addEdge(c);
    a->addEdge(d);
    d->addEdge(e);
    
    std::list<Graph*> dfs;
    std::unordered_set<Graph*> visited;
    
    dfs_search(a,dfs,visited);
    
    std::cout << dfs;
  }
    
  return 0;
}
