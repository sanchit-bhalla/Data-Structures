#include<iostream>
#include<climits>
using namespace std;

int findMinVertex(int *weights, bool *visited, int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex==-1 || weights[i]<weights[minVertex])){
            /* when minVertex is -1 we simply needs to come in if
               condition bcz then we don't compare as index of array
               can't be negative */
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **edges, int n){
    int *parent = new int[n];
    int *weights = new int[n];
    bool *visited = new bool[n];

    // Initially
    for(int i=0;i<n;i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    // For source
    weights[0] = 0; // Assume 0 as source
    parent[0] = -1; // Bcz. there is no parent of source

    for(int i=0;i<n-1;i++){  // n-1 bcz for last vertex no unvisited neighbour left
        int minVertex = findMinVertex(weights, visited, n);
        visited[minVertex] = true;

        // Explore all un visited neighbours of minVertex
        for(int j=0;j<n;j++){
            if(edges[minVertex][j] != 0  && !visited[j]){
                if(edges[minVertex][j] < weights[j]){
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    // Print the MST
        for(int i=1; i<n; i++){
             // i starts from 1 bcz there is no parent for source i.e 0
            // Smaller is printed first
            if(parent[i] < i)
                cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
            else
                cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
        }
}

int main()
{
    int n, E; // n->no. of vertices,  E-> no. of edges
    cin>>n>>E;

    // Create adjacency matrix
    int **edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[s][d] = w;
        edges[d][s] = w;
    }

    prims(edges, n);

    for(int i=0;i<n;i++)
        delete [] edges[i];
    delete [] edges;

  return 0;
}


