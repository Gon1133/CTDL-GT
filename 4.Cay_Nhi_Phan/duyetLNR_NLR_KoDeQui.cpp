#include<iostream>
using namespace std;

//Cai dat Cay nhi phan
typedef int Info;
struct BinT_Node{
	Info Key;
	BinT_Node *Left;
	BinT_Node *Right;
};
typedef BinT_Node *BinT_Type;
void Initialize(BinT_Type &BTree){
	BTree=new BinT_Node;
	BTree->Left=NULL;
	BTree->Right=NULL;
}

void ReadTree(BinT_Type &BTree){
	Info X;
	    cin>>X;
	    if(X!=0){
	   		BTree=new BinT_Node;
	   		BTree->Key=X;
	   		BTree->Left=NULL;
	   		BTree->Right=NULL;
	   		cout<<"Nhap con trai cua "<<X<<": ";
	   		ReadTree(BTree->Left);
	   		cout<<"Nhap con phai cua "<<X<<": ";
	   		ReadTree(BTree->Right);
	  	}
		
	
}

//Cai dat Stack
typedef BinT_Type ElementType;
struct Node{
	ElementType Element;
	Node *Next;
};
typedef Node *Position;
typedef Node *Stack;
void MakeNullStack(Stack &S){
	S=NULL;
}
bool EmptyStack(Stack S){
	return S==NULL;
}
void Push(ElementType X, Stack &S){
	Position Temp = new Node;
	Temp->Element =X;
	Temp->Next=S;
	S=Temp;
}
BinT_Type Top(Stack S){
	return S->Element;
}
void Pop(Stack &S){
	Position Temp;
	Temp=S;
	S=Temp->Next;
	delete Temp;
}

void DuyetNLR(BinT_Type BTree){ //Node-Left-Right
	BinT_Type Current=new BinT_Node;
	Stack S;
	Current=BTree;
	MakeNullStack(S);
	while(Current!=NULL){
		cout<<Current->Key<<"\t";
		if(Current->Right!=NULL)
			Push(Current,S);
		if(Current->Left != NULL)
			Current=Current->Left;
	    else{
	    	Current=Top(S)->Right;
	    	Pop(S);
		}
	}
}
void DuyetLNR(BinT_Type BTree){
	bool flag=false;
	Stack S;
	BinT_Type Current=new BinT_Node;
	Current=BTree;
	MakeNullStack(S);
	while(Current!=NULL){
		if(flag==false)
			Push(Current, S);
		if(Current->Left!=NULL){
			Current=Current->Left;			
		}
		else{		
			Current=Top(S);
			Pop(S);
			cout<<Current->Key<<"\t";
			flag=true;
			if(Current->Right!=NULL){
				Current=Current->Right;
				flag=false;
			}
		}			
	}
}


main(){
	BinT_Type BTree;
//	Stack S;
	Initialize(BTree);
	ReadTree(BTree);
//	cout<<"Duyet cay Node-Left-Right: ";
//	DuyetNLR(BTree, S);
	cout<<"Duyet cay Left-Node-Right: ";
	DuyetLNR(BTree);
}
