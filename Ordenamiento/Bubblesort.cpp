#include<iostream>
using namespace std;
const int N=5;

void imprimir(int a[N])
{
	int i;
	for(i=0;i<N;i++)
			cout<<a[i]<<" ";
	cout<<endl;
}

void ord_burguja(int a[N])
{	
	int i,j,aux;
	for(i=1;i<N;i++)
		for(j=0;j<N-1;j++)
			if(a[j]>a[j+1])
			{
				aux=a[j];
				a[j]=a[j+1];
				a[j+1]=aux;
				imprimir(a);
			}
}

int main(){
	
	int a[N]={3,4,5,2,1};
	imprimir(a);
	ord_burguja(a);	
}
