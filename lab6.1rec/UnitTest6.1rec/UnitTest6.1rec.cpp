#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lab6.1rec/6.1rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountPositiveNotMultipleOf5)
        {
            int arr[] = { 1, -3, 5, 6, 7, 0, 8, 10, 15, 17 };
            int size = 10;
            int expectedCount = 7; // 1, 6, 7, 8, 17
            int actualCount = countPositiveNotMultipleOf5(arr, size);
            Assert::AreEqual(expectedCount, actualCount);
        }

        TEST_METHOD(TestSumPositiveNotMultipleOf5)
        {
            int arr[] = { 1, -3, 5, 6, 7, 0, 8, 10, 15, 17 };
            int size = 10;
            int expectedSum = 68; // 1 + 6 + 7 + 8 + 17
            int actualSum = sumPositiveNotMultipleOf5(arr, size);
            Assert::AreEqual(expectedSum, actualSum);
        }

        TEST_METHOD(TestReplaceWithZero)
        {
            int arr[] = { 1, 6, 5, 6, 7, 10, 8, 17 };
            int size = 8;
            replaceWithZero(arr, size);
            int expectedArr[] = { 0, 6, 5, 0, 0, 10, 0, 0 };

            for (int i = 0; i < size; i++) {
                Assert::AreEqual(expectedArr[i], arr[i]);
            }
        }
    };
}
