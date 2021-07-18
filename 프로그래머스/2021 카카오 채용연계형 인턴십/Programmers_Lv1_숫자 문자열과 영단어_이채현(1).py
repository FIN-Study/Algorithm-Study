import re


def solution(s):
    convert_table = {'zero': 0, 'one': 1, 'two': 2, 'three': 3, 'four': 4, 'five': 5, 'six': 6, 'seven': 7, 'eight': 8,
                     'nine': 9}

    result = []
    # 문자열에서 영단어만 체크하고, 위치랑 같이 result에 저장
    for word in convert_table.keys():
        if word in s:
            check_duplicate = [m.start() for m in re.finditer(word, s)]
            for idx in check_duplicate:
                result.append((idx, convert_table[word]))

    # 문자열에서 숫자를 체크하고, 위치랑 같이 result에 저장
    checked_num = []
    for element in s:
        if element.isdigit() and element not in checked_num:
            checked_num.append(element)
            check_duplicate = [m.start() for m in re.finditer(element, s)]
            for idx in check_duplicate:
                result.append((idx, element))

    # 위치 순으로 정렬
    result = sorted(result, key=lambda x: x[0])

    answer = ''
    for element in result:
        answer += str(element[1])

    return int(answer)


# print(solution("one4seveneight"))
# print(solution("23four5six7"))
# print(solution('2three45sixseven'))
# print(solution('nine8sevenseven'))
print(solution('sixsevensixsevensix'))
print(solution('667676'))
