// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
       unordered_map<char,int>mp;
       for(auto it:pat){
           mp[it]++;
       }
       int m=pat.size();
       int n=txt.size();
       int i=0,j=0,count=mp.size(),ans=0;
       while(j<n){
           if(mp.find(txt[j])!=mp.end()){
               mp[txt[j]]--;
               if(mp[txt[j]]==0){
                   count--;
               }
           }
           if(j-i+1 < m){
               // move j
               j++;
           }
           else{
               // now its of size m
               if(count==0)ans++;
               // now remove element at index i
               if(mp.find(txt[i])!=mp.end()){
                   mp[txt[i]]++;
                   if(mp[txt[i]]==1){
                       count++;
                   }
               }
               i++;
               j++;
               
           }
       }
       
       return ans;
    }
};