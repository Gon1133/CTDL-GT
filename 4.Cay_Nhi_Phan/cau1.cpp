#include<iostream>
using namespace std;

typedef int Info;
struct BinT_Node{
	Info Key;
	BinT_Node* Left;
	BinT_Node* Right;
};
typedef BinT_Node* BinT_Type;

void Initialize(BinT_Type &BTree){
	BTree = NULL;
}

BinT_Type Create_Node(Info newdata){
	BinT_Type BTnode = new BinT_Node;
	if(BTnode!=NULL){
		BTnode->Left=NULL;
		BTnode->Right=NULL;
		BTnode->Key=newdata;
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

int Count_Node(BinT_Type BTree){
	if(BTree == NULL) return 0;
	int NNL = Count_Node(BTree->Left);
	int NNR = Count_Node(BTree->Right);
	return(NNL + NNR + 1); 
}
	

//tinh chieu cao cua cay
int Tree_Height(BinT_Type BTree){
	if (BTree==NULL) return 0;
	int HTL = Tree_Height(BTree->Left);
	int HTR = Tree_Height(BTree->Right);
	if (HTL>HTR)
		return HTL+1;
	else 
		return HTR+1;
}

//a. in cac nut la 
void LRootR_Traverse(BinT_Type BTree){
	if (BTree==NULL) return;
	LRootR_Traverse(BTree->Left);
	if(BTree->Left==NULL && BTree->Right==NULL)
		cout << BTree->Key << " ";
	LRootR_Traverse(BTree->Right);
}

//b. in cac nut o muc K
void InMucK(int K, BinT_Type BTree){
	if (BTree==NULL) return;
	if (K==1){
		cout << BTree->Key<<" ";
		return;
	}
	InMucK(K-1,BTree->Left);
	InMucK(K-1,BTree->Right);
}

//d. in cac nut con trai cua cay
void InTrai(BinT_Type BTree){
	if (BTree==NULL) return;
	InTrai(BTree->Left);
	InTrai(BTree->Right);
	if(BTree->Left!=NULL)
		cout << BTree->Left->Key<<" ";
}

//f. dem so nut bac 2 cua cay
int DemNutBac2(BinT_Type BTree){
	if (BTree==NULL) return 0;
	int v1=DemNutBac2(BTree->Left);
	int v2=DemNutBac2(BTree->Right);
	if(BTree->Left!=NULL && BTree->Right!=NULL)
		return v1+v2+1;
	else
		return v1+v2;
}
	
//i. cho biet nut lon nhat trong tree
Info NutMax(BinT_Type BTree){
	if (BTree==NULL)	return 0;
	int v1=NutMax(BTree->Left);
	int v2=NutMax(BTree->Right);
	int max = BTree->Key;
	if (max<v1)	max=v1;
	if (max<v2)	max=v2;
	return max;
}

	
		
//j. tinh tong cac nut co noi dung le
Info TongNutLe(BinT_Type BTree){
	if (BTree==NULL) return 0;
	int v1=TongNutLe(BTree->Left);
	int v2=TongNutLe(BTree->Right);
	if (BTree->Key % 2 != 0)
		return v1+v2+BTree->Key;
	else 
		return v1+v2;
}

//l. cho biet muc nao co nhieu nut nhat
	//dem so nut o muc k
int SoNutMuck(BinT_Type BTree, int k){
	if (BTree==NULL) return 0;
	if (k==1) return 1;
	int v1 = SoNutMuck(BTree->Left,k-1);
	int v2 = SoNutMuck(BTree->Right,k-1);
	return v1+v2;
}

Info MucNutMax(BinT_Type BTree){
	int *a;
	int h = Tree_Height(BTree);
	a = new int [h];
	for(int i=0; i<=h-1; i++)
		a[i] = SoNutMuck(BTree,i+1);
	int max=a[1];
	for(int i=0; i<=h-1; i++)
		if(a[i]>max)
			max = a[i];
	cout << max<<endl;
	for(int i=0; i<=h-1; i++)
		if(a[i]==max) cout << i+1 << " ";
}

//m. chieu dai duong di trong
Info RoadIn(BinT_Type BTree, Info m=1){
	if (BTree==NULL) return 0;
	int v1 = RoadIn(BTree->Left,m+1);
	int v2 = RoadIn(BTree->Right,m+1);
	return v1+v2+m;
}

//n. chieu dai duong di ngoai
Info RoadOut(BinT_Type BTree, Info m=1){
	if (BTree==NULL) return m;
	int v1 = RoadIn(BTree->Left,m+1);
	int v2 = RoadIn(BTree->Right,m+1);
	return v1+v2;
}

main(){
	BinT_Type BT;
	cout << "NHAP CAY NHI PHAN"<<endl;
	Initialize(BT);
	Read_Tree(BT);
//a.
	cout << "In cac nut la tu trai sang phai"<<endl;
	LRootR_Traverse(BT);
	cout << endl;
//b.
//	int K;
//	cout << "Nhap muc K:";
//	cin >> K;
//	cout << "cac nut o muc "<<K<<endl;
//	InMucK(K,BT);
//	cout << endl;
//d.
//	InTrai(BT);
//	cout <<endl;
//f.
//	cout << "so nut bac 2 cua cay = "; 
//	cout << DemNutBac2(BT);
//	cout << endl;
//j.
//	cout << "Tong cac nut co noi dung le = "<<TongNutLe(BT)<<endl;
//l.
//	cout << MucNutMax(BT);


//m.
//	cout << "Chieu dai duong di trong cua cay = "<<RoadIn(BT);


}
