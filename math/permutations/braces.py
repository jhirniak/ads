"""
Find all well-formed braces.
"""


LEFT = '('
RIGHT = ')'


def bracemutations(n):
    if n == 1:
        yield LEFT + RIGHT
    else:
        for bracemutation in bracemutations(n-1):
            yield LEFT + bracemutation + RIGHT
            yield LEFT + RIGHT + bracemutation
            yield bracemutation + LEFT + RIGHT


if __name__ == '__main__':
    for i in range(1, 10):
        braces = set(bracemutations(i))
        print('{} ({}): {}'.format(i, len(braces), braces))
