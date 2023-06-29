#include<iostream>
using namespace std;

typedef float Info;
struct BST_Node{
	Info Key;
	int Count;
	BST_Node* Left;
	BST_Node* Right;
};
typedef BST_Node* BST_Type;

void Initialize(BST_Type &BST){
	BST = NULL;
}

BST_Type Create_Node(Info NewData){
	BST_Type BSTnode = new BST_Node;
	if (BSTnode != NULL){
		BSTnode->Left = NULL;
		BSTnode->Right = NULL;
		BSTnode->Key = NewData;
	}
	return BSTnode;
}

void Read_Tree(BST_Type &BST){
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


//duyet cay theo LNR
void LNR_Traverse(BST_Type BST){
	if (BST == NULL)
		return;
	LNR_Traverse(BST->Left);
	cout << BST->Key << " ";
	LNR_Traverse(BST->Right);
}

//in nut la trong cay
void InLa(BST_Type BST){
	if (BST == NULL)
		return;
	InLa(BST->Left);
	if (BST->Left==NULL && BST->Right==NULL)
		cout << BST->Key << " ";
	InLa(BST->Right);
}

//dem so nut nam o muc K
Info SoNutMucK(int K, BST_Type BST){
	if (BST==NULL)
		return 0;
	if (K==1){
		return 1;
	}
	int v1 = SoNutMucK(K-1,BST->Left);
	int v2 = SoNutMucK(K-1,BST->Right);
	return v1+v2;
}

//tong cac nut co noi dung phan nguyen la chan
Info Sum(BST_Type BST){
	if (BST == NULL)
		return 0;
	Info v1 = Sum(BST->Left);
	Info v2 = Sum(BST->Right);
	if (int(BST->Key) % 2 == 0)
		return v1+v2+BST->Key;
	else
		return v1+v2;
}

main(){
//cau1
	BST_Type BST;
	BST=NULL;
	cout << "Nhap BST"<<endl;

	Read_Tree(BST);
//cau2
	cout << "In BST theo LNR"<<endl;
	LNR_Traverse(BST);
	cout << endl;
//cau3
	cout << "in cac nut la: ";
	InLa(BST);
	cout << endl;
//cau4
	int K;
	cout << "nhap muc K: ";
	cin >> K;
	cout << "co " << SoNutMucK(K,BST) << " nut o muc "<<K;
	cout << endl;
//cau5
	cout << "Tong cac nut co phan nguyen la chan " << Sum(BST);
}
