days = day1 day2
dayso = build/day1.o build/day2.o

AdventOfCode: prebuild $(days) main
	cc $(dayso) build/main.o -o build/AdventOfCode

prebuild:
	rm -rf build && mkdir build

main: prebuild
	cc -c main.c -o build/main.o

day1: prebuild
	cc -c 2021/day1/day1.c -o build/day1.o

day2: prebuild
	cc -c 2021/day2/day2.c -o build/day2.o