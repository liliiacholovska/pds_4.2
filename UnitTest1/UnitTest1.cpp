#include "pch.h"
#include "CppUnitTest.h"
#include "../pds_4.2/pds_4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestLexicographicCombinations)
        {
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

            lexicographicCombinations(4, 2);

            std::cout.rdbuf(oldCoutBuffer);

            std::string strOutput = output.str();
            Assert::IsTrue(strOutput.find("combination = {1, 2}") != std::string::npos);
            Assert::IsTrue(strOutput.find("combination = {1, 3}") != std::string::npos);
            Assert::IsTrue(strOutput.find("combination = {1, 4}") != std::string::npos);
            Assert::IsTrue(strOutput.find("combination = {2, 3}") != std::string::npos);
            Assert::IsTrue(strOutput.find("combination = {2, 4}") != std::string::npos);
            Assert::IsTrue(strOutput.find("combination = {3, 4}") != std::string::npos);
        }
	};
}