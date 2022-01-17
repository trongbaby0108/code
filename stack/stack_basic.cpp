bool stackfull(int varable)
{
	if(top>= varable)  return true ; else return false ; 
}
bool stackempty()
{
	if (top==-1 ) return true; else return false ; 
}
void pushstack(int stack[],char varable ,int heigh)
{ 
	if (stackfull(heigh)) cout << " stack is full " << endl ; 
	else  
	{
		top++; 
		stack[top] = varable ; 
	}
}
void popstack()
{
	if (stackempty()) cout <<" stack is empty " << endl;  else top--; 
}	
int topstack(int stack[])
{
	return stack[top]; 
}
