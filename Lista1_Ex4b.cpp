#include <bits/stdc++.h>
using namespace std;
  

int main(){
    
	stack<int> pilha, pilha2, pilha3;
    queue<int> fila;
	
	pilha.push(10);
	pilha.push(11);
	pilha.push(12);
	pilha.push(13);
	pilha.push(14);
	
	//Tira da pilha e coloca na pilha2 (inverte a ordem dos elementos)
	while (!pilha.empty()) {
        pilha2.push(pilha.top());
        
        pilha.pop();
    }
	
	//Tira da pilha2 e coloca na pilha3 (retorna à ordem original)
	while (!pilha2.empty()) {
        pilha3.push(pilha2.top());
        
        pilha2.pop();
    }
    
    //Tira da pilha3 e coloca na pilha (inverte a ordem novamente, mas desta vez passando para a pilha original)
	while (!pilha3.empty()) {
        pilha.push(pilha3.top());
        
        pilha3.pop();
    }
    
    
	while (!pilha.empty()) {
        
        cout << "Tirando da pilha " << pilha.top() << "\n";
        pilha.pop();
    }
     
    return 0;
}
