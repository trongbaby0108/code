#include<bits/stdc++.h>

using namespace std; 

struct node {
	int num;
	node* next ;
};

void Init ( node* &x)
{
	x=NULL ;
}

bool isEmpty( node* x )
{
	return (x== NULL); 
}

void push(int key , node* &x)
{
	node* p = new node ;
	p->num=key ;
	p->next= x;
	x = p ;
}

bool pop (int key , node* x )
{
	if (isEmpty(x)) return false ; 
	node* p=x; 
	key=p->num ;
	x=x->next;
	delete p;
	return true ; 
}
int main ()
{
	node* stack  ;
	Init(stack); 
	if(isEmpty(stack)) 
		cout << "rong" << endl;
	else  
		cout << "khong rong " << endl;
	system("pause ");
	return 0 ; 
}



