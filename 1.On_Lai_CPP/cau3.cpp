#include<iostream>
#include<math.h>
using namespace std;

void N(int a[], int n,int i=0){
	if (i<n){
		cout << "nhap ptu a[" <<i<<"] = ";
		cin >> a[i];
	}
	return N(a,n,i++);
}

void X(int a[],int n, int i=0){
	if (i<n)
		cout << a[i]<<" ";
	return X(a,n,i++);
}

main(){
	int n,a[20];
	cout << "nhap so ptu cua mang: ";
	do{
		cin >> n;
	}while (n<0 || n>20);
	N(a,n);
	cout << "mang sau khi nhap la: " ; 
	X(a,n);
	cout << endl;
}
