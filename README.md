# CS 3503 Assignment 2 - Data Representation and Mapping

## Author
Alexander Duty

## Description
In this assignment I use the framework from Assignment 1 to implement advanced data representation such as direct mapping functions and signed number representations.

## Build Instructions
Same deal as with Assignment 1, The program was ran in terminal. Open the repository folder in terminal to get the path, then input the following:

```
gcc -o convert main.c convert.c
./convert
```

Again, a copy of the repository can be downloaded from GitHub.
 
## Test Results
For the most part, the result of these tests went smoothly. The file reading and test output format was copied from Assignment 1 and modified to work properly (it has to now ignore comment lines as the conditional for parsing the function/parameters checked for three strings, which essentially applied to almost every line now). 

However, there were a couple discrepencies that I couldn't seem to find the root cause. Starting with a more external issue: The A2 test file only had 51 avaliable test cases for some reason. Everywhere else in the assginment instructions mentions there being 60 test cases, but the provided file that could be downloaded only has 51 (I even counted to be sure). I'm not sure if this is just an instructor's typo, but those supposeded 9 extra tests are absent in the submission for this reason.

With the 51 test cases that I could actually run, 49 of them successfully passed. The remaining 2 tests that failed were from the oct_to_hex conversion tests, specifically the ones for converting 345 and 100. This seems to be an odd case where my conversion method works for the most part but has some errors in writing the output, as the other oct_to_hex tests managed to work correctly. It's more evident when looking at the actual outputs, since the converted value is essentially the same, but has a starting 0 in the output for whatever reason. I couldn't figure out why this was the case and didn't have much time to troubleshoot it. It also didn't help that I don't have an easy way to debug code executed from the terminal, which I have no experience of.
