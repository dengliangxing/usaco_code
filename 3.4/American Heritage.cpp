/*
ID:15256292
LANG:C++
TASK:heritage
*/ 
#include<iostream>
#include<fstream>
using namespace std;
struct treenode{
	char ch;
	treenode* L;
	treenode* R;
};
char DLR[27],LDR[27];
int N=0;
void init(){
	
	char ch;
	cin.get(ch);
	while(ch!='\n'){
		LDR[++N]=ch;
		cin.get(ch);
	}
	for(int i=1;i<=N;i++){
		cin>>ch;
		DLR[i]=ch;
	}
}
treenode* createtree(int ld,int hd,int ll,int hl){
	if(ld>hd)
		return NULL;
	int i,sum=0; 
	for(i=ll;i<=hl;i++){
		if(LDR[i]==DLR[ld])
			break;
		sum++;
	}
	treenode* tn=new treenode;
	tn->ch=DLR[ld];
	tn->L=createtree(ld+1,ld+sum,ll,i-1);
	tn->R=createtree(ld+sum+1,hd,i+1,hl);
	return tn;		
}
void LRD(treenode* tree){
	if(tree==NULL)
		return;
	LRD(tree->L);
	LRD(tree->R);
	cout<<tree->ch;
}
int main(){
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	init();

	treenode * tree=createtree(1,N,1,N);
	LRD(tree);
	cout<<endl;
	return 0;
}
