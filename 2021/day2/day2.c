#include "day2.h"

#include <stdio.h>
#include <string.h>

#define STR_EQ( a, b) (strcmp( a, b) == 0)

#ifndef COMMAND_BUFFER_SIZE
#	define COMMAND_BUFFER_SIZE 32
#endif

bool Day2_test1(void) {
	return Day2_solution1("2021/day2/test.txt") == 150;
}

bool Day2_test2(void) {
	return Day2_solution2("2021/day2/test.txt") == 900;
}

int Day2_solution1(const char* path) {
	FILE* file = fopen(path, "r");
	if(file == NULL) {
		fprintf(stderr, "[ERROR] Unable to open file\n");
		return -1;
	}
	
	int res, amount, horizontal = 0, depth = 0;
	char command[COMMAND_BUFFER_SIZE];
	while(1) {
		res = fscanf(file, "%s %i\n", (char*)command, &amount);
		if(res != 2) {
			break;
		}
		
		if(STR_EQ(command, "forward")) {
			horizontal += amount;
		} else if(STR_EQ(command, "down")) {
			depth += amount;
		} else if(STR_EQ(command, "up")) {
			depth -= amount;
		}
	}
	
	fclose(file);
	
	return horizontal * depth;
}

int Day2_solution2(const char* path) {
	FILE* file = fopen(path, "r");
	if(file == NULL) {
		fprintf(stderr, "[ERROR] Unable to open file\n");
		return -1;
	}
	
	int res, amount, horizontal = 0, depth = 0, aim = 0;
	char command[COMMAND_BUFFER_SIZE];
	while(1) {
		res = fscanf(file, "%s %i\n", (char*)command, &amount);
		if(res != 2) {
			break;
		}
		
		if(STR_EQ(command, "forward")) {
			horizontal += amount;
			depth += aim * amount;
		} else if(STR_EQ(command, "down")) {
			aim += amount;
		} else if(STR_EQ(command, "up")) {
			aim -= amount;
		}
	}
	
	fclose(file);
	
	return horizontal * depth;
}

#undef STR_EQ
#undef COMMAND_BUFFER_SIZE