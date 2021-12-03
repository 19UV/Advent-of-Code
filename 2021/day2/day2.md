# Day 2
[Problem](https://adventofcode.com/2021/day/2) |
[Input](https://adventofcode.com/2021/day/2/input)

You take in a series of commands in the format ```<command> <amount>```
where command can be ```forward```, ```up```, or ```down```, and amount
can be any positive integer.

Sample Puzzle Input:
```
forward 5
down 5
forward 8
up 3
down 8
forward 2
```

## Part 1
You need to keep track of 2 variables, the horizontal position and the
depth. Both start at 0.

```forward <amount>``` - Increase the horizontal position by ```amount```

```down <amount>``` - Increase the depth by ```amount```

```up <amount>``` - Decrease the depth by ```amount```

Given the example puzzle input:

```forward 5``` adds 5 to your horizontal position, a total of 5.

```down 5``` adds 5 to your depth, resulting in a value of 5.

```forward 8``` adds 8 to your horizontal position, a total of 13.

```up 3``` decreases your depth by 3, resulting in a value of 2.

```down 8``` adds 8 to your depth, resulting in a value of 10.

```forward 2``` adds 2 to your horizontal position, a total of 15.

You should have a horizontal position of 15 and a depth of 10.
The puzzle output is ```horizontal * depth```

## Part 2
You now also need to keep track of aim (also starts at 0).

```down <amount>``` - Increases aim by ```amount```

```up <amount>``` - Decreases aim by ```amount```

```forward <amount>``` - Increases horizontal by amount, and increases
depth by ```aim * amount```

Therefore given the example puzzle input:

```forward 5``` adds 5 to your horizontal position, a total of 5. Because
your aim is 0, your depth does not change.

```down 5``` adds 5 to your aim, resulting in a value of 5.

```forward 8``` adds 8 to your horizontal position, a total of 13. Because
your aim is 5, your depth increases by 8*5=40.

```up 3``` decreases your aim by 3, resulting in a value of 2.

```down 8``` adds 8 to your aim, resulting in a value of 10.

```forward 2``` adds 2 to your horizontal position, a total of 15. Because
your aim is 10, your depth increases by 2*10=20 to a total of 60.

You would have a horizontal position of 15 and a depth of 60. (Multiplying
these produces 900.)