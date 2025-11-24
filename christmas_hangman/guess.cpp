#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

ifstream in("cleaninput.txt");

char t[100][101], cat[100][101];
int choice, k=0;

void guess()
{
    char gword[101], aux[101];
    while(cin.getline(gword, 100))
    {
        for(int i=0;i<k;++i)
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

int main()
{
    while(in.getline(t[k], 100))
    {
        ++k;
    }
    guess();
    return 0;
}
