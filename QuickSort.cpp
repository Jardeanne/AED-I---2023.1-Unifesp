/* O QuickSort seleciona um elemento do array como pivô e particiona o array em duas partes, 
de forma que todos os elementos menores que o pivô fiquem antes dele e todos os elementos maiores 
que o pivô fiquem depois dele. Em seguida, ele repete esse processo recursivamente nas duas metades 
do array, até que o array esteja completamente ordenado.
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

// Função para selecionar o pivô e particionar o array em relação a ele
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função para ordenar o array utilizando o QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Ordenar o array utilizando o QuickSort
    long long startTime = getTimeMillis();
    quickSort(arr, 0, n - 1);
    long long endTime = getTimeMillis();

    // Imprimir o array ordenado
    cout << "Array ordenado: ";
    printArray(arr, n);

    // Imprimir o tempo de execução em milissegundos
    cout << "Tempo de execucao: " << (endTime - startTime) << " ms" << endl;

    return 0;
}