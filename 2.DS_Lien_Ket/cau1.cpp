#include<iostream>
using namespace std;
//khai bao cau truc du lieu
typedef int ElementType;
struct Node{
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
typedef Node* List;
//tao danh sach rong
void MakeNullList(List &L){
	L=new Node;
	L->Next=NULL;
}
//ktra danh sach rong
bool EmptyList(List L){
	return L->Next==NULL;
}
//them mot phan tu
void InsertList(ElementType X, Position P, List &L){
	Position temp;
	temp=new Node;
	temp->Element=X;
	temp->Next=P->Next;
	P->Next=temp;
}
//xac dinh phan tu cuoi cung
Position Last(List L){
	Position P;
	P=L;
	while(P->Next!=NULL)
		P=P->Next;
	return P;
}
//xac dinh phan tu dung sau P
Position Next(Position P, List L){
	return P->Next;
}
//xac dinh phan tu dung ngay truoc P
Position Previous(Position P, List L){
	Position temp;
	if(P==L) return NULL;
	else{
		temp=L;
		while(temp->Next!=P) temp=temp->Next;
		return temp;
	}
}
//dinh vi mot phan tu 
Position Locate(ElementType X, List L){
	Position P;
	int found=0;
	P=L;
	while(P->Next!=NULL && found==0)
		if(P->Next->Element==X)
			found=1;
		else P=P->Next;
	return P->Next;
}
//xoa phan tu ngay sau P
void DeleteList(Position P, List &L){
	Position temp;
	if(P->Next!=NULL){
		temp=P->Next;
		P->Next=temp->Next;
		delete temp;
	}
}
//nhap danh sach
void ReadList(List &L){
	ElementType X;
	do{
		cout << "Nhap noi dung phan tu: ";
		cin >> X;
		if(X!=0) InsertList(X, Last(L),L);
	}while(X!=0);
}
//in danh sach
void PrintList(List L){
	if(EmptyList(L)!=0)
		cout << "Danh sach rong"<<endl;
	else
		while(L->Next!=NULL){
			cout << L->Next->Element<<" ";
			L=L->Next;
		}
}
//xac dinh noi dung mot phan tu
ElementType Retrieve(Position P, List L){
	if(P!=NULL) return P->Element;
	else return 0;
	
}


//a. them 1 ptu vao sau Y xuat hien cuoi cung
void InsertZY(ElementType Z,ElementType Y,List &L){
	Position P;
	P=L;
	int d2,d1=0;
	while(P->Next!=NULL){
		if(P->Next->Element==Y){
			d1=d1+1;
			cout <<"d1 = "<< d1 << '\n';
		}
		P=P->Next;
	}
	P=L;
	while(P->Next!=NULL){
		if(P->Next->Element==Y){
			d2=d2+1;
			if(d2==d1){
				cout <<"d2 = "<< d2 << '\n';
				P=P->Next;
				InsertList(Z,P,L);
			}
		}
		P=P->Next;
	}
}
//d. xoa tat ca pt X co trong danh sach(1)
void DeleteX(ElementType X,List &L){
	Position P;
	P=L;
	while (P->Next!=NULL){					
		if(P->Next->Element==X){
			DeleteList(P,L);			
		}
		else
			P=P->Next;
	} 
}
//xoa tat ca pt X co trong danh sach(2)

//f. In tu X xuat hien o lam thu K den cuoi danh sach
void PrintXK(ElementType X, int K, List L){
	Position P=L;
	int d=1;
	while (P->Next!=NULL){
		if(P->Next->Element==X){
			if(d==K){
				while(P->Next!=NULL){
					cout << P->Next->Element<<" ";
					P=P->Next;
				}
			}
			else{
				d+=1;
			} 
		}
		P=P->Next;
	}
}

//g. tách 1 ds thành 2 ds chua nd tuong ung là chan le
void Separate(List &L, List &O){
	Position P=L;
	Position K=O;
	ElementType t;
	while(P->Next!=NULL){
		if(P->Next->Element%2==0){
			t=P->Next->Element;
			InsertList(t,K,O);
			K=K->Next;
			DeleteList(P,L);
		}
		P=P->Next;
	}
}

//h. ghep ds 2 vao chinh giua ds 1
void Graft(List &L, List &O){
	Position P=L;
	Position K=O;
	ElementType t;
	int d1,d2=0;
	while(P->Next!=NULL){
		P=P->Next;
		d1+=1;
		cout << d1 << '\n';
	}
	P=L;
	while(P->Next!=NULL){
		if(d2==d1/2){
			while(K->Next!=NULL){
				cout << "111"<<'\n';
				t=K->Next->Element;
				InsertList(t,P,L);
				P=P->Next;
				DeleteList(K,O);	
			}
			break;
		}
		else{
			d2+=1;
			P=P->Next;
		} 
	}
}

main(){
	List L;
	Position P;
	ElementType X;
	MakeNullList(L);
	cout << "NHAP DANH SACH LIEN KET" << endl;
	ReadList(L);
	cout << "IN DANH SACH LIEN KET" << endl;
	PrintList(L);
	cout << endl;
//	cout << "Nhap ptu muon xoa: ";
//	cin >> X;
//	DeleteX(X,L);
//	ElementType Z,Y;
//	cout << "nhap ptu muon them: ";
//	cin >> Z;
//	cout << "nhap Y: ";
//	cin >> Y;
//	InsertZY(Z,Y,L);
//	ElementType F;
//	int K;
//	cout << "Nhap ptu muon bat dau in: ";
//	cin >> F;
//	cout << "Nhap thu tu cua ptu "<< F <<": ";
//	cin >> K;
//	PrintXK(F,K,L);
	List O;
	Position K;
	MakeNullList(O);
	Separate(L,O);

	

	cout << "DANH SACH LIEN KET SAU KHI XU LY"<<endl;
	PrintList(L);
	cout << endl; 
	PrintList(O);
	cout << endl;
	cout << "cau h"<<endl;
	Graft(L,O);
	PrintList(L);
	
	
}
