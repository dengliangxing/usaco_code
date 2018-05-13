    /* 
    ID: 15256292
    PROG: namenum 
    LANG: C++ 
    */  
    #include<iostream>  
    #include<fstream>  
    #include<string>  
      
    using namespace std;  
      
    const char alpha[26]={'2','2','2','3','3','3','4','4','4','5','5','5', '6','6','6','7','0','7','7','8','8','8','9','9','9','0'};  
    string data,tmp,words;  
    bool flag=false;  
      
    int main(){  
        ifstream fin("namenum.in");  
        ofstream fout("namenum.out");  
        fin>>data;  
        ifstream tin("dict.txt");  
        while (tin>>words){  
              int l=words.size();  
              tmp="";  
              for (int i=0;i<l;i++) tmp+=alpha[words[i]-65];  
              if (tmp==data) {fout<<words<<endl;flag=true;}  
              }  
        if (!flag) fout<<"NONE"<<endl;  
        return 0;  
    }  
