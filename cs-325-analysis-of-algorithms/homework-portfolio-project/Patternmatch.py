# Divide and conquer plus backtracking
def patternmatch(string, pattern):

    num_of_asterisk, num_of_question_mark = 0, 0
    for current_pattern_index in range(len(pattern)):
        if pattern[current_pattern_index] == "*":
            num_of_asterisk += 1
        if pattern[current_pattern_index] == "?":
            num_of_question_mark += 1
    # if the pattern only contains asterisk and question mark
    if num_of_asterisk + num_of_question_mark == len(pattern):
        if num_of_asterisk == 0:
            return num_of_question_mark == len(string)
        else:
            return num_of_question_mark <= len(string)
    # if the pattern does not contain wildcard
    if (num_of_asterisk, num_of_question_mark) == (0, 0):
        return pattern == string

    for current_pattern_index in range(len(pattern)):
        if pattern[current_pattern_index] not in ["*", "?"]:
            for current_string_index in range(len(string)):
                if string[current_string_index] == pattern[current_pattern_index]:
                    is_left_matched = patternmatch(string[:current_string_index], pattern[:current_pattern_index])
                    is_right_matched = patternmatch(string[current_string_index + 1:], pattern[current_pattern_index + 1:])
                    if is_left_matched and is_right_matched:
                        return True

    return False


if __name__ == "__main__":
    input_str = "aabbcde"
    input_pattern = "*a??c*e"
    print(patternmatch(input_str, input_pattern))