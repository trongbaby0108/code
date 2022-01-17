#include<bits/stdc++.h>
#define lgh length 
using namespace std; 
int num ; 
string data[10000]; 
void readInput()
{
	ifstream source("stack.inp") ; 
	source >> num ;
	for (int i= 0 ; i < num; i++ ) source >> data[i];  
}
bool check(string a)
{
	int key=a.lgh();
	int res=-1 ; 
	for (int i= 0 ; i< key;i++  )
	{
		if (a[i]=='(' ) res ++ ; 
		else 
			if (a[i]=')')  
				if (res== -1 ) 
				{
					return false  ; 
					break  ; 
				}
				else res--; 
	} 
	if (res==-1) return true ; else return false ; 
}
void solve ()
{
	for (int i= 0 ; i < num; i++ ) 
		if (check(data[i])) 
			{
				cout<< data[i];
				cout<< "perfect" <<endl ; 
			}	
	else 
		{
			cout << data[i];
			cout << "not perfect" <<endl; 
		}
}

int main ()
{
	readInput();
	solve(); 
	return 0 ; 
}
