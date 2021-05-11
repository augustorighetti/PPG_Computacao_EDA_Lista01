#include <bits/stdc++.h>
 
using namespace std;
 
struct No{
    int valor; 	// S� usamos um inteiro aqui, mas podemos usar um Struct para ter v�rios atributos "organizados" em um mesmo n�
	No *prox;
    
	//Inicializador
	static No* novoNo(int valorP){
        No* novo = (No*)malloc(sizeof(No));
        novo->valor = valorP;
        novo->prox = NULL;
        return novo;
    }
};

//Pilha que possui os m�todos empilha, desempilha e topo com custo O(1).
//Al�m disso fornece uma fun��o que retorna o valor m�nimo que est� na lista tamb�m com custo O(1).
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
 
    // Opera��es b�sicas de pilha
    int getTopo();
    void empilha(int val);
    int desempilha();
    int obterMinimo();
    
};

//Custo O(1)
int PilhaMin::getTopo(){
	// Verifica se a lista est� vazia
	if (topo == NULL)
	    cout << "N�o tem mais elementos...\n";
	
	else{
		return topo->valor;
	}
	
}


//Custo O(1)
void PilhaMin::empilha(int val){
	No* novo = No::novoNo(val);
	
	//Testa se o novo elemento consegue ser criado, se n�o foi criado retorna mensagem de overflow
	if (novo == NULL)
    	cout << "Overflow\n";
    else{
    	//Se for o primeiro uso da estrutura
    	if (topo == NULL)
    		//O topo e m�nimo recebem o elemento inserido
        	topo = minimo = novo;
    	else{
    		//Se o valor for menor que o m�nimo atual guarde o ponteiro novo
    		if (val < minimo->valor){
    			minimo = novo;
			}
    		
			//O topo se torna o pr�ximo do novo e o novo se torna o topo 
    		novo->prox = topo;
			topo = novo;
    	}
	}
	
}

//Custo O(1)
int PilhaMin::desempilha(){
	// Verifica se a lista j� est� vazia
	if (topo == NULL)
	    cout << "N�o tem mais elementos para tirar!\n";
	
	else{
		//Guarda o valor que est� no topo antes de come�ar a mexer
		int valorInicio = topo->valor;
		
		//Topo avan�a uma casa (o que era seu prox)
	    No* temp = topo; //Guarda o endere�o do que est� no inicio
	    topo = topo->prox; 
	
	    free(temp); //Libera o antigo inicio
	    
	    return(valorInicio);
	}
	
}

//Custo O(1)
int PilhaMin::obterMinimo(){
	// Verifica se a lista est� vazia
	if (topo == NULL)
	    cout << "N�o tem mais elementos...\n";
	
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
 
    cout << "O elemento que est� no topo: " << pmin.getTopo() << endl;
 
    pmin.desempilha();
    cout << "Depois de remover o elemento do topo, quem est� no topo �:" << pmin.getTopo() << endl;
 
    cout << "Empilha valor 4.\n";
    pmin.empilha(4);
 
    cout << "O elemento que est� no topo: " << pmin.getTopo() << endl;
 
    pmin.desempilha();
    cout << "Depois de remover o elemento do topo, quem est� no topo �:" << pmin.getTopo() << endl;
    
    pmin.desempilha();//Remove 60
    
    pmin.desempilha();//Tenta remover, mas a pilha n�o tem mais elementos
    return 0;
}
