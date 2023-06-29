#include<iostream>
using namespace std;

const int maxn=20;
typedef int Graph[maxn][maxn];

void Initialize(Graph &g, int n, int &e){
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			if(i==j) g[i][j]=1;
			else g[i][j]=0;	
		}
	e=0;
}

void InsertEdge(Graph &g, int n, int &e, int d1, int d2){
	g[d1][d2]=1;
	g[d2][d1]=1;
	e++;
}

void DeleteEdge(Graph &g, int n, int &e, int d1, int d2){
	g[d1][d2]=0;
	g[d2][d1]=0;
	e--;
}

int CountEdge(Graph g, int n, int e, int d){
	int dem=0;
	for(int i=1; i<=n; i++)
		if(g[d][i]==1) dem++;
	return dem-1;
}

void InsertVertice(Graph &g, int &n, int &e, int sc){
	int d;
	for(int i=1; i<=n; i++){
		g[i][n+1]=0;
		g[n+1][i]=0;
	}
	g[n+1][n+1]=1;
	for(int i=1; i<sc; i++){
		cout << "Nhap dinh noi voi dinh moi: ";
		cin>>d;
		InsertEdge(g,n,e,n+1,d);
	}
}

void DeleteVertice(Graph &g, int &n, int &e, int d){
	int i, j;
	e=e-CountEdge(g, n, e, d);
	for(i=d; i<=n-1; i++)
 		for(j=1; j<=n; j++)
 			g[i][j]=g[i+1][j];
	for(i=1; i<=n-1; i++)
 		for(j=d; j<=n-1; j++)
 			g[i][j]=g[i][j+1];
	for (i=1; i<=n; i++){
 		g[i][n]=0;
		g[n][i]=0;	
	}
	n--;
}


void ReadGraph(Graph &g, int n, int e){
	int i, d1, d2;
	for(i=1; i<=e; i++){
		cout<<"Nhap dinh dau va dinh cuoi : ";
		cin>>d1>>d2;
		g[d1][d2]=1;
		g[d2][d1]=1;
	}
}


void PrintGraph(Graph g, int n, int e){
	int i, j;
	for(i=1; i<=n; i++){
 		for(j=1; j<=n; j++)
 			cout<<g[i][j]<<'\t';
 	cout<<endl;
	}
}

//a. cho biet dinh nao co so canh noi la K
void DinhSoCanhNoiK(Graph g, int n, int e, int K){
	int i;
	for(i=1; i<=n; i++){		
		if(CountEdge(g,n,e,i) == K)
			cout << i << " ";
	}
}	

//b. in ra cac dinh co canh noi voi dinh nhap vao
void DinhCoCN(Graph g, int n ,int e, int d){
	for(int i=1; i<=n; i++){
		if(g[d][i]==1 && d!=i)
			cout << i << " ";
	}
}

//c. nhap 2 dinh, ktra canh noi
bool KTCN(Graph g, int n, int e, int d1, int d2){
	if(g[d1][d2]==1) return true;
	else return false;
}

//d. dem cac dinh treo 
int DemDT(Graph g, int n ,int e){
	int dem;
	for(int i=1; i<=n; i++){
		if(CountEdge(g,n,e,i)==1)
			dem++;
		return dem;
	}
}

//e. in ra cac dinh co canh noi voi cac dinh treo
void InDinhCanhDT(Graph g, int n, int e){
	for(int i=1; i<=n; i++){
		if(CountEdge(g,n,e,i)==1)
			for(int j=1; j<=n; j++)
				if(g[i][j]==1 && i!=j){			
	    			cout << j << " ";
	    			break;
	    	}
	}
}

main(){
	Graph g;
	int n,e;
	do{
		cout << "Nhap so dinh cua do thi: ";
		cin >> n;
	}while (n<0||n>maxn);
	Initialize(g,n,e);
	cout << "DO THI VUA KHOI TAO"<<endl;
	PrintGraph(g,n,e);
	cout<<"Nhap so canh cua do thi : ";
	cin>>e;
	ReadGraph(g, n, e);
	cout<<"=====DO THI VUA NHAP====="<<endl;
	PrintGraph(g, n, e);
	cout<<endl;
//a.
	int K;
	cout << "Nhap so K: ";
	cin >> K;
	DinhSoCanhNoiK(g,n,e,K);
	cout << endl;
//b.
	int d;
	cout << "Nhap dinh d: ";
	cin >> d;
	DinhCoCN(g,n,e,d);
	cout << endl;
//c.
	int d1, d2;
	cout << "Nhap 2 dinh: ";
	cin >> d1 >> d2;
	if(KTCN(g,n,e,d1,d2)) cout << "Co";
	else cout << "Khong";
	cout << endl;
//d.
	cout << "Co "<<DemDT(g,n,e)<<" dinh treo";
	cout << endl;
//e.
	cout << "dinh co canh noi voi dinh treo la: ";
	InDinhCanhDT(g,n,e);
	


}
