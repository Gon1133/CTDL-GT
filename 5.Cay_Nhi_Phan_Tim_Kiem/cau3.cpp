#include<iostream>
using namespace std;

typedef int Info;
struct BST_Node{
	BST_Node* Left;
	BST_Node* Right;
	int Count;
	Info Key;
};
typedef BST_Node* BST_Type;

void Initialize(BST_Type &BST){
	BST = NULL;
}

BST_Type Create_Node(Info NewData){
	BST_Type BSTNode = new BST_Node;
	if (BSTNode != NULL){
		BSTNode->Left = NULL;
		BSTNode->Right = NULL;
		BSTNode->Key = NewData;
	}
	return BSTNode;
}

void Read_Tree (BST_Type &BST){
	Info X;
	cin >> X;
	if (X!=0){
		BST_Type BT;
		BT = Create_Node(X);
		BST = BT;
		cout << "Nhap con trai cua "<<X<<" : ";
		Read_Tree(BST->Left);
		cout << "Nhap con phai cua "<<X<<" : ";
		Read_Tree(BST->Right);
	}
	else BST=NULL;
}

void Add_Node(BST_Type &BST, Info NewData){ 
	if(BST == NULL){
		BST = new BST_Node;
		if(BST != NULL){
			BST->Left = NULL; 
			BST->Right = NULL; 
			BST->Key = NewData; 
		}
	}
	else //BST != NULL
		if(BST->Key == NewData) return;
		else 
			if(BST->Key > NewData) 
				Add_Node(BST->Left, NewData);
			else
				Add_Node(BST->Right, NewData);
}


void Auto_Read(BST_Type &BST){
	Info X;
	cout << "Nhap khoa: ";
	cin >> X;
	cout << endl;
	while (X!=0){
		Add_Node(BST, X);
		cout << "Nhap khoa tiep theo: ";
		cin >> X;
	}
	cout << "Ket thuc nhap cay" << endl;
}

void InLNR(BST_Type BST){
	if (BST == NULL) return;
	InLNR(BST->Left);
	cout << BST->Key << " ";
	InLNR(BST->Right);
}

//a. in tu goc den nut K 
void RtoK(BST_Type BST,Info K){
	if (BST!=NULL){
		cout << BST->Key << " ";
		if (BST->Key < K)
			RtoK(BST->Right,K);
		else RtoK(BST->Left,K);
	}
}

//b. in tu K ve goc
void KtoR(BST_Type BST,Info K){
	if (BST!=NULL){
		if(BST->Key < K)
			KtoR(BST->Right,K);
		else KtoR(BST->Left,K);
		cout << BST->Key << " ";
	}
}

//c. in tu goc den nut max
void RtoMax(BST_Type BST){
	if (BST!=NULL){
		cout << BST->Key<<" ";
		RtoMax(BST->Right);
	}
}

//d. in tu nut min ve goc 
void MintoR(BST_Type BST){
	if (BST!=NULL){
		MintoR(BST->Left);
		cout << BST->Key<<" ";
	}
}

//e. in tu min den max
void MintoMax(BST_Type BST){
	MintoR(BST);
	RtoMax(BST->Right);
}

//g. in cac nut lon hon K
void RK(BST_Type BST , Info K){
	if (BST!=NULL){
		if(BST->Key==K)
			InLNR(BST->Right);
		else if(BST->Key < K)
			RK(BST->Right, K);
			else{
				RK(BST->Left,K);
				cout << BST->Key <<" ";
				InLNR(BST->Right);
			}
	}
}



main(){
	BST_Type BST;
	BST = NULL;
//	cout << "NHAP BST:"<<endl;
//	Auto_Read(BST);
//	cout << "CAY BST VUA NHAP LA"<<endl;
//	InLNR(BST);
//	cout <<endl;
	
//nhap cay BST tu dong
	cout << "NHAP BST:"<<endl;
	Auto_Read(BST);
	cout << "CAY BST VUA NHAP LA"<<endl;
	InLNR(BST);
	cout <<endl;
//a.
	Info K;
	cout << "nhap K: ";
	cin >> K;
	cout << "in tu nut goc den "<<K<<" : ";
	RtoK(BST,K);
	cout << endl;
//b.
	cout << "Nhap K: ";
	cin >> K;
	cout << "in tu "<<K<<" ve goc: ";
	KtoR(BST,K);
	cout << endl;
//c.
	cout << "in tu goc den nut max: ";
	RtoMax(BST);
	cout<<endl;
//d.
	cout << "in tu min ve goc: ";
	MintoR(BST);
	cout <<endl;
//e.
	cout << "in tu min den max: ";
	MintoMax(BST);
	cout <<endl;
//g.
	cout << "Nhap K: ";
	cin>>K;
	cout << "in cac nut lon hon "<<K<<": ";
	RK(BST,K);
}
