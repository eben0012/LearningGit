# Lab 06: Lab + Recursion(6) = Lab + (Lab + Recursion(5))

Today you will be implementing a few recursive algorithms. The neat thing about recursion is that you can solve problems with a relatively small amount of well thought out code.

The google form for submitting can be found [here.](https://goo.gl/forms/uo3x0XqgIpMjphGC2) The instructors will open the form at the start of the lab session.

## A Quick Review of Recursion

In its simplest form, recursion is just the act of a function calling itself within its own body. Recursion essentially breaks the problem apart into smaller, more easily solvable, pieces; which can lead to some very elegant and important algorithms. When a recursive function is called by a function other than itself it begins execution, just like any other function. However, when the program reaches the line in which the function calls itself a new "instance" of the function is created, hopefully with a slightly different set of parameters (otherwise it may be looping forever!). This new instance will likely reach a point where it calls itself again, creating yet another new instance with, again, slightly different parameters; this process repeats until the *base case* is reached.

At first, this may seem like an infinite loop of sorts, but if the function is implemented correctly, the input size should get reduced on each call, as the function works towards solving the problem. Eventually the function will reduce it's parameters enough to handle the input non-recursively, and then return to whatever instance of the function last called it. From there each previous function will return (perhaps after doing some processing) until the original call returns and the recursive function has completed. Unfortunately, if the function is implemented without a base case, or continually recurses without reaching one, the program will crash with a stack overflow error.

Below are some visual aids to help in understanding recursion.


### Visual for how to think about recursive function calls
![image](https://i.imgur.com/Z5eeHrE.png)


### Visual showing how a factorial recursive function works. Example is factorial(5)

Notice how when n is set to 5 and the code is executing, the function has the form of:
1. Base case - ( if n == 1 ) return 1;
2. A recursive call - return n * factorial(n-1);

![image](https://i.imgur.com/HAgjJlu.gif)

### Fibonacci Sequence Visualized

Sometimes there can be multiple base cases.
In this example, there is a basecase for 0 and for 1

![image](https://i.imgur.com/rbAZFhN.gif)

### Recursively finding the length of a list

All recursive functions need a base case otherwise there is no ending point.

![image](https://i.imgur.com/ByMc0mX.gif)


## 1. Sum of Numbers

For the first problem, you will implement the sum of numbers up until _n_. The header for this function will be

```c++
unsigned long int sum(unsigned int n);
```

If the input is `10`, your function should calculate `10+9+8+7+6+5+4+3+2+1`, which should equal `55`.  This must be done recursively (no loops).

### Running the Code

You will create a small program `sum.cc` and time the execution of your function.  See the example below:

```c++
#include <chrono>
#include <iostream>

int main() {
    auto start = std::chrono::steady_clock::now();
    // call your function here
    auto end = std::chrono::steady_clock::now();

    // print the elapsed time
    std::cout << std::chrono::duration<double> (end-start).count() << " seconds" << std::endl;
}
```

Then compile and run your program using the command below:
```bash
$ g++ -std=c++11 -g -Wall sum.cc -o sum && ./sum
```
> The **&&** here symbolizes "do what's on the left of me, then if that's successful, do what's on the right" -- Learning bash can make development a much easier process!

> You will **report** the actual running time of calling your function with the following values: 1000, 10000, 100000, 1000000.  Include your intuition behind the running time of this function (constant? linear? logarithmic? quadratic? ...).


## 2. Greatest Common Divisor

The Euclidean algorithm is a computationally efficient way to find the greatest common divisor between any two numbers.
The greatest common divisor of _a_ and _b_ is the largest number that will divide evenly into both _a_ and _b_.
For example, _GCD(81,96)_ is _3_ because _3_ is the largest number that will divide _81_ and _96_ with no remainder.  The algorithm can be formulated as follows:

```python
GCD for any a, b:
    if b is larger than a:
        swap a and b
    if a is equal to b:
        a is the GCD of a and b
    otherwise apply GCD(a-b, b)
```
Here is the wikipedia on GCD in a recursive context. Use it as a resource if needed https://en.wikipedia.org/wiki/Recursion_(computer_science)#Greatest_common_divisor


From this you can see that recursion is fundamental to the problem, as the GCD algorithm we have just defined invokes itself for certain inputs.  Your job is to implement the GCD algorithm and time your function as you did in the previous question.

> You will **report** the actual running time of calling your function with the following pairs of values: (100,612), (1098,8721), (10872,17238), (1000000000,100000000), (184729384, 2273652).  Include your intuition behind the running time of this function (constant? linear? logarithmic? quadratic? ...).


## 3. The Natural Numbers

The set of all integers greater than 0 (i.e., {1,2,3,4,5,...}) is commonly referred to the set of natural numbers. Write a recursive algorithm that takes a positive integer input _n_ and prints out all of the natural numbers from 1 to n. The function signature for this problem should be as follows:

```C++
void print_nums(unsigned int n);
```

You may print all the numbers on one line separated by spaces, or each number on its own line, but these are not very elegant for large values of _n_. For brownie points, start printing your output on a new line after every 10 numbers. Your expected output will then look similar to this:

```
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
21 22 23 24 25 26 27 28 29 30
31 32 33 34 35 36 37 38 39 40
41 42 43 44 45
```


## 4. The Fibonacci Series

The Fibonacci series is a special series of numbers that has actually appeared numerous times in art and nature, in addition to various areas in mathematics. The series is constructed by taking two initial numbers f<sub>0</sub> = 0 and f<sub>1</sub> = 1, and obtaining each f<sub>n</sub> by adding together f<sub>n-1</sub> and f<sub>n-2</sub>. Implement a function that finds and returns the _nth_ Fibonacci number, using the following signature:

```C++
unsigned long int fibonacci(unsigned int n);
```

For reference, the first 10 digits of fibonacci are

    0, 1, 1, 2, 3, 5, 8, 13, 21, and 34

so `fibonacci(10)` would return 55.

**Hint**: Your implementation of fibonacci should use _two_ recursive calls. Be careful with the size of your inputs when testing this function, as it runs in _O_(2<sup>n</sup>) time.

## 5. Number of Digits

When working with and processing large numbers, it is at times useful to be able to determine how many digits long the number is. With access to a graphing calculator, (or a math library), a quick way to compute this would be to take the floor of log<sub>10</sub>(n) and add 1. For example, log<sub>10</sub>(382) is roughly 2.582, the floor of which is 2, and adding 1 then yields 3 which is the length of n. This is a handy trick, but if there is no access to a log function then this problem may alternatively be solved recursively.

Write a recursive algorithm that takes an integer n and returns its length, using the following function signature:

```C++
unsigned int num_len(unsigned long int num);
```

## 6. Tracing a Recursive Program

There is included code called factorial_trace.cc. Take and open that code and read it. The function is called with n=10. Trace the program by hand starting at main. Keep track of the function calls in order of their call and then paste the functions that were called with the proper params in the question 6 box form answer.


## Submission

When you have finished implementing the algorithms above, copy and paste each of your implementations into the associated field in the Google Forms document. https://goo.gl/forms/RdxnMJFQ0NUIAHKE2
