#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    string texto, palavra="zelda";
    getline(cin,texto);
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);

    for(int i=0; i<(int)texto.size()-4; i++){
        int r=0;
        while(r<(int)palavra.size() && texto[i] == palavra[r]){
            i++;
            r++;
            if(r==(int)palavra.size()){
                cout<<"Link Bolado"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"Link Tranquilo"<<endl;
    
    return 0;
}