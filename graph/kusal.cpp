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
void sort (edge e[100],int n)
{
	for(0,n,i)
		for(i+1,n,j)
		if (e[i].value > e[j].value) swap(e[i],e[j]);
}
void kruskal(graph g)
{
	edge listedge[100];
	int num =0;
	for(0,g.n,i)
	for(i+1,g.n,j) 
		if(g.data[i][j] >0 )
		{
			listedge[num].u =i;
			listedge[num].v =j;
			listedge[num].value =g.data[i][j];
			num ++ ;
		}
	sort(listedge, num );
	int cnt= 0,_cnt = 0,res[100];
	edge t[100]; 
	for(0,g.n,i) res[i] =i;
	while (cnt< g.n && _cnt < num)
	{
			if (res[listedge[_cnt].u] != res[listedge[_cnt].v] )
			{
				t[cnt]= listedge[_cnt];
				cnt++;
				int val = res[listedge[_cnt].v] ; 
				for (0,g.n,j)
				if (res[j] == val )
					res[j] = res[listedge[_cnt].u]; 
			}
		_cnt++ ;
	}
	if (cnt != g.n - 1 ) cout << "khog co"; 
	else {
		int total = 0 ; 
		for(0,cnt,i)
		{
			cout <<t[i].u+1 <<"  " <<t[i].v+1 <<",";
			total+= t[i].value;
		}
		cout<< " " << total ;
	}
}
int main ()
{
	graph g ;
	#ifndef setting
		FILE *fin= freopen("data.inp","r", stdin);
		FILE *fout= freopen("data.out","w",stdout);
	#endif	
	read(g); 
	kruskal(g);
	fclose(fin); 
	fclose(fout); 
}
