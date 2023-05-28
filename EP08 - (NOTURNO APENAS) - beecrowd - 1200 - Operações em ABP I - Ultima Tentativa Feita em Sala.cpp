/*
SUBMISSÃO # 33732806
PROBLEMA: 			1200 - Operações em ABP I
RESPOSTA: 			Presentation error (100%)
LINGUAGEM: 			C++17 (g++ 7.3.0, -std=c++17 -O2 -lm) [+0s]
TEMPO: 				0.000s
TAMANHO: 			2,38 KB
MEMÓRIA: 			-
SUBMISSÃO: 			22/05/2023 20:57:18chat
*/


#include <iostream>
#include <string>
using namespace std;

struct node {
    char chave;
    char conteudo;
    node* esq;
    node* dir;
};

typedef node* arvore;

node* Busca(arvore r, char k) {
    if (r == NULL || r->chave == k)
        return r;
    if (r->chave > k)
        return Busca(r->esq, k);
    else
        return Busca(r->dir, k);
}

arvore Insere(arvore r, node* novo) {
    node *f, *p;
    if (r == NULL) return novo;
    f = r;

    while (f != NULL) {
        p = f;
        if (f->chave > novo->chave) f = f->esq;
        else f = f->dir;
    }
    if (p->chave > novo->chave) p->esq = novo;
    else p->dir = novo;
    return r;
}

void posOrder(node* r) {
    if (r == NULL) {
        return;
    }

    posOrder(r->esq);
    posOrder(r->dir);
    if (r != NULL && (r->esq != NULL || r->dir != NULL)) cout << r->chave<< " ";
    else cout << r->chave;
        
}

void preOrder(node* r) {
    if (r == NULL) {
        return;
    }

    if (r != NULL && (r->esq != NULL || r->dir != NULL)) cout << r->chave<< " ";
    else cout << r->chave;
    preOrder(r->esq);
    preOrder(r->dir);
}

void infOrder(node* r) {
    if (r == NULL) {
        return;
    }

    infOrder(r->esq);
    if (r != NULL && (r->esq != NULL || r->dir != NULL)) cout << r->chave<< " ";
    else cout << r->chave;
    infOrder(r->dir);
}

int main() {
    arvore r = NULL;

    string N;

    while (cin >> N) {
        if (N == "I") {
            char letra;
            cin >> letra;
            node* novo = new node;
            novo->chave = letra;
            novo->conteudo = letra;
            novo->esq = NULL;
            novo->dir = NULL;
            r = Insere(r, novo);
        }
        else if (N == "P") {
            char letra;
            cin >> letra;
            node* resultado = Busca(r, letra);
            if (resultado != NULL) {
                cout << letra << " existe" << endl;
            }
            else {
                cout << letra << " nao existe" << endl;
            }
        }
        else if (N == "INFIXA") {
            infOrder(r);
            cout << endl;
        }
        else if (N == "PREFIXA") {
            preOrder(r);
            cout << endl;
        }
        else if (N == "POSFIXA") {
            posOrder(r);
            cout << endl;
        }
    }
    return 0;
}