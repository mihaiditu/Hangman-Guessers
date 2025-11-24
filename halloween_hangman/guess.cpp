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
    char gword[101], aux[101];
    int f[27]={}; char alphabet[28]="ABCDEFGHIJKLMNOPQRTSTUVWXYZ"; bool check[26]={};
    while(cin.getline(gword, 100))
    {
        for(int i=0;i<27;++i)
            f[i]=0;
        strcpy(alphabet, "ABCDEFGHIJKLMNOPQRTSTUVWXYZ");
        for(int i=0;i<k;++i)
        {
            strcpy(aux, t[i]);
            for(int j=0;j<strlen(aux);++j)
                if(aux[j] >= 'A' && aux[j] <= 'Z')
                {
                    aux[j]='-';
                }
            if(strcmp(aux, gword)==0)
            {

                for(int j=0;j<26;++j)
                    check[j]=false;
                for(int j=0;j<strlen(t[i]);++j)
                {
                    if(t[i][j] >= 'A' && t[i][j] <= 'Z') //this stuff doesn't work properly for V
                    {
                        if(check[t[i][j]-65] == false)
                            ++f[t[i][j]-65];
                        check[t[i][j]-65]=true;
                    }
                }
                cout<<"    "<<t[i]<<'\n';
            }
        }
        for(int i=0;i<25;++i)
            for(int j=i;j<26;++j)
                if(f[i]>f[j])
                {
                    swap(f[i], f[j]);
                    swap(alphabet[i], alphabet[j]);
                }
        for(int i=25;i>=20;--i)
            cout<<alphabet[i]<<' '<<f[i]<<(i==20 ? "" : ", ");
        cout<<'\n';
    }
}

int main()
{
    while(in.getline(t[k], 100))
    {
        ++k;
    }
    guess();
    return 0;
}
