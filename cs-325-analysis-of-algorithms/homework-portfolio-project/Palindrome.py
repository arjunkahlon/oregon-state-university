# bruteforce approach
def checkPalindrome_1(string, k):
    chars = list(string)
    return checkPalindrome_1_helper(chars, k, 0)


def checkPalindrome_1_helper(chars, k, pop_start_position):
    if k == 0:
        return helper_is_str_palindrome(chars)
    else:
        for i in range(pop_start_position, len(chars)):
            popped_char = chars.pop(i)
            is_palindrome = checkPalindrome_1_helper(chars, k - 1, i)
            if is_palindrome:
                return True
            chars.insert(i, popped_char)
    return False


# backtracking approach
# k - at most number of characters to be removed
def checkPalindrome_2(string, k):
    # since at most we can remove k characters
    for i in range(k+1):
        for j in range(len(string)-1, len(string)-1-k+i-1, -1):
            if string[i] == string[j]:
                if helper_is_str_palindrome(string[i:j+1]):
                    return True
                else:
                    max_chars_to_remove = k - (i + len(string) - 1 - j)
                    is_inner_str_palindrome = checkPalindrome_2(string[i+1:j], max_chars_to_remove)
                    if is_inner_str_palindrome:
                        return True
    return False


def helper_is_str_palindrome(chars):
    for i in range(len(chars) // 2):
        if chars[i] != chars[-(i + 1)]:
            return False
    # print(''.join(chars))
    return True


if __name__ == "__main__":
    # input_str = "abeczdfcba"
    # input_k = 3
    input_str = "character"
    input_k = 4
    print(checkPalindrome_1(input_str, input_k))
    print(checkPalindrome_2(input_str, input_k))