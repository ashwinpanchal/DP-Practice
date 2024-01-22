#include<bits/stdc++.h>
using namespace std;

int coinProbRecursive(vector<int> coins,int target){
    if(target==0){
        return 0;
    }
    if(target<0){
        return 1e9;
    }
    int ans = 1e9;
    for(int i=0;i<coins.size();i++){
        ans = min(ans, 1 + coinProbRecursive(coins,target-coins[i]));
    }
    return ans;
}

int coinMemo(vector<int> coins,int target, vector<int> &memo){
    if(target==0){
        return 0;
    }
    if(target<0){
        return 1e9;
    }
    if(memo[target]!=-1){
        return memo[target];
    }
    int ans = 1e9;
    for(int i=0;i<coins.size();i++){
        ans = min(ans, 1 + coinMemo(coins,target-coins[i],memo));
    }
    memo[target] = ans;
    return ans; 
}

int coinDP(vector<int> coins,int target){
    vector<int> ans(target+1,-1);
    ans[0] = 0;
    for(int i=1;i<ans.size();i++){
        int ansi = 1e9;
        for(auto c: coins){
            int g = i-c;
            if(g<0){
                continue;
            }
            ansi = min(ansi, 1 + ans[g]);
        }
        ans[i] = ansi;
    }
    return ans[target];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int k,target;
    cin>>k>>target;
    vector<int> coins(k);
    for(int &t: coins){
        cin>>t;
    }
    cout<<"Rescursive "<<coinProbRecursive(coins,target)<<endl;
    vector<int> memo(target+1,-1);
    cout<<"Memo "<<coinMemo(coins,target,memo)<<endl;
    cout<<"DP "<<coinDP(coins,target);
    return 0;
}