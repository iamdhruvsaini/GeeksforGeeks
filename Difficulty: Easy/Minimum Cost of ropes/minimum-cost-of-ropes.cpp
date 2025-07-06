class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(auto i : arr){
            pq.push(i);
        }
        int count=0;
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            count+=a+b;
            
            pq.push(a+b);
        }
        
        return count;
        
    }
};