class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size(), i = 0, j = 0;
        vector<int> temp;
        queue<int> q;

        while (j < n) {
            // Step 1: add element
            if (arr[j] < 0) q.push(arr[j]);

            // Step 2: window not reached
            if (j - i + 1 < k) {
                j++;
            }
            // Step 3: window size k
            else if (j - i + 1 == k) {
                // store answer
                if (!q.empty()) temp.push_back(q.front());
                else temp.push_back(0);

                // remove element going out
                if (!q.empty() && arr[i] == q.front()) {
                    q.pop();
                }

                i++;
                j++;
            }
        }
        return temp;
    }
};