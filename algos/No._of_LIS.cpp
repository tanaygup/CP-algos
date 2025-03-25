class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int>dp(n,1),count(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }else if(a[i]>a[j] && dp[j]+1==dp[i])count[i]+= count[j];
            }
        }
        int ind= *max_element(dp.begin(),dp.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==ind)ans+=count[i];
        }
        return ans;

    }
};
