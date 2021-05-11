#include <bits/stdc++.h>
using namespace std;
  

int main(){
    
	stack<int> pilha;
    queue<int> fila;
	
	pilha.push(10);
	pilha.push(11);
	pilha.push(12);
	pilha.push(13);
	pilha.push(14);
	
	//Tira da pilha e coloca na fila até esvaziar
	while (!pilha.empty()) {
        fila.push(pilha.top());
        //cout << "Tirando da pilha " << pilha.top() << "\n";
        pilha.pop();
    }
	
	//Retorna para a pilha, já que a fila é FIFO a ordem já vai estar invertida
	while (!fila.empty()) {
        pilha.push(fila.front());
        fila.pop();
    }
    
    
	/* Apenas para testar
	
	while (!pilha.empty()) {
        cout << "Tirando da pilha (invertida) " << pilha.top() << "\n";
        
        pilha.pop();
    }
    */
     
    return 0;
}
