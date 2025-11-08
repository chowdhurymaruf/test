#include <iostream>
using namespace std;

void BFS(int** adj, int n, int start) {
    bool* visited = new bool[n];    
    for (int i = 0; i < n; i++) visited[i] = false;

    int* queue = new int[n];       
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;          
    cout << "BFS Traversal: ";

    while (front < rear) {          
        int u = queue[front++];     
        cout << u << " ";           

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                queue[rear++] = v;  
            }
        }
    }

    cout << endl;
    delete[] visited;
    delete[] queue;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int** adj = new int*[n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n];
    }

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    int start;
    cout << "Enter starting vertex (0 to " << n-1 << "): ";
    cin >> start;

    BFS(adj, n, start);


    for (int i = 0; i < n; i++) {
        delete[] adj[i];
    }
    delete[] adj;

    return 0;
}
