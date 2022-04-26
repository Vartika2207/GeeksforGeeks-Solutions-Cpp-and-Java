//time: O(2^n), space: (2^n)
class Solution
{
    void function(vector<int> arr, int idx, int sum, vector<int> &subset_arr){
        if(idx == arr.size()){
            subset_arr.push_back(sum);
            return;
        }
        
        //not pick
        function(arr, idx + 1, sum, subset_arr);
        //pick
        function(arr, idx + 1, sum + arr[idx], subset_arr);
    }
    
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> subset_arr;
        
        function(arr, 0, 0, subset_arr);
        return subset_arr;
    }
};
