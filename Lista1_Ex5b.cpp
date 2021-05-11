#include <bits/stdc++.h>
using namespace std;
  

int main(){
    
	queue<int> fila, fila2, fila3;
	
	
	fila.push(10);
	fila.push(11);
	fila.push(12);
	fila.push(13);
	fila.push(14);
	
		
	//Passa todos elementos para a fila2 (vamos deixar a fila original j� vazia, preparada para receber os elementos na ordem inversa)
	while (!fila.empty()){
			fila2.push(fila.front());
		    fila.pop();
	}
	
	
	
	int tam_inicial = fila2.size();//armazena o tamanho inicial/total
	int cont=0;//contador interno para controlar a quantidade de elementos que passar�o para o vetor auxiliar - ver descri��o abaixo
	int j = 0;//Contador interno para guardar o tamanho da fila que est� com os elementos no momento - ver descri��o abaixo
	
	
	
	//Passa todos elementos (com exce��o do �ltimo) para uma fila auxiliar e transfere o �ltimo elemento para a fila para o local definitivo. Faz isso at� pegar todos os "�ltimos".
	int i =0;
	while(i<tam_inicial){
		
		cont=0;
		
		//Se a fila3 estiver vazia ela que vai ser a fila auxiliar
		if (fila3.empty()){
			j = fila2.size();
			
			while (cont != j-1){
		        fila3.push(fila2.front());
		        fila2.pop();
		        cont++;
		    }
		    fila.push(fila2.front());
		    fila2.pop();
		}
		
		//Sen�o a fila2 que ser� o vetor que vai receber os elementos-1
		else{
			j = fila3.size();
						
			while (cont != j-1){
		        fila2.push(fila3.front());
		        fila3.pop();
		        cont++;
		    }
		    fila.push(fila3.front());
		    fila3.pop();
		}	
		
		i++;
	}
	
	
	
	while (!fila.empty()) {
        cout << "Tirando da fila (invertida) " << fila.front() << "\n";
        
        fila.pop();
    }
    
	
	
	
    
	//O custo deste algoritmo � O(n!): O loop come�a com todos elementos. � medida que o loop avan�a a quantidade de elementos a serem transferidos diminui em 1.     
    return 0;
}
