

def permutations(items):
    if len(items) <= 1:
        yield items
    else:
        for permutation in permutations(items[1:]):
            for i in range(len(items)):
                mutator = items[0] if type(items[0]) == str else [items[0]]
                yield permutation[:i] + mutator + permutation[i:]


tests = [
    'abcd',
    [1, 2, 3]
]


if __name__ == '__main__':
    for test in tests:
        perms = list(permutations(test))
        print('Permutations ({}):\n{}'.format(len(perms), perms))
