#include<bits/stdc++.h>
using namespace std;

int main ()
{
    string text;
    map<string, int>index;
    int pos=1,i,j,k,l,m;
    for (i='a';i<='z';i++)
    {
        string temp="";
        temp+=i;
        index[temp]=pos++;
    }
    for (i='a';i<='z';i++)
    {
        for (j=i+1;j<='z';j++)
        {
            string temp="";
            temp+=i;
            temp+=j;
            index[temp]=pos++;
        }
    }
    for (i='a';i<='z';i++)
    {
        for (j=i+1;j<='z';j++)
        {
            for (k=j+1;k<='z';k++)
            {
                string temp="";
                temp+=i;
                temp+=j;
                temp+=k;
                index[temp]=pos++;
            }
        }
    }
    for (i='a';i<='z';i++)
    {
        for (j=i+1;j<='z';j++)
        {
            for (k=j+1;k<='z';k++)
            {
                for (l=k+1;l<='z';l++)
                {
                    string temp="";
                    temp+=i;
                    temp+=j;
                    temp+=k;
                    temp+=l;
                    index[temp]=pos++;
                }
            }
        }
    }
    for (i='a';i<='z';i++)
    {
        for (j=i+1;j<='z';j++)
        {
            for (k=j+1;k<='z';k++)
            {
                for (l=k+1;l<='z';l++)
                {
                    for (m=l+1;m<='z';m++)
                    {
                        string temp="";
                        temp+=i;
                        temp+=j;
                        temp+=k;
                        temp+=l;
                        temp+=m;
                        index[temp]=pos++;
                    }
                }
            }
        }
    }
    while(getline(cin,text))
    {
        cout<<index[text]<<endl;
    }
    return 0;
}

