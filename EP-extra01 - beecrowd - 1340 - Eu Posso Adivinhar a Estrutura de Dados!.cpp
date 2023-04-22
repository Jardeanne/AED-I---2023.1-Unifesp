#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n; 
    
    // la�o que l� o tamanho da sequ�ncia a ser testada
    while (cin >> n) {
    	// define as estruturas de dados a serem checadas
        bool is_stack = true;
        bool is_queue = true;
        bool is_priority_queue = true;
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;
        
        // la�o para realizar as opera��es
        for (int i = 0; i < n; i++) {
            int operation, value;
            cin >> operation >> value;
            
            // adiciona um valor na pilha, fila e fila de prioridade
            if (operation == 1) {
                st.push(value);
                q.push(value);
                pq.push(value);
            } 
			// remover um valor da pilha, fila e fila de prioridade
			else {
				// verifica se a pilha est� vazia ou se o valor no topo da pilha � diferente do valor a ser removido
                if (st.empty() || st.top() != value) {
                    is_stack = false;
                }
                // verifica se a fila est� vazia ou se o valor no in�cio da fila � diferente do valor a ser removido
                if (q.empty() || q.front() != value) {
                    is_queue = false;
                }
                // verifica se a fila de prioridade est� vazia ou se o valor no topo da fila de prioridade � diferente do valor a ser removido
                if (pq.empty() || pq.top() != value) {
                    is_priority_queue = false;
                }
                
                // remove o elemento da pilha, fila e fila de prioridade caso n�o vazias
                if (!st.empty()) {
                    st.pop();
                }
                if (!q.empty()) {
                    q.pop();
                }
                if (!pq.empty()) {
                    pq.pop();
                }
            }
        }
        
        // cont retorna a soma dos status bool de cada estrutura de dados
        int count = is_stack + is_queue + is_priority_queue;
        // verifica se nenhuma das estruturas de dados � v�lida
        if (count == 0) {
            cout << "impossible" << endl;
        } 
		// verifica se mais de uma estrutura de dados � v�lida
		else if (count > 1) {
            cout << "not sure" << endl;
        } 
		// verifica qual estrutura de dados � v�lida
		else {
            if (is_stack) {
                cout << "stack" << endl;
            } 
			else if (is_queue) {
                cout << "queue" << endl;
            } 
			else {
                cout << "priority queue" << endl;
            }
        }
    }
    
    return 0;
}