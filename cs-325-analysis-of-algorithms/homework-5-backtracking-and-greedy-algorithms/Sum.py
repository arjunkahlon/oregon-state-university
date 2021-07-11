def combination(n, k):
    result = []
    combination_helper(result, n, k, [])
    return result


def combination_helper(result, rem_sum, rem_times, picked_numbers):
    if rem_times == 0 and rem_sum == 0:
        # copy the list so that the original list can be changed in the later iteration
        result.append(picked_numbers[:])

    if rem_times != 0:
        for x in range(1 if len(picked_numbers) == 0 else picked_numbers[-1] + 1, 9 + 1):
            picked_numbers.append(x)
            combination_helper(result, rem_sum - x, rem_times - 1, picked_numbers)
            picked_numbers.pop()


if __name__ == "__main__":
    k = 3
    n = 12
    output = combination(n, k)
    print(output)