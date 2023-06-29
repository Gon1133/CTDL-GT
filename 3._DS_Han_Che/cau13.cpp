#include<iostream>
using namespace std;

typedef float ElementType;
struct Node{
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
typedef Node* List;

void MakeNullList(List &L){
	L=new Node;
	L->Next=NULL;
}

bool EmptyList(List L){
	return L->Next==NULL;
}

void InsertList(ElementType X, Position P, List &L){
	Position T;
	T=new Node;
	T->Element=X;
	T->Next=P->Next;
	P->Next=T;
}

void DeleteList(Position P, List &L){
	Position T;
	if (P->Next==NULL){
		T=P->Next;
		P->Next=T->Next;
		delete T;
	}
}

Position Last(List L){
	Position P=L;
	while (P->Next!=NULL){
		P=P->Next;
	}
	return P;
}

void ReadList(List &L){
	ElementType X;
	do{
		cout << "Nhap noi dung ptu: ";
		cin>>X;
		if(X!=0) InsertList(X,Last(L),L);
	}while(X!=0);
}

void PrintList(List L){
	if(EmptyList(L)) cout << "Danh sach rong"<<endl;
	else while(L->Next!=NULL){
		cout << L->Next->Element<<" ";
		L=L->Next;
	}
}

Position Previous(Position P, List L){
	Position temp;
	if(P==L) return NULL;
	else{
		temp=L;
		while(temp->Next!=P) temp=temp->Next;
		return temp;
	}
}

void InsertX(ElementType X, List &L){
	Position P=L->Next;
	while (P->Next!=NULL){
		if (X > P->Element && X < P->Next->Element){
			InsertList(X,P,L);
		}
		P=P->Next;
	}
}


main(){
	List L;
	Position P;
	MakeNullList(L);
	cout << "NHAP DANH SACH LIEN KET TANG DAN"<<endl;
	ReadList(L);
	float X;
	cout << "Nhap so muon them: ";
	cin>>X;
	InsertX(X,L);
	cout << "IN DANH SACH LIEN KET TANG DAN"<<endl;	
	PrintList(L);
		
}
