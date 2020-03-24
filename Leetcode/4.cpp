class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vc;
        for(int i = 0, len = nums1.size(); i < len; ++i) {
            vc.push_back(nums1[i]);
        }

        for(int i = 0, len = nums2.size(); i < len; ++i) {
            vc.push_back(nums2[i]);
        }
        sort(vc.begin(), vc.end());

        if(vc.size() % 2 == 1) return 1.0 * vc[vc.size() / 2];
        else return (vc[vc.size() / 2] + vc[vc.size() / 2 - 1]) / 2.0;
    }   
};



/*


给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/