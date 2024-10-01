#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100;
int priority(char op) {
	switch(op) {
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}
int isOp(char ch) {
	return (ch=='+' || ch == '-' || ch == '*' || ch=='/' || ch == '^');
}
char * infixToPostfix(char *infix) {
	int i, j;
	int len;
	len = strlen(infix);
	char *postfix = (char *)malloc(sizeof(char)*(len+2));
	char stack[MAX];
	int top=-1;
	for(i=0,j=0;i<len;i++) {
		if(infix[i]==' ' || infix[i]=='\t')
			continue;
		if(isalnum(infix[i])
			postfix[j++] = infix[i];
		else if(infix[i]=='(')
			stack[++top] = infix[i];
		else if(infix[i]==')') {
			while(top>-1 && stack[top]!='(')
				postfix[j++] = stack[top--];
			if(top>-1 && stack[top]!='(')
				return "Invalid Expression";
			else
				top--;
		}
		else if(isOp(infix[i])) {
			while(top>-1 && priority(stack[top]) >= priority(infix[i]))
				postfix[j++] = stack[top--];
			stack[++top] = infix[i];
		}
	}
	while(top>-1) {
		if(stack[top]=='(')
			return "Invalid Expression";
		postfix[j++] = stack[top--];
	}
	postfix[j] = '\0';
	return postfix;
}
void main() {
	char expression[100], postfix[102];
	printf("\nEnter the infix expression: ");
	gets(expression);
	postfix = infixToPostfix(expression);
	printf("\nPostfix: ");
	puts(postfix);
}
