#include <bits/stdc++.h>
 
using namespace std;
 
struct No{
    int valor; 	// Só usamos um inteiro aqui, mas podemos usar um Struct para ter vários atributos "organizados" em um mesmo nó
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
 
    // Operações
    void insereInicio(int valor);
    void insereFim(int valor);
    int removeInicio();
    int removeFim();
    int getInicio();
    int getFim();
    
};

//Função com custo O(1)
void Deque::insereInicio(int valor){
	No* novo = No::novoNo(valor);
	
	//Testa se o novo elemento não conseguir ser criado
	//se não foi criado retorna mensagem de overflow
	if (novo == NULL)
    	cout << "Overflow\n";
	
	else{
    	// Se o Deque estiver vazio (se for o primeiro uso)
    	if (inicio == NULL)
    		//O novo estará no início e fim ao mesmo tempo
        	fim = inicio = novo;
    	else{
    		//Senão não for o primeiro uso do Deque
			//o novo Nó fica no inicio normalmente e
			//o que estava no início passapara trás
    		novo->prox = inicio;
			inicio->ant = novo;
			inicio = novo;
    	}

    // Depois de inserir um novo Nó, aumenta o tamanho
    tamanho++;
	}
}


//A função de inserir no fim é muito parecida! Tem custo também O(1)
void Deque::insereFim(int valor){
	No* novo = No::novoNo(valor);
	
	//Testa se o novo elemento não conseguir ser criado
	//se não foi criado retorna mensagem de overflow
	if (novo == NULL)
    	cout << "OverFlow\n";
	
	else{
    	// Se o Deque estiver vazio (se for o primeiro uso)
    	if (fim == NULL)
    		//O novo estará no início e fim ao mesmo tempo
        	fim = inicio = novo;
    	else{
    		//Senão não for o primeiro uso do Deque
			//o novo Nó fica no fim normalmente e
			// passa o que estava no fim para frente
			
			//Muito parecido com a lógica do insereInicio, né?
    		novo->ant = fim;
			fim->prox = novo;
			fim = novo;
    	}

    // Depois de inserir um novo Nó, aumenta o tamanho
    tamanho++;
	}
}

//Custo O(1)
int Deque::removeInicio(){
	// Verifica se a lista já está vazia
	if (inicio == NULL)
	    cout << "Não tem mais elementos para tirar!\n";
	
	else{
		//Guarda o valor que está no início antes de começar a mexer
		int valorInicio = inicio->valor;
		
		//Inicio avança uma casa (o que era seu prox)
	    No* temp = inicio; //Guarda o endereço do que está no inicio
	    inicio = inicio->prox; 
	
	    // Se só tinha um elemento, início e fim são novamente NULL
	    if (inicio == NULL)
	        fim = NULL;
	    else
	        inicio->ant = NULL; //Altera o anterior do que se tornou o inicio
	    
		free(temp); //Libera o antigo inicio
	    tamanho--;
	    return(valorInicio);
	}
}


//A removeFim é muito parecida com a removeInicio. Também com custo O(1)
int Deque::removeFim(){
    // Verifica se a lista já está vazia
    if (inicio == NULL)
        cout << "Não tem mais elementos para tirar!\n";
    
    else{
    	//Pega o valor que está no fim antes de começar a mexer
    	int valorFim = fim->valor;
    	
    	//Fim retorna uma casa (o que era seu anterior)
        No* temp = fim;
        fim = fim->ant;
 
        // Se só tinha um elemento, início e fim são NULL
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
 
    cout << "O elemento que está no fim: " << dq.getFim() << endl;
 
    dq.removeFim();
    cout << "Depois de remover o elemento do fim/cauda, quem está no fim é:" << dq.getFim() << endl;
 
    cout << "Insere elemento 4 no inicio.\n";
    dq.insereInicio(4);
 
    cout << "O elemento que está no inicio: " << dq.getInicio() << endl;
 
    dq.removeInicio();
    cout << "Depois de remover o elemento do inicio/cabeça, quem está no inicio é:" << dq.getInicio() << endl;
 
    return 0;
}
