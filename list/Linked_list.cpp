#include  "list.h"

node* creatNode(Data x)
{
	node* Node= new node ; 
	if (Node== NULL ) return NULL; 
	Node->data=x; // gian gia tri cho data 
	Node->pNext= NULL;// con tro tra ve NULL 	
}


node* creatNode(int x)
{
	Data data={x};	
	node* Node= creatNode(data) ; 
	return Node ; 
}


void init(List &lst)//khoi tao node 
{
	lst.pHead=lst.pTail = NULL ; 
}

bool isEmpty(List lst )//kiem tra node co rong hay khong  
{
	if (lst.pHead==NULL ) return true ; else return false ; 
}

void addHead (List &lst , node* pNode )
{
	if (isEmpty(lst))
	{
		lst.pHead=lst.pTail= pNode ; 
	}
	// neu nhu list rong thi con phan tu dau tien va phan tu cuoi cung = chinh Node 
	else 
	{
		pNode->pNext= lst.pHead;
		lst.pHead= pNode ; 
	}
	// neu nhu list khong rong thi gan Node vao phan tu dau tien  
}

void printList(List lst, char* massage){
	cout << massage << endl ;
	if (isEmpty(lst))
	{
		cout << "list is empty ";	
	}
	else 
	{
		node *Node = lst.pHead; // gian node vao phan tu dau tien 
		while (Node != NULL) 
		{
			cout << Node->data.x<< endl; 
			Node = Node->pNext; // gian node cho phan tu tiep theo 
		}
	}		
}

int List_size(List lst )// kiem tra so luong phan tu 
{
	if (isEmpty(lst)) return 0 ; 
	else 
	{
		node *Node = lst.pHead; 
		int count =0 ;
		while (Node != NULL) 
		{
			++ count ; 
			Node = Node->pNext; 
		}
		return count ; 	
	}
}

node* addTail(List &lst, node* pNode)
{
		if (isEmpty(lst))
	{
		lst.pHead=lst.pTail= pNode ; 
	}
	// neu nhu list rong thi con phan tu dau tien va phan tu cuoi cung = chinh Node 
	else 
	{
		lst.pTail->pNext=  pNode;
		lst.pTail= pNode ; 
	}
		
	// neu nhu list khong rong thi gan Node vao phan tu cuoi cung  
}

void Insert(List &lst, node* pos,node* pNode)
{
	if (pNode == NULL || pos == NULL ) return ;
	if (isEmpty(lst))
	{
		lst.pHead=lst.pTail= pNode ; 
	}
	else 
	if (lst.pTail== pos ) // neu pos la node cuoi list thi add vao cuoi 
		{
			addTail(lst,pNode);
		}
	else // n
		{
			pNode->pNext= pos->pNext;
			pos->pNext=pNode;
		}
}

node* Getnode(List &lst , int index )
{
	if (isEmpty(lst) && index < 0 ) return NULL;
	else 
	{
		int key= 0 ;
		node* pNode = lst.pHead ; 
		while (pNode != NULL && key < index )
		{
			++ key ; 
			pNode=pNode->pNext; 
		}
		return pNode ;
	}
	
}


void Insert(List &lst, int index,node* pNode)
{
	node* Node= Getnode(lst ,index); 
	if (Node!= NULL )
	{
		Insert(lst,Node,pNode);
	}
}
