#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

ifstream in("cleaninput.txt");

char t[700][101], cat[700][101];
int choice, k=0;

void guess()
{
    char gword[101], gcat[101], aux[101];
    while(cin>>gcat)
    {
        strupr(gcat);
        cin.get(); cin.getline(gword, 100);
        for(int i=0;i<k;++i)
            if(strcmp(gcat, cat[i])==0)
            {
                strcpy(aux, t[i]);
                for(int j=0;j<strlen(aux);++j)
                    if(aux[j] >= 'A' && aux[j] <= 'Z')
                        aux[j]='-';
                if(strcmp(aux, gword)==0)
                    cout<<"    "<<t[i]<<'\n';
            }
    }
}

void statistics()
{
    char stats[20][100]={""};
    int m=0, f[200]={}; bool ok;
    for(int i=0;i<k;++i)
    {
        ok=true;
        for(int j=0;j<=m;++j)
        {
            if(strcmp(cat[i], stats[j])==0)
            {
                ++f[j]; ok=false;
            }
        }
        if(ok)
        {
            ++f[m];
            strcpy(stats[m++], cat[i]);
        }
    }
    for(int i=0;i<m-1;++i)
        for(int j=i;j<m;++j)
            if(f[i]<f[j])
            {
                swap(f[i], f[j]);
                swap(stats[i], stats[j]);
            }
    for(int i=0;i<m;++i)
        cout<<f[i]<<' '<<stats[i]<<'\n';
}

int main()
{
    while(in.getline(t[k], 100))
    {
        in.getline(cat[k], 100);
        ++k;
    }
    cout<<"1 TO GUESS, 2 FOR STATS"<<'\n';
    cin>>choice; cin.get();
    switch(choice)
    {
        case 1: guess(); break;
        case 2: statistics(); break;
    }
    return 0;
}


