#!/usr/bin/env python3

"""
Different ways to implement least recently used cache in Python 3.

1. Using double-linked list and standard Python dictionary.
2. Using OrderedDict from collections library (easy as OrderedDict has already all necessary methods).
3. Caching using @lru_cache wrapper from functools library.

Finally, some simple tests to show that all are working as expected.
"""

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


class Node(object):

    def __init__(self, key, value, prev=None, next=None):
        self.key = key
        self.value = value
        self.prev = prev
        self.next = next

    def __repr__(self):
        return '<Node: ({}, {})>'.format(self.key, self.value)


class LRUCache(object):

    def __init__(self, capacity=10):
        self.capacity = capacity
        self.root = Node(None, None)
        self.root.prev = self.root
        self.root.next = self.root
        self.cache = {}

    def _remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        del self.cache[node.key]
        del node

    def add(self, key, value):
        if key in self.cache:
            # remove to push to the front of the list
            self._remove(self.cache[key])
        elif len(self.cache) >= self.capacity:
            # remove least recently used item
            self._remove(self.root.prev)

        first = self.root.next
        self.root.next = Node(key, value, self.root, first)
        first.prev = self.root.next
        self.cache[key] = self.root.next

    def get(self, key):
        try:
            value = self.cache[key]
            self.add(key, value)
            return value
        except KeyError as e:
            print(e, file=sys.stderr)

    def contains(self, key):
        return key in self.cache

    def __repr__(self):
        curr = self.root.next
        dll_str = '{}'.format(self.root)
        while curr != self.root:
            dll_str += ' -- {}'.format(curr)
            curr = curr.next
        dll_str += ' -- {}'.format(self.root)
        return '<ClassName: {}\n' \
               'Cache keys: {}\n' \
               'DLL root: {}>'\
                .format(self.__class__.__name__, self.cache.keys(), dll_str)


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


from collections import OrderedDict


class LRUCacheOD(object):

    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = OrderedDict()

    def add(self, key, value):
        if len(self.cache) >= self.capacity:
            self.cache.popitem(last=False)
        self.cache[key] = value

    def get(self, key):
        value = self.cache.pop(key)
        self.cache[key] = value
        return value

    def contains(self, key):
        return key in self.cache


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


from functools import lru_cache


@lru_cache(maxsize=None)
def fib(n):
    return fib(n-1) + fib(n-2) if n > 2 else 1


fibs = lru_cache(None)(lambda n: fibs(n-1) + fibs(n-2) if n > 2 else 1)

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


if __name__ == '__main__':
    import sys
    from string import ascii_lowercase

    Implementations = [LRUCache, LRUCacheOD]

    tests = [
        (10,
         [('add', k, v) for k, v in zip(range(len(ascii_lowercase)), ascii_lowercase)] +
         [('get', k, v) for k, v in [(10, False), (16, True), (0, False), (25, True)]]),
        (3, [('add', 0, 'a'), ('add', 1, 'b'), ('get', 0, True), ('add', 2, 'c'), ('add', 2, 'c'), ('add', 3, 'd'),
             ('get', 0, True), ('get', 1, False), ('get', 2, True), ('get', 3, True)])
    ]

    for Implementation in Implementations:
        test_counter = 0
        for capacity, operations in tests:
            print('Test {}'.format(test_counter), file=sys.stderr)
            test_counter += 1
            lru_cache = Implementation(capacity)

            for op, key, value in operations:
                if op == 'add':
                    print('add: ({}, {})'.format(key, value), file=sys.stderr)
                    lru_cache.add(key, value)
                elif op == 'get':
                    print('get: {}'.format(key), file=sys.stderr)
                    if lru_cache.contains(key):
                        lru_cache.get(key)
                    assert lru_cache.contains(key) == value,\
                        'Expected cache to{} contain {}, but it did{}.\nCache:\n{}'\
                        .format('' if value else ' not', key, ' not' if value else '', lru_cache)

    print('End of tests', file=sys.stderr)

    print('Test fib', file=sys.stderr)
    print([fib(n) for n in range(1, 1000)], file=sys.stderr)
    print([fibs(n) for n in range(1, 1000)], file=sys.stderr)
