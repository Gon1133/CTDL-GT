#include<iostream>
using namespace std;

//khoi bao cau truc du lieu
typedef int Info;
struct BinT_Node{ //khai bao 1 nut co key va 2 tro L va R
	Info Key;
	BinT_Node* Left;
	BinT_Node* Right;
};
typedef BinT_Node* BinT_Type; //dinh nghia con tro Node cho Type

//khoi tao
void Initialize(BinT_Type &BTree){
	BTree = NULL;
}

//tao moi 1 nut 
BinT_Type Create_Node(Info newdata){
	BinT_Type BTnode = new BinT_Node;
	if(BTnode!=NULL){
		BTnode->Left=NULL;
		BTnode->Right=NULL;
		BTnode->Key = newdata;
	}
	return BTnode;
}

//them 1 nut vao ben trai nhat cua cay
void Add_Left(BinT_Type &BTree, Info newdata){
	BinT_Type newnode = Create_Node(newdata);
	if (BTree==NULL)
		BTree = newnode;
	else{
		BinT_Type Lnode = BTree;
		while(Lnode->Left!=NULL)
			Lnode=Lnode->Left;
		Lnode->Left=newnode;
	}
}

//nhap cay nhi phan
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

//thuat toan de qui de duyet cay theo LN(Root)R
void LRootR_Traverse(BinT_Type BTree){
	if (BTree==NULL) return;
	LRootR_Traverse(BTree->Left);
	//Process(BTree->Key);== 
	cout << BTree->Key << " "; //xu ly thong tin nut goc
	LRootR_Traverse(BTree->Right);
}

//tinh chieu cao cua cay
int Tree_Height(BinT_Type BTree){
	if(BTree==NULL) return 0;
		int HTL = Tree_Height(BTree->Left);
		int HTR = Tree_Height(BTree->Right);
		if(HTL>HTR) return HTL+1;
		else return HTR+1;
}

//dem so nut cua cay
int Count_Node(BinT_Type BTree){
	if(BTree==NULL) return 0;
	int NNL = Count_Node(BTree->Left);
	int NNR = Count_Node(BTree->Right);
	return (NNL+NNR+1);
}

main(){
	BinT_Type BT;
	cout << "NHAP CAY NHI PHAN"<<endl;
	Initialize(BT);
	Read_Tree(BT);
	cout << "IN CAY NHI PHAN THEO CACH LNR"<<endl;
	LRootR_Traverse(BT);
	cout << endl;
	Info X;
	cout << "Ban muon them vao nut trai la bao nhieu: ";
	cin >> X;
	Add_Left(BT,X);
	cout << "CAY NHI PHAN SAU KHI THEM NUT TRAI"<<endl;
	LRootR_Traverse(BT);
	cout << "\nChieu cao cua cay la: "<<Tree_Height(BT);
	cout << "\nCay co "<<Count_Node(BT)<<" nut"<<endl;
		
}
