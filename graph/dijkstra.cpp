#include <iostream>
using namespace std ; 
#define max 100
#define INFINITY 10000
struct graph
{
	int data[100][100];
	int n ; 
};

int save[100], check[100], dis[100];

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

/*void dijkstra(int G[max][max],int n,int startnode) {
   	int cost[max][max],distance[max],pred[max];
   	int visited[max],count,mindistance,nextnode,i,j;
   	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
   			if(G[i][j]==0)
      			cost[i][j]=INFINITY;
   			else
      			cost[i][j]=G[i][j];
	
   	for(i=0;i<n;i++) 
	{
      distance[i]=cost[startnode][i];
      pred[i]=startnode;
      visited[i]=0;
   }

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

   	while(count<n-1) {
      	mindistance=INFINITY;
      	for(i=0;i<n;i++)
         	if(distance[i]<mindistance&&!visited[i]) 
			{
         		mindistance=distance[i];
         		nextnode=i;
      		}
      	visited[nextnode]=1;
      	for(i=0;i<n;i++)
         	if(!visited[i])
		if(mindistance+cost[nextnode][i]<distance[i]) 
		{
			distance[i]=mindistance+cost[nextnode][i];
			pred[i]=nextnode;
		}
		count++;
   }
   for(i=0;i<n;i++)
   if(i!=startnode) 
   {
		cout<<"\nDistance of node "<<i<<"="<<distance[i];
		cout<<"\nPath="<<i;
		j=i;
		do 
		{
			j=pred[j];
			cout<<"<-"<<j;
		}
		while(j!=startnode);
   }
}

*/
int mindistance(graph g)
{
	int min = 999999 , min_index=-1;
	for (int i = 0; i < g.n; i++)
		if (check[i]==0 && dis[i] < min )
		{
			min = dis[i]; 
			min_index = i;
		}
		return min_index;
}

void update(int u, graph g)
{
	check[u] =1  ; 
	for (int  i = 0; i < g.n; i++)
	{
		if (check[i] == 0 && g.data[u][i]>0 && g.data[u][i] < INFINITY)
		if (dis[i] > dis[u] + g.data[u][i]) 
		{
			dis[i] = dis[u] + g.data[u][i];
			save[i]=u ;
		}
	}
	
}

void dijkstra(graph g ,int s, int e)
{
	for(int i = 0 ;i < g.n ; i++)
	{
		check[0]=  0; 
		dis[i] = INFINITY;
		save[i]=-1; 
	}
	dis[s]= 0 ;
	
	while (check[e]==0)
	{
		int u= mindistance(g);
		if(u==-1) break ; 
		update(u,g);
	}
	if (check[e]==1 )
	{
		cout << "duong di tu " <<s<<"->"<<e << "  la :  " ;
		int i= e ;
		cout <<e ;
		while (save[i]!= s)
		{
			cout << " <- " << save[i];
			i= save[i];
		}
		cout << " <- " << save[i] <<endl;
		cout <<"do dai :" << dis[e];
	}
	else 
		cout <<"khong co duong di ";
}
int main()
{
	#ifndef solve 
		FILE *fin = freopen("input.txt", "r", stdin); 
		FILE *fout = freopen("output.txt", "w", stdout) ; 
	#endif
	graph g ;

	read(g); 
	write(g); 
	dijkstra(g,1,2);
	fclose(fin);
	fclose(fout); 
	return 0;	
}
