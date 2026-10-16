#include <stdio.h>
#include <stdlib.h>

const char COMMA = ',';
const char NEWLINE = '\n';

int main(int argc, char *argv[]) {
	FILE *f = argc > 1 ? fopen(argv[1], "r") : stdin;
	if (!f) return 1;

	long rows = 0, cols = 0, cur_cols = 0;
	int ch, has_content = 0;

	while ((ch = fgetc(f)) != EOF) {
		has_content = 1;
		if (ch == COMMA) {
			cur_cols++;
		} else if (ch == NEWLINE) {
			cur_cols++;
			if (!rows) cols = cur_cols;
			rows++;
			cur_cols = 0;
		}
	}

	if (has_content) {
		if (cur_cols > 0) {
			cur_cols++;
			rows++;
			if (!rows) {
				cols = cur_cols;
			}
		}
		if (!rows) {
			rows = 1;
			cols = cur_cols + 1;
		}
	}

	if (f != stdin) fclose(f);
	printf("rows: %ld\ncols: %ld\n", rows, cols);
	return 0;
}
