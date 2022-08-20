typedef long long int ll;
#define N 50010
class Solution {
public:
    
    ll seg_tree[4*N];
    ll ar[N+10];
    ll build(ll n,ll b,ll e)
    {
       if(b==e)
      {
           seg_tree[n]=0;
            return 0;
     }
     ll p=build(n*2,b,(b+e)/2);
     ll q=build(n*2+1,(b+e)/2+1,e);
     seg_tree[n]=0;
     return 0;
}
    void update(ll n,ll b,ll e,ll i,ll j,ll up_no)
{
    if(b>=i&&e<=j)
    {
        seg_tree[n]+=up_no;
        return;
    }
    if(e<i||b>j)
    {
        return;
    }
    update(n*2,b,(b+e)/2,i,j,up_no);
    update(n*2+1,(b+e)/2+1,e,i,j,up_no);
}
    ll cnt;
void query(ll n,ll b,ll e,ll i,ll j )
{
    if(b>=i&&e<=j)
    {
        cnt+=seg_tree[n];
        return;
    }
    if(e<i||b>j)
    {
        return;
    }
    cnt+=seg_tree[n];
    query(n*2,b,(b+e)/2,i,j);
    query(n*2+1,(b+e)/2+1,e,i,j);;
}
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        ll x=build(1,1,n);
        int siz=shifts.size();
        for(int i=0;i<siz;i++){
            int a=shifts[i][0];
            int b=shifts[i][1];
            int f=shifts[i][2];
            if(a>b)swap(a,b);
            a++;b++;
            if(f==1){
                update(1,1,n,a,b,1);
            }
            else{
                 update(1,1,n,a,b,-1);
            }
        }
        string str;
        for(int i=0;i<n;i++){
            int val=i+1;
            cnt=0;
            query(1,1,n,val,val);
            ll st_val=s[i]-'a';
            cnt+=st_val;
            cnt+=(26000000000);
            cnt%=26;
            str+=(char)(cnt+'a');
            
        }
        return str;
    }
};