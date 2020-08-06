Subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

class Solution {
private:
    vector<vector<int>>powerset;
    vector<int>subset;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,0);
        return powerset;
    }
    void backtrack(vector<int>&nums,int start){
        powerset.push_back(subset);
        for(int i=start;i<nums.size();i++){
            subset.push_back(nums[i]);
            backtrack(nums,i+1);
            subset.pop_back();
        }
    }
};
2)Combination sum
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

class Solution {
private:
    vector<vector<int>>powerset;
    vector<int>subset;
    int sum=0;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,0,target);
        return powerset;
    }
    void backtrack(vector<int>candidates,int start,int target){
        if(target==0){powerset.push_back(subset);return;}
        if(target<0)return;
        for(int i=start;i<candidates.size();i++){
            subset.push_back(candidates[i]);
            backtrack(candidates,i,target-candidates[i]);
            subset.pop_back();
        }
    }
};

3) Combination sum 2
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Each number in candidates may only be used once in the combination.

class Solution {
private:
    vector<vector<int>>powerset;
    vector<int>subset;
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,0,target);
        return powerset;
    }
    void backtrack(vector<int>candidates,int start,int target){
        if(target==0){powerset.push_back(subset);return;}
        if(target<0)return;
        for(int i=start;i<candidates.size();i++){
        if(i>start && candidates[i]==candidates[i-1])continue;
        subset.push_back(candidates[i]);
        backtrack(candidates,i+1,target-candidates[i]);
        subset.pop_back();
        }
    }
};

4)Permutations
Given a collection of distinct integers, return all possible permutations.

#include<bits/stdc++.h>
class Solution {
private:
    vector<vector<int>>powerset;
    vector<int>subset;
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
       backtrack(nums,0);
        return powerset;
    }
    void backtrack(vector<int>nums,int start){
        if(start==nums.size())
        powerset.push_back(nums);
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            backtrack(nums,start+1);
         }
    }
};