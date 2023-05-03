/* O HeapSort ordena por compara��o; utiliza a estrutura de dados heap para ordenar os elementos do array. 
Ele come�a construindo um heap m�ximo a partir do array desordenado e, em seguida, coloca o maior elemento 
do heap (que est� na raiz) no final do array. Ele repete esse processo com o segundo maior elemento do heap 
e assim sucessivamente at� que o array esteja completamente ordenado.
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

// Fun��o para ajustar o heap de acordo com as regras de um heap m�ximo
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Fun��o para ordenar o array utilizando o HeapSort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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

    // Ordenar o array utilizando o HeapSort
    long long startTime = getTimeMillis();
    heapSort(arr, n);
    long long endTime = getTimeMillis();

    // Imprimir o array ordenado
    cout << "Array ordenado: ";
    printArray(arr, n);

    // Imprimir o tempo de execu��o em milissegundos
    cout << "Tempo de execucao: " << (endTime - startTime) << " ms" << endl;

    return 0;
}
