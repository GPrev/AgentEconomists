#include "CppUnitTest.h"
#include "Agent.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace agenteconomists;

namespace AgentEconomistsTests
{
	/// <summary>
	/// Tests related to the "Action" class
	/// </summary>
	TEST_CLASS(ActionTests)
	{
	public:
		
		/// <summary>
		/// Dummy test, to make sure the link to the DLL works fine
		/// </summary>
		TEST_METHOD(CreationTest)
		{
			Action test("test");
			Assert::AreEqual(std::string("test"), test.getName());
		}
	};
}
