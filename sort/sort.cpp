#include<bits/stdc++.h>
using namespace std;

void readInput(int & num, int data[])
	{ 
		cin >> num;  
		for (int i=0; i< num ; i++ ) 
			cin >> data[i];
	} 
		
	
void bubbleSort(int n ,int a[])
	{
		for (int i= 0 ; i < n-1 ;++i )
			for (int j=n-1 ;i<j ;j--  )
			if (a[j] < a[j-1]) swap (a[j] , a[j-1]); 
	}


void interchangeSort(int n , int a[])
	{
		for (int i= 0 ; i < n-1 ;++i )
			for (int j=i+1 ;j< n ;j++)
			if (a[i] > a[j]) swap (a[i] , a[j]); 
	}


void selectionSort(int n , int a[])
	{
		for (int i=  0; i < n-1 ;++i )
		{
			int key = i; 
			for (int j=i+1 ;j< n ;j++) 
					if (a[j] < a[key])
					key=j ;
					swap(a[key],a[i]);	
		}
	}


void InsertionSort(int n, int a[])
{
		for (int i=  1 ; i < n ;++i )
			{
				int x=a[i] , pos=i--;
				while (a[pos] > x && pos >= 0 )
				{
					a[pos+1] =a[pos];
					--pos;
				}
				a[pos+1]=x;	
			}
	}


//void shellSort()


// counting sort 

void counttingsort(int *a,int n)
{
	int max  = a[0] , min = a[0] , *b = new int , *c =new int ;
	for (int i = 0; i < n  ; ++i) 
		{
			max = (max < a[i]) ? a[i] :max ;
			min = (min < a[i]) ? min : a[i] ; 
		}
	int size = max - min +1 ;
	for (int i = 0; i < size ; i++) b[i]  = 0 ; 
	for (int i = 0; i < n  ; i++)  b[a[i]-min]++ ; 
	for (int i = 1; i < size; i++) b[i] += b[i-1] ; 
	for (int i = 0; i < n ; i++ )
		{
			c[b[a[i]-min] -1 ] = a[i]; 
			b[a[i]- min]--;
		} 
	for (int i = 0; i < n ; ++i) a[i] = c[i];
	delete b,c  ; 
}
//void TimSort()

//void heepsort()

//void mergesort()

//void flashsort()


void quickSort(int l ,int r , int a[])
	{
		int i = l, j= r, x=a[(l+r)/2];
		do
		{		
			while ( a[i] < x) i++;
			while ( a[j] > x) j--; 
			if (i<=j)
			{
				swap(a[i], a[j]);
				i++; j-- ; 
		 	}
		} while (i<j);
		if (l < j ) quickSort(l,j,a);
		if (r > i ) quickSort(i,r,a);
	}
void printOutput(int n,int a[])
	{
    	for (int i=0; i < n; i++) cout <<  a[i] <<" " ;
	}
int main()
{
	int n,data[100];

	#ifndef file 
		FILE *fin = freopen("data.inp","r",stdin) ; 
		FILE *fout = freopen("data.out","w",stdout) ; 
	#endif 
	readInput(n,data);
	//bubbleSort(n,data);
	//interchangeSort(n,data);
	//selectionSort(n,data);
	//InsertionSort(n,data);
	//quickSort(0,n-1,data);
    counttingsort(data,n);
    printOutput(n,data); 
    return 0;
    fclose(fin); 
    fclose(fout);     
    system("pause");
}
