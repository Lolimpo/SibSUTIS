#define CTEST_MAIN

#include <ctest.h>
#include <stdbool.h>
char a[9][9];

CTEST(Syntax, Correct_Syntax_Check)
{
	bool result = moveboard(a, "e20-e40");
	ASSERT_FALSE(result);
}

CTEST(Syntax, Incorrect_Syntax_Check)
{
	bool result = moveboard(a, "Pb2-b4");
	ASSERT_FALSE(result);
}

CTEST (Syntax, Incorrect_Figure_Move)
{
	bool result = moveboard(a, "c1-c3");
	ASSERT_FALSE(result);
}

CTEST (Syntax, Incorrect_Movemet_Split)
{
	bool result = moveboard(a, "d1=d3");
	ASSERT_FALSE(result);
}

CTEST (Syntax, Incorrect_Syntax_Order)
{
	bool result = moveboard(a, "1e-3e");
	ASSERT_FALSE(result);
}

int main (int argc, const char** argv)
{
	makeboard(a);
	return ctest_main(argc, argv);
}
