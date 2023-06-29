#include<iostream>
#include<string.h>
using namespace std;

//xay dung cau truc theo ds lien ket
struct Sinhvien{
	int mssv;
	char hoten[30];
	float dtb;
}SV;

typedef Sinhvien ElementType;
struct Node{
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
typedef Node* List;

void MakeNullList(List &L){
	L = new Node;
	L->Next = NULL; 
}

bool EmptyList(List L){
	return L->Next==NULL;
}


Position Last(List L){
	Position P=L;
	while (P->Next!=NULL)
		P=P->Next;
	return P;
}

void InsertList(ElementType X, Position P, List &L){
	Position t;
	t = new Node;
	t->Element.mssv=X.mssv;
	strcpy(t->Element.hoten,X.hoten);
	t->Element.dtb=X.dtb;
	t->Next=P->Next;
	P->Next=t;
}

void ReadList(List &L){
	ElementType X;
	do{
		cout << "Nhap ma so sinh vien: ";
		cin >> X.mssv;
		if (X.mssv==0) 
			break;
		cin.ignore(1);
		cout << "Nhap ho ten sinh vien: ";
		cin.getline(X.hoten,30);
		cout << "Nhap diem trung binh: ";
		cin >> X.dtb;
//		if (X.mssv!=0)
		InsertList(X,Last(L),L);
	}while(X.mssv!=0);	
}

void PrintList(List L){
	if (EmptyList(L)!=0){
		cout << "Danh sach rong" << endl;
	}
	else{
		int i=0;
		while (L->Next!=NULL){
			cout << "Thong tin sinh vien thu " <<i+1<<endl;
			cout << "mssv: " << L->Next->Element.mssv << '\n';
			cout << "ho ten: " << L->Next->Element.hoten << '\n';
			cout << "diem trung binh: " << L->Next->Element.dtb << '\n';
			i++;
			L=L->Next;
		}
	}
}

//dem so SV co trong ds
int Reccount(List L){
	Position P=L;
	int d=0;
	while (P->Next!=NULL){
		P=P->Next;
		d++;
	}
	return d;	
}

//them 1 sv vao vi tri i
void addSV(List &L,int i){
	ElementType X;
	cout << "Nhap ma so sinh vien: ";
	cin >> X.mssv;
	cin.ignore(1);
	cout << "Nhap ho ten sinh vien: ";
	cin.getline(X.hoten,30);
	cout << "Nhap diem trung binh: ";
	cin >> X.dtb;
	if (i==0)
		InsertList(X,L,L);
	if (i>Reccount(L))
		InsertList(X,Last(L),L);
	if (i>0 && i<=Reccount(L)){
		Position P=L;
		while (i>0){
			P=P->Next;
			i--;
		}
		InsertList(X,P,L);
	}
}

main(){
	List L;
	Position P;
	MakeNullList(L);
	cout << "NHAP DANH SACH SINH VIEN"<<endl;
	ReadList(L);
	cout << "IN DANH SACH SINH VIEN"<<endl;
	PrintList(L);
	cout << "Tong so ptu co trong danh sach = " << Reccount(L)<<endl;
	int i;
	cout << "Nhap vi tri can them: ";
	cin>>i;
	addSV(L,i);
	cout << "IN DANH SACH SINH VIEN SAU KHI THEM"<<endl;
	PrintList(L);
}
