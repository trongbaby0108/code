#include<bits/stdc++.h>
using namespace std; 
int a= [1,2,3,4,5,6,7,8,9];
struct node{
    int info ; 
    node *left , *right;
};
node* createnode (int data ){
    node *x= new node ;
    x->info = data ;
    x->left = NULL; 
    x->right= NULL;
    return x ;
}

void init (node *&tree )
{
    tree = NULL ; 
}

bool isempty(node *tree)
{
    return (tree == NULL );
}
node* creatnode (int x )
{
	node* q= new node ; 
	q->left = q->right = NULL;
	q->info=x; 
	return tree; 
}
void input(node * tree,int x )
{
	if (isemty(tree)) tree=createnode(x) ; 
}
