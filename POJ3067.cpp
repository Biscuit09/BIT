#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long int n,m,k;
long long int c[2000];
struct road
{
    long long int x,y;
}r[1003*1003];

bool cmp(road a,road b)
{
    if(a.x==b.x)
    {
        return a.y<b.y;
    }
    else return a.x<b.x;
}
long long int lowbit(long long int i)
{
    return i&(-i);
}
void add(long long int i,long long int v)
{
    while(i<=m)
    {
        c[i]+=v;
        i+=lowbit(i);
    }
}
long long int sum(long long int i)
{
    long long int s=0;
    long long int j=i;
    while(j > 0 )
    {
        s+=c[j];
        j-=lowbit(j);
    }
    return s;
}

int main()
{
    long long int tt;
    long long int T=1;
    long long int i,j;
    scanf("%lld",&tt);
    while(tt--)
    {
        memset(c,0,sizeof(c));
        scanf("%lld%lld%lld",&n,&m,&k);
        for(i = 0; i < k; i++)
            scanf("%lld%lld",&r[i].x,&r[i].y);
        sort(r,r+k,cmp);
        long long int ans=0;
        for(i = 0; i < k; i++)
        {
            add(r[i].y,1);
            ans+=((sum(m))-(sum(r[i].y)));
        }
        printf("Test case %lld: %lld\n",T++,ans);
    }
    return 0;
}
