#include <bits/stdc++.h>
 
using namespace std;
 
struct No{
    int valor; 	// Só usamos um inteiro aqui, mas podemos usar um Struct para ter vários atributos "organizados" em um mesmo nó
	No *prox;
    
	//Inicializador
	static No* novoNo(int valorP){
        No* novo = (No*)malloc(sizeof(No));
        novo->valor = valorP;
        novo->prox = NULL;
        return novo;
    }
};

//Pilha que possui os métodos empilha, desempilha e topo com custo O(1).
//Além disso fornece uma função que retorna o valor mínimo que está na lista também com custo O(1).
class PilhaMin{
    No* topo;
    No* minimo;
    int tamanho;
 
public:
    //Instanciador/Inicializador
	PilhaMin(){
        topo = minimo = NULL;
        tamanho = 0;
    }
 
    // Operações básicas de pilha
    int getTopo();
    void empilha(int val);
    int desempilha();
    int obterMinimo();
    
};

//Custo O(1)
int PilhaMin::getTopo(){
	// Verifica se a lista está vazia
	if (topo == NULL)
	    cout << "Não tem mais elementos...\n";
	
	else{
		return topo->valor;
	}
	
}


//Custo O(1)
void PilhaMin::empilha(int val){
	No* novo = No::novoNo(val);
	
	//Testa se o novo elemento consegue ser criado, se não foi criado retorna mensagem de overflow
	if (novo == NULL)
    	cout << "Overflow\n";
    else{
    	//Se for o primeiro uso da estrutura
    	if (topo == NULL)
    		//O topo e mínimo recebem o elemento inserido
        	topo = minimo = novo;
    	else{
    		//Se o valor for menor que o mínimo atual guarde o ponteiro novo
    		if (val < minimo->valor){
    			minimo = novo;
			}
    		
			//O topo se torna o próximo do novo e o novo se torna o topo 
    		novo->prox = topo;
			topo = novo;
    	}
	}
	
}

//Custo O(1)
int PilhaMin::desempilha(){
	// Verifica se a lista já está vazia
	if (topo == NULL)
	    cout << "Não tem mais elementos para tirar!\n";
	
	else{
		//Guarda o valor que está no topo antes de começar a mexer
		int valorInicio = topo->valor;
		
		//Topo avança uma casa (o que era seu prox)
	    No* temp = topo; //Guarda o endereço do que está no inicio
	    topo = topo->prox; 
	
	    free(temp); //Libera o antigo inicio
	    
	    return(valorInicio);
	}
	
}

//Custo O(1)
int PilhaMin::obterMinimo(){
	// Verifica se a lista está vazia
	if (topo == NULL)
	    cout << "Não tem mais elementos...\n";
	
	else{
		return minimo->valor;
	}
	
}


		

int main(){
    PilhaMin pmin;
    cout << "Empilha valor 60.\n";
    pmin.empilha(60);
 
    cout << "Empilha valor 32.\n";
    pmin.empilha(32);
 
    cout << "O elemento que está no topo: " << pmin.getTopo() << endl;
 
    pmin.desempilha();
    cout << "Depois de remover o elemento do topo, quem está no topo é:" << pmin.getTopo() << endl;
 
    cout << "Empilha valor 4.\n";
    pmin.empilha(4);
 
    cout << "O elemento que está no topo: " << pmin.getTopo() << endl;
 
    pmin.desempilha();
    cout << "Depois de remover o elemento do topo, quem está no topo é:" << pmin.getTopo() << endl;
    
    pmin.desempilha();//Remove 60
    
    pmin.desempilha();//Tenta remover, mas a pilha não tem mais elementos
    return 0;
}
