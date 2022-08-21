/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for (auto a:nums)
        {
            sum +=a;
            ans = max(ans, sum);
            if(sum<0)sum =0;
        }
        return ans;
    }
};

/*209 / 209 test cases passed.
Status: Accepted
Runtime: 184 ms
Memory Usage: 67.6 MB
*/
