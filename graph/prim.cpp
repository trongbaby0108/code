#include <bits/stdc++.h>
#define for(l,r,i) for(int i = l ; i < r ; i++  )
using namespace std ; 
struct graph
{
	int data[100][100],n;
};
struct edge 
	{
		int u,v,value ;
	};
edge t[100];
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
void conect(graph g, int *reveit , int i)
{
	for(0,g.n,j) 
	if (g.data[i][j] != 0 && reveit[j]!= reveit[i] )
	{
		reveit[j]=reveit[i];
		conect(g,reveit,j);
	}
}
int check_connect(graph g)
{
	int reveit[100],res =0 ; 
	for(0,g.n,i) reveit[i] = 0 ; 
	for (0,g.n,i) 
		if (reveit[i] == 0) 
		{
			res ++ ; 
			reveit[i] = res;
			conect(g, reveit ,i) ;
		}
	return res;
}
void prim (graph g) 
{
	int cnt = 0 , *cmp = new int ;
	for(0,g.n,i) cmp[i]= 0 ;
	cmp[0]=1;
	while(cnt <g.n -1 ) 
	{
	 	edge min; 
		int minx = 100 ;
		for(0,g.n,i)
			if (cmp[i] ==1) 
			for(0,g.n,j) 
				if (cmp[j]== 0 && g.data[i][j]!=0 && minx > g.data[i][j])
				{
					min.u =i ; 
					min.v =j ;
					min.value = g.data[i][j];
					minx = g.data[i][j];
				}
		t[cnt] = min ;
		cnt ++  ; 
		cmp[min.v] = 1 ;
	}
	int total = 0 ;
	cout <<" cay khung nho nhat la : ";
	for(0,cnt-1,i)
	{
		cout << t[i].u+1 << " " << t[i].v+1 <<",";
		total += t[i].value ;
	}
	cout << t[cnt-1].u+1 <<" "<<t[cnt-1].v+1 ; 
	total+= t[cnt-1].value;
	cout << endl << "tong gia tri cua cay khung :"<< total ;
}
int main ()
{
	graph g ;
	#ifndef setting
		FILE *fin= freopen("data.inp","r", stdin);
		FILE *fout= freopen("data.out","w",stdout);
	#endif	
	read(g); 
	write(g);
	prim(g);
	fclose(fin); 
	fclose(fout); 
}
