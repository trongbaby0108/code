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
void bfs(graph g, int v)
{
	queue <int> qlist ; 
	qlist.push(v);
	while( !qlist.empty() )
	{
		int v = qlist.front() ;
		qlist.pop();
		cnt[v]= false ; 
		for(0, g.n, i) 
		{
			if(g.data[v][i] != 0 && cnt[i] == true )
			{
				qlist.push(i); 
				if (res[i] == -1 ) res[i]= v ;
			}
		}
	}
}
void printpath(int start , int end , graph g)
{
	clear(cnt,res,g); 	
	bfs(g,start);
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
	printpath(2,4,g);	
	fclose(fin); 
	fclose(fout); 
}
