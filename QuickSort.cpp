/* O QuickSort seleciona um elemento do array como piv� e particiona o array em duas partes, 
de forma que todos os elementos menores que o piv� fiquem antes dele e todos os elementos maiores 
que o piv� fiquem depois dele. Em seguida, ele repete esse processo recursivamente nas duas metades 
do array, at� que o array esteja completamente ordenado.
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

// Fun��o para selecionar o piv� e particionar o array em rela��o a ele
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

// Fun��o para ordenar o array utilizando o QuickSort
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
    
    // Gerar um array aleat�rio de n�meros distintos
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

    // Imprimir o tempo de execu��o em milissegundos
    cout << "Tempo de execucao: " << (endTime - startTime) << " ms" << endl;

    return 0;
}