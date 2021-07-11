import time


def game_topdown(n):
    for i in range(1, n):
        if n % i == 0:
            first_hand_value_for_b = n - i
            # when A can find one possible first hand losing case for B, choose that case immediately
            if first_hand_win_or_lose_cache[first_hand_value_for_b] == LOSE:
                first_hand_win_or_lose_cache[n] = WIN
                return True
            # when the value of first_hand_value_for_b is not calculated yet, Calculate it
            elif first_hand_win_or_lose_cache[first_hand_value_for_b] == NA:
                is_b_first_hand_win = game_topdown(first_hand_value_for_b)
                if not is_b_first_hand_win:
                    first_hand_win_or_lose_cache[n] = WIN
                    return True

    # if loop finishes without find any possible winning case, then it must be a losing case
    first_hand_win_or_lose_cache[n] = LOSE
    return False


def game_bottomup(n):
    # start from 4 since 2 & 3 are the base cases
    for i in range(4, n + 1):
        for k in range(1, i):
            if i % k == 0:
                first_hand_value_for_b = i - k
                if first_hand_win_or_lose_cache[first_hand_value_for_b] == LOSE:
                    first_hand_win_or_lose_cache[i] = WIN
        # set to lose if there is not any win case
        if first_hand_win_or_lose_cache[i] == NA:
            first_hand_win_or_lose_cache[i] = LOSE
    return first_hand_win_or_lose_cache[n] == WIN


if __name__ == "__main__":
    n = int(input("Input the number: "))

    # constant
    LOSE, NA, WIN = -1, 0, 1
    # initialization and base case of 2 & 3
    first_hand_win_or_lose_cache = [NA] * (n + 1)
    first_hand_win_or_lose_cache[2] = WIN
    first_hand_win_or_lose_cache[3] = LOSE

    start = time.time()
    is_player_a_the_winner = game_topdown(n)
    end = time.time()
    print(f"Player A is the {'winner' if is_player_a_the_winner else 'loser'}")
    print(f"Time elapsed with top down: {end - start}")
    print(f"cache array {first_hand_win_or_lose_cache}")

    # Reset base case of 2 & 3
    first_hand_win_or_lose_cache = [NA] * (n + 1)
    first_hand_win_or_lose_cache[2] = WIN
    first_hand_win_or_lose_cache[3] = LOSE

    start = time.time()
    is_player_a_the_winner = game_bottomup(n)
    end = time.time()
    print(f"Player A is the {'winner' if is_player_a_the_winner else 'loser'}")
    print(f"Time elapsed with bottom up: {end - start}")
    print(f"cache array {first_hand_win_or_lose_cache}")
