#include <bits/stdc++.h>
 
using namespace std;
 
struct No{
    int valor; 	// S� usamos um inteiro aqui, mas podemos usar um Struct para ter v�rios atributos "organizados" em um mesmo n�
	No *ant, *prox; //Duplamente encadeada
    
	//Inicializador
	static No* novoNo(int valorP){
        No* novo = (No*)malloc(sizeof(No));
        novo->valor = valorP;
        novo->ant = novo->prox = NULL;
        return novo;
    }
};

class Deque{
    No* inicio;
    No* fim;
    int tamanho;
 
public:
    //Instanciador/Inicializador
	Deque(){
        inicio = fim = NULL;
        tamanho = 0;
    }
 
    // Opera��es
    void insereInicio(int valor);
    void insereFim(int valor);
    int removeInicio();
    int removeFim();
    int getInicio();
    int getFim();
    
};

//Fun��o com custo O(1)
void Deque::insereInicio(int valor){
	No* novo = No::novoNo(valor);
	
	//Testa se o novo elemento n�o conseguir ser criado
	//se n�o foi criado retorna mensagem de overflow
	if (novo == NULL)
    	cout << "Overflow\n";
	
	else{
    	// Se o Deque estiver vazio (se for o primeiro uso)
    	if (inicio == NULL)
    		//O novo estar� no in�cio e fim ao mesmo tempo
        	fim = inicio = novo;
    	else{
    		//Sen�o n�o for o primeiro uso do Deque
			//o novo N� fica no inicio normalmente e
			//o que estava no in�cio passapara tr�s
    		novo->prox = inicio;
			inicio->ant = novo;
			inicio = novo;
    	}

    // Depois de inserir um novo N�, aumenta o tamanho
    tamanho++;
	}
}


//A fun��o de inserir no fim � muito parecida! Tem custo tamb�m O(1)
void Deque::insereFim(int valor){
	No* novo = No::novoNo(valor);
	
	//Testa se o novo elemento n�o conseguir ser criado
	//se n�o foi criado retorna mensagem de overflow
	if (novo == NULL)
    	cout << "OverFlow\n";
	
	else{
    	// Se o Deque estiver vazio (se for o primeiro uso)
    	if (fim == NULL)
    		//O novo estar� no in�cio e fim ao mesmo tempo
        	fim = inicio = novo;
    	else{
    		//Sen�o n�o for o primeiro uso do Deque
			//o novo N� fica no fim normalmente e
			// passa o que estava no fim para frente
			
			//Muito parecido com a l�gica do insereInicio, n�?
    		novo->ant = fim;
			fim->prox = novo;
			fim = novo;
    	}

    // Depois de inserir um novo N�, aumenta o tamanho
    tamanho++;
	}
}

//Custo O(1)
int Deque::removeInicio(){
	// Verifica se a lista j� est� vazia
	if (inicio == NULL)
	    cout << "N�o tem mais elementos para tirar!\n";
	
	else{
		//Guarda o valor que est� no in�cio antes de come�ar a mexer
		int valorInicio = inicio->valor;
		
		//Inicio avan�a uma casa (o que era seu prox)
	    No* temp = inicio; //Guarda o endere�o do que est� no inicio
	    inicio = inicio->prox; 
	
	    // Se s� tinha um elemento, in�cio e fim s�o novamente NULL
	    if (inicio == NULL)
	        fim = NULL;
	    else
	        inicio->ant = NULL; //Altera o anterior do que se tornou o inicio
	    
		free(temp); //Libera o antigo inicio
	    tamanho--;
	    return(valorInicio);
	}
}


//A removeFim � muito parecida com a removeInicio. Tamb�m com custo O(1)
int Deque::removeFim(){
    // Verifica se a lista j� est� vazia
    if (inicio == NULL)
        cout << "N�o tem mais elementos para tirar!\n";
    
    else{
    	//Pega o valor que est� no fim antes de come�ar a mexer
    	int valorFim = fim->valor;
    	
    	//Fim retorna uma casa (o que era seu anterior)
        No* temp = fim;
        fim = fim->ant;
 
        // Se s� tinha um elemento, in�cio e fim s�o NULL
        if (fim == NULL)
            inicio = NULL;
        else
            fim->prox = NULL;
        
		free(temp);
        tamanho--;
        return(valorFim);
    }
}


int Deque::getInicio(){
    //Se estiver vazio retorne -1
    if (inicio == NULL)
        return -1;
    return inicio->valor;
}


int Deque::getFim(){
	    //Se estiver vazio retorne -1
	    if (inicio == NULL)
	        return -1;
	    return fim->valor;
	}	
		

int main(){
    Deque dq;
    cout << "Insere valor 60 no fim.\n";
    dq.insereFim(60);
 
    cout << "Insere valor 32 no fim.\n";
    dq.insereFim(32);
 
    cout << "O elemento que est� no fim: " << dq.getFim() << endl;
 
    dq.removeFim();
    cout << "Depois de remover o elemento do fim/cauda, quem est� no fim �:" << dq.getFim() << endl;
 
    cout << "Insere elemento 4 no inicio.\n";
    dq.insereInicio(4);
 
    cout << "O elemento que est� no inicio: " << dq.getInicio() << endl;
 
    dq.removeInicio();
    cout << "Depois de remover o elemento do inicio/cabe�a, quem est� no inicio �:" << dq.getInicio() << endl;
 
    return 0;
}
