// MathFuncsDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MathFuncsDll.h"
#include <stdexcept>

const int MAX_PRIME = 2000000;
using namespace std;

namespace MathFuncs
{
	double MyMathFuncs::Add(double a, double b)
	{
		return a + b;
	}

	double MyMathFuncs::Subtract(double a, double b)
	{
		return a - b;
	}

	double MyMathFuncs::Multiply(double a, double b)
	{
		return a * b;
	}

	double MyMathFuncs::Divide(double a, double b)
	{
		if (b == 0)
		{
			throw invalid_argument("b cannot be zero!");
		}

		return a / b;
	}

	unsigned long long MyMathFuncs::GetNthPrime(int n)
	{
		int PrimeTable[10000];
		int IsPrime[10000 + 1];
		int PrimeCnt = 0;
		memset(IsPrime, 1, sizeof(IsPrime));
		IsPrime[0] = IsPrime[1] = 0;
		for (int i = 2; i < 10000; i++)
		{
			if (IsPrime[i])
			{
				for (long long j = (PrimeTable[PrimeCnt++] = i) * (long long)i; j < 10000; j += i)
					IsPrime[j] = 0;
			}
		}
		return PrimeTable[n-1];
	}

	unsigned int s[1000000] = { 2 };
	unsigned int s_i = 1;

	unsigned int MyMathFuncs::is_sushu(unsigned int n)
	{
		int i = 0;
		int m = sqrt(n) + 1;
		for (i = 0; i <= m; i++) {
			if (i == s_i)
				return 1;
			if (n%s[i] == 0)
				return 0;
		}
		return 1;
	}

	unsigned long long MyMathFuncs::GetPrime(int n)
	{
		int i;
		for (i = 3; ; i++) {
			if (is_sushu(i))
				s[s_i++] = i;
			if (s_i >= n)
				break;
		}
		return s[n - 1];
	}
}