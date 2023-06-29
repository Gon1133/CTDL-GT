#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct Node
{
 	ElementType Element;
 	Node* Next;
};
typedef Node* Position;
typedef Node* Stack;


void MakeNullStack(Stack &S)
{
 	S=NULL;
}

bool EmptyStack(Stack S)
{ 
 	if(S==NULL) 
		return true;
	else 
		return false; 
}

void Push(ElementType X, Stack &S)
{ 
	Position Temp; 
	Temp=new Node; 
	Temp->Element=X;
	Temp->Next=S;
	S=Temp;
}
ElementType Top(Stack S)
{
	if(EmptyStack(S)) 
		return 0;
	else 
		return S->Element;
}
void Pop(Stack &S)
{
	if(!EmptyStack(S))
	{
		Position Temp=S;
		S=S->Next;
 		delete Temp;
	}
}

void ReadStack(Stack &S)
{ 
	ElementType X;
 	do{
 		cout<<"Nhap noi dung phan tu: "; 
 		cin>>X;
 		if(X!=0)Push(X,S);
 	}while(X!=0);
}

void PrintStack(Stack &S)
{
 	if(EmptyStack(S))
 		cout<<"Ngan xep rong"<<endl;
 	else
 		while(S!=NULL){
 			cout<<Top(S)<<'\t';
 			Pop(S);
 		}
}

main()
{ 
	Stack S;
	MakeNullStack(S);
	cout<<"=====NHAP NGAN XEP====="<<endl;
	ReadStack(S);
	cout<<"=====IN NGAN XEP====="<<endl;
	PrintStack(S);
	cout<<endl;
}


