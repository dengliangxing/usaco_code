#include <iostream>  
#include <fstream>  
#include <string>  
#include<memory.h>  
#include<algorithm>  
using namespace std;  
struct Node  
{  
  int Count,index;  
  char str[14];  
};  
Node n[20000];  
int used[20000];  
int cmp(Node n1,Node n2)  
{  
  if(n1.Count==n2.Count)  
    return n1.index<n2.index;  
  else return n2.Count<n1.Count;  
}  
int main() {  
    ofstream fout ("contact.out");  
    ifstream fin ("contact.in");  
    int A,B,N;  
    string s,temp;  
    int count,num;  
    cin>>A>>B>>N;  
    getline(cin,temp);  
    while(getline(cin,temp))  
      s+=temp;  
    if(s.length()<B)B=s.length();  
    for(int i=A;i<=B;i++)  
      for(int j=0;j<s.length()-i+1;j++)  
      {  
         int count=0;num=1;  
         while(count<i)  
         {  
           num=num<<1;  
           num=num|(int)(s[j+count]-'0');  
           count++;  
         }  
       n[num].Count++;  
       if(n[num].Count==1){  
           n[num].index=num;  
        for(int k=0;k<i;k++)  
         n[num].str[k]=s[k+j];  
         }  
      }  
      sort(n,n+20000,cmp);  
      memset(used,0,sizeof(used));  
      bool judge=true;count=0;  
      for(int i=0;i<20000;i++)  
       {  
   
         if(n[i].Count!=0){  
            if(!used[n[i].Count])  
            {  
              count++;num=1;  
             if(count>N)break;  
             if(!judge)cout<<endl;judge=false;  
             cout<<n[i].Count<<endl<<n[i].str;  
             used[n[i].Count]=1;  
            }  
            else{  
            if(num%6==0)cout<<endl<<n[i].str;  
            else cout<<" "<<n[i].str;num++;  
            }  
          }  
       }  
         
    return 0;  
}  
