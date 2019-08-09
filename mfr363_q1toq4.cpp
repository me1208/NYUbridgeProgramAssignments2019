//  mfr363 - Melissa Frendo-Rosso
// Questions 1 to 4


/*
Question 1 (14 points)
Use mathematical induction to prove that for every positive integer n ≥ 3, n^2 > 2n + 1.
Note: A non-inductive proof will not get any points.

 Theorem: for every positive integer n ≥ 3, n^2 > 2n + 1.
 Proof: by induction for n
 Base case: n = 3
    3^2 > 2(3) + 1
    9 > 7
    thus the base case is true for 3. where k^2 > 2k + 1
 Induction Step: Using k^2 > 2k + 1 show that (k+1)^2 > 2(k+1) + 1
    starting with k^2 > 2k + 1,
    multiplying both sides by k+1,
    (k+1)k^2 > (2k + 1)(k+1)
    Using induction,
    (k+1)^2 ≥ (k+1)k^2 > (2k + 1)(k+1) ≥ 2(k+1) + 1
    Therefore,
    (k+1)^2 > 2(k+1) + 1


Question 2 (12 points)
How many binary strings of length 20 are there in which the number of 0’s in the
string is not equal to the number of 1’s in the string?
Explain your answer.

 Binary strings - meaning they are only made up of 0s and 1s - 2 possible elements.
 Since the length of the string is 20, there are 20! possible total outcomes.
 There are  20!/10! binary strings of length 20 are there in which the number of 0’s in the
string is not equal to the number of 1’s in the string. Where 10! represents the repeated values of 0 and 1 where they are
 equal.





Question 3 (15 points)
A fair coin is tossed three times. The random variable X is defined to be 2^h, where h is the number of flips that come
up heads. For example, X(HHT) = 2^2. What is E[X]?
Explain your answer.

 A fair coin is tossed 3 times. There are 2^3 = 8 possible outcomes of three flips since the coin tossed has 2 sides.
 The possible outcomes of the coin flip are HHH, HHT, HTT, HTH, TTT, TTH, THH, THT. Each possible outcome has a probability
 of 1/8 and the random variable associated with each is X(HHH) = 8, X(HHT) = 4, X(HTT) = 2, X(HTH) = 4, X(TTT) = 0,
 X(TTH) = 2, X(THH) = 4, X(THT) = 2.
 There is: 1 occurance where the random var is 8, p = 1/8
          3 occurances for 4, p = 3/8
          3 occurances for 2, p = 3/8
          1 occurance for 0. p = 1/8

 Using the equation to solve for expected value by taking the summation of the probability of the occurance of the random value
 times the random value is the following:
    E[x] = 8(1/8) + 4(3/8) + 2(3/8) + 0(1/8)
         = 1      + 3/2    +   3/4    +  0
         = 13/ 4
     E[X] = 3.25

 Where, E[X] represents the expected outcome of X.


Question 4 (14 points)
Analyze its running time of func1 and func2.
Explain your answers.

 func 1:
    For function 1 we start by analyzing the inner for loop to see how many times it is iterating
    it will run n times as j increments by 1. Next wee look at the outter for loop, it will also run n times; however, i is
    incrementing by *2 which is twice as much as the inner for loop. The run time is T(n) = Θ(n*sqrt(n))

 func 2:
    function 2 is the same as function 1, it will not be added to the overall runtime because the highest order will be taken
    and the leading number is dropped when conducting the overall analysis.
    Thus, the run time is T(n) = Θ(n*sqrt(n))

 */

