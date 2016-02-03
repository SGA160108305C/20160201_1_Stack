#pragma once

#include "Node.h"

class FlexibleStack
{
public:
	enum commandType
	{
		PUSH, POP, PRINT
	};

	FlexibleStack();
	~FlexibleStack();

	void Push(int number);
	Node* Pop();
	void Print();

	void Clear();
	void ReadData(char* inputFileName = nullptr);
	void ParseLine(char* line);

private:
	Node* top = nullptr;
};

