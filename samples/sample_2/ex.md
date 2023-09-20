Union Array
Given two integer sequences 
�
A & 
�
B. Find the sequence 
�
C consisting of all the elements present in either sequence 
�
A & 
�
B.
If an element appears more than once in the sequences 
�
A & 
�
B, then in the sequence 
�
C it must appear only once.

Cho hai dãy số nguyên AA & BB. Tìm dãy CC gồm tất cả các phần tử có trong dãy AA & BB.
Nếu một phần tử xuất hiện nhiều hơn một lần trong dãy AA & BB, thì trong dãy CC nó chỉ được xuất hiện một lần

Input description
The first line is an integer 
�
T, which is the number of test sets.
Each test includes:
The first line of each test contains 
2
2 integers 
�
n and 
�
m are the size of the two given sequences.
The second line of each test contains 
�
n integers 
�
1
a 
1
​
 ,
�
2
a 
2
​
 ,...,
�
�
a 
n
​
  which are the elements of the first sequence.
The third line of each test contains 
�
m integer 
�
1
b 
1
​
 ,
�
2
b 
2
​
 ,...,
�
�
b 
m
​
  which are the elements of the second sequence.
Constraints
1
≤
�
≤
30
1≤T≤30
1
≤
�
,
�
≤
1000
1≤n,m≤1000
1
≤
�
�
,
�
�
≤
1000
1≤a 
i
​
 ,b 
i
​
 ≤1000
Output description
�
T lines, each line is the result of a test: the sequence of numbers after sorting ascending.

Sample test case
Sample input 1
2
5 3
1 2 3 4 5
1 2 3
6 2
85 25 1 32 54 6
85 2
Sample output 1
1 2 3 4 5
1 2 6 25 32 54 85