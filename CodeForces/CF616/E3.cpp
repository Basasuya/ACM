#include<bits/stdc++.h>
using namespace std;
const int maxn = 6e5+7;
int n,k;
string s;
int l[maxn][2],r[maxn],cnt[maxn];
int getroot(int x){
    return r[x]==x?x:r[x]=getroot(r[x]);
}
int calc(int x){
    int y=x<=k?x+k:x-k;
    x=getroot(x);
    y=getroot(y);
    if(x==0||y==0){
        return cnt[x+y];
    }
    return min(cnt[x],cnt[y]);
}
void fmerge(int x,int y){
    x=getroot(x);
    y=getroot(y);
    if(y==0){
        swap(x,y);
    }
    r[y]=x;
    if(x!=0){
        cnt[x]+=cnt[y];
    }
}
int main(){
    cin>>n>>k;
    cin>>s;
    for(int i=1;i<=k;i++){
        int c;cin>>c;
        for(int j=0;j<c;j++){
            int x;cin>>x;
            if(l[x][0]==0)l[x][0]=i;
            else l[x][1]=i;
        }
        r[i]=i; // i dont't use i+k use
        r[i+k]=i+k;
        cnt[i+k]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(l[i][1]==0){
            int x = l[i][0];
            if(x){
                ans-=calc(x);
                if(s[i-1]=='1'){
                    r[getroot(x+k)]=0;
                }else{
                    r[getroot(x)]=0;
                }
                ans+=calc(x);
            }
        }else{
            int x=l[i][0],y=l[i][1];
            if(s[i-1]=='1'){
                if(getroot(x)!=getroot(y)){
                    ans-=calc(x);
                    ans-=calc(y);
                    fmerge(x,y);
                    fmerge(x+k,y+k);
                    ans+=calc(x);
                }
            }else{
                if(getroot(x+k)!=getroot(y)){
                    ans-=calc(x);
                    ans-=calc(y);
                    fmerge(x+k,y);
                    fmerge(x,y+k);
                    ans+=calc(x);
                }
            }
        }
        cout<<ans<<endl;
    }
}