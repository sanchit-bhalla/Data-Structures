#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *distance, bool *visited, int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex==-1 || distance[i]<distance[minVertex])){
            /* when minVertex is -1 we simply needs to come in if
               condition bcz then we don't compare as index of array
               can't be negative */
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int **edges, int n){
    int *distance = new int[n];
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    // Assume 0 as source
    distance[0] = 0;

    for(int i=0;i<n-1;i++){ // n-1 bcz for last vertex no unvisited neighbour left
        int minVertex = findMinVertex(distance, visited, n);
        visited[minVertex] = true;

        // Explore all unvisited neighbours of minVertex
        for(int j=0;j<n;j++){
            if(edges[minVertex][j] != 0  &&  !visited[j]){
                int dist = distance[minVertex] + edges[minVertex][j];
                if(dist < distance[j])
                    distance[j] = dist;
            }
        }
    }

    // Print shotest distance from source i.e 0 to all vertices
    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete [] distance;
    delete [] visited;
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

    dijkstra(edges, n);

    for(int i=0;i<n;i++)
        delete [] edges[i];
    delete [] edges;

  return 0;
}
