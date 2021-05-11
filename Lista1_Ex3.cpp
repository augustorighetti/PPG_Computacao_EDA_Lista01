#include <bits/stdc++.h>
using namespace std;
  
struct Fila_comPilhas {
    //Duas pilhas
	stack<int> s1, s2;
  
  	//Função com custo O(1)
    void enfileira(int x){
        //Coloque na pilha 1
        s1.push(x);
    }
  
    //Função com custo O(n)
    int desenfileira(){
        //Verifica se ambas pilhas estão vazias
        if (s1.empty() && s2.empty()) {
            cout << "Fila esta vazia.";
            exit(0);//Aqui optamos por sair, mas poderia ter retornado um valor pré-definido, como -1
        }
  
        //Se a Pilha 2 estiver vazia, vai tirando da 1 e acumulando na 2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
  
        //Retorna então o elemento do topo da Pilha 2
		//(que era o elemento que estava na base da Pilha 1)
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    
    //Retorna primeiro da fila
    //Função com custo O(n)
    int frente(){
    	//Se a Pilha 2 estiver vazia, vai tirando da 1 e acumulando na 2 - isso vai inverter a ordem e permitir o acesso ao primeiro item de forma fácil
    	if (s2.empty()) {
			while (!s1.empty()) {
            	s2.push(s1.top());
            	s1.pop();
            }
		}
		
		//Retorna o topo da Pilha 2, que é o elemento que entrou primeiro (em relação aos presentes)
		int x = s2.top();
    	return x;
	}
	
	
	//Retorna último da fila - ficou com custo  O(n) também...
	//No pior cenário são duas passadas em n, o que pode ser aproximado para n.
	int rear(){
		
		//Se tiver elementos na Pilha 2, coloque para a 1
		if (!s2.empty()){
			int i = 0;
			while (!s2.empty()) {
            	s1.push(s2.top());
            	s2.pop();
            	i++;
            }
            
            //Guarde o valor do topo de Pilha 1, que é o valor que estava na base de Pilha 2
			int val = s1.top();
            
            //Volte os elementos para a Pilha 2 para não desordenar
			while (i>0) {
            	s2.push(s1.top());
            	s1.pop();
            	i--;
            }
            
            return (val);
		}
		
		//Caso não tenha elementos guardados na Pilha 2, só precisa pegar o que está no topo de Pilha 1 (que foi o último a ser inserido)
		int x = s1.top();
		return x;
		
	}
    
};


int main(){
    Fila_comPilhas fila_cp;
    fila_cp.enfileira(1);
    fila_cp.enfileira(2);
    fila_cp.enfileira(3);
    fila_cp.enfileira(4);
    fila_cp.enfileira(5);
    
    cout << "Primeiro na fila: " << fila_cp.frente() << "\n";
    
  	cout << "Ultimo na fila na fila: " << fila_cp.rear() << "\n";
  	
    cout << fila_cp.desenfileira() << '\n';
    cout << fila_cp.desenfileira() << '\n';
    cout << fila_cp.desenfileira() << '\n';
    cout << fila_cp.desenfileira() << '\n';
    cout << fila_cp.desenfileira() << '\n';
    cout << fila_cp.desenfileira() << '\n';
  
    return 0;
}
