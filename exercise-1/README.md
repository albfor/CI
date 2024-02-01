# FizzBuzz

## Requirements

Make a program that prints the numbers from one to an entered number by the user.

    If a number is a multiple of three, print “Fizz” instead

    If a number is a multiple of five, print “Buzz” instead

    If a number is a multiple of both three and five, print “FizzBuzz” instead
    
    For example; The sequence from one to twenty looks like this:
        1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz

Follow the TDD technique to develop the module.

Source: <https://en.wikipedia.org/wiki/Fizz_buzz>

## Exercise

Write a Makefile without using variables, functions and pattern rules to build and run the main and the test programs.

1. There shall be a rule to clean the project.
2. The generated files shall be stored in a directory named build.
3. There shall be a target named run to build and run the main program
    * A integer number in the range of 1 and 255 shall be passed to the program as an argument.
        * E.g. `make run NUM=123`
4. There shall be a target named **check** to build and run the test.

## To Run

```shell
make NUM=3
```

Will compile and run fizzbuzz with 3 as the user entered number.

```shell
make check
```

Will compile and run the tests.

