#include <stdio.h>
#include <string>

#include "FlexibleStack.h"

FlexibleStack::FlexibleStack()
{

}

FlexibleStack::~FlexibleStack()
{

}

void FlexibleStack::Push(int number)
{
	Node* node = new Node();
	node->data = number;
	node->next = top;

	top = node;
}

Node* FlexibleStack::Pop()
{
	if (top == nullptr)
	{
		printf_s("Stack is empty!\n");
		return nullptr;
	}

	Node* target = top;
	top = top->next;
	return target;
}

void FlexibleStack::Print()
{
	printf_s("List Print---------\n");
	Node* node = top;
	while (node != nullptr)
	{
		printf_s("%d -> ", node->data);
		node = node->next;
	}
	printf_s("End\n\n");
}

void FlexibleStack::Clear()
{
	while (top != nullptr)
	{
		Node* target = top;
		top = top->next;

		delete target;
		target = nullptr;
	}
}

void FlexibleStack::ReadData(char* inputFileName)
{
	if (inputFileName == nullptr)
	{
		printf_s("No data file name provided!\n");
		return;
	}

	FILE* fp = nullptr;
	fopen_s(&fp, inputFileName, "r");
	char line[256];
	if (fp != nullptr)
	{
		while (
			fgets(line, 256, fp) != nullptr)
		{
			printf_s("line : %s\n", line);
			ParseLine(line);
		}

		fclose(fp);
	}
}

void FlexibleStack::ParseLine(char* line)
{
	char delim[] = " :;,\t\n";
	char* token = NULL;
	char* next_token = NULL;

	token = strtok_s(line, delim, &next_token);

	commandType command;
	if (strcmp(token, "push") == 0) command = PUSH;
	else if (strcmp(token, "pop") == 0) command = POP;
	else if (strcmp(token, "p") == 0) command = PRINT;
	else
	{
		printf_s("Unknown command!");
		return;
	}

	while (token != NULL)
	{
		token = strtok_s(NULL, delim, &next_token);

		Node* ret = nullptr;

		switch (command)
		{
		case PUSH:
			if (token != NULL)
			{
				int num = std::stoi(token);
				printf_s("Push(%d)\n", num);

				Push(num);

				Print();
			}

			break;

		case POP:
				printf_s("Pop()\n");

				ret = Pop();
				if (ret != nullptr)
				{
					delete ret;
					ret = nullptr;
				}

				Print();

			break;

		case PRINT:
			printf_s("Print()\n");
			Print();

			break;

		default:
			break;
		}
	}
}