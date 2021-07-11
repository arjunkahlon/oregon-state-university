def MajorityBirthdays(input_arr):

    def max_occurrence_birthday(arr, start, end):  # a helper D&C function
        if start < end:
            mid = (start+end) // 2
            max_birthday_left, occurrence_of_weekdays_left = max_occurrence_birthday(arr, start, mid)
            max_birthday_right, occurrence_of_weekdays_right = max_occurrence_birthday(arr, mid + 1, end)
            return merge( occurrence_of_weekdays_left, occurrence_of_weekdays_right)
        else:
            max_birthday = {arr[start]}
            occurrence_of_weekdays = {arr[start]: 1}
            return max_birthday, occurrence_of_weekdays

    def merge(occurrence_of_weekdays_left: dict, occurrence_of_weekdays_right: dict):
        max_day_of_birthday = set()  # invariant
        occurrence_of_weekdays = {}  # invariant

        # process left side structure first
        for day_of_week, num_of_occurrence in occurrence_of_weekdays_left.items():
            occurrence_of_weekdays[day_of_week] = num_of_occurrence
            if len(max_day_of_birthday) == 0:
                max_day_of_birthday.add(day_of_week)
            else:
                original_max_day_of_week = max_day_of_birthday.pop()
                if occurrence_of_weekdays_left[original_max_day_of_week] == num_of_occurrence:
                    max_day_of_birthday.add(original_max_day_of_week)
                    max_day_of_birthday.add(day_of_week)
                elif occurrence_of_weekdays_left[original_max_day_of_week] > num_of_occurrence:
                    max_day_of_birthday.add(original_max_day_of_week)
                else:
                    max_day_of_birthday.add(day_of_week)

        # process right side structure, merge it with the processed left side
        for day_of_week, num_of_occurrence in occurrence_of_weekdays_right.items():
            occurrence_of_weekdays[day_of_week] = occurrence_of_weekdays.get(day_of_week, 0) + num_of_occurrence
            if day_of_week in max_day_of_birthday:  # if day_of_week is already the day of max birthday due to left side
                max_day_of_birthday.clear()         # then now it should be the only one of max birthday
                max_day_of_birthday.add(day_of_week)
            else:
                original_max_day_of_week = max_day_of_birthday.pop()
                if occurrence_of_weekdays[original_max_day_of_week] == occurrence_of_weekdays[day_of_week]:
                    max_day_of_birthday.add(original_max_day_of_week)
                    max_day_of_birthday.add(day_of_week)
                elif occurrence_of_weekdays[original_max_day_of_week] > occurrence_of_weekdays[day_of_week]:
                    max_day_of_birthday.add(original_max_day_of_week)
                else:
                    max_day_of_birthday.clear()
                    max_day_of_birthday.add(day_of_week)

        return max_day_of_birthday, occurrence_of_weekdays

    rt_max_birthday, rt_occurrence_of_weekdays = max_occurrence_birthday(input_arr, 0, len(input_arr)-1)
    return rt_max_birthday


if __name__ == "__main__":
    # input_days = [3, 2, 3]
    input_days = [2, 2, 1, 1, 1, 2, 2]
    # input_days = [7]
    #input_days = [2, 2, 3, 7, 4, 5, 3, 2, 4, 5, 1, 3]
    print(MajorityBirthdays(input_days))