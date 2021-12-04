#include "day3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static const char* read_file(const char* path) {
    FILE* file = fopen(path, "r");
    if(file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* data = malloc(size);
    if(data == NULL) {
        fclose(file);
        return NULL;
    }

    char* write = data, ch;
    while((ch = fgetc(file)) != EOF) {
        *(write++) = ch;
    }
    *write = 0;

    fclose(file);

    return (const char*)data;
}

static void write_bit(uint64_t* variable, bool bit) {
    *variable = (*variable << 1) | bit;
}

static uint64_t find_rating(unsigned int line_count, unsigned int line_length, const char** line_ptrs, bool negate) {
    bool* mask = malloc(line_count * sizeof(bool));
    memset(mask, true, line_count * sizeof(bool));

    uint64_t res = 0;
    for(unsigned int i = 0; i < line_length; i++) {
        unsigned int count = 0, of = line_count;

        for(unsigned int y = 0; y < line_count; y++) {
            if(!mask[y]) {
                of--;
                continue;
            }

            if(line_ptrs[y][i] == '1') {
                count++;
            }
        }

        int common = count >= (of - count);
        if(negate) {
            common = (common == 0) ? 1 : 0;
        }

        unsigned int valid = 0, index;
        for(unsigned int y = 0; y < line_count; y++) {
            if((line_ptrs[y][i] - '0') != common) {
                mask[y] = false;
                continue;
            }

            if(mask[y]) {
                valid++;
                index = y;
            }
        }

        if(valid == 1) {
            for(i = 0; i < line_length; i++) {
                write_bit(&res, line_ptrs[index][i] - '0');
            }
            break;
        }
    }

    free(mask);

    return res;
}

bool Day3_test1(void) {
    return Day3_solution1("2021/day3/test.txt") == 198;
}

bool Day3_test2(void) {
    return Day3_solution2("2021/day3/test.txt") == 230;
}

int Day3_solution1(const char* path) {
    FILE* file = fopen(path, "r");
	if(file == NULL) {
		fprintf(stderr, "[ERROR] Unable to open file\n");
		return -1;
	}
	
	int res;
	char line[64]; // Using a buffer here technically slower
    unsigned int bit_count[64] = {0};
    unsigned int line_count = 0, line_length;
	while(1) {
		res = fscanf(file, "%s\n", (char*)line);
		if(res != 1) {
			break;
		}

        line_count++;

        unsigned int i;
        for(i = 0; i < 64; i++) {
            if(line[i] == 0x00) {
                break;
            }
            
            if(line[i] == '1') {
                bit_count[i]++;
            }
        }
        line_length = i;
	}

    uint64_t gamma = 0, epsilon = 0;

    for(int i = 0; i < line_length; i++) {
        gamma = (gamma << 1) | (bit_count[i] > (line_count - bit_count[i]));
        epsilon = (epsilon << 1) | (bit_count[i] <= (line_count - bit_count[i]));
    }

	fclose(file);

    return (int)(gamma * epsilon);
}

int Day3_solution2(const char* path) {
    // Dumping into buffer because I'll need to do filtering
    const char* data = read_file(path);
    if(data == NULL) {
        return -1;
    }

    unsigned int line_count = 1, line_length;
    { // Get line count and line length
        const char* read = data;
        bool first = true;
        while(*read != 0x00) {
            if(*read == '\n' || *read == '\r') {
                if(first) {
                    line_length = read - data;
                    first = false;
                }
                line_count++;
            }
            read++;
        }
    }

    const char** line_ptrs = malloc(line_count * sizeof(char*));

    { // Initialize Line Pointers
        const char* read = data;
        for(unsigned int y = 0; y < line_count; y++) {
            line_ptrs[y] = read;

            read += line_length;
            while((*read == '\n') || (*read == '\r'))
                read++;
        }
    }

    uint64_t oxygen = find_rating(line_count, line_length, line_ptrs, false);
    uint64_t co2 = find_rating(line_count, line_length, line_ptrs, true);

    free((void*)data);
    free((void*)line_ptrs);

    return (int)(oxygen * co2);
}