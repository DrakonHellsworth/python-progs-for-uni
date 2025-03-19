#Create a claculator without eval function the expression will only have non-negative integers the input will be string and the expression will folloe BODMAS
def tokenize(expr):
    tokens=[]
    num=""
    for char in expr:
        if char.isdigit():
            num+=char
        else:
            if num:
                tokens.append(num)
                num=""
            if char in "+-*/^()":
                tokens.append(char)
    if num:
        tokens.append(num)
    return tokens

def calculate(expr):
    tokens=tokenize(expr)
    index=0

    def addsub():
        nonlocal index
        result=multdiv()
        while index<len(tokens) and tokens[index] in ('+','-'):
            op=tokens[index]
            index+=1
            next_val=multdiv()
            if op=='+':
                result+=next_val
            else:
                result-=next_val
        return result

    def multdiv():
        nonlocal index
        result=power()
        while index<len(tokens) and tokens[index] in ('*','/'):
            op=tokens[index]
            index+=1
            next_val=power()
            if op=='*':
                result*=next_val
            else:
                result/=next_val
        return result

    def power():
        nonlocal index
        result=primary()
        while index<len(tokens) and tokens[index]=='^':
            index+=1
            exponent=power()
            result**=exponent
        return result

    def primary():
        nonlocal index
        token=tokens[index]
        if token=='(':
            index+=1
            result=addsub()
            index+=1  
            return result
        else:
            index+=1
            return int(token)

    return parse_exp()

if __name__=="__main__":
    expr=input("Enter an expression: ")
    result=calculate(expr)
    print(f"{expr}={result}")
