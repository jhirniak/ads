"""
Compute the number of possible ways to climb stairs if a person can make from 1 to `n` steps at the time.

In a sense, it is a generalisation of Fibonacci numbers, where Fibonacci numbers are case when `n = 2`.
`n = 3` means that g(n) = g(n-1) + g(n-2) + g(n-3).
"""


from functools import lru_cache


@lru_cache(maxsize=None)
def steps(stairs, n=2):
    return sum([steps(stairs - i, n) for i in range(1, n+1)]) if stairs >= n else 1


# For n = 2 should be same as Fib
tests = [(stairs, n) for n in range(2, 10) for stairs in range(100)]


if __name__ == '__main__':
    for stairs, n in tests:
        print('({}, {}): {}'.format(stairs, n, steps(stairs, n)))
