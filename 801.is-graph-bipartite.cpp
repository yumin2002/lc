// we cannot initialize an int reference
// backtrack
/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 */

// @lc code=start
// class Solution {
// public:
//     int minSwap(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> swap(nums1.size(),MAX_INT);
//         vector<int> not_swap(nums1.size(),MAX_INT);
//         swap[0] = 1;
//         not_swap[0] = 0;
//         for (int i = 1; i < nums1.size(); i++) {
//             if (nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]) {
//                 swap[i] = swap[i - 1] + 1;
//                 not_swap[i] = not_swap[i - 1];
//             }
//             if (nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
//                 swap[i] = min(swap[i],not_swap[i-1] + 1);
//                 not_swap[i] = min(not_swap[i], swap[i-1]);
//             }
//         }
//         return min(*(swap.end()), *(not_swap.end()));
//     }
// };

// for backtracking we have:
// containers for permutation: nums1, nums2,
// index that we have permutated: i
// our current status: curr(which is the current swap made given the status of the container)
// optimal soluction so far: opt

// for a backtracking:
// when i reach the end of the container, we finished the permutation, so we need to update the optimal solution
// optimization: when the current solution is already worse than the optimal solution, discard the current permutation
// recursive step: when to choose swap or not swap
// when we have and index where swaping and not swaping are both legal, we need to choose
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() <= 1) return 0;
        int opt = INT_MAX;
        backtrack(nums1,nums2,1,0,opt);
        return opt;
    }
    void backtrack(vector<int> & nums1, vector<int> & nums2, int i, int curr, int& opt){
        if (curr > opt) return;
        if (i == nums1.size()) {
            opt = min(curr, opt);
            return;
        }
        // choose to keep the number at index i
        if (nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]){
            backtrack(nums1,nums2,i+1,curr,opt);
        }
        // choose to swap the number at index i
        if (nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
            swap(nums1[i],nums2[i]);
            backtrack(nums1,nums2,i+1,curr+1,opt);
            swap(nums1[i],nums2[i]);
        }
    }
};
// @lc code=end
// https://www.youtube.com/watch?v=__yxFFRQAl8

