def solution2(N, A):
    # write your code in Python 3.6
    ans = [0] * N
    max_value = 0
    for i in A:
        if i != N+1:
            ans[i-1] += 1
            if max_value < ans[i-1]:
                max_value = ans[i-1]
        else:
            ans = [max_value] * N
    
    return ans

def solution(N, A):
    answer = [0] * N
    next_counter = counter = 0
    
    for value in A:
        if value != N+1:
            current_counter = answer[value-1] = max(answer[value-1], counter) + 1
            next_counter = max(current_counter, next_counter)
        else:
            counter = next_counter
            
    return [counter if ans < counter else ans for ans in answer]

N = 5
A = [3,4,4,6,1,4,4]
# A[0] = 3
# A[1] = 4
# A[2] = 4
# A[3] = 6
# A[4] = 1
# A[5] = 4
# A[6] = 4
print(solution(N, A))