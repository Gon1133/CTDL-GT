#include<iostream>
using namespace std;

# define M 5
struct Node
{ int Key;
Node* Next;
};
// Khai bao kieu con tro chi danh sach lien ket
typedef Node* Bucket;
// Khai bao mang bucket chua M con tro dau cua M bucket
Bucket Hash[M];

int HF(int k)
{
return (k % M);
}

void Initialize()
{ for(int b = 0; b < M; b++)
{
Hash[b] = new Node;
Hash[b]->Next = NULL;
}
}

bool Empty_Bucket(int b)
{
return(Hash[b]->Next == NULL);
}

bool Empty()
{ for(int b=0; b < M; b++)
if(!Empty_Bucket(b))
return false;
return true;
}

bool Search(int k)
{ Bucket p;
int b = HF(k);
p = Hash[b];
while(p->Next != NULL && p->Next->Key < k)
p = p->Next;
if(p->Next != NULL && p->Next->Key == k)
return true;
else
return false;
}

void Insert_Bucket(int b, int k){
Bucket t = new Node;
t->Key = k;
if(Empty_Bucket(b) || k < Hash[b]->Next->Key)
{
t->Next = Hash[b]->Next;
Hash[b]->Next = t;
}
else
{
Bucket p = Hash[b];
while(p->Next != NULL && p->Next->Key < k)
p = p->Next;
t->Next = p->Next;
p->Next = t;
}
}

void Insert(int k)
{
int b = HF(k);
if(!Search(k)) Insert_Bucket(b, k);
}

void Remove(int k)
{
int b = HF(k);
Bucket p = Hash[b];
while(p->Next != NULL && p->Next->Key < k)
p = p->Next;
if(p->Next == NULL || p->Next->Key != k)
 cout<<"Khong co khoa nay"<<endl;
else
{
Bucket t = p->Next;
p->Next = t->Next;
delete t;
}
}

void Clear_Bucket(int b)
{ Bucket t;
while(Hash[b]->Next != NULL)
{
t = Hash[b]->Next;
Hash[b]->Next = t->Next;
delete t;
}
}

void Clear()
{
for(int b = 0; b < M; b++)
Clear_Bucket(b);
}

void Traverse_Bucket(int b)
{
Bucket p = Hash[b];
while(p->Next != NULL)
{
cout<<p->Next->Key<<'\t';
p = p->Next;
}
}

void Traverse()
{
for(int b = 0; b < M; b++)
{
cout<<"Bucket "<<b<<": ";
Traverse_Bucket(b);
cout<<endl;
}
}

void Read_Hash()
{ int k;
do{
cout<<"Nhap khoa vao bang bam:";
cin>>k;
if(k != 0) Insert(k);
}while (k != 0);
}


main()
{ int k, b;
Initialize();
Traverse();
Read_Hash(); 
Traverse();
cout<<"Nhap khoa can tim:";
cin>>k;
if(Search(k)) 
 cout<<"Co khoa "<<k<<" trong bang bam"<<endl;
else 
 cout<<"Khong co khoa "<<k<<" trong bang bam"<<endl;
cout<<"Nhap khoa can xoa:";
cin>>k;
Remove(k); 
Traverse();
cout<<"Ban muon xoa bucket nao?";
cin>>b;
Clear_Bucket(b); 
Traverse();
cout<<"Bang bam sau khi xoa:"<<endl;
Clear(); 
Traverse();
}

