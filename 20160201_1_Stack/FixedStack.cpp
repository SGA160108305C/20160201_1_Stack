#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FixedStack.h"


FixedStack::FixedStack()
{
	memset(stack, -1, sizeof(unsigned int) * STACK_SIZE);
}


FixedStack::~FixedStack()
{
}

void FixedStack::Push(int number)
{
	topIndex++;
	if (topIndex >= STACK_SIZE)
	{
		printf_s("Stack overflow\n");
	}
	else
	{
		stack[topIndex] = number;
	}
}

int FixedStack::Pop()
{		
	int popData = -1;
	if (topIndex >= 0 && topIndex < STACK_SIZE)
	{
		popData = stack[topIndex];
		topIndex--;
		if (topIndex < 0)
		{
			topIndex = -1;
		}
	}

	return popData;
}

void FixedStack::Print()
{
	printf_s("Fixed Stack Print------------------------------\n");

	for (int i = topIndex; i >= 0; --i)
	{
		printf_s("%d\n", stack[i]);
	}
	printf_s("-----------------------------------------------\n\n");
}

void FixedStack::Clear()
{
	memset(stack, -1, sizeof(unsigned int) * STACK_SIZE);
}

void FixedStack::ReadData(char* inputFileName /*= nullptr*/)
{
	char filename[256] = "\0";
	if (inputFileName != nullptr)
	{
		strcpy_s(filename, inputFileName);
	}
	else
	{
		strcpy_s(filename, "data_stack.txt");
	}


	FILE* fp = nullptr;
	fopen_s(&fp, filename, "r");
	if (fp != nullptr)
	{
		char line[256];
		while (fgets(line, 256, fp) != nullptr)
		{
			//파싱
			char* command = nullptr;
			char* parameter = nullptr;

			char* context = nullptr;
			char seperator[] = " :\n\0";
			command = strtok_s(line, seperator, &context);
			if (command != nullptr)
			{
				parameter = strtok_s(nullptr, seperator, &context);

				//파싱한 명령어들 처리
				if (strcmp("pop", command) == 0)
				{
					int data = Pop();
					
				}
				else if (strcmp("push", command) == 0)
				{
					Push(atoi(parameter));
				}
				else if (strcmp("p", command) == 0)
				{
					Print();
				}
				else
				{
					printf_s("Unknown command.\n");
				}
			}

		}
		fclose(fp);
	}
}
