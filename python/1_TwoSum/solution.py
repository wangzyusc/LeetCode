class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        pos = {}
        for index, num in enumerate(nums):
            if (target - num) in pos:
                return pos[target-num], index
            else:
                pos[num] = index


if __name__ == '__main__':
    sol = Solution()
    print sol.twoSum([2, 7, 9, 11], 9)
