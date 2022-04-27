#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

//Alumno:Bryan Edward Suca Jaramillo

//Pregunta 1b
// cifrar en minisculas: elementalmiqueridowatson	
// Descrifrar en minisculas: okhfsnkfnwfcwjhsnchqywfswf
//Pregunta 2b
// Descifrar el texto a=23,b=17: slbcmvrbshzbt#nsrqvvmszbvh#nbvrqvlalhzbt#nsrqvwqaxlzw#naqfqv

char alf[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','#','o','p','q','r','s','t','u','v','w','x','y','z'};

void euclides_extendido(int a,int b, int *q1, int *q2, int *q3){
    int d,x,y,x1,x2,y1,y2,q,r;
    if(b==0){
        d=a;
        x=1;
        y=0;
        //return(d);
    }
    x1=0;
    x2=1;
    y1=1;
    y2=0;
    while(b>0){
        q=a/b;
        r=a-(q*b);
        x=x2-(q*x1);
        y=y2-(q*y1);
        a=b;
        b=r;
        x2=x1;
        x1=x;
        y2=y1;
        y1=y;
    }
    d=a;
    x=x2;
    y=y2;
    *q1=d;
    *q2=x;
    *q3=y;
}

int inverso(int n,int a){
	 int d,x,y,inver;
	 int *p1=&d;
	 int *p2=&x;
	 int *p3=&y;
     euclides_extendido(a,n,p1,p2,p3);
     if(d>1){
     	return 0;
     }
     else{
     	if(x<0){
     		inver=n+x;
     	}
     	else{
     		inver=x;
     	}
     }
     return(inver);
}

void cifrado_afin(){
	//cout<<"Cifrado afin C=a.P+b(mod n)"<<endl;
	char m[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a cifrar: ";
	cin.getline(m,100);
	int a,b;
	do{
	   cout<<"Ingrese el valor de a: ";
	   cin>>a;
   }while(a<0||inverso(27,a)==0);
	do{
      cout<<"Ingrese el valor de b: ";
      cin>>b;
   }while(b<0||b>26);


	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 32){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					int aux=((a*j)+b)%27;
					m[i]=alf[aux];
					break;
				}
			}	
		}		
	}
	cout<<"El mensaje cifrado es: "<<m<<endl<<endl;
}

void descifrado_afin(){
	//cout<<"Descifrado afin P=a-1.(C-b)(mod n)"<<endl;
	char m[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a descifrar: ";
	cin.getline(m,100);
	int a,b;
	do{
		cout<<"Ingrese el valor de a: ";
		cin>>a;	
	}while(inverso(27,a)==0||a<0);
   do{	
      cout<<"Ingrese el valor de b: ";
	   cin>>b;
   }while(b<0||b>26);
	int inv_a=inverso(27,a);      	
	b=27-((inv_a*b)%27); 
	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 32){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					int aux=((inv_a*j)+b)%27;
					m[i]=alf[aux];
					break;
				}
			}	
		}		
	}
	cout<<"El mensaje descifrado es: "<<m<<endl<<endl;
}
int main(){
    int opc1,opc2;
    do{
        cout << "Escoge si quieres descifrar o cifrar la palabra"<<endl;
        cout<<"1.- Cifrar"<<endl;
		cout<<"2.- Descrifrar"<<endl;
        cout<< "---------------------------------------------------"<<endl;
        cout<<"Selecciona la opcion 1 o 2: ";
        cin >>opc1;
        switch(opc1){
            case 1: cifrado_afin(); break;
			case 2: descifrado_afin(); break;
        }
     }while(opc1!=3);
		system("cls");				
}
//Pregunta 1b
// cifrar en minisculas: elementalmiqueridowatson	
// Descrifrar en minisculas: okhfsnkfnwfcwjhsnchqywfswf
//Pregunta 2b
// Descifrar el texto a=23,b=17: slbcmvrbshzbt#nsrqvvmszbvh#nbvrqvlalhzbt#nsrqvwqaxlzw#naqfqv
