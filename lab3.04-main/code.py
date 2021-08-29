# Aiden B.
# 4/12/2021
# Lab 3.04

global wtf_is_lambda
wtf_is_lambda=43835798
print(wtf_is_lambda)
print("Why the fuck does lambda exist")
add2=lambda a:a+2
multiply_num=lambda a:a*wtf_is_lambda
add2_and_multiply=lambda a:multiply_num(add2(a))
print(add2_and_multiply(wtf_is_lambda))
print("I mean, sure putting lambda in your code looks cool but it makes no sense like, just why")

"""
global wtf_is_lambda
wtf_is_lambda=43835798
print(wtf_is_lambda)
print("Why the fuck does lambda exist")
def add2(a):return a+2
def multiply_num(a):a*wtf_is_lambda
def add2_and_multiply(a):multiply_num(add2(a))
print(add2_and_multiply(wtf_is_lambda))
print("I mean, sure putting lambda in your code looks cool but it makes no sense like, just why")
"""