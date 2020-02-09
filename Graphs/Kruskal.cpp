// Kruskal algo is used to find minimum spanning tree (MST)
// Complexity of below code is O(E*logE + E*V)
// Complexity can be reduced to O(E*logE + E*logV) by using
// Union by Rank and Path compression

#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
    public:
    int source;
    int dest;
    int weight;
};

// Make this function to pass in sort function as 3rd argument
bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

// This function returns the topmost parent of any vetex
int findParent(int v, int *parent){
    if(parent[v] == v)
        return v;
    return findParent(parent[v], parent);
}

void kruskals(Edge *input, int n, int E){
    // sort input in ascending order based upon weights
    sort(input, input+E, compare);  // sort(starting iterator, end iterator)

    Edge *output = new Edge[n-1]; // bcz n-1 edges shld be in output array i.e in MST

    int *parent = new int[n];
    // Initially parents of all vertices are vertices itself
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while(count != n-1){
        // Use Union-Find Algorithm

        Edge currentEdge = input[i];

        // Check we can add currentEdge in MST or not i.e Cycle detection
        int sourceParent = findParent(currentEdge.source, parent); // Topmost parent of connected component where source is present
        int destParent = findParent(currentEdge.dest, parent);  // Topmost parent of connected component where destination is present

        if(sourceParent != destParent){
            output[count] = currentEdge; // Add edge in minimum spaning tree
            count++;

            // Union of two disconnected components
            parent[sourceParent] = destParent;  // we can also do like parent[destParent] = sourceParent
        }
        i++;
    }

    // Print the MST
    for(int i=0;i<n-1;i++){
        // smaller of source or destination is printed first
        if(output[i].source < output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }
}
int main()
{
    int n, E; // n->no. of vertices,  E-> no. of edges
    cin>>n>>E;

    Edge *input = new Edge[E];
    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input, n, E);
  return 0;
}

