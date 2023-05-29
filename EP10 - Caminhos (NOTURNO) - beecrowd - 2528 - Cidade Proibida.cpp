#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Algoritmo de Dijkstra
int dijkstra(vector<vector<int> >& graph, int source, int destination, int forbidden) {
    int numCities = graph.size();
    vector<int> dist(numCities, INF); // Vetor de dist�ncias m�nimas
    vector<bool> visited(numCities, false); // Vetor de n�s visitados

    dist[source] = 0; // A dist�ncia para o n� de origem � zero

    for (int count = 0; count < numCities - 1; ++count) {
        int minDist = INF, minDistCity;

        // Encontra o n� com a menor dist�ncia ainda n�o visitado
        for (int i = 0; i < numCities; ++i) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                minDistCity = i;
            }
        }

        visited[minDistCity] = true; // Marca o n� como visitado

        // Atualiza as dist�ncias dos n�s adjacentes ao n� atual
        for (int i = 0; i < numCities; ++i) {
            if (!visited[i] && graph[minDistCity][i] != INF && dist[minDistCity] + graph[minDistCity][i] < dist[i]) {
                if (i != forbidden) {
                    dist[i] = dist[minDistCity] + graph[minDistCity][i];
                }
            }
        }
    }

    return dist[destination]; // Retorna a menor dist�ncia at� o n� de destino
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<vector<int> > graph(N, vector<int>(N, INF)); // Matriz de adjac�ncia do grafo

        // L� as arestas do grafo
        for (int i = 0; i < M; ++i) {
            int A, B;
            cin >> A >> B;
            graph[A - 1][B - 1] = 1; // Aresta entre os n�s A e B tem peso 1
            graph[B - 1][A - 1] = 1; // Aresta entre os n�s B e A tem peso 1
        }

        int C, R, E;
        cin >> C >> R >> E; // L� os n�s C (origem), R (destino) e E (n� proibido)

        int shortestPath = dijkstra(graph, C - 1, R - 1, E - 1); // Calcula o menor caminho
        cout << shortestPath << endl; // Imprime o menor caminho
    }

    return 0;
}
