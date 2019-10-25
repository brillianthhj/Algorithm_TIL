class Solution(object):
    def isAlienSorted(self, words, order):
        dic = {
            alphabet : num
            for num, alphabet in enumerate(order)
        }
        
        for i in range(len(words)-1):            
            for j in range(min(len(words[i]), len(words[i + 1]))):
                if dic[words[i][j]] > dic[words[i + 1][j]]:
                    return False
                elif dic[words[i][j]] < dic[words[i + 1][j]]:
                    break
            
            else:
                if len(words[i]) > len(words[i + 1]):
                    return False

        return True





# words = ["word","world","row"]
# order = "worldabcefghijkmnpqstuvxyz"

# words = ["hello","leetcode"]
# order = "hlabcdefgijkmnopqrstuvwxyz"

# words = ["apple","app"]
words = ["abcde", "ad"]
order = "abcdefghijklmnopqrstuvwxyz"

s = Solution()
print(s.isAlienSorted(words, order))