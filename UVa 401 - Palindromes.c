#include<stdio.h>
#include<string.h>
int main()
{
    char a[125];
    while(scanf("%s",&a)==1)
    {
        char b[125],c[125];
        int i,j,k,l,m,n1=0,n2=0,count=0;
        j=0;
        for(i=strlen(a)-1;i>=0;i--)
        {
            b[j++]=a[i];
        }
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]!=b[i])
              break;
        }
        if(i==strlen(a))
           n1=1;
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='A')
            {
                b[i]='A';
            }
            else if(a[i]=='H')
            {
                b[i]='H';
            }
            else if(a[i]=='I')
            {
                b[i]='I';
            }
            else if(a[i]=='M')
            {
                b[i]='M';
            }
            else if(a[i]=='O')
            {
                b[i]='O';
            }
            else if(a[i]=='T')
            {
                b[i]='T';
            }
            else if(a[i]=='U'||a[i]=='V'||a[i]=='W'||a[i]=='X'||a[i]=='Y'||a[i]=='1'||a[i]=='8')
            {
                b[i]=a[i];
            }
            else if(a[i]=='E')
            {
                b[i]='3';
            }
            else if(a[i]=='J')
            {
                b[i]='L';
            }
            else if(a[i]=='L')
            {
                b[i]='J';
            }
            else if(a[i]=='S')
            {
                b[i]='2';
            }
            else if(a[i]=='Z')
            {
                b[i]='5';
            }
            else if(a[i]=='2')
            {
                b[i]='S';
            }
            else if(a[i]=='3')
            {
                b[i]='E';
            }
            else if(a[i]=='5')
            {
                b[i]='Z';
            }
            else
            {
                b[i]=a[i];
                count++;
            }
        }
        j=0;
        for(i=strlen(a)-1;i>=0;i--)
        {
            if(b[i]==a[j])
            {
                j++;
            }
            else
               break;
        }
        if(j==strlen(a)&&count==0)
        {
            n2=1;
        }
        if(n1==1&&n2==1)
        {
            printf("%s -- is a mirrored palindrome.\n",a);
        }
        else if(n1==1&&n2==0)
        {
            printf("%s -- is a regular palindrome.\n",a);
        }
        else if(n1==0&&n2==1)
        {
            printf("%s -- is a mirrored string.\n",a);
        }
        else
        {
            printf("%s -- is not a palindrome.\n",a);
        }
        printf("\n");
    }
    return 0;
}
