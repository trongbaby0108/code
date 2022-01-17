#include<bits/stdc++.h>
#define maxlist 1000
using namespace std ; 

struct lst{
	int num ;
	int node[maxlist]; 
};


void Init(lst &x)
{
	x.num=0 ;
}


bool isFull(lst x)
{
	if (x.num==maxlist) return true ; else return false ;
}


int isEmpty(lst x)
{
	if (x.num==0) return true ; else return false ; 
}


int listsize(lst x){
	return x.num;
		
}


int retrive(lst &x, int pos ){
	if (pos>0 && pos < listsize(x)) return x.node[pos]; 
	else
			return 0;
}


void insert(lst x, int pos, int k )
{
	if (isFull(x)) cout << "day bo nho ";
	else  
	if (pos>0 && pos < listsize(x)) cout << "vi tri chen khong phu hop ";
	else 
		for (int i=listsize(x)-1 ; i >= pos ;i--) x.node[i+1]=x.node[i];
		x.node[pos]=k; 
		x.num ++ ;
	
}


int remove(lst x, int pos )
{
	int key ; 
	if (isEmpty(x)) cout << "day bo rong ";
	else  
	if (pos>0 && pos < listsize(x)) cout << "vi tri xoa khong phu hop ";
	else 
		key= x.node[pos];
		for (int i =pos  ; i < listsize(x)  ;i++) x.node[i]=x.node[i++];
}


void replace(lst x, int pos ,int key)
{
	if (isFull(x)) 
	{
		cout << "day bo nho ";
		return ;
	}
	else  
	if (pos>0 && pos < listsize(x)) 
	{
		cout << "vi tri thay the khong phu hop ";
		return ; 
	}
	else x.node[pos]=key;
}


void showlist(lst x)
{
	if (isEmpty(x)) cout << "day bo rong ";
	else for (int i= 0 ;  i < x.num ;i++  ) cout << x.node[i]<<"  " ;
}


void sort (lst x )
{
	for (int i =0  ; i < x.num-1  ; i++  )
	for (int j= i++ ; j < x.num ; j++ )
	if (x.node[i] < x.node[j]) swap (x.node[i] , x.node[j]);
}


int  search(int key , lst x )
{
	int res= -1 ;  
	for (int i = 0 ; i < x.num ; i++ )
	if (x.node[i] ==key ) res=i  ; 
	return res ; 	
}


void clearlist(lst x)
{
	if (isEmpty(x)) cout << "da xoa het ";
	else 
		for (int i =0 ; i< x.num; i++) x.node[i]= 0 ; 
	x.num= 0; 
}


int main()
{
	lst data ; 
	int ans, x; 
	Init(data);
	cout << "1 nhap du lieu , 0 out :"; 
	cin >> ans ; 
	while (ans == 1 ) {
		cout << "nhap gia tri :" ; 
		cin >> x; 
		++data.num;
		insert(data,data.num,x);
		cout << "1 nhap du lieu , 0 out :"; 
		cin >> ans ; 
	}
}


