#include <bits/stdc++.h>
using namespace std;
struct point
{
    double  x, y;
} A[10000];
bool srt(point A, point B)
{
    if(A.x!=B.x)
        return A.x<B.x;
    return A.y<B.y;
}
double dist(point A, point B)
{
    return(sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)));
}
int main()
{
    cout<<fixed<<setprecision(2);
    int t;
    scanf("%d", &t);
    int n;

    while(t--)
    {
        double ans=0;
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>A[i].x>>A[i].y;
        if(n==2)
            ans=dist(A[0],A[1]);
        else
        {
            sort(A,A+n,srt);
            point mx=A[n-1];
            int cnt=0,B[100];


            for(int i=n-2;i>=0;i--)
            {
                if(A[i].y>mx.y)
                {
                point p;
                p.y=mx.y;
                double m =(A[i].y-A[i+1].y)/(A[i].x-A[i+1].x);
                p.x = (p.y - A[i].y + m*A[i].x)/m;

                double dst = dist(p,A[i]);

                ans+=dst;
                    mx=A[i];
                }

            }
        }
          cout<<ans<<endl;

    }

    return 0;
}
