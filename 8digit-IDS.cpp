#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long lt;

int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

int deep;
int dx[5]={0,-1,1,0};
int dy[5]={1,0,0,-1};
char m[5][5];
char mb[4][4]={
'0','0','0','0',
'0','1','2','3',
'0','4','5','6',
'0','7','8','0'
};
bool dfs(int step,int x,int y,int last,int sum)//sum为还有多少未匹配的格子数
{
    if (step+sum>deep)return false;
    if (!sum)return true;
    int p;
    for (int k=0;k!=4;++k)
    {
        if (k!=(3-last))
        {
            p=sum;
            int xx=x+dx[k],yy=y+dy[k];
            if (xx<=0||yy<=0||xx>3||yy>3)continue;
            if (m[xx][yy]==mb[xx][yy]&&m[xx][yy]!=mb[x][y])++p;
            if (m[xx][yy]!=mb[xx][yy]&&m[xx][yy]==mb[x][y])--p;
            if (mb[xx][yy]=='0')--p;
            if (mb[x][y]=='0')++p;
            swap(m[xx][yy],m[x][y]);
            if (dfs(step+1,xx,yy,k,p))return true;
            swap(m[xx][yy],m[x][y]);
        }
    }
    return false;
}

int main()
{
    int x,y;
    int sum=0;
    for (int i=1;i<=3;++i)
    {
        for (int j=1;j<=3;++j)
        {
            m[i][j]=getchar();//输入673014582
            if (m[i][j]=='0')
            {
                x=i;
                y=j;
            }
            if (m[i][j]!=mb[i][j])
            ++sum;
        }
    }
    for (deep=1;;++deep)
    {
        if (dfs(0,x,y,-1,sum))
        {
            cout<<deep-1<<endl;
            break;
        }
        if(deep>27){ cout<<"no solution"<<endl; break; }
    }
    system("pause");
    return 0;
}
