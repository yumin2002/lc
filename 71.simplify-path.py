#
# @lc app=leetcode id=71 lang=python3
#
# [71] Simplify Path
#

# @lc code=start
# class Solution:
#     def simplifyPath(self, path: str) -> str:
#         if path == '/':
#             return path
#         dq = collections.deque()
#         folders = path.split('/')
#         for folder in folders:
#             if folder == '.' or folder == '':
#                 continue
#             elif folder == '..':
#                 if len(dq) != 0:
#                     dq.pop()
#             else:
#                 dq.append(folder)
#         res = '/'
#         for item in dq:
#             res+=item + '/'
#         return '/' if len(res) == 1 else res[0:len(res) - 1]

class Solution:
    def simplifyPath(self, path: str) -> str:

        # Initialize a stack
        stack = []

        # Split the input string on "/" as the delimiter
        # and process each portion one by one
        print(path.split('/'))
        for portion in path.split("/"):

            # If the current component is a "..", then
            # we pop an entry from the stack if it's non-empty
            if portion == "..":
                if stack:
                    stack.pop()
            elif portion == "." or not portion:
                # A no-op for a "." or an empty string
                continue
            else:
                # Finally, a legitimate directory name, so we add it
                # to our stack
                stack.append(portion)

        # Stich together all the directory names together
        final_str = "/" + "/".join(stack)
        return final_str
# @lc code=end