class Solution:
    def longestCommonPrefix(self, arr1, arr2):
        # Create a dictionary to store the lengths of all prefixes from arr1
        prefix_dict = {}

        # Populate the dictionary with prefixes from arr1
        for num in arr1:
            str_num = str(num)
            # Add all prefixes of the number to the dictionary
            for i in range(1, len(str_num) + 1):
                prefix = str_num[:i]
                prefix_dict[prefix] = max(prefix_dict.get(prefix, 0), i)

        max_common_prefix_length = 0

        # Check prefixes of numbers in arr2 against the prefix dictionary
        for num in arr2:
            str_num = str(num)
            for i in range(1, len(str_num) + 1):
                prefix = str_num[:i]
                if prefix in prefix_dict:
                    max_common_prefix_length = max(max_common_prefix_length, prefix_dict[prefix])

        return max_common_prefix_length