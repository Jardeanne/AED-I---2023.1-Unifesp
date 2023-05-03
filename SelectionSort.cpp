/* O SelectionSort percorre o array diversas vezes, buscando o menor elemento em cada iteração 
e o colocando na sua posição correta. Ele faz isso a cada iteração, ele seleciona o menor elemento 
restante no array e o coloca na sua posição correta. Esse processo continua até que todo o array esteja ordenado.
*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

// Função para medir o tempo atual em milissegundos
long long getTimeMillis() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

// Função para imprimir o array na tela
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Função para gerar um array aleatório de números distintos
void generateRandomArray(int arr[], int n) {
    srand(time(NULL)); // Gera números aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    random_shuffle(arr, arr + n);
}

// Função para trocar dois elementos de posição no array
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função para ordenar o array utilizando o SelectionSort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    
    int n; // Tamanho do array
	cout << "Digite o tamanho do array: ";
    cin>>n;
    int arr[n];
    
    // Gerar um array aleatório de números distintos
    generateRandomArray(arr, n);

    // Imprimir o array desordenado
    cout << "Array desordenado: ";
    printArray(arr, n);

    // Ordenar o array utilizando o SelectionSort
    long long startTime = getTimeMillis();
    selectionSort(arr, n);
    long long endTime = getTimeMillis();

    // Imprimir o array ordenado
    cout << "Array ordenado: ";
    printArray(arr, n);

    // Imprimir o tempo de execução em milissegundos
    cout << "Tempo de execucao: " << (endTime - startTime) << " ms" << endl;

    return 0;
}