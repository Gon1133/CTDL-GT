#include<iostream>
#include<math.h>
using namespace std;

bool ktCP(int n){
	if (sqrt(n) == (int)sqrt(n))
		return true;
	else return false;
}

int TongCP(int n){
	int S=0;
	for (int i=0; i<=n; i++){
		S = S + pow(i,2);
	}
	return S;
}

int Tohop(int k, int n){
	if (k==0 || k==1) return 1;
	else return Tohop(k-1,n-1) + Tohop(k,n-1);
}

void InBoiSo(int k, int n, int i=1){
	if (i<=n){
		if (k % i == 0)
			cout << i << " ";
		InBoiSo(k,n,i+1);
	}
}

int inF(int n){
    int f0 = 0, f1 = 1, fn = 1;
    if (n < 0)	
		return -1;
 	else if (n == 0 || n == 1) 
        return n;
    	else 
        	for (int i = 2; i < n; i++) {
            f0 = f1;
            f1 = fn;
            fn = f0 + f1;
        }
    return fn;
}

main(){
//cau a
	int a;
	cout << "nhap so a: ";
	cin >> a;
	if (ktCP(a)==true) 
		cout << a << " la so CP";
	else cout << a << " ko phai la so CP";
	cout << endl;
//cau b
	int b;
	cout << "nhap n so CP";
	cin >> b;
	cout << TongCP(b);
	cout << endl;
//cau c
	int k,n;
	cout << "nhap to hop k,n: ";
	cin >> k >> n;
	cout << "to hop chap "<< n << " cua "<< k << " = "<<Tohop(k,n);
	cout << endl;
//cau d
	int c,d;
	cout << "nhap boi so k = ";
	cin >> c;
	cout << "nhap n so tu nhien: ";
	cin >> d;
	cout << "day boi so k cua n so tu nhien: ";
	InBoiSo(c,d);
	cout << endl;
//cau e
	int e;
	cin >> e;
//phan tu dau tien cua day fibonacci
	cout<<endl<<n<<" phan tu dau tien day fibonacci la: "<<endl;
	for(int i = 1; i<=n; i++)
		cout<<inF(i)<<'\t';


}


