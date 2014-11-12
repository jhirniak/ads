"""
    by Konrad Stojanowki
    12 November 2014
"""

matching = {}
matching['{'] = '}'
matching['('] = ')'
matching['['] = ']'

def balanced(braces):
    stack = []
    for b in braces:
        if b in matching.keys():
            stack.append(b)
        else:
            if len(stack) > 0:
                last = stack.pop()
                if matching[last] != b:
                    return False
            else:
                return False
    return stack == []

tests = ["[({])}", "[({})]"]

for t in tests:
    print t, "is balanced?", balanced(t)


