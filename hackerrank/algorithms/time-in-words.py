""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
dic = {
    1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five', 6: 'six', 7: 'seven',
    8: 'eight', 9: 'nine', 10: 'ten', 11: 'eleven', 12: 'twelve', 13: 'thirteen',
    14: 'fourteen', 15: 'fifteen', 16: 'sixteen', 17: 'seventeen', 18: 'eighteen',
    19: 'nineteen', 20: 'twenty', 21: 'twenty one', 22: 'twenty two',
    23: 'twenty three', 24: 'twenty four', 25: 'twenty five', 26: 'twenty seven',
    28: 'twenty eight', 29: 'twenty nine'
}
p=1
if p==1:
    n=input()
    m=input()
    if m == 0:
        print(dic[n] +' o\' clock')
    elif m == 15:
        print('quarter past '+ dic[n])
    elif m < 30:
        print(dic[m] +' minutes past '+ dic[n])
    elif m == 30:
        print('half past '+ dic[n])
    elif m == 45:
        print('quarter to '+ dic[(n + 1) % 12])
    else:
        print(dic[60 - m] +' minutes to '+ dic[(n + 1) % 12])
