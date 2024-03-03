#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_CHARS 100

void findFirst(char, int, int);
void findFollow(char, int, int);
bool isTerminal(char);

char grammar[MAX_RULES][MAX_CHARS];
char firstSet[MAX_RULES][MAX_CHARS];
char followSet[MAX_RULES][MAX_CHARS];

int main() {
	int n;
	printf("Enter number of rules: ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		printf("Enter rule %d: ", i + 1);
		scanf("%s", grammar[i]);
	}
	
	for (int i = 0; i < n; i++) {
		findFirst(grammar[i][0], i, n);
	}
	
	followSet[0][0] = '$';
	for (int i = 0; i < n; i++) {
		findFollow(grammar[i][0], i, n);
	}
	
	printf("First Sets:\n");
	for (int i = 0; i < n; i++) {
		printf("First(%c): %s\n", grammar[i][0], firstSet[i]);
	}
	
	printf("Follow Sets:\n");
	for (int i = 0; i < n; i++) {
		printf("Follow(%c): %s\n", grammar[i][0], followSet[i]);
	}
	
	return 0;
}

void findFirst(char c, int index, int n) {
	if (isTerminal(c)) {
		strncat(firstSet[index], &c, 1);
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (grammar[i][0] == c) {
			if (grammar[i][2] == '@') {
				strncat(firstSet[index], "@", 1);
			} else {
				for (int j = 2; j < strlen(grammar[i]); j++) {
					if (grammar[i][j] != '|') {
						findFirst(grammar[i][j], index, n);
					}
				}
			}
		}
	}
}

void findFollow(char c, int index, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 2; j < strlen(grammar[i]); j++) {
			if (grammar[i][j] == c) {
				if (grammar[i][j + 1] != '\0') {
					findFirst(grammar[i][j + 1], index, n);
				}
				
				if (grammar[i][j + 1] == '\0' && c != grammar[i][0]) {
					findFollow(grammar[i][0], index, n);
				}
			}
		}
	}
}

bool isTerminal(char c) {
	return (c >= 'a' && c <= 'z') || c == '+' || c == '-' || c == '*' || c == '/';
}

