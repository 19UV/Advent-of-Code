#include <stdio.h>
#include <stdbool.h>

#include "2021/day1/day1.h"
#include "2021/day2/day2.h"
#include "2021/day3/day3.h"

int main(void) {
	const char* success = "TEST SUCCESS",
	          * fail    = "TEST FAILED";

	int problem1, problem2;
	bool problem1_valid, problem2_valid;

	/* -------------------------------------------------- */
	
	problem1_valid = Day1_test1();
	problem2_valid = Day1_test2();
	problem1 = Day1_solution1("2021/day1/input.txt");
	problem2 = Day1_solution2("2021/day1/input.txt");
	printf("---------- DAY 1 ----------\n");
	printf("  Solution 1: %i\n", problem1);
	printf("    %s\n", problem1_valid ? success : fail);
	printf("  Solution 2: %i\n", problem2);
	printf("    %s\n", problem2_valid ? success : fail);
	printf("\n");

	problem1_valid = Day2_test1();
	problem2_valid = Day2_test2();
	problem1 = Day2_solution1("2021/day2/input.txt");
	problem2 = Day2_solution2("2021/day2/input.txt");
	printf("---------- DAY 2 ----------\n");
	printf("  Solution 1: %i\n", problem1);
	printf("    %s\n", problem1_valid ? success : fail);
	printf("  Solution 2: %i\n", problem2);
	printf("    %s\n", problem2_valid ? success : fail);
	printf("\n");

	problem1_valid = Day3_test1();
	problem2_valid = Day3_test2();
	problem1 = Day3_solution1("2021/day3/input.txt");
	problem2 = Day3_solution2("2021/day3/input.txt");
	printf("---------- DAY 3 ----------\n");
	printf("  Solution 1: %i\n", problem1);
	printf("    %s\n", problem1_valid ? success : fail);
	printf("  Solution 2: %i\n", problem2);
	printf("    %s\n", problem2_valid ? success : fail);
	printf("\n");

	return 0;
}