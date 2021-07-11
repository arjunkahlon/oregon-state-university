def max_independent_set(numbers):
    for idx in range(len(numbers) + 1):
        if idx == 0: # base case of 0
            max_sum[idx] = 0
            picked_numbers[idx] = ''
        elif idx == 1: # base case of 1
            max_sum[idx] = numbers[idx - 1]
            picked_numbers[idx] = str(numbers[idx - 1])
        else:
            if max_sum[idx-1] > max_sum[idx-2] + numbers[idx - 1]:
                max_sum[idx] = max_sum[idx-1]
                picked_numbers[idx] = picked_numbers[idx-1]
            else:
                max_sum[idx] = max_sum[idx-2] + numbers[idx - 1]
                picked_numbers[idx] = picked_numbers[idx-2] + f' {numbers[idx - 1]}'
    print(f'picked numbers - [{picked_numbers[-1].lstrip()}], max sum value - {max_sum[-1]}')


if __name__ == '__main__':
    input_numbers = [7, 2, 5, 8, 6]
    max_sum = [0] * (len(input_numbers) + 1)
    picked_numbers = [''] * (len(input_numbers) + 1)
    max_independent_set(input_numbers)