#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	double result = 0;
	int line = 0;
	
	int (*fp1) (int, int);
	double (*fp2) (int, int);

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				// result = add(operand1, operand2);
				fp1 = add;
				result = fp1(operand1, operand2);		
				break;
				case '-':
				// result = minus(operand1, operand2);
				fp1 = minus;
				result = fp1(operand1, operand2);
				break;
				case '*':
				// result = mul(operand1, operand2);
				fp1 = mul;
				result = fp1(operand1, operand2);
				break;
				case '/':
				// result = div(operand1, operand2);
				fp2 = div;
				result = fp2(operand1, operand2);
				break;
			}		
			printf("%d %c %d = %lf\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}
