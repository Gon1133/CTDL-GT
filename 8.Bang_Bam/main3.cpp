#include<iostream>
using namespace std;

# define NULLKEY 0
# define M 13
struct Node
{
int Key;
};
Node Hash[M];
int N = 0; //Bi?n toàn c?c ch? s? ph?n t? hi?n có trong b?ng

int HF(int k)
{ 
return (k % M);
}

void Initialize()
{
for(int b = 0; b < M; b++)
Hash[b].Key = NULLKEY;
}

bool Empty()
{
return (N == 0 ? true : false);
}

bool Full()
{
return(N == M - 1);
}

int G(int i)
{
return i;
}

int Search(int k)
{ if(Empty()) return M;
int b = HF(k), vt = b, i = 0;
while(Hash[vt].Key != NULLKEY && Hash[vt].Key != k)
{ //X? lý d?ng d?
i = i + 1;
vt = (b + G(i)) % M;
}
if(Hash[vt].Key == k) return vt;
else return M;
}


int Insert(int k)
{ int b = HF(k);
int vt = b, i = 0;
if(Full())
{
cout<<"Bang bam day, khong them duoc"<<endl;
return M;
}
if(Search(k) < M) 
{
cout<<"Khoa da co, khong them nua"<<endl;
return M;
}
while(Hash[vt].Key != NULLKEY) //X? lý d?ng d?
{
i = i + 1;
vt = (b + G(i)) % M;
}
Hash[vt].Key = k;
N = N + 1;
return vt;
}

void Remove(int k)
{
int vt = Search(k);
if(vt < M) 
{
Hash[vt].Key = NULLKEY;
N = N - 1;
}
else
cout<<"Khong co khoa nay"<<endl;
}


void Read_Hash()
{ int k;
do
{ cout<<"Nhap khoa vao bang bam:";
cin>>k;
if(k != 0) Insert(k);
}while(k != 0);
}

void Print_Hash()
{
for(int b = 0; b < M; b++)
cout<<"Bucket "<<b<<": "<<Hash[b].Key<<endl;
}

main(){
int k;
Initialize();
Print_Hash();
Read_Hash();
Print_Hash();
cout<<"Nhap khoa can tim:";
cin>>k;
int vt = Search(k);
if(vt == M)
cout<<"Khong co khoa "<<k<<" trong bang bam"<<endl;
else
cout<<"Khoa "<<k<<" nam o vi tri "<<vt<<endl;
cout<<"Nhap khoa can xoa:";
cin>>k;
Remove(k);
Print_Hash();
}

