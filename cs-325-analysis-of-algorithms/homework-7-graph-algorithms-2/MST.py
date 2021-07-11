from heapq import heapify, heappush, heappop

# use the structure (cost, (node_a, node_b)) to store the edge with node info
# e.g edge with cost 2 from node 1 to node 2 will be stored as (2, (0, 1)) due to zero based index
# when storing data, node_a's index is always smaller than node_b's so (2, (0, 1)) instead of (2, (1, 0) is stored

def Prims(G):
    picked_vertices = set()
    picked_edges = []

    wip_edges_heap = []
    heapify(wip_edges_heap)

    # put the first node in the heap
    picked_vertices.add(0)
    for j in range(0 + 1, len(G[0])):
        if G[0][j] < float('inf'):
            heappush(wip_edges_heap, (G[0][j], (0, j)))

    # when there are non-picked vertices
    while len(picked_vertices) < len(G):
        min_cost_edge = heappop(wip_edges_heap)
        vertex_a, vertex_b = min_cost_edge[1][0], min_cost_edge[1][1]
        if vertex_a in picked_vertices and vertex_b in picked_vertices:
            continue

        introduced_vertex = vertex_a if vertex_b in picked_vertices else vertex_b
        picked_edges.append(min_cost_edge)
        picked_vertices.add(introduced_vertex)
        # push newly connected edges into the min heap
        for col in range(0, len(G[introduced_vertex])):
            row_idx, col_idx = (introduced_vertex, col) if introduced_vertex < col else (col, introduced_vertex)
            to_be_pushed_edge = (G[row_idx][col_idx], (row_idx, col_idx))
            if G[row_idx][col_idx] < float('inf') and to_be_pushed_edge not in wip_edges_heap:
                heappush(wip_edges_heap, to_be_pushed_edge)

    print(f"By Prim's algorithm the MST is: {picked_edges}")
    return picked_edges


def Kruskal(G):
    picked_edges = []
    # working as the combined disjoint data set
    picked_nodes = set()

    all_non_picked_edges_heap = []
    heapify(all_non_picked_edges_heap)

    for i in range(len(G)):
        for j in range(len(G[0])):
            cost = G[i][j]
            if cost != float('inf'):
                heappush(all_non_picked_edges_heap, (cost, (i, j)))

    # in MST, num of edge is equal to num of node minus 1
    while len(picked_edges) < len(G) - 1:
        min_cost_edge = heappop(all_non_picked_edges_heap)
        vertex_a = min_cost_edge[1][0]
        vertex_b = min_cost_edge[1][1]

        if (vertex_a not in picked_nodes) or (vertex_b not in picked_nodes):
            picked_nodes.add(vertex_a)
            picked_nodes.add(vertex_b)
            picked_edges.append(min_cost_edge)

    print(f"By Kruskal's algorithm the MST is: {picked_edges}")
    return picked_edges


if __name__ == "__main__":
    input_G = [
        [float('inf'), 2, 3, float('inf'), float('inf')],
        [2, float('inf'), 1, 3, 2],
        [3, 1, float('inf'), float('inf'), 1],
        [float('inf'), 3, float('inf'), float('inf'), 5],
        [float('inf'), 2, 1, 5, float('inf')]
    ]

    input_G_1 = [
        [float('inf'), 2, 3, float('inf'), float('inf'), float('inf')],
        [2, float('inf'), float('inf'), 2, 5, float('inf')],
        [3, float('inf'), float('inf'), float('inf'), 4, 3],
        [float('inf'), 2, float('inf'), float('inf'), float('inf'), 4],
        [float('inf'), 5, 4, float('inf'), float('inf'), 3],
        [float('inf'), float('inf'), 3, 4, 3, float('inf')]
    ]

    Prims(input_G)
    Kruskal(input_G)
    Prims(input_G_1)
    Kruskal(input_G_1)