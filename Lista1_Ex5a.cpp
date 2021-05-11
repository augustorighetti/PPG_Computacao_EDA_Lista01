#include <bits/stdc++.h>
using namespace std;
  

int main(){
    
	stack<int> pilha;
    queue<int> fila;
	
	
	fila.push(10);
	fila.push(11);
	fila.push(12);
	fila.push(13);
	fila.push(14);
	
	
	//Esvazia a fila na pilha
	while (!fila.empty()) {
        pilha.push(fila.front());
        fila.pop();
    }
    
    //Tira da pilha e coloca na fila de volta
	//(a ordem vai estar invertida por conta de como as estruturas funcionam: Fila é FIFO, lista é LIFO)
	while (!pilha.empty()) {
        fila.push(pilha.top());
        pilha.pop();
    }
	     
    return 0;
}
