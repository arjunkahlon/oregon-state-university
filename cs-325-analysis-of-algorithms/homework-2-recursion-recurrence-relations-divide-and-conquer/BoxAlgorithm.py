def doBoxesOverlap(box1, box2):

    #print(box1)

    points = ([box1[0], box1[-1]], [box1[2], box1[1]], [box1[0], box1[1]],[box1[2], box1[3]])
    for point in points:
        if point[0] > box2[0] and point[0] < box2[2] and point[1] > box2[1] and point[1] < box2[3]:
            return "true"
    return "false"


if __name__ == '__main__':
    print(doBoxesOverlap([0,0,2,2], [1,1,3,3]))
    print(doBoxesOverlap([0,0,1,1], [1,0,2,1]))



