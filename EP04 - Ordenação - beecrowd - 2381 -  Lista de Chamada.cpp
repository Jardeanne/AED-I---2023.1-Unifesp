#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int qtd, n;
    vector<string> ListaAlunos;
    cin>>qtd>>n;
    
    
    for(int i=0; i<qtd; i++){
        string nome;
        cin>>nome;
        ListaAlunos.push_back(nome);
    }
    
    sort(ListaAlunos.begin(), ListaAlunos.end());
    
    cout<<ListaAlunos[n-1]<<endl;
    
    return 0;
}
