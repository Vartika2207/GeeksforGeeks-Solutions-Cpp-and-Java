
class Solution{
    vector<int> demo = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    public:
       vector<int> ans ;
       vector<int> min_demo(int val){
           int n = demo.size();
           for(int i = n - 1; i >= 0; i--){
               while(val >= demo[i]){
                   val -= demo[i];
                   ans.push_back(demo[i]);
               }

           }
           return ans;
       }

    vector<int> minPartition(int N)
    {
        return min_demo(N);
    }
};
