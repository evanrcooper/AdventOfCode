#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stod(char *str) {
	char c = str[0];
	int val = 0;
	int i = 0;
	while (isdigit(c) && c != '\0') {
		val = (val*10)+c-'0';
		c = str[++i];
	}
	return val;
}

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
	int index = 0;
	int arr[256] = {0};
    fp = fopen("input.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
		if (line[0] == '\n') {
			index++;
		}
		arr[index] += stod(line);
	}
	int top = arr[0];
	int tops[3];
	int x = 0;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 256; i++) {
			if (arr[i] != 0) {
				if (arr[i] != tops[0] && arr[i] != tops[1] && arr[i] > top) {
					top = arr[i];
				}
			} else {
				break;
			}
		}
		tops[x++] = top;
		top = 0;
	}
	printf("Top 3:\n%d\n%d\n%d\n", tops[0], tops[1], tops[2]);
	printf("\n\nTop 3 Summed: %d\n", tops[0] + tops[1] + tops[2]);
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
