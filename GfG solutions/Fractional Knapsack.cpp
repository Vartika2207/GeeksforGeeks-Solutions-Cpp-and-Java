
class Solution
{
    bool static cmp(Item a, Item b){
        double a_val_per_wt = (double)a.value / (double)a.weight;
        double b_val_per_wt = (double)b.value / (double)b.weight;
        return a_val_per_wt > b_val_per_wt;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //desc order of val per weight
        sort(arr, arr + n, cmp);
         
        double ans = 0.0, curr_wt = 0.0; //currwt is knapsack wt
        
        for(int i = 0; i < n; i++){
            if(curr_wt + arr[i].weight <= W){
                ans += arr[i].value;
                curr_wt += arr[i].weight;
            }
            else{
                double fractional_val = (double)arr[i].value / (double)arr[i].weight;
                //for W weight
                fractional_val *= (W - curr_wt);
                ans += fractional_val;
                
                break;
            }
        }
        
        return ans;
    }
        
};
