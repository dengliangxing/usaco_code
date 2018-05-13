/*
ID: 15256292
LANG:C++
TASK:camelot
*/
#include<iostream>        
#include<istream>    
#include<stdio.h>        
#include<string.h>        
#include<math.h>        
#include<stack>    
#include<algorithm>        
#include<queue>     
#define oo 1000000000    
#define ll long long     
using namespace std;  
struct node  
{  
     int x,y,w;    
}h,k,king,knight[1000];  
queue<node> myqueue;  
int R,C,p,arc[33][33][33][33],kingm[33][33],num;   
int move[2][8][2]={{{1,0},{1,1},{0,1},{-1,1},{-1,0},{1,-1},{0,-1},{-1,-1}},  
                   {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}}};   
int getdata()  
{  
      char c='1';  
      while (c<'A' || c>'Z' )  
         if (scanf("%c",&c)==EOF) return 0;   
      return c-'A'+1;     
}   
void make(node hh,int tp)  
{         
      h=hh;    
      arc[hh.x][hh.y][h.x][h.y]=0;  
      myqueue.push(h);  
      while (!myqueue.empty())  
      {  
             h=myqueue.front();    
             myqueue.pop();  
             for (p=0;p<8;p++)  
             {  
                     k.x=h.x+move[tp][p][0];    
                     k.y=h.y+move[tp][p][1];  
                     if (k.x<1 || k.y<1 || k.x>C || k.y>R) continue;   
                     if (arc[hh.x][hh.y][k.x][k.y]==-1)  
                     {  
                            k.w=h.w+1;   
                            myqueue.push(k);          
                            arc[hh.x][hh.y][k.x][k.y]=k.w;               
                     }                 
             }      
      }    
}  
void makekingmove()  
{         
      h=king;   
      kingm[h.x][h.y]=0;  
      myqueue.push(h);  
      while (!myqueue.empty())  
      {  
             h=myqueue.front();    
             myqueue.pop();  
             for (p=0;p<8;p++)  
             {  
                     k.x=h.x+move[0][p][0];    
                     k.y=h.y+move[0][p][1];  
                     if (k.x<1 || k.y<1 || k.x>C || k.y>R) continue;   
                     if (kingm[k.x][k.y]==-1)  
                     {  
                            k.w=h.w+1;   
                            myqueue.push(k);          
                            kingm[k.x][k.y]=k.w;               
                     }                 
             }      
      }    
}  
int getanswer()  
{  
      int x,y,p,i,j,m,k,t,v,ans=oo;   
      for (x=1;x<=C;x++)  
         for (y=1;y<=R;y++)  
         {  
                 m=kingm[x][y];  
                 for (i=1;i<=num;i++)  
                   if (arc[knight[i].x][knight[i].y][x][y]==-1) goto A;  
                     else m+=arc[knight[i].x][knight[i].y][x][y];  
                 if (m<ans) ans=m;  
                 for (t=0;t<5;t++)  
                 for (v=0;v<8;v++)  
                 {  
                        i=move[0][v][0]*t+king.x; j=move[0][v][1]*t+king.y;  
                        if (i<1 || j<1 || i>C || j>R) continue;  
                        if (arc[i][j][x][y]!=-1)  
                        {  
                              for (p=1;p<=num;p++)  
                              if (arc[knight[p].x][knight[p].y][i][j]!=-1)  
                              {  
                                    k=m-kingm[x][y]-arc[knight[p].x][knight[p].y][x][y]+arc[knight[p].x][knight[p].y][i][j]+arc[i][j][x][y]+kingm[i][j];  
                                    if (k<ans) ans=k;   
                              }  
                        }  
                 }    
                 A: ;  
         }  
      return ans;      
}  
int main()    
{    
      freopen("camelot.in","r",stdin);      
      freopen("camelot.out","w",stdout);    
      while (!myqueue.empty()) myqueue.pop();   
      memset(arc,-1,sizeof(arc));     
      memset(kingm,-1,sizeof(kingm));  
      scanf("%d%d",&R,&C);    
      king.x=getdata(); scanf("%d",&king.y); king.w=0;     
      makekingmove();  
      for (int x=1;x<=C;x++)  
        for (int y=1;y<=R;y++)  
        {  
              h.x=x; h.y=y; h.w=0;  
              make(h,1);      
        }  
      num=0;  
      while (1)  
      {   
              h.x=getdata();   
              if (!h.x) break;  
              scanf("%d",&h.y); h.w=0;     
              knight[++num]=h;  
      }      
      printf("%d\n",getanswer());  
      return 0;       
}    
