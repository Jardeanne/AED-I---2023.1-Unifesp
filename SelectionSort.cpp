/* O SelectionSort percorre o array diversas vezes, buscando o menor elemento em cada itera��o 
e o colocando na sua posi��o correta. Ele faz isso a cada itera��o, ele seleciona o menor elemento 
restante no array e o coloca na sua posi��o correta. Esse processo continua at� que todo o array esteja ordenado.
*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

// Fun��o para medir o tempo atual em milissegundos
long long getTimeMillis() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

// Fun��o para imprimir o array na tela
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Fun��o para gerar um array aleat�rio de n�meros distintos
void generateRandomArray(int arr[], int n) {
    srand(time(NULL)); // Gera n�meros aleat�rios
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    random_shuffle(arr, arr + n);
}

// Fun��o para trocar dois elementos de posi��o no array
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Fun��o para ordenar o array utilizando o SelectionSort
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
    
    // Gerar um array aleat�rio de n�meros distintos
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

    // Imprimir o tempo de execu��o em milissegundos
    cout << "Tempo de execucao: " << (endTime - startTime) << " ms" << endl;

    return 0;
}