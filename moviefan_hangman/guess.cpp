#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

ifstream in("cleaninput.txt");

char t[300][101], cat[300][101];
int choice, k=0;

void guess()
{
    char gcat[101];
    while(cin.getline(gcat, 100))
        for(int i=0;i<k;++i)
            if(strcmp(gcat, cat[i])==0)
                cout<<"    "<<t[i]<<'\n';
}

void statistics_ind()
{
    char *p, stats[25][100]={""};
    int m=0, f[25]={}; bool ok;
    for(int i=0;i<k;++i)
    {
        p=strtok(cat[i], " ");
        while(p)
        {
            ok=true;
            for(int j=0;j<=m;++j)
            {
                if(strcmp(p, stats[j])==0)
                {
                    ++f[j]; ok=false;
                }
            }
            if(ok)
            {
                ++f[m];
                strcpy(stats[m++], p);
            }
            p=strtok(NULL, " ");
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

void statistics_col()
{
    char stats[200][100]={""};
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
    cout<<"1 TO GUESS, 2 FOR INDIVIDUAL STATS, 3 FOR COLLECTIVE STATS"<<'\n';
    cin>>choice;
    switch(choice)
    {
        case 1: guess(); break;
        case 2: statistics_ind(); break;
        case 3: statistics_col(); break;
    }
    return 0;
}

