class Solution(object):
    '''
    This solution beats 62.4% solutions.
    '''
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        nums = {}
        res, count = 0, 0
        j = 0
        for i, c in enumerate(s):
            nums[c] = 1 if c not in nums else nums[c] + 1
            while nums[c] > 1:
                nums[s[j]] -= 1
                j += 1
            if (i - j + 1) > res:
                res = i - j + 1
        return res
        

