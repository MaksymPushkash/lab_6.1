#include "pch.h" // ���� ��������������� precompiled header
#include "CppUnitTest.h"
#include <vector>
#include "../lab_06.1/lab_06.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(UnitTestProject)
    {
    public:

        TEST_METHOD(TestGenerateArray)
        {
            const int SIZE = 27;
            const int MIN_VAL = -35;
            const int MAX_VAL = 25;
            std::vector<int> arr(SIZE);

            generateArray(arr, MIN_VAL, MAX_VAL);

            for (const int& elem : arr) {
                Assert::IsTrue(elem >= MIN_VAL && elem <= MAX_VAL, L"Element is out of range.");
            }
        }

        TEST_METHOD(TestProcessArray)
        {
            std::vector<int> arr = { -35, -3, 2, 5, -4, 0, 25 }; // ������ ���
            int expectedSum = -3 + 5 + 25; // ��������� ����
            int expectedCount = 3; // ��������� ������� ��������
            int sum = 0;
            int count = 0;

            processArray(arr, sum, count);

            Assert::AreEqual(expectedSum, sum, L"Sum is incorrect.");
            Assert::AreEqual(expectedCount, count, L"Count is incorrect.");

            // ����������, �� �������� ������ �� ���
            std::vector<int> expectedArr = { -35, 0, 2, 0, -4, 0, 0 };
            Assert::IsTrue(arr == expectedArr, L"Array was not processed correctly.");
        }

        // ���� ��� �������� ��������� ������ (printArray)
        TEST_METHOD(TestPrintArray)
        {
            std::vector<int> arr = { -35, -3, 2, 5, -4, 0, 25 };

            // ��������� � ������� ������������ �� ��������� ������������ �����
            std::ostringstream output;
            std::streambuf* prevcoutbuf = std::cout.rdbuf(output.rdbuf());

            printArray(arr);

            std::cout.rdbuf(prevcoutbuf); // ³��������� ������������ ������
            std::string expectedOutput = "-35 -3 2 5 -4 0 25 \n";

            Assert::AreEqual(expectedOutput, output.str(), L"Array output is incorrect.");
        }
    };
}
