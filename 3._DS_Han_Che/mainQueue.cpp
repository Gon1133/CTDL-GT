#include<iostream>
using namespace std;

typedef int ElementType;
struct Node{
 	ElementType Element;
 	Node* Next;
};
typedef Node* Position;

struct Queue{ 
	Position Front, Rear; 
};

void MakeNullQueue(Queue &Q){
	Q.Front=NULL; 
	Q.Rear=NULL; 
}

bool EmptyQueue(Queue Q){ 
	if(Q.Front==NULL && Q.Rear==NULL) return true;
	else return false; 
}

//them 1 ptu vao Queue
void EnQueue(ElementType X, Queue &Q){ 
	if(EmptyQueue(Q)){
		Q.Rear=new Node;
		Q.Front=Q.Rear;
		}
	else{
		Q.Rear->Next=new Node;
		Q.Rear=Q.Rear->Next;
		}
	Q.Rear->Element=X;
	Q.Rear->Next=NULL;
}

//tra ve gia tri ptu o dau hang doi
ElementType FirstQueue(Queue Q){ 
	if(EmptyQueue(Q)) return 0;
	else return Q.Front->Element;
} 

//xoa 1 ptu
void DeQueue(Queue &Q){ 
	if(!EmptyQueue(Q)){
		Position T=Q.Front;
 		Q.Front=Q.Front->Next;
		if(Q.Front==NULL) Q.Rear=NULL; 
		delete T; 
		} 
}

void ReadQueue(Queue &Q){
 	ElementType X;
 	do{
 		cout<<"Nhap noi dung phan tu: "; 
 		cin>>X;
 		if(X!=0)EnQueue(X,Q);
 	}while(X!=0);
} 

void PrintQueue(Queue &Q){
 	if(EmptyQueue(Q))
 		cout<<"Hang rong"<<endl;
 	else
 		while(!EmptyQueue(Q)){
 			cout<<FirstQueue(Q)<<'\t';
 			DeQueue(Q);
 		}
}

main()
{
 	Queue Q;
 	MakeNullQueue(Q);
 	cout<<"=====NHAP HANG DOI====="<<endl;
 	ReadQueue(Q);
	cout<<"=====IN HANG DOI====="<<endl;
 	PrintQueue(Q);
 	cout<<endl;
}

