def powerset(picked_numbers, numbers):
    for num in numbers:
        if num not in picked_numbers:
            picked_numbers.append(num)

            if set(picked_numbers) not in result:
                result.append(set(picked_numbers))

            if len(picked_numbers) != len(numbers):
                powerset(picked_numbers, numbers)

            picked_numbers.pop()


if __name__ == "__main__":
    # empty set should be included
    result = [{}]
    # input_numbers = [1, 2, 3, 4]
    input_numbers = [1, 2, 3]
    powerset([], input_numbers)
    print(result)