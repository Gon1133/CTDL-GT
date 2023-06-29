#include<iostream>
using namespace std;

typedef int Info;
struct BinT_Node{
	Info Key;
	BinT_Node* Right;
	BinT_Node* Left;
};
typedef BinT_Node* BinT_Type;

BinT_Type Create_Node(Info Newdata){
	BinT_Type BTnode = new BinT_Node;
	if (BTnode != NULL){
		BTnode->Left=NULL;
		BTnode->Right=NULL;
		BTnode->Key=Newdata;
	}
	return BTnode;
}

void Read_Tree(BinT_Type &BTree){
	Info X;
	cin>>X;
	if(X!=0){
		BinT_Type BT;
		BT = Create_Node(X);
		BTree=BT;
		cout << "Nhap con trai cua "<<X<<" : ";
		Read_Tree(BTree->Left);
		cout << "Nhap con phai cua "<<X<<" : ";
		Read_Tree(BTree->Right);
	}
	else BTree=NULL;
}

void InLNR(BinT_Type BTree){
	if (BTree==NULL) 
		return;
	InLNR(BTree->Left);
	cout << BTree->Key << " ";
	InLNR(BTree->Right);
}

void Add_Node(BinT_Type &BST, Info NewData){
	if (BST == NULL){
		BST = new BinT_Node;
		if(BST!=NULL){
			BST->Left = NULL;
			BST->Right = NULL;
			BST->Key = NewData;
		}
}
	else
		if (BST->Key == NewData) return;
		else
			if (BST->Key > NewData)
				Add_Node(BST->Left, NewData);
			else
				Add_Node(BST->Right, NewData);
}

void BT_BST(BinT_Type BT, BinT_Type &BST){
	if (BT==NULL) 
		return;
	Add_Node(BST, BT->Key);
	BT_BST(BT->Left, BST);
	Add_Node(BST, BT->Key);
	BT_BST(BT->Right, BST);
	Add_Node(BST, BT->Key);
}

main(){
//tao cao nhi phan
	BinT_Type BT=NULL;
	cout << "Nhap cay nhi phan"<<endl;
	Read_Tree(BT);
	cout << "Cay sau khi nhap"<<endl;
	InLNR(BT);
//tao cay BST
	BinT_Type BST=NULL;
	BT_BST(BT,BST);
	cout << endl;
	cout << "cay BST"<<endl;
	InLNR(BST);

}
