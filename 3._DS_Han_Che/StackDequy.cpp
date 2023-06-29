#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct Node
{
 ElementType Element;
 Node* Next;
};
typedef Node* Position;
typedef Node* List;
typedef Node* Stack;
void MakeNullList(List &L)
{
 L = new Node;
 L->Next=NULL;
}
bool EmptyList(List L)
{
 return L->Next==NULL;
}
void InsertList(ElementType X, Position P, List &L)
{ Position Temp;
Temp=new Node;
Temp->Element=X;
Temp->Next=P->Next;
P->Next=Temp;
}
Position Last(List L)
{
 Position P=L;
 while(P->Next!=NULL)
 P=P->Next;
 return P;
}
void ReadList(List &L)
{ ElementType X;
 do{
 cout<<"Nhap noi dung phan tu: ";
 cin>>X;
 if(X!=0)
 InsertList(X, Last(L),L);
 }while(X!=0);
}
void PrintListRecursion(List L)
{
if(L->Next!=NULL)
 {
 cout<<L->Next->Element<<'\t';
 PrintListRecursion(L->Next);
 }
}
void PrintList(List L)
{
 if(EmptyList(L)!=0)
 cout<<"Danh sach rong"<<endl;
 else
 while(L->Next!=NULL)
 {
 cout<<L->Next->Element<<'\t';
 L=L->Next;
 }
}
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
{ Position Temp;
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
//Xuat nguoc de qui
void ContPrintListRecursion(List L)
{
 if(L->Next!=NULL)
 {
 ContPrintListRecursion(L->Next);
 cout<<L->Next->Element<<'\t';
 }
}
//Xuat nguoc khong de qui
void ContPrintList(List L)
{ Stack S;
 MakeNullStack(S);
 while(L->Next!=NULL){
 Push(L->Next->Element,S);
 L=L->Next;
 }
 while(!EmptyStack(S))
 {
cout<<Top(S)<<'\t';
 Pop(S);
}
}
main()
{ List L;
 MakeNullList(L);
 cout<<"=====NHAP DANH SACH LIEN KET====="<<endl;
 ReadList(L);
 cout<<"=====IN XUOI KHONG DE QUI====="<<endl;
 PrintList(L);
 cout<<endl;
 cout<<"=====IN XUOI DE QUI====="<<endl;
 PrintListRecursion(L);
 cout<<endl;
 cout<<"=====IN NGUOC DE QUI====="<<endl;
 ContPrintListRecursion(L);
 cout<<endl;
 cout<<"=====IN NGUOC KHONG DE QUI====="<<endl;
 ContPrintList(L);
}

