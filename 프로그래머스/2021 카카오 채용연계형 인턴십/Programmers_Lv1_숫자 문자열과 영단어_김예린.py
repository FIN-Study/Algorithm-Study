def solution(s):
    answer = ""
    dic = {"zero":0, "one":1, "two":2, "three":3, "four":4, "five":5,
          "six":6, "seven":7, "eight":8, "nine":9}
    
    temp = ""
    for i in s:
        # isdigit() = 숫자인지 확인
        if i.isdigit():
            answer = answer + i
        # isalpha() = 알파벳인지 확인            
        elif i.isalpha():
            # 알파벳이면 temp에 한 글자씩 추가
            temp = temp + i
            # temp가 dic.keys()에 있는 글자면
            if temp in dic.keys():
                #answer에 dic[temp] = value를 추가
                answer = answer+str(dic[temp])
                temp = ""
                
    #answer이 문자열이니까 int로 변환
    answer = int(answer)
    return answer
