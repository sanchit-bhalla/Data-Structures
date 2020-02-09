#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// DFS for a single connected component starting from sv
void printDFS(int **edges, int n, int sv, bool *visited){
    // sv is starting vertex
    cout<<sv<<" ";
    visited[sv] = 1;
    for(int i=0;i<n;i++){
        if(i==sv)
            continue;
        if(edges[sv][i] == 1){
            if(visited[i])
                continue;
            printDFS(edges, n , i, visited);
        }
    }
}

// BFS for a single connected component starting from sv
printBFS(int **edges, int n, int sv, bool *visited){
    // visited[i] = 1 when we push i in queue
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<" ";
        for(int i=0;i<n;i++){
            if(i==sv) // No need of this if condition
                continue;
            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete [] visited;
}
//=====================================================================
/* ==================  BFS and DFS for DISCONNECTED GRAPHS  ===========*/

void DFS(int ** edges, int n){
    // visited array is used so that when one element is printed that
    //will not be print again in print function
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    // For disconnected graphs we have to print all connected components
    for(int i=0;i<n;i++){
        if(!visited[i])
            printDFS(edges, n, i, visited);
    }
    delete [] visited;
}

void BFS(int **edges, int n){
    // visited array is used so that when one element is printed that
    //will not be print again in print function
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    // For disconnected graphs we have to print all connected components
    for(int i=0;i<n;i++){
        if(!visited[i])
            printBFS(edges, n, i, visited);
    }
    delete [] visited;
}
//==================================================================

// This function returns true if there is path b/w s and e
bool traverse_DFS(int **edges, int n, int s, int e, bool *visited){
//   cout<<s<<e<<endl;
    if(s==e)
        return true;

    visited[s] = true;
    for(int i=0;i<n;i++){
       // if(i==s)
         //   continue;
        if(edges[s][i] == 1){
            if(visited[i])
                continue;
            bool ans = traverse_DFS(edges, n, i, e, visited);
            // Don't simply return ans bcz there may be more than 1 ajacent of s out of which if path is not present through 1st
            // adjacent then it return false. Although it is possible that path is possible through next adjacents of s
            if(ans)
                return ans;
        }
    }
    // Now if we come out of loop it means path is not poosible from s to e
    return false;
}
bool hasPath(int **edges, int n, int s, int e){
    // s - star vertex,  e - end vertex
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    // Create new function if check path using DFS bcz if we perform recursion here visited is created for each recursive call
    // If we traverse using BFS then no need of another function. Make queue and check path in this function

    // We traverse using DFS. So we need to create a new function
    bool ans = traverse_DFS(edges, n, s, e, visited);
    delete [] visited;
    return ans;
}
//===================================================================

// Get Path - DFS
vector<int>* Path(int ** edges, int n, int v1, int v2, bool *visited){
    visited[v1] = true;

    if(v1==v2){
        vector<int>* output = new vector<int>(0);
        output->push_back(v1); // or output->push_back(v2)
        return output;
    }

    for(int i=0;i<n;i++){
        //if(i==v1)
        //    continue;
        if(edges[v1][i] == 1  && !visited[i]){
            vector<int>* output = Path(edges, n, i, v2, visited);
            if(output != NULL){
                output->push_back(v1);
                return output;
            }
        }
    }

    // If we reach here it means Path not present from v1 to v2
    return NULL;
}
vector<int>* getPath_DFS(int ** edges, int n, int v1, int v2){
    // visited array is used so that when one element is consisdered that
    //will not be consisderedt again
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    vector<int>* ans = Path(edges, n, v1, v2, visited);
    delete [] visited;
    return ans;
}
//====================================================================

// Get Path - BFS
vector<int>* getPath_BFS(int ** edges, int n, int v1, int v2){
    // visited array is used so that when one element is consisdered that
    //will not be consisderedt again
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    vector<int>* output = new vector<int>(0);
    if(v1==v2){
        output->push_back(v1);
        return output;
    }

    /* Push v1 in queue.  Then pop one by one elements from queue and insert elements in queue which are adjacent to top elemnt.
       Except v1 for every other elemnt when we push into queue also add them in map.
       Stop as we push v2 into queue. or after traversing when we find that v2 is not present or not reachable through v1
       Then using map fill the output vector and return */

    queue<int> q;
    q.push(v1);
    visited[v1] = true;
    unordered_map<int,int> mp; // key-> adjacent element we put in queue. value-> whom key is adjacent to
    int f=0;
    while(true){ // This loop runs until we add v2 in queue or after traversing we find that v2 is not present
        int cv = q.front(); // cv = currentVertex
        q.pop();
        for(int i=0;i<n;i++){
            if(i==v1)
                continue;
            if(edges[cv][i] == 1  && !visited[i]){
                q.push(i);
                visited[i] = true;
                mp[i] = cv; // Add key-value in map
                if(i==v2){
                    f=1;
                    break;
                }
            }
        }
        if(f==1 || q.empty())
            break;
    }

    if(f==1){
        output->push_back(v2);
        int t = v2;
        while(mp.count(t)>0){
            int p = mp[t];
            output->push_back(p);
            t = p;
        }
    }

    delete [] visited;
    if(f==1)
        return output;
    else
        return NULL;
}
//====================================================================

// Check graph is connected or not
void traverse_using_DFS(int **edges, int n, int s, bool *visited){
    // s - starting Vertex
    visited[s] = true;
    for(int i=0;i<n;i++){
       // if(i==s)
         //   continue;
        if(edges[s][i] == 1){
            if(visited[i])
                continue;
            traverse_using_DFS(edges, n, i, visited);
        }
    }
}

bool isConnected(int **edges, int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    // traverse using DFS
    traverse_using_DFS(edges, n, 0, visited);  // Assume starting vetex to be 0

    for(int i=0;i<n;i++){
        if(visited[i] == false) // graph is not connected
            return false;
    }
    // all vertices are visited. It means graph is connected
    return true;
}
//==================================================================

// Return Single connected component starting from sv
vector<int> SingleConnectedComponent(int **edges, int n, int sv, bool *visited, vector<int> output){
    output.push_back(sv);
    visited[sv] = true;

    for(int i=0;i<n;i++){
        if(edges[sv][i] == 1  && !visited[i])
            output = SingleConnectedComponent(edges, n, i, visited, output);
    }

    return output;
}

// Return all connected components of a graph
vector<vector<int>>* connectedComponents(int** edges, int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    vector<vector<int>> *ans = new vector<vector<int>>(0);

    for(int i=0;i<n;i++){
        if(visited[i] == false){
            vector<int> output;
            vector<int> singleConnectedComponent = SingleConnectedComponent(edges, n, i, visited, output);

            // push the output vector in (vector of vectors) ans
            ans->push_back(singleConnectedComponent);
        }
    }
    return ans;
}
//====================================================================

int main(){
    int n; // Number of vetices
    int e; // Number of edges
    cin>>n>>e; // vertices are 0 1 2 3 ... (n-1)

    // Adjacency Matrix initialized with zeros
    int **edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int s,f;
        cin>>s>>f; // s and f are two vertices which have edge between them
        //edges[i][j] = 1 means there is edge between vertex i and j
        edges[s][f] = 1;
        edges[f][s] = 1;
    }
    /*
    cout<<"DFS\n";
    DFS(edges, n);

    cout<<"\nBFS\n";
    BFS(edges, n);
    */

    /*
    int firstvertex,secondvertex;
    cin>>firstvertex>>secondvertex;
    bool path = hasPath(edges, n, firstvertex, secondvertex);
    if(path==true)
        cout<<"true";
    else
        cout<<"false";
    */


    int v1,v2;
    cin>>v1>>v2;

    vector<int>* ans = getPath_DFS(edges, n, v1, v2);
    if(ans != NULL){
        for(int i=0; i<ans->size(); i++)
            cout<<ans->at(i)<<" ";
    }
    /*
    int v1,v2;
    cin>>v1>>v2;

    vector<int>* ans = getPath_BFS(edges, n, v1, v2);
    if(ans != NULL){
        for(int i=0; i<ans->size(); i++)
            cout<<ans->at(i)<<" ";
    }
    */

    /*
    // check if graph is connected
    bool connected = isConnected(edges, n);
    if(connected)
        cout<<"true";
    else
        cout<<"false";
    */

    /*
    // Print all connected components
    vector<vector<int>> *ans = connectedComponents(edges, n);
    for(int i=0;i<ans->size(); i++){
        vector<int> temp = ans->at(i);

        // In question given that we have to print in sorted order. So sort the vector
        sort(temp.begin(), temp.end());   // for this we use #include <bits/stdc++.h>

        for(int j=0; j< temp.size(); j++){
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }
    */

    // Delete dynamically created space
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
}
