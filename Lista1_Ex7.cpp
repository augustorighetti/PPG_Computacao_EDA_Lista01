#include <iostream>
#include<ctype.h>
using namespace std;


int main(){
    int top=-1;
    char vet[100];	//Vetor acumulador para guardar os caracteres que n�o s�o letras
					//(para imprimir em ordem reversa � medida que segmentos s�o fechados)
    
	string original; 
    cin>>original;//L� a string/vetor de chars no formato convencional
    
    
    //Agora vamos percorrer a string verificando o que fazer com cada caracter
    for(int i=0;i<original.length();i++ ){
    	
		//Se fechou algum segmento, volte no vetor acumulador imrpimindo at� encontrar a abertura
		if(original[i]==')'){
           while(vet[top]!='('){
                cout<<vet[top];
                top--;
            }
            top--;//Volta o espa�o correspondente ao par�nteses de abertura
        }
        
        
        else{
        	//Se o caracter for uma letra imprima
            if(isalpha(original[i]))
                cout<<original[i];
        	
        	//Se n�o for, aumente o contador e guarde o caracter (operador/par�nteses aberto)
            else{
            	top++;
                vet[top]=original[i];
            }
        }
    }
    
	cout<<endl;
    return 0;
}
