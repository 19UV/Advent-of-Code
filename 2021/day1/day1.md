# Day 1
[Problem](https://adventofcode.com/2021/day/1) |
[Input](https://adventofcode.com/2021/day/1/input)

The puzzle input is a list of positive integer distances. For example,
the example input is:
```
199
200
208
210
200
207
240
269
260
263
```

## Problem 1
**Count the number of times the line increases from the last line** (ignoring
the first line). For example (given the example input):
```
199 (ignore)
200 (increase) +1
208 (increase) +1
210 (increase)
200 (decrease)
207 (increase) +1
240 (increase) +1
269 (increase) +1
260 (decrease) +1
263 (increase) +1

Solution: 7
```

## Problem 2
To prevent 'noise', use a **three-measurement sliding window**
and **compare the sums of the windows**. Example:
```
199 A
200 A B
208 A B C
210   B C D
200     C D E
207 F     D E
240 F G     E
269 F G H
260   G H
263     H
```

Get the value of each window by summing the lines in the window. For example
A: ```199 + 200 + 208 = 607```. Therefore
```
A: 607 (N/A - no previous sum)
B: 618 (increase) +1
C: 618 (no change)
D: 617 (decrease)
E: 647 (increase) +1
F: 716 (increase) +1
G: 769 (increase) +1
H: 792 (increase) +1

Solution: 5
```