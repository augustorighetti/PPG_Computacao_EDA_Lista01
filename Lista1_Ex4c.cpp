#include <bits/stdc++.h>
using namespace std;

//Passa os valores de pilha para pilha2 -sem inverter a ordem-
void passa(stack<int> &pilha, stack<int> &pilha2){
    if(pilha.empty()){
        return;
    }
    
    //Guarda o valor do topo
    int x = pilha.top();
    pilha.pop();
    
    //Chama a si mesma com a pilha já sem o valor do topo
    passa(pilha,pilha2);
    
    //Depois que volta da recursão vai guardando os valores na pilha2
    pilha2.push(x);
}


void inverte(stack<int> &pilha, stack<int> &pilha2) {
    
    //Passa os valores para pilha 2 SEM IVERTER A ORDEM 
    passa(pilha,pilha2);
    
    //Passa para a pilha (Agora sim, invertendo a ordem, já que são duas pilhas)
    while (!pilha2.empty()) {
        pilha.push(pilha2.top());
        pilha2.pop();
    }
}


int main(){
	stack<int> pilha, pilha2;
	
	pilha.push(10);
	pilha.push(11);
	pilha.push(12);
	pilha.push(13);
	pilha.push(14);
	
	inverte(pilha, pilha2);
	
	
	/* Apenas para testar
	
	while (!pilha.empty()) {
        cout << "Tirando da pilha (invertida) " << pilha.top() << "\n";
        
        pilha.pop();
    }
    */
	
	return 0;
}
