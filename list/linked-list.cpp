#include<bits/stdc++.h>
using namespace std;
//dinh nghia cau truc 1 SV
struct arr
{
	string id , name;
	float mark;  
}; 

//dinh nghia 1 node trong dslk 
struct node 
{
	arr info ; 
	node * next;
};

//dinh nghia cau truc danh sach lien ket
struct lst 
{
	node *phead;
	node *ptail;
};
  
// khoi tao 1 node voi gia tri vao la 1 SV
node* creatnode(arr data)
{
	node *x= new node ;
	x->info = data; 
	x->next = NULL; 
	return x;
}

// khoi tao dslk
void init( lst &x)
{
	x.phead = x.ptail = NULL ; 
}

//kiem tra rong
bool isempty(lst x)
{
	return (x.phead == NULL);
}

//them vao dau
void add_head(lst &x , arr data)
{
	node *cmp= creatnode(data);
	if (x.phead == NULL) // neu dslk dang rong thi cmp se la phan tu dau tien cua dslk
		x.phead = x.ptail =cmp ;
	else // nguoc lai thi them vao dau 
	{
		cmp->next=x.phead;
		x.phead =cmp ;
	}
}

//them vao cuoi 
void add_tail(lst &x, arr data )
{
	if (isempty(x)) x.phead=x.ptail =creatnode(data);  // neu dslk dang rong thi cmp se la phan tu dau tien cua dslk
	else // nguoc lai thi them vao cuoi
	{
		node *cmp = creatnode(data);
		x.ptail->next=cmp ;
		x.ptail =cmp ; 
	}
}

// them vao sau 1 phan tu nao do trong dslk 
void add_at(lst &x , arr data , node *p)
{
	if (p== NULL ) add_head(x, data) ;
	else
	{
		node *temp =creatnode(data);
		temp -> next  = p->next;
		p-> next = temp; 
	}
}

// xoa o dau 
void delete_head(lst &x)
{
	node *q=x.phead;
	x.phead= x.phead->next; 
	delete q; 
	return ;
}

//xoa cuoi 
void delete_tail(lst &x)
{
	if (x.phead == x.ptail) delete_head(x);
	node *i = x.phead->next ,*q= x.ptail; 
	while (i->next != x.ptail ) i=i->next;
	x.ptail = i;
	x.ptail->next = NULL;
	delete q;
	return ;
}

//xoa sau 1 phan tu nao do 
void delete_at(lst &x, node *q)
{
	if ( q != NULL )
	{
		node *p= q->next;
		if (p != NULL)
		{
			if (x.ptail == p) x.ptail == q;
			q->next = p->next;
			delete p ;
		}
	}
}

// sap xep 
void sort(lst &x)
{
	for(node *i=x.phead; i!=x.ptail;i = i->next)
		for (node *j = i->next ; j != NULL; j=j->next)
			if(i->info.mark > j->info.mark) swap(i->info ,j->info);
}

// tim max
node *max(lst x)
{
	node *max= x.phead;	
	for(node *i=x.phead; i!=NULL;i = i->next)
		if(max->info.mark < i->info.mark) max= i;
	return max;	 
}

// in ra so luong phan tu co trong dslk 
int size(lst x)
{
	int res = 0 ;
	for (node *i = x.phead; i != NULL; i= i->next)  res ++ ; 
	return res;
}

//nhap 1 sv 
void read(arr &x)
{
	fflush(stdin);
	cout <<"nhap ms :";
	getline(cin, x.id);
	fflush(stdin);
	cout <<"nhap ten:";
	getline(cin, x.name);
	cout <<"nhap diem:";
	cin >> x.mark;
}

//in 1 sv
void print(arr x)
{
	cout << "[ " << x.id<< " " << x.name << " " << x.mark << " ]"<<endl;
}
// nhap du lieu 
void input(lst &x)
{
	int key = 1; 
	arr data;
	while(key == 1 )
	{
		cout << "nhap du lieu : " <<endl; 
		read(data); 
		add_tail(x, data);
		cout << "0: thoat " <<endl; 
		cout << "1: tiep tuc" <<endl;
		cin >> key ;
	}
}

//in danh sach 
void printlist(lst x)
{
	if (isempty(x)) cout << "danh sach dang rong ";
	else 
	{
		cout <<"danh sach :" <<endl;
		for(node *i=x.phead; i!=NULL;i = i->next) print(i->info);		
		cout << endl;	
	}
}

//xoa sau 1 sv nao do co id== key 
void deleteatx(lst &x)
{
	string id ;
	cout << "nhap ma so sinh vien can xoa :";
	fflush(stdin);
	getline(cin , id );
	for(node *i=x.phead; i!=NULL;i = i->next) 
	if (i->info.id == id) delete_at(x,i);	
}

// xoa theo ten 
void deletename(lst x)
{	
	lst res = x;
	string name; 
	cout << "nhap ten can xoa :";
	fflush(stdin);
	getline(cin , name );
	node *q=res.phead;
	while (x.phead->info.name == name)  delete_head(x);
	while(q->next != NULL)
	{
		
		if (res.ptail->info.name==name)
		{
			delete_tail(res);
		}
		if (q->next->next !=NULL && q->next->info.name==name) 
		{
			delete_at(x,q);
		}
		q= q-> next;
	}
}
void massage()
{
	cout << "0 : thoat " <<endl;
	cout << "1 : nhap du lieu"<<endl;
	cout << "2 : tim sv co diem so lon nhat"<<endl;
	cout << "3 : sap xep"<<endl;
	cout << "4 : xoa sinh vien sau sinh vien theo ma so "<<endl;
	cout << "5 : xoa sinh vien theo ten"<<endl;
	cout << "6 : in danh sach lien ket "<<endl;

}

void menu(lst &x)
{
	int ans ;

	while(true)
	{
		massage();
		cin >> ans;	
		switch (ans)
		{		
			case 1:
				input(x);
				break;
			case 2:
				print(max(x)->info);
				break;
			case 3:
				sort(x);
				break;
			case 4:
				deleteatx(x); 
				break;
			case 5:
				deletename(x);
				break;
			case 6:
				printlist(x);
			default: 
				return ;
		};
	}
}
int main ()
{
	lst x;
	init(x);
	menu(x);
}
