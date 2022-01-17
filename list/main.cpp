#include "Linked_list.cpp"

int main()
{
	List lst ; 
	Data res= {69}; 
	 
	init(lst);
	
	if(isEmpty(lst)) cout << "list is empty " <<endl;
		
	node *Node = creatNode(98); 
	addHead (lst,Node);
	
	Node = creatNode(97); 
	addHead (lst,Node);
	
	Node = creatNode(11); 
	addTail(lst,Node);
	
	Node = creatNode(12); 
	addTail(lst,Node);
	
	Insert(lst, 3 , creatNode(15));
	printList(lst , "list :");
	
	int size = List_size(lst); 
	cout << "size :"<< size <<endl  ; 
	
	return 0  ; 
}



