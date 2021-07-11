import time
import sys

# Function implementing Dynamic Programming Paradigm

def blockpuzzle_dp(n):
    # base case 1: if n=1 return 1
    if n == 1:
        return 1
    # base case 2: if n=2 return 2
    if n == 2:
        return 2

    if n - 1 in stored_result:
        result_n_minus_one = stored_result[n - 1]
    else:
        result_n_minus_one = blockpuzzle_dp(n - 1)
    if n - 2 in stored_result:
        result_n_minus_two = stored_result[n - 2]
    else:
        result_n_minus_two = blockpuzzle_dp(n - 2)
    stored_result[n] = result_n_minus_one + result_n_minus_two
    return result_n_minus_one + result_n_minus_two


# Brute Force Function

def blockpuzzle(n):
    # base case 1: if n=1 return 1
    if n == 1:
        return 1
    # base case 2: if n=2 return 2
    if n == 2:
        return 2
    # else divide the number in pieces of 1 and 2
    return blockpuzzle(n - 1) + blockpuzzle(n - 2)


if __name__ == "__main__":
    # input N
    N = int(input("Enter your number: "))

    stored_result = {}


    # for calculating time elapse
    start = time.process_time()

    # set recursion depth limit and the default value is 1000
    sys.setrecursionlimit(2000)

    # calling the function puzzle to print the number of ways
    print(blockpuzzle_dp(N))
    end = time.process_time()

    print(f"Time elapsed for dp: {end - start} second(s)")
    # print(stored_result)

    start = time.process_time()
    print(blockpuzzle(N))
    end = time.process_time()

    print(f"Time elapsed for bf: {end - start} second(s)")
