def solution(goods, boxes):
    answer = 0

    goods.sort()
    boxes.sort()

    bIndex = 0
    index = 0

    while index < len(goods) :
        if goods[index] <= boxes[bIndex] :
            answer += 1
        else :
            index -= 1
    
        bIndex += 1

        if bIndex >= len(boxes) :
            break

        index += 1

    return answer

print(solution([3,8,6], [5,6,4]))