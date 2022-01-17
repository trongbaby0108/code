#include<bits/stdc++.h>
using namespace std ; 

struct mark 
{
	string id,name ; 
};


void readInt(int num , int* arr)
{
	for (int i = 0; i < num; i++)
		cin >> *(arr+i);
}


void readFloat(int num , float* arr)
{
	for (int i = 0; i < num; i++)
		cin >> *(arr+i);
}


void printInt(int num ,int* arr )
{
	for (int i = 0; i < num; i++) cout << *(arr+i)<< " ";
}


void printFloat(int num ,float* arr )
{
	for (int i = 0; i < num; i++) cout << *(arr+i)<<" ";
}


void readMatrix(int l, int c, int **a)
{
	for(int i= 0; i < l ; i++)
		for(int j=0; j < c; j++)
		cin 	>> a[i][j];
}
void printMatrix(int l, int c, int **a)
{
	cout << "matrix :" << endl;
	for(int i= 0; i < l ; i++)
	{
		for(int j=0; j < c; j++) cout << a[i][j]<< " ";
		cout << endl;
	}
}


void readStruct(mark *a)
{
	cin >> a->id;
	cin >> a->name;
}


void printStruct(mark *a)
{
	cout << a->id << endl;
	cout << a->name; 
}
int main()
{
	int num ,line,columm; 
	int* data; 
	float* data1 ; 
	//cin >> num;
	mark *x=new mark;
	
	//data=(int*)malloc(num);
	//data1=(float*)malloc(num);
	
	//cin >> line >> columm;
	//int **a= new int*[line];
	//for(int i=0; i<line;  ++i) a[i]= new int[columm];
	
	readStruct(x);
	printStruct(x);
	
//	readMatrix(line,columm,a);
//	printMatrix(line,columm,a);

//	readInt(num,data);	
//	printInt(num,data);

//	readFloat(num,data1);
//	printFloat(num,data1);
}
