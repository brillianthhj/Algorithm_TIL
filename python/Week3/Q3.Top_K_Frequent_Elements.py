from collections import Counter, OrderedDict

class Solution:
    def topKFrequent(self, nums, k):
        d = Counter(nums)
        dd = dict(OrderedDict(sorted(d.items(), key = lambda t : t[1], reverse = True)))
        
        return list(dd.keys())[:k]