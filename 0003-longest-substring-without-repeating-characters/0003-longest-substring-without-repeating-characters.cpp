class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        int i =0,j=0;
        int maxi =0;
        
        while(i<n && j<n){
            if(mpp.find(s[j])!=mpp.end()){ //
                //int k =i;
                i=max(i,mpp[s[j]]+1); 
                // int k =i; 
                // while(k<j){
                //     mpp.erase(s[k]);
                //     k++;
                // }
                
            }
            mpp[s[j]]=j;
            maxi=max(maxi,j-i+1);
            j++; 
        }
        return maxi;
    }
};