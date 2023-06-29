#include<iostream>
#include<math.h>
using namespace std;
	
void nhap(int a[], int n){
	for (int i=0; i<n; i++){
		cout << "nhap ptu a[" <<i<<"] = ";
		cin >> a[i];
	}
}	


void xuat(int a[], int n){
	for (int i=0; i<n; i++)
	cout << a[i]<<" ";
}


main(){
	int n,a[20];
	cout << "nhap so ptu cua mang: ";
	do{
		cin >> n;
	}while (n<0 || n>20);
	nhap(a,n);
	cout << "mang sau khi nhap la: " ; 
	xuat(a,n);
	cout << endl;
}
