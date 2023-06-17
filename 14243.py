def remove_spaces(input_string):
    start = 0
    end = len(input_string) - 1

    while start < len(input_string) and input_string[start] == ' ':
        start += 1

    while end >= 0 and input_string[end] == ' ':
        end -= 1

    return input_string[start:end+1]

def solution(blob):
    pomegranate = blob.count('A')
    guava = blob.count('B')
    apple = blob.count('C')
    blob_size = len(blob)
    result = [''] * blob_size
    prime = secondary = 0

    for fruit in range(blob_size):
        if guava - 1 == pomegranate + apple and guava > 0 and prime != 2:
            secondary, prime = prime, 2
            result[fruit] = 'B'
            guava -= 1
        elif 2 * (apple - 1) == pomegranate + guava and apple > 0 and prime != 3 and secondary != 3:
            secondary, prime = prime, 3
            result[fruit] = 'C'
            apple -= 1
        else:
            if guava > 0 and prime != 2:
                secondary, prime = prime, 2
                result[fruit] = 'B'
                guava -= 1
            elif apple > 0 and prime != 3 and secondary != 3:
                secondary, prime = prime, 3
                result[fruit] = 'C'
                apple -= 1
            elif pomegranate > 0:
                secondary, prime = prime, 1
                result[fruit] = 'A'
                pomegranate -= 1
            else:
                return "-1"
    return ''.join(result)


magic_blob = remove_spaces(input())
print(solution(magic_blob))
