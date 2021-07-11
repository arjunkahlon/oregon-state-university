# dynamic programming(bottom-up)
# remaining_health_point = min_start_health_point + value of current cell
def getTesla(M):
    remaining_health_point_matrix = [ [0 for j in range(len(M[0]))] for i in range(len(M)) ]
    min_start_health_point_matrix = [ [0 for j in range(len(M[0]))] for i in range(len(M)) ]
    min_start_health_point_matrix[-1][-1] = 1 - M[-1][-1] if M[-1][-1] < 0 else 1
    movement_trace_matrix = [ [0 for j in range(len(M[0]))] for i in range(len(M)) ]
    movement_trace_matrix[-1][-1] = "Done"
    for i in range(-1, -len(M)-1, -1):
        for j in range(-1, -len(M[0])-1, -1):
            if (i, j) == (-1, -1):
                continue

            down_min_start_health_point = float('inf') if i == -1 else min_start_health_point_matrix[i+1][j]
            right_min_start_health_point = float('inf') if j == -1 else min_start_health_point_matrix[i][j+1]
            movement_trace_matrix[i][j] = "Down -> " + movement_trace_matrix[i+1][j] if down_min_start_health_point < right_min_start_health_point else "Right -> " + movement_trace_matrix[i][j+1]
            remaining_health_point_matrix[i][j] = down_min_start_health_point if down_min_start_health_point < right_min_start_health_point else right_min_start_health_point

            min_start_health_point_matrix[i][j] = remaining_health_point_matrix[i][j] - M[i][j]
            if min_start_health_point_matrix[i][j] <= 0:
                min_start_health_point_matrix[i][j] = 0 if (i, j) == (-len(M), -len(M[0])) else 1

    # print out the route if needed
    #print(movement_trace_matrix[0][0])
    return min_start_health_point_matrix[0][0]


if __name__ == "__main__":
    input_M = [[-1, -2, 2], [10, -8, 1], [-5, -2, -3]]
    # input_M = [[1, 2, 2], [10, 8, 1], [5, 2, 3]]
    # input_M = [[-3, 3, -2, 1], [5, -4, 4, -3], [-10, 6, -1, 2], [3, -2, 3, -1]]
    print(getTesla(input_M))