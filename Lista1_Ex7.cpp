#include <iostream>
#include<ctype.h>
using namespace std;


int main(){
    int top=-1;
    char vet[100];	//Vetor acumulador para guardar os caracteres que não são letras
					//(para imprimir em ordem reversa à medida que segmentos são fechados)
    
	string original; 
    cin>>original;//Lê a string/vetor de chars no formato convencional
    
    
    //Agora vamos percorrer a string verificando o que fazer com cada caracter
    for(int i=0;i<original.length();i++ ){
    	
		//Se fechou algum segmento, volte no vetor acumulador imrpimindo até encontrar a abertura
		if(original[i]==')'){
           while(vet[top]!='('){
                cout<<vet[top];
                top--;
            }
            top--;//Volta o espaço correspondente ao parênteses de abertura
        }
        
        
        else{
        	//Se o caracter for uma letra imprima
            if(isalpha(original[i]))
                cout<<original[i];
        	
        	//Se não for, aumente o contador e guarde o caracter (operador/parênteses aberto)
            else{
            	top++;
                vet[top]=original[i];
            }
        }
    }
    
	cout<<endl;
    return 0;
}
