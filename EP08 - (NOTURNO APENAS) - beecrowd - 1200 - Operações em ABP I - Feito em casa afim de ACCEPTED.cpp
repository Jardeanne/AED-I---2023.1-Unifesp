/*
PROBLEMA: 			1200 - Operações em ABP I
RESPOSTA: 			Accepted
LINGUAGEM: 			C++17 (g++ 7.3.0, -std=c++17 -O2 -lm) [+0s]
TEMPO: 				0.000s
TAMANHO: 			2,62 KB
MEMÓRIA: 			-
SUBMISSÃO: 			28/05/2023 11:06:58
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

void posOrder(node* r, bool& first) {
    if (r == NULL) {
        return;
    }

    posOrder(r->esq, first);
    posOrder(r->dir, first);

    if (first) {
        cout << r->chave;
        first = false;
    } else {
        cout << " " << r->chave;
    }
}

void preOrder(node* r, bool& first) {
    if (r == NULL) {
        return;
    }

    if (first) {
        cout << r->chave;
        first = false;
    } else {
        cout << " " << r->chave;
    }

    preOrder(r->esq, first);
    preOrder(r->dir, first);
}

void infOrder(node* r, bool& first) {
    if (r == NULL) {
        return;
    }

    infOrder(r->esq, first);

    if (first) {
        cout << r->chave;
        first = false;
    } else {
        cout << " " << r->chave;
    }

    infOrder(r->dir, first);
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
            bool first = true;
            infOrder(r, first);
            cout << endl;
        }
        else if (N == "PREFIXA") {
            bool first = true;
            preOrder(r, first);
            cout << endl;
        }
        else if (N == "POSFIXA") {
            bool first = true;
            posOrder(r, first);
            cout << endl;
        }
    }
    return 0;
}