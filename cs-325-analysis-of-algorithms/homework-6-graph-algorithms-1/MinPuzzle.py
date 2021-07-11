def minEffort(puzzle):
    source_node_coordinate = (0, 0)
    target_node_coordinate = (len(puzzle) - 1, len(puzzle[0]) - 1)
    # minEffort_helper(puzzle, source)
    wip_nodes_effort[source_node_coordinate] = 0
    while target_node_coordinate not in processed_nodes_effort:
        # get the min effort node from wip nodes
        picked_min_effort = min(wip_nodes_effort.values())
        picked_min_effort_node = [key for key in wip_nodes_effort if wip_nodes_effort[key] == picked_min_effort][0]
        processed_nodes_effort[picked_min_effort_node] = picked_min_effort
        wip_nodes_effort.pop(picked_min_effort_node, None)
        update_effort_helper(puzzle, picked_min_effort_node)
    return processed_nodes_effort[target_node_coordinate]


def update_effort_helper(puzzle, node_coordinate):
    # update the effort to the upper cell(consider to move up) if it's not processed
    update_coordinate = (node_coordinate[0] - 1, node_coordinate[1])
    if update_coordinate[0] >= 0 and update_coordinate not in processed_nodes_effort:
        potential_less_effort = max(processed_nodes_effort[node_coordinate], abs(
            puzzle[node_coordinate[0]][node_coordinate[1]] - puzzle[update_coordinate[0]][update_coordinate[1]]))
        wip_nodes_effort[update_coordinate] = min(wip_nodes_effort.get(update_coordinate, float('inf')),
                                                  potential_less_effort)

    # update the effort to the down cell(consider to move down) if it's not processed
    update_coordinate = (node_coordinate[0] + 1, node_coordinate[1])
    if update_coordinate[0] <= len(puzzle) - 1 and update_coordinate not in processed_nodes_effort:
        potential_less_effort = max(processed_nodes_effort[node_coordinate], abs(
            puzzle[node_coordinate[0]][node_coordinate[1]] - puzzle[update_coordinate[0]][update_coordinate[1]]))
        wip_nodes_effort[update_coordinate] = min(wip_nodes_effort.get(update_coordinate, float('inf')),
                                                  potential_less_effort)

    # update the effort to the left cell(consider to move left) if it's not processed
    update_coordinate = (node_coordinate[0], node_coordinate[1] - 1)
    if update_coordinate[1] >= 0 and update_coordinate not in processed_nodes_effort:
        potential_less_effort = max(processed_nodes_effort[node_coordinate], abs(
            puzzle[node_coordinate[0]][node_coordinate[1]] - puzzle[update_coordinate[0]][update_coordinate[1]]))
        wip_nodes_effort[update_coordinate] = min(wip_nodes_effort.get(update_coordinate, float('inf')),
                                                  potential_less_effort)

    # update the effort to the right cell(consider to move right) if it's not processed
    update_coordinate = (node_coordinate[0], node_coordinate[1] + 1)
    if update_coordinate[1] <= len(puzzle[0]) - 1 and update_coordinate not in processed_nodes_effort:
        potential_less_effort = max(processed_nodes_effort[node_coordinate], abs(
            puzzle[node_coordinate[0]][node_coordinate[1]] - puzzle[update_coordinate[0]][update_coordinate[1]]))
        wip_nodes_effort[update_coordinate] = min(wip_nodes_effort.get(update_coordinate, float('inf')),
                                                  potential_less_effort)


if __name__ == "__main__":
    input_puzzle = [[1, 3, 5], [2, 8, 3], [3, 4, 5]]
    # input_puzzle = [[3, 8, 3], [2, 6, 1], [7, 4, 3]]
    # input_puzzle = [[3, 5, 4], [8, 9, 2], [4, 9, 4]]

    processed_nodes_effort = {}
    wip_nodes_effort = {}
    print(minEffort(input_puzzle))
