#include <iostream>
#include <string>

using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
};

Node* buildTree(string prefix, string infix) { // constroi a árvore binária com base nos prefixo e infixo
    if (prefix.empty()) {
        return NULL;
    }

    char rootValue = prefix[0];
    int rootIndex = infix.find(rootValue);

    Node* root = new Node;
    root->value = rootValue;
    root->left = buildTree(prefix.substr(1, rootIndex), infix.substr(0, rootIndex));
    /*
	prefix.substr(1, rootIndex): Esta parte pega uma substring do prefix, começando no índice 1 
	(ignorando o primeiro caractere) e com comprimento igual a rootIndex. Ou seja, estamos obtendo 
	o percurso prefixo da subárvore esquerda.
	infix.substr(0, rootIndex): Essa parte extrai uma substring do infix, começando no índice 0 
	e indo até o índice rootIndex. Aqui, estamos obtendo o percurso infixo da subárvore esquerda.
	*/
	
    root->right = buildTree(prefix.substr(rootIndex + 1), infix.substr(rootIndex + 1));
    /*
    prefix.substr(rootIndex + 1): Essa parte pega uma substring de prefix, começando no índice rootIndex + 1. 
	Ou seja, estamos obtendo o percurso prefixo da subárvore direita. Ao usar rootIndex + 1, estamos ignorando 
	o caractere da raiz e todos os elementos anteriores que já foram utilizados.
	infix.substr(rootIndex + 1): Essa parte extrai uma substring de infix, começando no índice rootIndex + 1. 
	Aqui, estamos obtendo o percurso infixo da subárvore direita. Novamente, usamos rootIndex + 1 para ignorar 
	o caractere da raiz e todos os elementos anteriores que já foram utilizados.
	*/

    return root;
}

void postOrder(Node* root) { // posfixo da árvore e imprime os valores dos nós
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->value;
}

int main() {
    int C; cin >> C; //indica o número de casos de teste

    while (C--) {
        int N; //número de nodos da árvore binária
        string prefix, infix; //descrevem o percurso prefixo e infixo, respectivamente
        cin >> N >> prefix >> infix;

        Node* root = buildTree(prefix, infix);
        postOrder(root);
        cout << endl;
    }

    return 0;
}
