# -*- coding: utf-8 -*-
"""Untitled0.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1yYGmGNkl_R4uxXbECjDrS_w3tI67Exes
"""

N = 5
Pi = [3,1,4,3,2]
time = 0

#Pi를 오름차순으로 정렬하기
Pi.sort()
for i in range(N):
    for j in range(i+1):
        time += Pi[j] #첫번째 사람부터 줄을 서있는 시간을 더하기
print(time)
