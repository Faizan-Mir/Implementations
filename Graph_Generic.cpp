#include <bits/stdc++.h>
using namespace std;

template<typename T>

class Graph {
 
  public:
        unordered_map<T,list<T>> adj; // here we created an adjacency list. 
        // here list is an stl data structure, which will store the nodes connected with the adj.first
        // Creating a Constructor of Graph
        Graph() {
            // blank constructor
            // array initialize, in case we use array. 
        }
        
        void add_edge(T n1, T n2, bool bidir = true){
            // adding an edge between n1 (type T) and n2 (Type T). A connection between n1 and n2. 
            // here, by default the value of bidir (Bidirectional) is true. Therefore the graph is //undirected. 
            adj[n1].push_back(n2); //adding n1 and n2 simulataneously.  
            
            if(bidir){
                adj[n2].push_back(n1); 
            }
            
        }
        
        void print(){
            for(auto row: this->adj){
                cout<<row.first<<"-->"; 
                for(T el : row.second){
                    cout<<el<<" "; 
                }
                cout<<endl; 
            }
        }
        
        
        
        
};

int main()
{
   Graph<int> g1;
   Graph<string> g2;
   
   g1.add_edge(1,2);
   g1.add_edge(3,2);
   g1.add_edge(4,2);
   g1.add_edge(1,4);
   g1.add_edge(1,3);
   
   g1.print(); 
   cout<<endl;
   
   g2.add_edge("delhi","bombay");
    g2.add_edge("delhi","Goa" );
     g2.add_edge("delhi","abc" );
      g2.add_edge("delhi","def");
       g2.add_edge("delhi","ghi");
        g2.add_edge("delhi","ijk");
        
        g2.print(); 
   
   return 0;
}




























