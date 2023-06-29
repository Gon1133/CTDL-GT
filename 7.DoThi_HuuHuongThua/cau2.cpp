#include<iostream>
using namespace std;

const int maxn=20;
typedef int ElementType;
struct Node{
	ElementType Element;
	Node* Next;
};
typedef Node* List;
typedef List Graph[maxn];

void Initialize(Graph &g, int n, int &e){
	for (int i=1; i<=n; i++){
		g[i] = new Node;
		g[i]->Next = NULL;
	}
	e=0;
}

void InsertArc(Graph &g, int n, int &e, int d1, int d2){
	Node *t = new Node;
	t->Element = d2;
	t->Next = g[d1]->Next;
	g[d1]->Next = t;
	e++;
}

//dem so cung xuat phat tu 1 dinh
int CountArcFromVertice(Graph g, int n, int e, int d){
	int dem=0;
	Node *t = g[d];
	while(t->Next!=NULL){
		dem++;
		t=t->Next;
	}
	return dem;
}


//dem so cung di den 1 dinh
int CountArcToVertice(Graph g, int n, int e, int d){
	int i, dem = 0;
	Node *t;
	for(i=1; i<=n; i++){
		t = g[i];
		while(t->Next != NULL && t->Next->Element != d)
			t = t->Next;
		if(t->Next != NULL) dem++; 
	} 
	return dem;
}

//them 1 dinh
void InsertVertice(Graph &g, int &n, int &e, int scxp, int scdd){ 
	int i, d;
	g[n+1]= new Node;
	g[n+1]->Next = NULL;
	for(i=1; i<=scxp; i++){
		cout<<"Dinh moi di den dinh nao? ";
		cin>>d;
		InsertArc(g, n, e, n+1, d);
	} 
	for(i=1; i<=scdd; i++){
		cout<<"Dinh nao di den dinh moi? ";
		cin>>d;
		InsertArc(g, n, e, d, n+1);
	} 
	n++;
}

//nhap do thi
void ReadGraph(Graph &g, int n, int e){
 	int i, d1, d2, sc = e;
 	for(i=1; i<=sc; i++){
 		cout<<"Nhap cung di tu d1 den d2 : ";
		cin>>d1>>d2;
		InsertArc(g, n, e, d1, d2);
 	}
}

//xuat do thi
void PrintGraph(Graph g, int n, int e){
	Node *t = new Node;
	for(int i=1; i<=n; i++){
		cout<<"Dinh "<<i<<" : ";
		t = g[i];
		while(t->Next != NULL)
	{
		cout<<t->Next->Element<<'\t';
		t = t->Next;
	}
	cout<<endl;
	}
}

//a. cho bt dinh co so cung den cac dinh khac nhieu nhat
void cungXPmax(Graph g, int n, int e){
	int *a;
	a = new int[n];
	for (int i=1; i<=n; i++)
		a[i] = CountArcFromVertice(g,n,e,i);	
	int max = a[1];
	for (int i=1; i<=n; i++)
		if (a[i]>max)
			max = a[i];
	for (int i=1; i<=n; i++)
		if(a[i]==max)
			cout << i << " ";
}

//b. cho bt dinh co so cung den tu cac dinh khac it nhat
void dinhcungdenmin(Graph g, int n, int e){
	int min = CountArcToVertice(g,n,e,1);
	for (int i=2; i<=n; i++)
		if (min > CountArcToVertice(g,n,e,i))
			min = CountArcToVertice(g,n,e,i);
	cout << "dinh co cung den tu cac dinh khac it nhat: ";
		for (int i=1; i<=n; i++)
			if (CountArcToVertice(g,n,e,i)==min)
				cout << i <<" ";
}

//c. dem so khuyen
bool ktkhuyen(List t, int d){
	while (t->Next!=NULL && t->Next->Element!=d)
		t=t->Next;
	if (t->Next!=NULL)
		return true;
	else return false;
}
int demkhuyen(Graph g, int n, int e){
	int dem=0;
	for (int i=1; i<=n; i++)
		if (ktkhuyen(g[i],i))
			dem++;
	return dem;
}

//d. cho biet co bao nhieu dinh treo trong do thi
int demdinhtreo(Graph g, int n, int e){
	int dem=0;
	for(int i=1; i<=n; i++)
		if (CountArcFromVertice(g,n,e,i)==0 && CountArcFromVertice(g,n,e,i))
			dem++;
	return dem;
}

//e. in ra cac dinh co cung den dinh d
void indinh(Graph g, int n, int e, int d){
	for (int i=1; i<=n; i++)
		if(ktkhuyen(g[i],d))
			cout << i << " ";
}


main(){
	Graph g;
	int n,e;
	do{
		cout<<"Nhap so dinh cua do thi : ";
		cin>>n;
	}while(n<=0 || n>=maxn);
	Initialize(g, n, e);
	cout << "Do thi vua khoi tao la:\n";
	PrintGraph(g, n, e);
	cout << "Nhap so cung cua do thi : "; 
	cin>>e;
	ReadGraph(g, n, e);
	cout<<"Do thi vua nhap la:\n";
	PrintGraph(g, n, e); 	

//a.
	cout << "Dinh co nhieu cung xuat phat nhat la: ";
	cungXPmax(g,n,e);
	cout << endl;
//b.
	dinhcungdenmin(g,n,e);
	cout << endl;
//c.
	cout << "tong so khuyen cua do thi = "<<demkhuyen(g,n,e);
	cout << endl;
//d.
	cout << "tong cac dinh treo trong do thi = " << demdinhtreo(g,n,e);
	cout << endl;
//e.
	int d;
	cout << "nhap dinh can tinh: ";
	cin >> d;
	cout << "cac dinh di den dinh " << d << " la: ";
	indinh(g,n,e,d);
}
