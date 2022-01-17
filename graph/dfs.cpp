#include <bits/stdc++.h>
#define for(l,r,i) for(int i = l ; i < r ; i++  )
using namespace std ; 
struct graph
{
	int data[100][100];
	int n ; 
};
bool *cnt  = new bool ;
int *res = new int;  
void read(graph &g)
{
	cin >> g.n ; 
	for(0,g.n,i)
	for(0,g.n,j)
			cin >> g.data[i][j]; 
}

void write(graph g)
{
	for(0,g.n,i)
	{
		for(0,g.n,j)
			cout <<  g.data[i][j] << " " ; 
			cout << endl; 
	} 
}
void clear(bool *cnt, int *res, graph g)
{
	for(0,g.n,i) 
	{
		cnt[i]= true ; 
		res[i]= -1 ; 
	}
}
void dfs(graph g , int s )
{
	cnt[s]=false ;   
	for(0,g.n,i) 
	{
		if (g.data[s][i] != 0 && cnt[i] == true ) 
		{
			res[i]= s ;
			dfs(g,i);
		}
	}
}

void printpath(int start , int end , graph g)
{
	clear(cnt,res,g); 	
	dfs(g,start) ; 
	if(start == end) 
	 cout <<start ; 
	else
	if (res[end]==-1)
	cout << "khong co duong di ";
	else 
	{
		printpath(start ,res[end] , g);
		cout <<"-> " <<end ;
	}
}
int main () 
{
	int k;
	graph g ;
	#ifndef setting
		FILE *fin= freopen("data.inp","r", stdin);
		FILE *fout= freopen("data.out","w",stdout);
	#endif	
	read(g); 
	write(g);
	printpath(1,1,g);	
	fclose(fin); 
	fclose(fout); 
}
