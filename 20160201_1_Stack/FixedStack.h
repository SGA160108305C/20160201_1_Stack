#pragma once
class FixedStack
{
public:
	FixedStack();
	~FixedStack();

	void Push(int number);
	int Pop();
	void Print();

	void Clear();
	void ReadData(char* inputFileName = nullptr);

private:
	static const int STACK_SIZE = 5;
		
	unsigned int stack[STACK_SIZE];

	int topIndex = -1;
};

