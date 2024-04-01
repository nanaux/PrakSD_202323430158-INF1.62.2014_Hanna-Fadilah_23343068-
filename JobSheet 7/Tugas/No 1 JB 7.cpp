//created by 23343068_Hanna Fadilah
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Struktur untuk representasi graf
struct Graph {
    int V; // Jumlah simpul (vertices)
    int adj[MAX][MAX]; // Matriks adjacency
};

// Inisialisasi graf
void initGraph(struct Graph* G, int V) {
    G->V = V;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            G->adj[i][j] = 0;
        }
    }
}

// Menambahkan edge ke graf
void addEdge(struct Graph* G, int src, int dest) {
    G->adj[src][dest] = 1;
    // Untuk graf tak berarah, tambahkan juga edge dari dest ke src
    G->adj[dest][src] = 1;
}

// BFS traversal dari simpul s dalam graf
void BFS(struct Graph* G, int s) {
    bool visited[MAX] = { false }; // Array untuk menandai simpul yang sudah dikunjungi
    int queue[MAX]; // Queue untuk menyimpan simpul yang akan dikunjungi
    int front = -1, rear = -1; // Indeks untuk front dan rear queue

    visited[s] = true; // Tandai simpul awal sebagai sudah dikunjungi
    queue[++rear] = s; // Masukkan simpul awal ke queue

    while (front != rear) { // Selama queue belum kosong
        int v = queue[++front]; // Ambil simpul dari queue dan tandai sebagai dikunjungi
        printf("%d ", v);

        // Lakukan BFS untuk semua simpul yang bertetangga dengan simpul v
        for (int i = 0; i < G->V; ++i) {
            if (G->adj[v][i] && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    struct Graph G;
    int V = 6; // Jumlah simpul
    initGraph(&G, V);

    // Tambahkan edge ke graf
    addEdge(&G, 0, 1);
    addEdge(&G, 0, 2);
    addEdge(&G, 1, 3);
    addEdge(&G, 1, 4);
    addEdge(&G, 2, 4);
    addEdge(&G, 3, 5);
    addEdge(&G, 4, 5);

    printf("Hasil BFS traversal (dimulai dari simpul 0): ");
    BFS(&G, 0); // Lakukan BFS traversal dimulai dari simpul 0

    return 0;
}
