#include<bits/stdc++.h>
using namespace std; 


void readInput(int & n, int a[])
{
	cout << "nhap so luong phan tu :"; cin >> n ; 
	for(int i=0 ; i< n; i++)
	{
		cout << "data[" << i <<"]:";
		cin >>  a[i]; 
	}
}

void printOutput(int n , int a[ ])
{
	for(int i=0 ; i< n; i++) 
		cout << "a[" <<i<< "]="<<a[i] <<endl; 
}
int search(int n , int key , int a[])
{
	int i=0;
	while(i<n && key != a[i]) ++ i ;
	if (i<n) return i;
	return -1 ;  	
}
void sort (int n ,int a[])
{
	for (int i=0 ;i<n-1 ;++i)	
		for (int j =i+1 ;j < n; j++)
		if (a[i] < a[ j ]) swap(a[i] ,a[j]);

} 
int binarySearch(int n,int key, int a[])
{
	int l = 0, r =n-1,mid; 
	while (l < r )
	{
		mid=  (l+r)/2; 
		if (a[mid]== key) return mid;
		if (a[mid]>  key) l=mid++ ; else r=mid--;
	}
	return -1 ;
}
int main ()
{
	system("cls");
	int num,arr[1000],key ,ans;
	readInput(num,arr);
	printOutput(num ,arr); 	
	cout << "nhap gia tri can tim " ; 
	cin >> key ;
	ans= binarySearch(num ,key ,arr);
	if (ans != -1 ) cout << "vi tri can tim la : " << ans; 
	else cout << "khong tim dc :("; 
}
