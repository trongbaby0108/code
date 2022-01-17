#include <iostream>
using namespace std ; 
#define max 100
#define INFINITY 10000
int next[max][max],l[max][max];
struct graph
{
	int data[100][100];
	int n ; 
};

void read(graph &g)
{
	cin >> g.n ; 
	for (int i = 0; i < g.n; ++i)
		for (int j = 0; j  < g.n; ++j)
			cin >> g.data[i][j]; 
}

void write(graph g)
{
	for (int i = 0; i < g.n; ++i)
	{
		for (int j = 0; j  < g.n; ++j) 
			cout <<  g.data[i][j] << " " ; 
		cout << endl; 
	} 
}

void floyd(graph g)
{
	int i,j ;
	for(i=0 ;i<g.n ;i++)
		for(j=0 ;j<g.n ;j++)
			if (g.data[i][j]>0)
			{
				next[i][j]= j ;
				l[i][j]=g.data[i][j];
			}
			else
			{
				next[i][j]=-1 ;
				l[i][j]= INFINITY;
			}
	for (int k= 0;k<g.n;k++)
		for(i=0 ;i<g.n ;i++)
		for(j=0 ;j<g.n ;j++)
			if (l[i][j]> l[i][k]+l[k][j])
			{
				l[i][j] =l[i][k]+l[k][j];
				next [i][j] = next[i][k];
			}
	int s= 1, f= 2 ; 
	if (next[s][f] == -1 ) cout << "khong co duong di " ;
	else 
	{
		cout << s ;
		int u= s;  
		while (next[u][f]!=f)
		{
			u =next[u][f]; 
			cout <<"<-"<<u; 
		}
		cout << "<-"<<f;
	}
}

int main()
{
	#ifndef solve 
		FILE *fin = freopen("input.txt", "r", stdin); 
		//FILE *fout = freopen("output.txt", "w", stdout) ; 
	#endif

	graph g ;

	read(g); 
	floyd(g);
	fclose(fin);
	//fclose(fout); 
	return 0;	
}
