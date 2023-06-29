#include<iostream>

using namespace std;

typedef int ElementType;
struct Node{
	ElementType Element;
	Node* Next;
};
typedef Node* Stack;
typedef Node* Position;

void MakeNullStack(Stack &S){
	S=NULL;
}

bool EmptyStack(Stack S){
	if (S==NULL) return true;
	else return false;
}

//them 1 ptu vao stack
void Push(ElementType X, Stack &S){
	Position T;
	T=new Node;
	T->Element=X;
	T->Next=S;
	S=T;
}

//lay ptu tren cung cua stack
ElementType Top(Stack S){
	if (EmptyStack(S)) return 0;
	else return S->Element;
}

//xoa 1 ptu tu stack neu ko con thi tu xoa chinh no
void Pop(Stack &S){
	if (!EmptyStack(S)){
		Position T=S;
		S=S->Next;
		delete T;
	}
}

void ReadStack(Stack &S){
	ElementType X;
	do{
		cout << "Nhap noi dung ptu: ";
		cin>>X;
		if(X!=0) Push(X,S);
	}while(X!=0);
}

void PrintStack(Stack &S){
	if(EmptyStack(S)) cout << "Danh sach rong"<<endl;
	else 
		while(S!=NULL){
			cout << Top(S)<<" ";
			Pop(S);
		}
}

//doi 10 sang 2
void Dec_Bin(int n, Stack &S){
	int a;
	while(n > 0){
		a=n%2;
		Push(a,S);
		n=n/2;
	}
	cout << "nhi phan: ";
	PrintStack(S);
	cout << endl;
}


main(){
	Stack S;
	MakeNullStack(S);
	int n;
	cout << "Nhap so thap phan: ";
	cin>>n;
	Dec_Bin(n,S);
}
