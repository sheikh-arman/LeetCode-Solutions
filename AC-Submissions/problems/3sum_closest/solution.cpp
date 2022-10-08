//later
class Solution {
public:
    int mymin(int a,int b){
        return (b>a ? a : b);
    }
    int threeSumClosest(vector<int>& nums, int target) {
       vector<int> arr(nums.begin(),nums.end());
        sort(arr.begin(),arr.end());
        int ans=1e5;
        bool check=false;
		int finalans=ans;
        int sum=0;
        for(int i=0;i<arr.size()-2;i++){
            int var1=arr[i];
            int front=i+1;
            int back=arr.size()-1;
            while(front<back)
            {
                sum=var1+arr[front]+arr[back];
                if(  ans > mymin(ans,abs(sum-target))    )
                {
                    ans=mymin(ans,abs(sum-target));
                    finalans=sum;
                }
                if(sum>target)
                {
					back--;
                }
                else if(sum<target)
                {
                    front++;
                }
                else{
                    return target;
                }
            }
           
            
        }
        return finalans;
        
    }
};