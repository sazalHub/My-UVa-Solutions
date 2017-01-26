#include<bits/stdc++.h>
using namespace std;
int main ()
{
    char text,save;

    while(scanf("%c",&text)==1)
    {
        if (text=='A'||text=='a'||text=='E'||text=='e'||text=='I'||text=='i'||text=='O'||text=='o'||text=='U'||text=='u')
        {
            printf("%c",text);
            while(scanf("%c",&text)==1&&(('z'>=text && text>='a') ||('Z'>=text && text>='A')))
            {
                printf("%c",text);
            }
            printf("ay%c",text);
        }
        else if (('z'>=text && text>='a') ||('Z'>=text && text>='A'))
        {
            save=text;
            while(scanf("%c",&text)==1&&(('z'>=text&& text>='a') ||('Z'>=text && text>='A')))
            {
                printf("%c",text);
            }
            printf("%cay%c",save,text);
        }
        else
        {
            printf("%c",text);
        }
    }
    return 0;
}
