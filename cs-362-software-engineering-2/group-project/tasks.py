# Group 30
# Arjun Kahlon, Harry Grunner, Roman Guerrero
# [CS 362] Software Engineering II
# Group Project: Part 2
# 6/1/20

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Function 1: conv_num(num_str)                                               #
# This function takes in a string and converts it into a base 10 number and   #
# returns it                                                                  #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

import re


def str_to_unicode_list(num_str):
    unicode_list = []

    for s in num_str:
        unicode_list.append(ord(s))

    return unicode_list


# convert string to int, float, or hex
def conv_num(num_str):
    if (not isinstance(num_str, str)):
        return
    else:
        # if hex
        if (validate_hex(num_str)):
            # treat it as a hex
            unicode_list = str_to_unicode_list(num_str)
            # print(unicode_list)

            return str_to_hex(unicode_list)

        # if decimal
        elif (validate_decimal(num_str)):
            # treat it as a decimal

            return str_to_decimal(num_str.split("."))

            pass
        # if int
        elif (validate_int(num_str)):
            # treat it as an int
            #
            # Check for non-numeric characters
            #
            # convert num_str to list of unicode characters
            # print("is int")
            unicode_list = str_to_unicode_list(num_str)
            return str_to_int(unicode_list)
        # bogus
        else:
            return None


def unicode_to_int(unicode):
    if (48 <= unicode <= 57):
        return unicode - 48

    elif (65 <= unicode <= 70):
        return unicode - 55
    else:
        return None


def unicode_to_float(unicode):
    if (48 <= unicode <= 57):
        return unicode - 48.0

    elif (65 <= unicode <= 70):
        return unicode - 55
    else:
        return None


def validate_decimal(num_str):
    # only numbers and decimal point and -
    p = re.compile(r'^\-?[0-9]*\.[0-9]*$')
    return p.match(num_str)


def validate_int(num_str):
    # only numbers -
    p = re.compile(r'^\-?[0-9]+$')
    return p.match(num_str)


def validate_hex(num_str):
    # only a-f, 0, x, and -
    p = re.compile(r'^\-?0[xX][0-9a-fA-F]+$')
    return p.match(num_str)


def str_to_hex(unicode_list):
    neg_multiplier = 1
    value = 0
    base_sixteen = 0

    # if first character is dash
    if (unicode_list[0] == 45):
        unicode_list.pop(0)
        neg_multiplier = -1

    # pop 0 and x
    unicode_list.pop(0)
    unicode_list.pop(0)
    # print("after popping ")
    # print(unicode_list)
    # ABCDEF
    for i in reversed(unicode_list):
        # print(unicode_to_int(i))
        value += unicode_to_int(i) * (16 ** base_sixteen)
        base_sixteen += 1

    return neg_multiplier * value


def str_to_decimal(decimal_array):
    # print(decimal_array)
    # get the unicode list for the number before the decimal and convert to int
    before_decimal_as_int = str_to_int(str_to_unicode_list(decimal_array[0]))
    # print("before decimal " + str(before_decimal_as_int))
    # get the unicode list for the number after the decimal
    after_decimal = str_to_unicode_list(decimal_array[1])
    # print("after decimal ")
    # print(after_decimal)
    # print(after_decimal)
    base_ten = 1
    value = 0.0
    # print("loop")
    # loop through list backwards
    for s in after_decimal:
        # print("single digit" + str(unicode_to_int(s)))
        value += (unicode_to_float(s) / (10 ** base_ten))
        # print(value)
        base_ten += 1

    # value = value / (10 ** len(after_decimal))
    # print("value after " + str(value))

    if (before_decimal_as_int < 0):
        value *= -1
    # else:
    #    before_decimal_as_int += value

    # print(value)

    # print("ta-dah " + str(before_decimal_as_int))
    return before_decimal_as_int + value


def str_to_int(unicode_list):
    base_ten = 0
    value = 0
    # loop through list backwards
    for s in reversed(unicode_list):

        # print(s)

        # if last element and last element is "-"
        if (unicode_list[0] == s) and s == 45:
            value = value * -1
        else:
            value += (unicode_to_int(s) * (10 ** base_ten))
            base_ten += 1

    return value

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Function 2: my_datetime(num_sec)                                            #
# This function takes in an integer value that represents the number of       #
# seconds since the epoch: January 1st 1970                                   #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


def my_datetime(num_sec):
    year = 31536000
    leap_year = 31622400
    cur_year = 1970

    # checks if cur_year is a leap, then subtracts # of seconds (year or leap)
    # from total sec remaining, until less than a year of seconds remaining
    # Also increments the current year as it iterates
    while num_sec > year:

        if leap_check(cur_year):
            num_sec -= leap_year
        else:
            num_sec -= year
        cur_year += 1

    days = num_sec / 86400 + 1

    # Calculates the correct month given the < year day remainder
    if leap_check(cur_year):
        months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    else:
        months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    count = 0
    for i in months:
        count += 1
        if i >= days:
            break
        else:
            days -= i

    # call format_date for month and day values, adds them to cur_year
    format_date = date_format(count, days) + str(cur_year)
    return format_date


def leap_check(year):

    # determines if year is a leap year, returns False if not
    if (year % 400 == 0) or (year % 100 != 0) and (year % 4 == 0):
        return True

    return False


# formats the month and day to add 0 to 1-9 values
def date_format(month, day):

    month_format = ''
    day_format = ''
    day = int(day)

    if month < 10:
        month_format = '0' + str(month)
    else:
        month_format = str(month)

    if day < 10:
        day_format = '0' + str(day)
    else:
        day_format = str(day)

    month_format = str(month_format)
    day_format = str(day_format)
    form_mon_day = month_format + "-" + day_format + "-"

    return form_mon_day

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Function 3: conv_endian(num, endian='big')                                  #
# This function takes in an integer value as num and converts it to a         #
# hexadecimal number. The endian type is determined by the flag endian. The   #
# function will return the converted number as a string.                      #
# Sources:  https://www.rapidtables.com/convert/number/decimal-to-hex.html    #
#           https://stackoverflow.com/a/3258596/10895933                      #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


def conv_endian(num, endian='big'):
    answer = negative = ''
    hexTable = ['0', '1', '2', '3', '4', '5', '6',
                '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']

    if endian != 'big' and endian != 'little':
        return None

    if num < 0:
        num *= -1
        negative = True

    # Conversion logic
    while True:
        # Floor divide num by 16 & get integer quotient for next iteration
        quotient = num // 16
        remainder = num - (quotient * 16)  # Get the remainder for hex digit
        num = quotient  # iterate num to next quotient
        remainder = hexTable[remainder]  # Convert to hex digit (string)
        answer = remainder + answer  # Push to string

        if num == 0:
            break

    # Format hex string
    length = len(answer)
    lm2 = length % 2  # length mod 2
    if lm2 == 1:  # Each byte must be 2 characters in length
        answer = '0' + answer  # add '0' if applicable

    if endian == 'little':  # Reverses order if little-endian
        temp = ''
        for i in range(0, length, 2):
            temp = answer[i] + answer[i + 1] + temp
        answer = temp

    # Insert space after every 2nd byte
    if length > 2:
        # https://stackoverflow.com/a/3258596/10895933
        # t is an iterator of tuples, with each tuple having 1 element
        t = iter(answer)
        answer = ' '.join(a + b for a, b in zip(t, t))

    # Add negative
    if negative:
        answer = '-' + answer

    return answer


if __name__ == '__main__':
    dummy = 0
