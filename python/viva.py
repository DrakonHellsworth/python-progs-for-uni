def pali(s):
    return[word for word in s if word==word[::-1]]

my_list=['level','word','radar','hello','madam']
palin=pali(my_list)
print(palin)