#include <bits/stdc++.h>
using namespace std ; 
struct graph
{
	int data[100][100];
	int n ; 
};

//đọc dữ liệu
void read(graph &g)
{
	cin >> g.n ; 
	for (int i = 0; i < g.n; ++i)
		for (int j = 0; j  < g.n; ++j)
			cin >> g.data[i][j]; 
}

//in dữ liệu
void write(graph g)
{
	for (int i = 0; i < g.n; ++i)
	{
		for (int j = 0; j  < g.n; ++j) 
			cout <<  g.data[i][j] << " " ; 
		cout << endl; 
	} 
}

//kiểm tra đồ thị 
bool check_graph(graph g)
{
	for (int i = 0; i < g.n; ++i)
		if (g.data[i][i]!= 0 )
			return false; 
	return true  ; 
}

// kiểm tra đồ thị vô hướng ,có hướng
bool check_directed_graph(graph g)
{
	for (int i = 0; i < g.n; ++i)
		for (int j = 0; j < g.n; ++j)
			if (g.data[i][j] == g.data[j][i]) return true ;
	return false ; 			
}

//kiểm tra tính liên thông 
bool check_conectivity (graph g)
{
	int ans[1000],count,res;
	for (int i = 0; i < g.n ; ++i) ans[i]= 0 ; 
	ans[0]= 1  ;
	count ++ ; 
	do 
	{
		res =1;		//Giả sử không còn khả năng loang
		for(int i = 0; i< g.n; i++)
		if(ans[i]==1) 
		{
			for(int j = 0; j<g.n; j++)
			if (ans[j] == 0 && g.data[i][j] > 0)
			{
				ans[j] = 1;
				res = 0;	//Thực tế còn khả năng loang
				count++;
				if(count == g.n) 
					return true ;
			}
		}
	}while (res == 0);
	return false;
}
int main()
{
	// tiền xử lý file 
	#ifndef solve 
		FILE *fin = freopen("input.txt", "r", stdin); 
		FILE *fout = freopen("output.txt", "w", stdout) ; 
	#endif

	// code
	graph g ;

	read(g); 
	write(g); 

	//kiểm tra đồ thị hợp lệ
	if (check_graph(g)) 
		cout <<"đồ thị hợp lệ" <<endl;
	else 
		cout << "đồ thị không hợp lệ "<< endl; 

	// kiểm có hướng ,vô hướng 
	if (check_directed_graph(g)) 
		cout << "đồ thị có hướng " << endl; 
	else cout << "đồ thị vô hướng" << endl ; 

	//đóng file 
	fclose(fin);
	fclose(fout); 
	return 0;	
}
