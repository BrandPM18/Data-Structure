# Definimos memoria dinámica

```cpp
struct nodopila{
    int dato;
    nodopila *sig;
};
typedef nodo *pnodopila;
```
Declara la variable e inicializamos
```cpp
nodo pcima;
pcima=NULL;
```
## Forma de pila
![N|Solid](https://users.dcc.uchile.cl/~bebustos/apuntes/cc30a/TDA/pila.gif)
### Esctructura en C++ forma class
```cpp
class pila{
    private:
        pnodopila pcima;
    public:
        pila();
        ~pila();
        void apilar(int x);
        void desapilar();
        int desapilon();
        void desapilar_0();
        void imprimir();
        void vacio();
}
```
#### Apilar
```cpp
void apilar(int x){
    pnodopila p;
    p=new nodopila;
    (*p).dato=x;
    p->sig=pcima;
    pcima=p;
}
```
#### Desapilar int
```cpp
int desapilon(){
    pnodopila p;
    p=pcima;
    pcima=pcima->sig;
    return p->dato;
}
```
#### Desapilar void
```cpp
void desapilar(){
    pnodopila p;
    p=pcima;
    pcima=p->sig;
}
```
#### Imprimir void
```cpp
void imprimir(){
    pnodopila p;
    p=pcima;
    if(pcima==NULL)    cout<<"Pila vacia"<<endl;

    while(p!=NULL){IM
        cout<< p->dato <<" -> ";
        p=p->sig;
    }
    cout<<"NULL"<<endl;
```
## pilabase.h
```cpp
#include<iostream>
using namespace std;
struct nodopila{
    int dato;
    nodopila *sig;
};
typedef nodopila *pnodopila;

class pila{
    private:
        pnodopila pcima;
    public:
        pila();
        ~pila();
        void apilar(int x);
        void desapilar();
        int desapilon();
        void desapilar_0();
        void imprimir();
        void vacio();
};
pila::pila(){
    pcima=NULL;
}
pila::~pila(){
    pnodopila p,q;
    if(pcima!=NULL){
        p=pcima
        while(p!=NULL){
        q=p->sig;
        delete p;
        p=q;
        }
    }
}
void pila::apilar(int x){
    pnodopila p;
    p=new nodopila;
    (*p).dato=x;
    p->sig=pcima;
    pcima=p;
}
void pila::desapilar(){
    pnodopila p;
    p=pcima;
    pcima=p->sig;
    
}    
int pila::desapilon(){
    pnodopila p;
    p=pcima;
    pcima=pcima->sig;
    return p->dato;
}
void pila::vacio(){
    if(pcima==NULL){
    cout<<"Pila vaciada"<<endl;
    }
}
void pila::desapilar_0(){
    pnodopila p;
    p=pcima;
    pcima=pcima->sig;
    delete p;
}
void pila::imprimir(){
    pnodopila p;
    p=pcima;
    if(pcima==NULL)    cout<<"Pila vacia"<<endl;

    while(p!=NULL){
        cout<< p->dato <<" -> ";
        p=p->sig;
    }
    cout<<"NULL"<<endl;
}
```

### Ejm aplicativo
> Suma los valores en de una pila
```cpp
#include<iostream>
#include "pilabase.h"
using namespace std;
void Suma(pila L){
    int x,w;
    cout<<"Ingrese los datos a operar:"<<endl;
    cin>>x;
    for(int i=0;i<x;i++){
        cout<<"SUMANDO "<<i+1<<endl;
        cin>>w;
        L.apilar(w);
    }
    int s=0;
    for(int j=0;j<x;j++){
        s+=L.desapilon();
    }
    L.vacio();
    L.apilar(s);
    L.imprimir();
    cout<<"La suma es "<<L.desapilon()<<endl;
}
int main (){
    pila F;
    int y;
    while(y!=3){
        cout<<"\t CALCULADORA"<<endl;
        cout<<"\t1)SUMA\n\t3)Salir"<<endl;
        cin>>y;
        switch(y){
            case 1:     Suma(F);
                        break;
            case 3: break;
        }
    }
}
```
## Cola
### Definicion
> Una cola es una coleccion ordenada de elementos a partir de la cual se puede eliminar elementos de un extremo (llamado frente de la cola) y en la cual también se puede agregar en el otro extremo (llamado final de la cola).
> A la cola se le conoce como extructura de dato de tipo FIFO (First in first out).
 
![cola](http://1.bp.blogspot.com/-yU24HlEAb5k/UJFLeeCJEtI/AAAAAAAAAUg/nog3KdbtCg0/s1600/colas+en+c%2B%2B.png)
 
 **Operaciones de colas**
  - Encolar
  - Desencolar
  - Determ el primer elemento
  - Determ el ultimo elemento
# Definimos memoria dinámica

```cpp
struct nodocola{
    int dato;
    nodopila *sig;
};
typedef nodo *pnodopila;
```
## Declarando variables
```cpp
pnodocola pfrente;
pnodocola pfinal;
pfrente = NULL;
pfinal = NULL;
```
#### Encolar
```cpp
void encolar(int x){
    pnodocola p;
    p=new pnodocola;
    (*p).dato=x;
    p->sig=NULL;
    if(pfrente==NULL)
        pfrente = p;
    else
        pfinal->sig=p;
    pfinal=p;
}
```
#### Desncolar
```cpp
void desencolar(){
    pnodocola p;
    p=pfrente;
    if(p->sig == NULL)
        pfrente = NULL;
        pfinal = NULL;
    else
        pfrente = p->sig;
    delete p;
}
```

