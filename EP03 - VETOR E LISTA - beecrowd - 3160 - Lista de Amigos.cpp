#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    string currentFriendsList;
    string newFriendsList;
    string indicatedFriend;

    // Leitura da lista atual de amigos de Luiggy
    getline(cin, currentFriendsList);

    // Leitura da nova lista de amigos de Luiggy
    getline(cin, newFriendsList);

    // Leitura do nome do amigo indicado
    getline(cin, indicatedFriend);

    // Verificação se deve indicar a nova lista para algum amigo
    if (indicatedFriend != "nao") {
        // Encontrando a posição do amigo indicado na lista atual de amigos
        int pos = currentFriendsList.find(indicatedFriend);

        // Inserindo a nova lista de amigos antes do amigo indicado
        currentFriendsList.insert(pos, newFriendsList + " ");
    } else {
        // Caso não haja indicação, os novos amigos são adicionados no fim da lista atual
        currentFriendsList += " " + newFriendsList;
    }

    // Exibindo a nova lista de amigos de Luiggy atualizada
    cout << currentFriendsList << endl;

    return 0;
}
	
