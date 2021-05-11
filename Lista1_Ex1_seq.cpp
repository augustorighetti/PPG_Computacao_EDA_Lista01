#include <bits/stdc++.h>
 
using namespace std;


#define MAX 20
 
// Deque utilizando array
class Deque{
    int  arr[MAX];
    int  inicio;
    int  fim;
    int  tam;
    
    //Instancia Deque
	public:
	    Deque(){
	        inicio = -1;
	        fim = 0;
	        this->tam = MAX;
	    }
 
    
    void  insereInicio(int valor);
    void  insereFim(int valor);
    void  removeInicio();
    void  removeFim();
    int  getInicio();
    int  getFim();
	
	//Vamos criar duas opera��es de verifica��o para facilitar a legibilidade ao longo do c�digo
	bool  cheia();
    bool  vazia();
};
 

bool Deque::cheia(){
    //Verifica se estiver preenchido de 0 a tam-1 ("in�cio" ao "fim") ou se o inicio estiver uma casa � direita do fim (deu a volta e j� alcan�ou)
	return ((inicio == 0 && fim == tam-1) || (inicio == fim+1));
}
 

bool Deque::vazia (){
    return (inicio == -1);
}
 
//Custo O(1)
void Deque::insereInicio(int valor){
    // Verifica se j� est� cheio
    if (cheia()){
        cout << "Overflow\n" << endl;
        return;
    }
 
    // Verifica o in�cio para iniciar (caso necess�rio)
    if (inicio == -1){
        inicio = 0;
        fim = 0;
    }
 
    // inicio est� na primeira posi��o do array ele vai para o final (circula)
    else if (inicio == 0)
        inicio = tam - 1 ;
 	
	    else
	    	//sen�o s� move o in�cio para a esquerda
	        inicio = inicio-1;
 
    // Depois de todas as verifica��es
	//para alterar o �ndice para o lugar certo, insere o valor
    arr[inicio] = valor ;
}
 
//Bem parecida com insereInicio Custo O(1)
void Deque::insereFim(int valor){
    if (cheia()){
        cout << " Overflow\n " << endl;
        return;
    }
 
    // Verifica o in�cio para iniciar (caso necess�rio)
    if (inicio == -1){
        inicio = 0;
        fim = 0;
    }
 
    //Se o fim estiver na �ltima posi��o, volte para 0
    else if (fim == tam-1)
        fim = 0;
		
		else
        	fim = fim+1; //Sen�o s� move o fim para a direita
 
    // Depois de todas as verifica��es
	//para alterar o �ndice para o lugar certo, insere o valor
    arr[fim] = valor ;
}
 

//Custo O(1)
void Deque ::removeInicio(){
    
    if (vazia()){
        cout << "O Deque j� est� vazio.\n" << endl;
        return ;
    }
 
    // Se s� tiver um elemento, joga in�cio e fim para -1
    if (inicio == fim){
        inicio = -1;
        fim = -1;
    }
    else
        //Volta � posi��o 0
        if (inicio == tam -1)
            inicio = 0;
 
        else // Avan�a 1 para remover o in�cio atual
            inicio = inicio+1;
}
 
//Custo O(1)
void Deque::removeFim(){
    if (vazia()){
        cout << "O Deque j� est� vazio.\n" << endl ;
        return ;
    }
 
    // Se s� tiver um elemento, joga in�cio e fim para -1
    if (inicio == fim){
        inicio = -1;
        fim = -1;
    }
    else if (fim == 0)
        fim = tam-1;
    else
        fim = fim-1;
}
 

int Deque::getInicio(){
    if (vazia()){
        cout << "O Deque est� vazio.\n" << endl;
        return -1 ;
    }
    return arr[inicio];
}

int Deque::getFim(){
    if(vazia() || fim < 0){
        cout << "O Deque est� vazio.\n" << endl;
        return -1 ;
    }
    return arr[fim];
}
 

int main(){
    Deque dq = Deque();
    
    dq.insereFim(0);
    dq.insereFim(1);
    dq.insereFim(2);
    dq.insereFim(3);
    dq.insereFim(4);
    dq.insereFim(5);
 
       
    cout << "Insere valor 25 no fim.\n";
    dq.insereFim(25);
 
    cout << "Elemento que est� no fim: " << dq.getFim() << endl;
 
    dq.removeFim();
	
	cout << "Depois de remover o �ltimo elemento, o elemento que est� no fim �: " << dq.getFim() << endl;
 
    cout << "Insere valor 30 no in�cio.\n";
    dq.insereInicio(30);
 
    cout << "Elemento que est� no in�cio: " << dq.getInicio() << endl;
 
    dq.removeInicio();
 
    cout << "Depois de remover o primeiro elemento, o elemento que est� no in�cio �: " << dq.getInicio() << endl;
    return 0;
}
