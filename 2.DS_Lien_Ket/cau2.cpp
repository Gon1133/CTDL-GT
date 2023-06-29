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
	L = new Node;
	L->Next=NULL;
}

bool EmptyList(List L){
	return L->Next==NULL;
}

void InsertList(ElementType X, Position P, List &L){
	Position temp;
	temp = new Node;
	temp->Element=X;
	temp->Next=P->Next;
	P->Next=temp;
}

Position Last(List L){
	Position P;
	P=L;
	while (P->Next!=NULL)
		P=P->Next;
	return P;
}

void ReadList(List &L){
	ElementType X;
	do{
		cout << "Nhap noi dung ptu: ";
		cin >> X;
		if (X!=0)
			InsertList(X,Last(L),L);
	}while (X!=0);
}

void PrintList(List L){
	if (EmptyList(L)!=0)
		cout << "Danh sach rong"<<endl;
	else 
		while (L->Next!=NULL){
			cout << L->Next->Element<<" ";
			L=L->Next;
		}
}

Position Previous(Position P, List L){
	Position temp;
	if(P==L) return NULL;
	else{
		temp = L;
		while(temp->Next!=P)
			temp=temp->Next;
		return temp;
	}
}

Position Next(Position P, List L){
	return P->Next;
}

void DeleteList(Position P, List &L){
	Position temp;
	if(P->Next!=NULL){
		temp=P->Next;
		P->Next=temp->Next;
		delete temp;
	}
}

//cau a. sap xep ds tang dan
void TangDan(List &L){
	Position I=L;
	Position J;
	ElementType X;
	while(I->Next!=Last(L)){
		for(J=I->Next;J->Next!=NULL;J=J->Next){
			if(I->Next->Element > J->Next->Element){
				X = I->Next->Element;
				I->Next->Element = J->Next->Element;
				J->Next->Element = X;
			}		
		}
		I=I->Next;
	}
}

//sap xep ds giam dan
void GiamDan(List &L){
	Position I,J;
	I=L->Next;
	ElementType X;
	while(I->Next!=NULL){
		for(J=I->Next;J!=NULL;J=J->Next){
			if(I->Element < J->Element){
				X = I->Element;
				I->Element = J->Element;
				J->Element = X;
			}	
		}
		I=I->Next;
	}
}

//b. ghep 2 ds co thu tu giam dan thanh 1 ds co thu tu giam dan
void GhepDSGiam(List L, List T, List &O){
	Position l=L->Next;
	Position t=T->Next;
//	Position o=O;
	while (l!=NULL && t!=NULL){
		if (l->Element >= t->Element){
			InsertList(l->Element,Last(O),O);			
			l=l->Next;
		}
		else{
			InsertList(t->Element,Last(O),O);
			t=t->Next;
		}
	}
	for (Position P=l; P!=NULL; P=P->Next){
		InsertList(P->Element,Last(O),O);
	}
	for (Position P=t; P!=NULL; P=P->Next){
		InsertList(P->Element,Last(O),O);
	}
	PrintList(O);
	
}

//d. tim ptu MIN
ElementType MinList(List L){
	ElementType X=L->Next->Element;
	for (Position P=L->Next->Next; P!=NULL; P=P->Next){
		if (P->Element < X){
			X = P->Element;
		}
		
	}
	return X;
}

//g. cho bt ptu nho nhat la ptu thu may trong ds
int ViTriMin(List L){
	Position P=L->Next;
	int d=1;
	while (P!=NULL){
		if (P->Element == MinList(L)){
			return d;
		}
		else{
			P=P->Next;
			d++;
		}
	}
}

//i. tong ptu co phan nguyen la boi so cua K
ElementType TongBoiSo(int K, List L){
	Position P=L->Next;
	ElementType S=0;
	while (P!=NULL){
		if (K % int(P->Element) == 0){
			S = S + P->Element;
		}
		P=P->Next;
	}
	return S;
}



main(){
	List L;
	Position P;
	MakeNullList(L);
	cout << "NHAP DANH SACH LIEN KET"<<endl;
	ReadList(L);
	cout << "IN DANH SACH LIEN KET"<<endl;
	PrintList(L);
	cout << endl;
//cau a
//	TangDan(L);
//	cout << "ds sau khi sap xep"<<endl;
//	PrintList(L);
//	cout << endl;	
//cau b
	List A;
	Position a;
	MakeNullList(A);
	cout << "NHAP DANH SACH A"<<endl;
	ReadList(A);
	cout << "IN DANH SACH A"<<endl;
	GiamDan(A);
	PrintList(A);
	cout << endl;
	List B;
	Position b;
	MakeNullList(B);
	cout << "NHAP DANH SACH B"<<endl;
	ReadList(L);
	cout << "IN DANH SACH B"<<endl;
	GiamDan(B);
	PrintList(B);
	cout << endl;
	List C;
	Position c;
	MakeNullList(C);
	GhepDSGiam(A,B,C);
//cau d
//	cout << "ptu nho nhat trong ds la: "<<MinList(L)<<endl;
//cau g
//	cout << "vi tri ptu no nhat la: "<< ViTriMin(L)<<endl;
//cau i
//	int K;
//	cout << "Nhap boi so K = ";
//	cin >> K;
//	cout << "tong cac ptu la boi so cua "<<K<<" la: "<<TongBoiSo(K,L)<<endl;
	
	
}
