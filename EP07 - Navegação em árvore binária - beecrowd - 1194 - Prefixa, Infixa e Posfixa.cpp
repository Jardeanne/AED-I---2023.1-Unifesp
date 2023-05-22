#include <iostream>
#include <string>

using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
};

Node* buildTree(string prefix, string infix) { // constroi a �rvore bin�ria com base nos prefixo e infixo
    if (prefix.empty()) {
        return NULL;
    }

    char rootValue = prefix[0];
    int rootIndex = infix.find(rootValue);

    Node* root = new Node;
    root->value = rootValue;
    root->left = buildTree(prefix.substr(1, rootIndex), infix.substr(0, rootIndex));
    /*
	prefix.substr(1, rootIndex): Esta parte pega uma substring do prefix, come�ando no �ndice 1 
	(ignorando o primeiro caractere) e com comprimento igual a rootIndex. Ou seja, estamos obtendo 
	o percurso prefixo da sub�rvore esquerda.
	infix.substr(0, rootIndex): Essa parte extrai uma substring do infix, come�ando no �ndice 0 
	e indo at� o �ndice rootIndex. Aqui, estamos obtendo o percurso infixo da sub�rvore esquerda.
	*/
	
    root->right = buildTree(prefix.substr(rootIndex + 1), infix.substr(rootIndex + 1));
    /*
    prefix.substr(rootIndex + 1): Essa parte pega uma substring de prefix, come�ando no �ndice rootIndex + 1. 
	Ou seja, estamos obtendo o percurso prefixo da sub�rvore direita. Ao usar rootIndex + 1, estamos ignorando 
	o caractere da raiz e todos os elementos anteriores que j� foram utilizados.
	infix.substr(rootIndex + 1): Essa parte extrai uma substring de infix, come�ando no �ndice rootIndex + 1. 
	Aqui, estamos obtendo o percurso infixo da sub�rvore direita. Novamente, usamos rootIndex + 1 para ignorar 
	o caractere da raiz e todos os elementos anteriores que j� foram utilizados.
	*/

    return root;
}

void postOrder(Node* root) { // posfixo da �rvore e imprime os valores dos n�s
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->value;
}

int main() {
    int C; cin >> C; //indica o n�mero de casos de teste

    while (C--) {
        int N; //n�mero de nodos da �rvore bin�ria
        string prefix, infix; //descrevem o percurso prefixo e infixo, respectivamente
        cin >> N >> prefix >> infix;

        Node* root = buildTree(prefix, infix);
        postOrder(root);
        cout << endl;
    }

    return 0;
}
