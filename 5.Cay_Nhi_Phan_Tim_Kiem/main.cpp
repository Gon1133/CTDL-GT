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

BST_Type Creat_Node(Info NewData){
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
		BT = Creat_Node(X);
		BST = BT;
		cout << "Nhap con trai cua "<<X<<" : ";
		Read_Tree(BST->Left);
		cout << "Nhap con phai cua "<<X<<" : ";
		Read_Tree(BST->Right);
	}
	else BST=NULL;
}

void InLNR(BST_Type BST){
	if (BST == NULL) return;
	InLNR(BST->Left);
	cout << BST->Key << " ";
	InLNR(BST->Right);
}


//tim kiem 1 nut
BST_Type Searching(BST_Type BST, Info SearchData){
	BST_Type CurNode = BST;
	while (CurNode != NULL && CurNode->Key != SearchData)
		if (CurNode->Key > SearchData)
			CurNode = CurNode->Left;
		else
			CurNode = CurNode->Right;
	return CurNode;
}

//them mot nut
void Add_Node (BST_Type &BST, Info NewData){
	if (BST == NULL){
	
		BST = new BST_Node;
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
			
//xoa 1 nut bang pp chuyen cay
int Delete_Node_TRF(BST_Type &BST, Info DelData){
	BST_Type DelNode = BST;
	BST_Type PrDelNode = NULL;
	int OnTheLeft = 0;
	while (DelNode != NULL){
		if (DelNode->Key > DelData){
			DelNode = DelNode->Right;
			OnTheLeft = 0;
			
		}
	}
	if (DelNode == NULL) return 0; //ko co nut de huy
	if (PrDelNode == NULL){ //DelNode la nut goc
		if(DelNode->Left==NULL && DelNode->Right==NULL)
			BST = NULL;
		else 
			if (DelNode->Left==NULL){ //DelNode co 1 cay con phai
				BST = BST->Right;
				DelNode->Right = NULL;
			}
			else
				if (DelNode->Right == NULL){ //DelNode co 1 cay con trai
					BST = BST->Left;
					DelNode->Left = NULL;
				}
				else{ //DelNode co 2 cay con
					BST_Type MRNode = DelNode->Left;
					while(MRNode->Right != NULL)
						MRNode = MRNode->Right;
					MRNode->Right = DelNode->Right;
					DelNode->Right = NULL;
					BST = BST->Left;
					DelNode->Left = NULL;
				}
	}
	else {//DelNode ko la nut goc
		if (DelNode->Left==NULL && DelNode->Right==NULL)
			if (OnTheLeft == 1) PrDelNode->Left = NULL;
			else PrDelNode->Right = NULL;
		else if (DelNode->Left == NULL){ //Del co 1 cay con phai
			if(OnTheLeft == 1)
				PrDelNode->Left = DelNode->Right;
			else
				PrDelNode->Right = DelNode->Right;
			DelNode->Right = NULL;
		}
		else if (DelNode->Right == NULL){//DelNode co 1 cay con trai
			if (OnTheLeft == 1)
				PrDelNode->Left = DelNode->Left; 
			else 
				PrDelNode->Right = DelNode->Left; 
			DelNode->Left = NULL;
		}
		else{//DelNode co 2 cay con
			BST_Type MRNode = DelNode->Left;
			while(MRNode->Right != NULL)
				MRNode = MRNode = MRNode->Right;
			MRNode->Right = DelNode->Right;
			DelNode->Right = NULL;
			if (OnTheLeft == 1)
				PrDelNode->Left = DelNode->Left;
			else PrDelNode->Right = DelNode->Left;
			DelNode->Left = NULL;
		}
	}
	delete DelNode;
	return 1;
}

//xoa 1 nut bang pp the mang
int Delete_Node_SB(BST_Type &BST, Info DelData){
	BST_Type DelNode = BST;
	BST_Type PrDelNode = NULL; 
	int OnTheLeft = 0; 
	while(DelNode != NULL){
		if(DelNode->Key == DelData)
			break; 
		PrDelNode = DelNode; 
		if(DelNode->Key > DelData){
			DelNode = DelNode->Left; 
			OnTheLeft = 1;
		}
		else{
			DelNode = DelNode->Right; 
			OnTheLeft = 0; 
		}
	}
	if(DelNode == NULL) // Khong co nut de huy
		return 0; 
	if(PrDelNode == NULL){ // DelNode la nut goc
		if(DelNode->Left == NULL && DelNode->Right == NULL) 
			BST = NULL;
		else 
			if(DelNode->Left == NULL){
					// DelNode co 1 cay con phai 
				BST = BST->Right; 
			DelNode->Right = NULL; 
			} 
			else 
				if(DelNode->Right == NULL){
					// DelNode co 1 cay con trai 
					BST = BST->Left; 
					DelNode->Left = NULL; 
				} 
	} 
	else{ // DelNode khong la nut goc
		if(DelNode->Left==NULL && DelNode->Right==NULL) 
			if(OnTheLeft == 1) 
				PrDelNode->Left = NULL; 
			else 
				PrDelNode->Right = NULL; 
		else 
			if(DelNode->Left == NULL){
						// DelNode co 1 cay con phai 
				if(OnTheLeft == 1) 
					PrDelNode->Left = DelNode->Right; 
				else 
					PrDelNode->Right = DelNode->Right; 
				DelNode->Right = NULL; 
			} 
			else 
				if(DelNode->Right == NULL){
						// DelNode co 1 cay con trai 
					if(OnTheLeft == 1) 
						PrDelNode->Left = DelNode->Left; 
					else 
						PrDelNode->Right = DelNode->Left; 
					DelNode->Left = NULL;
				}
	}
	//DelNode co 2 cay con
	if (DelNode->Left!=NULL && DelNode->Right!=NULL){
		BST_Type MLNode = DelNode->Right;
		BST_Type PrMLNode = DelNode;
		while (MLNode->Left != NULL){
			PrMLNode = MLNode;
			MLNode = MLNode->Left;
		}
		DelNode->Key = MLNode->Key;
		if(PrMLNode == DelNode)
			PrMLNode->Right = MLNode->Right;
		else
			PrMLNode->Right = MLNode->Right;
		MLNode->Right = NULL;
		DelNode = MLNode;
	}
	delete DelNode;
	return 1;	
}	
		
		
main(){
	BST_Type BST;
	cout << "NHAP CAY NHI PHAN"<<endl;
	Initialize(BST);
	Read_Tree(BST);
	cout << "IN CAY NHI PHAN VUA NHAP"<<endl;
	InLNR(BST);
	Info X;
	cout << "nhap gia tri muon them: ";
	cin >> X;
	Add_Node(BST,X);
	cout << "In cay vua moi them"<<endl;
	InLNR(BST);
	Info Y;
	cin >> Y;
	cout << "nhap gia tri muon tim kiem: ";
	cin >> Y;
	cout << Searching(BST,Y);
	
	
	
}
