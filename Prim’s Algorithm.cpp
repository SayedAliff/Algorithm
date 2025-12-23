#include <iostream>
#define INF 99999
using namespace std;

int minKey(int key[], bool mstSet[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[20][20], int V) {
    cout << "\nEdge \tWeight\n";
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }
    cout << "Total Cost of MST: " << totalCost << endl;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[20][20];

    cout << "Enter the Adjacency Matrix (use 0 for no edge, or weight):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) graph[i][j] = INF; 
        }
    }

    int parent[20];
    int key[20];
    bool mstSet[20];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);

    return 0;
}