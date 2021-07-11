def feedDog(hunger_level, biscuit_size):
    # Sort the hunger level  and biscuit size
    hunger_level.sort()
    biscuit_size.sort()

    result = 0
    hunger_level_pointer = 0

    for i in range(len(biscuit_size)):
        if hunger_level[hunger_level_pointer] <= biscuit_size[i]:
            result += 1
            hunger_level_pointer += 1
        if hunger_level_pointer == len(hunger_level):
            break

    return result


if __name__ == "__main__":
    hunger_level_input = [1, 2]
    biscuit_size_input = [1, 2, 3]

    numDogsFed = feedDog(hunger_level_input, biscuit_size_input)
    print(numDogsFed)
