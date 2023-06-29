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

main(){
	List L;
	Position P;
	ElementType X,ND;
	MakeNullList(L);
	cout << "NHAP DANH SACH LIEN KET" << endl;
	ReadList(L);
	cout << "IN DANH SACH LIEN KET" << endl;
	PrintList(L);
	cout << endl;
	cout << "Phan tu dau tien trong danh sach la: ";
	cout << Last(L)->Element<<endl;
	cout << "Nhap noi dung ptu can them: ";
	cin >> X;
	cout << "Ban muon them sau phan tu nao: ";
	cin >> ND;
	P=Locate(ND,L);
	if (P==NULL) cout << "Khong them duoc" << endl;
	else InsertList(X,P,L);
	cout << "Ban muon them truoc phan tu nao: ";
	cin >> ND;
	P=Locate(ND,L);
	P=Previous(P,L);
	if (P==NULL) cout << "Khong them duoc"<<endl;
	else InsertList(X,P,L);
	cout << "DANH SACH LIEN KET SAU KHI THEM"<<endl;
	PrintList(L);
	cout << endl;
	cout << "Ban muon xoa phan tu sau phan tu nao: ";
	cin >> ND;
	P=Locate(ND,L);
	if(P==NULL) cout << "Khong xoa duoc" <<endl;
	else DeleteList(P,L);
	cout << "DANH SACH LIEN KET SAU KHI XOA"<<endl;
	PrintList(L); 
}
