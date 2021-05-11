#include <bits/stdc++.h>
using namespace std;
  
  
class Pilha {
    queue<int> q1, q2;
    int tam;
  
public:
	//Inicializador: coloca tamanho como zero apenas
	//Função com custo O(1)
	Pilha(){
        tam = 0;
    }
  		
  	//Verifica qual das filas está sendo usada no momento para guardar os valores
  	//Função com custo O(1)
  	void empilha(int val){
  		if(q2.empty()){
  			q1.push(val);
  			//cout << "Colocou " << val << " na Fila 1" << endl;
		}
		else{
			q2.push(val);
			//cout << "Colocou " << val << " na Fila 2" << endl;
		}
		tam++;
  		
	  }
  	
  	//A função desempilha ficou com custo O(n), pois todas as vezes percorre n-1
    int desempilha(){
    	
		int i = 0; //iterador
    	int w = 0; //variável temporária para retorno
    	
    	//Verifica se existem elementos na Fila 1
    	if (!q1.empty()){
    		//Caso tenha, passe (todos elementos)-1 para a Fila 2 
    		while (i<tam-1){
				q2.push(q1.front());
				//cout << "Passando: " << q1.front() << " para Fila 2" << endl;
				q1.pop();
				i++;
			}
    					
    		//Retorne o último elemento da Fila 1 (que foi o último a ser adicionado)
    		w = q1.front();
    		//cout << "Sobrou: " << w << " na Fila 1" << endl;
    		q1.pop();
			tam--;
			return(w);	
		}
		else{
			//Se não tiver ninguém na Fila 1, vamos ver na Fila2
			if (!q2.empty()){
				//Senão faça exatamente ao contrário: Passe (todos elementos)-1 da Fila 2 para a Fila 1 e pegue o último 
    			while (i<tam-1){
    				//cout << "Passando: " << q2.front() << " para Fila 1" << endl;
					q1.push(q2.front());
					q2.pop();
					i++;
				}
    			tam--;
    			w = q2.front();
    			//cout << "Sobrou: " << w << " na Fila 2" << endl;
    			q2.pop();
    			return(w);
			}
			else{//Se não tiver ninguém nas duas pilhas, vamos avisar e sair.
				cout << "Nao tem mais ninguem na pilha." << endl;
				exit(0);
			}
			
			
		}
	}
    	
    
	//Retorna o elemento mais antigo, o que está no fundo
	//Função com custo O(1)
	int fundo(){
		int x = 0;
		if(!q1.empty()){
			x = q1.front();
			return(x);
	  	}
		x = q2.front();
		return(x);
	}
	
	//Retorna o elemento mais atual da pilha, o que está no topo
	//Função com custo O(n)... Ela funciona de forma semelhante à desempilha, porém sem retirar o elemento.
	int topo(){
		
		int i = 0; //iterador
    	int w = 0; //variável temporária para retorno
    	
    	//Verifica se existem elementos na Fila 1
    	if (!q1.empty()){
    		//Caso tenha, passe (todos elementos)-1 para a Fila 2 
    		while (i<tam-1){
				//cout << "Passando: " << q1.front() << " para Fila 2" << endl;
				q2.push(q1.front());
				q1.pop();
				i++;
			}
    					
    		//Retorne o último elemento da Fila 1 (que foi o último a ser adicionado) SEM RETIRÁ-LO e nem mexer no tamanho da pilha
    		w = q1.front();
    		
    		//Passando o último elemento para esvaziar a Fila 1
    		q2.push(q1.front());
			q1.pop();
    		
    		return(w);	
		}
		else{
			//Se não tiver ninguém na Fila 1, vamos ver na Fila2
			if (!q2.empty()){
				//Senão faça exatamente ao contrário: Passe (todos elementos)-1 da Fila 2 para a Fila 1 e pegue o último 
    			while (i<tam-1){
    				//cout << "Passando: " << q2.front() << " para Fila 1" << endl;
					q1.push(q2.front());
					q2.pop();
					i++;
				}
    			
    			w = q2.front(); //Retorne o último elemento da Fila 2 (que foi o último a ser adicionado) SEM RETIRÁ-LO e nem mexer no tamanho da pilha
    			
				//Passando o último elemento para esvaziar a Fila 2
    			q1.push(q2.front());
				q2.pop();
				
				return(w);
			}
			else{//Se não tiver ninguém nas duas pilhas, vamos avisar e sair.
				cout << "Nao tem mais ninguem na pilha." << endl;
				exit(0);
			}
			
			
		}
	}
	
		
};
		
    	
    	
int main()
{
    Pilha p;
    cout << "Empilha: 1" << endl;
    p.empilha(1);
    cout << "Empilha: 2" << endl;
    p.empilha(2);
    cout << "Empilha: 3" << endl;
    p.empilha(3);
    
    cout << "Topo: " << p.topo() << endl;//Fundo da pilha tem 3
  	cout << "Fundo: " << p.fundo() << endl;//Fundo da pilha tem 1
    
  	cout << "Desempilhou: " << p.desempilha() << endl; //Desempilha 3
  	cout << "Empilha: 4" << endl;
  	p.empilha(4);
  	cout << "Desempilhou: " << p.desempilha() << endl;
  	cout << "Topo: " << p.topo() << endl;//Fundo da pilha tem 2
  	cout << "Fundo: " << p.fundo() << endl;//Fundo da pilha tem 1
  	
  	cout << "Empilha: 5" << endl;
  	p.empilha(5);
  	cout << "Empilha: 6" << endl;
  	p.empilha(6);
  	cout << "Desempilhou: " << p.desempilha() << endl;
  	cout << "Desempilhou: " << p.desempilha() << endl;
  	cout << "Desempilhou: " << p.desempilha() << endl;
  	cout << "Desempilhou: " << p.desempilha() << endl;
  	cout << "Desempilhou: " << p.desempilha() << endl;
  	

    
    return 0;
}
