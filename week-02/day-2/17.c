#include <stdio.h>

int main() {
	float w = 24;
	int out = 0;
	// if w is even increment out by one
	int w_int = (int)w;

	if(w_int%2 == 0){
        out = out+1;
    }
    printf("%d\n", out);

	return 0;
}
