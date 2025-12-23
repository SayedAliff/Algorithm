#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void sortEdges(Edge e[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (e[j].w > e[j + 1].w) {
                Edge temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, e_count;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e_count;

    Edge edges[100];

    cout << "Enter Source, Destination and Weight for each edge:" << endl;
    for (int i = 0; i < e_count; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sortEdges(edges, e_count);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int mstWeight = 0;
    int count = 0;

    cout << "\nEdges in MST:" << endl;
    
    for (int i = 0; i < e_count; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v) {
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
            mstWeight += edges[i].w;
            unionSet(u, v);
            count++;
        }
    }

    cout << "Total Cost of MST: " << mstWeight << endl;

    return 0;
}