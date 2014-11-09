# By Jakub Zalewski
# 08 November 2014

def subsets(vals, n):
    if n >= len(vals):
        return [vals]
    return subsets(vals, n+1) + subsets(vals[:n] + vals[(n+1):], n)

print subsets([1, 2, 3, 4], 0)
print subsets([], 0)
