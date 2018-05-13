/*
ID: 15256292
LANG: C++ 
TASK: beads
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream cin("beads.in");
    ofstream cout("beads.out");

    int before,after;
    int n;
    int p = 0;
    char necklace[800];
    char current_color;
    int max = 0;

    cin>>n;
    cin >> necklace;

    for(int i = 0;i < n;i ++)
        necklace[i+n] = necklace[i];
    necklace[n*2] = '\0';

    before = 0;
    while(necklace[p] == 'w')
    {
        before++;
        p++;
    }
    //cout << before<<" "<<p<<endl;
    current_color = necklace[p];
    while((necklace[p] == current_color|| necklace[p] == 'w') && p<n)
    {
        before++;
        p++;
    }
    //cout << before<<" "<<p<<endl;
    if(p < n)
    {
       while(p < 2*n)
        {
            current_color = necklace[p];
            after = 0;
            while(necklace[p] == current_color|| necklace[p] == 'w')
            {
                after++;
                p++;
            }
            if(before + after > max && before+after <= n)
            {
                max = before+after;
            }
            //cout<<max<<endl;
            before = after;
            int j = p-1-before;
            while(necklace[j] == 'w')
            {
                before++;
                j--;
            }
        }
    }
    else
        max = n;
    cout << max<<endl;
}

