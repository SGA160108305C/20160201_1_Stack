#include <stdio.h>
#include "FlexibleStack.h"
#include "FixedStack.h"

void main()
{
	//FlexibleStack stack;
	//stack.ReadData("data_stack.txt");
	//stack.Clear();

	printf_s("###############################################\n\n");

	FixedStack stack2;
	stack2.ReadData("data_stack2.txt");
	stack2.Clear();

	getchar();
}