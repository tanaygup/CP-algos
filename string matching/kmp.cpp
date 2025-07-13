class Solution {
  public:
    vector<int> search(string &p,string &s) {
        int n=s.size(),m=p.size();
        vector<int>ans;
        vector<int>lps(m,0);
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<m){
            if(p[i]==p[len]){
                lps[i++]= ++len;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    lps[i++]=0;
                }
            }
        }
        i=0;
        int j=0;
        while(i<n){
            if(s[i]==p[j]){
                i++;
                j++;
                if(j==m){
                    ans.push_back(i-j);
                    j=lps[j-1];
                }
            }else{
                if(j!=0){
                    j=lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return ans;
        
    }
};
