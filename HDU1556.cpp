#include<stdio.h>
#include<string.h>
#include<math.h>
int lowbit(int a)
{
    return a&-a;
}
int c[100010];
int sum[100010];
int main()
{
    int n,a,b;
    while(~scanf("%d",&n))
    {
        if(n==0)break;
        memset(c,0,sizeof(c));
        memset(sum,0,sizeof(sum));
        int i,j,k;
        int a,b;
        for(i = 1; i < n+1; i++)
        {
            scanf("%d%d",&a,&b);
            j=a;
            while(j<=n)
            {
                c[j]+=1;
                j+=lowbit(j);
            }
            j=b+1;
            while(j<=n)
            {
                c[j]-=1;
                j+=lowbit(j);
            }
        }

        for(j = 1; j < n+1; j++)
        {
            k = j;
            while(k >0)
            {
                sum[j]+=c[k];
                k-=lowbit(k);
            }
            if(j==n)printf("%d\n",sum[j]);
            else printf("%d ",sum[j]);
        }
    }
    return 0;
}
