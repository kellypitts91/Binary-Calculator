//Kelly Pitts 09098321
#include <stdio.h>
#include <string.h>

char expression[10];
unsigned int num1, num2, i, temp;
int main() {
	printf("Type in an expression (eg. 5 add 6)\nPossible expressions: \nadd\nsub\nand\nor\nxor\nshl\nshr\nasr\nrol\nror\n");
	scanf("%x %s %x", &num1, expression, &num2);
	//Add:
	if (strcmp(expression, "add") == 0) {
		num1 = num1 + num2;
	}
	//Sub:
	if (strcmp(expression, "sub") == 0) {
		num1 = num1 - num2;
	}
	//And:
	if (strcmp(expression, "and") == 0) {
		num1 = num1 & num2;
	}
	//Or:
	if (strcmp(expression, "or") == 0) {
		num1 = num1 | num2;
	}
	//Xor:
	if (strcmp(expression, "xor") == 0) {
		num1 = num1 ^ num2;
	}
	//Shift the bits left
	if (strcmp(expression, "shl") == 0) {
		for (i = 0; i < num2; i ++) {
			num1 = num1 << 1;
		}
	}
	//Shift the bits right
	if (strcmp(expression, "shr") == 0) {
		for (i = 0; i < num2; i ++) {
			num1 = num1 >> 1;
		}
	}
	//Arithmetic Shift the bits right
	if (strcmp(expression, "asr") == 0) {
		for(i = 0; i < num2; i++) {
			if((num1 & 0x80000000) == 0x80000000) { 
				num1 >>= 1;
				num1 = num1 | 0x80000000;
			}else{
				num1 >>= 1;
				num1 = num1 | 0x00000000;
			}
		}
	}
	//rotate left
	if (strcmp(expression, "rol") == 0) {
		for (i = 0; i < num2; i++) {
			temp = num1 & 0x80000000;
			if ((num1 & 0x80000000) == 0x80000000){ 
				num1 <<= 1;
				num1 = num1 | 0x00000001;
			} else {
				temp = num1 & 0x00000000;
				num1 <<= 1;
				num1 = num1 | 0x00000000;
			}
		}
	}
	//rotate right
	if (strcmp(expression, "ror") == 0) {
		for (i = 0; i < num2; i++) {
			temp = num1 & 0x00000001;
			if ((num1 & 1) == 1){ 
				num1 >>= 1;
				num1 = num1 | 0x80000000;
			} else {
				temp = num1 & 0x00000000;
				num1 >>= 1;
				num1 = num1 | 0x00000000;
			}
		}
	}
	printf("\nThe answer is: %x", num1);
}