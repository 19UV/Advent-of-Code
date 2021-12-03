#include "day1.h"

#include <stdio.h>
#include <limits.h>

bool Day1_test1(void) {
	return Day1_solution1("2021/day1/test.txt") == 7;
}

bool Day1_test2(void) {
	return Day1_solution2("2021/day1/test.txt") == 5;
}

int Day1_solution1(const char* path) {
	FILE* file = fopen(path, "r");
	if(file == NULL) {
		fprintf(stderr, "[ERROR] Unable to open file\n");
		return -1;
	}
	
	int res;
	unsigned int prev = UINT_MAX, line, cnt = 0;
	while(1) {
		res = fscanf(file, "%u\n", &line);
		if(res != 1) {
			break;
		}
		
		if(line > prev) {
			cnt++;
		}
		prev = line;
	}
	
	fclose(file);
	
	return (int)cnt;
}

int Day1_solution2(const char* path) {
	FILE* file = fopen(path, "r");
	if(file == NULL) {
		fprintf(stderr, "[ERROR] Unable to open file\n");
		return -1;
	}
	
	int res;
	unsigned int prev_sum = UINT_MAX, a = UINT_MAX,
	             b = UINT_MAX, line, cnt = 0;
	while(1) {
		res = fscanf(file, "%u\n", &line);
		if(res != 1) {
			break;
		}
		
		if(a != UINT_MAX) {
			unsigned int sum = a + b + line;
			
			if(sum > prev_sum) {
				cnt++;
			}
			prev_sum = sum;
		}
		
		a = b;
		b = line;
	}
	
	fclose(file);
	
	return (int)cnt;
}