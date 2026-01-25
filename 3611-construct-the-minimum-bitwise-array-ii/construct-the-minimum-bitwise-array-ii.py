class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for n in nums:
            if n == 2:
                ans.append(-1)
            else:
                # Find the position of the first zero bit starting from LSB.
                # Since n is an odd prime, it has a sequence of trailing ones.
                # We iterate bits until we find a 0.
                bit = 1
                while (n & bit):
                    bit <<= 1
                
                # 'bit' is now the power of 2 representing the first zero bit.
                # We want to flip the bit immediately to its right (the MSB of trailing ones).
                # That value is 'bit' shifted right by 1.
                ans.append(n - (bit >> 1))
        return ans