#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long int a[50010];
long long int c[50010];
int num;

long long int lowbit(long long int i)
{
    return i&(-i);
}
void add(int i,int v)
{
    while(i<=num)
    {
        c[i]+=v;

        i+=lowbit(i);
    }
}
long long int sum(int i)
{
    long long int s=0;
    int j=i;
    while(j > 0)
    {
        s+=c[j];
        j-=lowbit(j);
    }
    return s;
}

int main()
{
    int t,T=1;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        int n;
        scanf("%d",&num);
        printf("Case %d:\n",T++);
        int i,j;
        for(i = 1; i < num+1; i++)
        {
            scanf("%d",&a[i]);
            add(i,a[i]);
        }
        char s[10];
        while(scanf("%s",s))
        {
            if(strcmp(s,"End")==0)break;
            else if(strcmp(s,"Query")==0)
            {
                scanf("%d%d",&i,&j);
                printf("%I64d\n",sum(j)-sum(i-1));
            }
            else if(strcmp(s,"Add")==0)
            {
                scanf("%d%d",&i,&j);
                a[i]+=j;
                add(i,j);
            }
            else if(strcmp(s,"Sub")==0)
            {
                scanf("%d%d",&i,&j);
                a[i]-=j;
                add(i,-j);
            }
        }
    }
    return 0;
}
