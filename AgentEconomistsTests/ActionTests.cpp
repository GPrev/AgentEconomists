#include "CppUnitTest.h"
#include "ActionSequence.h"

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
			ActionSequence test("test", std::vector<Action*>());
			Assert::AreEqual(std::string("test"), test.getName());
		}
	};
}
