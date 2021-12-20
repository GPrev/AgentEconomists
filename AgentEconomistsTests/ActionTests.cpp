#include "CppUnitTest.h"
#include "ActionSequence.h"
#include "ActionConsume.h"
#include "ActionProduce.h"
#include "ActionDestroy.h"
#include "Agent.h"
#include "Zone.h"

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

		/// <summary>
		/// Test for the consume action
		/// </summary>
		TEST_METHOD(ConsumeTest)
		{
			Agent agent;
			Zone zone;
			Resource resource1, resource2;
			ActionConsume action("test", &resource1, 2);

			// Resource is not in inventory
			Assert::IsFalse(action.canExecute(&agent, &zone));

			// Incorrect resource
			agent.addResoucre(&resource2, 10);
			Assert::IsFalse(action.canExecute(&agent, &zone));

			// Amount in inventory is insufficient
			agent.addResoucre(&resource1, 1);
			Assert::IsFalse(action.canExecute(&agent, &zone));

			// Correct resource and amount
			agent.addResoucre(&resource1, 9);
			Assert::IsTrue(action.canExecute(&agent, &zone));

			// Tests the effect of the action
			action.execute(&agent, &zone);
			Assert::AreEqual(8, agent.getQuantity(&resource1));
		}

		/// <summary>
		/// Test for the produce action
		/// </summary>
		TEST_METHOD(ProduceTest)
		{
			Agent agent;
			Zone zone;
			Resource resource1, resource2;
			ActionProduce action("test", &resource1, 2);

			// Action is always possible
			Assert::IsTrue(action.canExecute(&agent, &zone));

			// Tests the effect of the action
			action.execute(&agent, &zone);
			Assert::AreEqual(2, agent.getQuantity(&resource1));
		}

		/// <summary>
		/// Test for the destroy action
		/// </summary>
		TEST_METHOD(DestroyTest)
		{
			Agent agent;
			Resource resource1, resource2;
			Zone zone;
			ResourceNode node1(&resource1), node2(&resource2, 10);
			ActionDestroy action("test", &resource1, 2);

			// Resource is not in inventory
			Assert::IsFalse(action.canExecute(&agent, &zone));

			// Incorrect resource
			zone.getResourceNodes().push_back(node2);
			Assert::IsFalse(action.canExecute(&agent, &zone));

			// Amount in inventory is insufficient
			zone.getResourceNodes().push_back(node1);
			Assert::IsFalse(action.canExecute(&agent, &zone));

			// Correct resource and amount
			zone.getResourceNodes().at(1).addAmount(10);
			Assert::IsTrue(action.canExecute(&agent, &zone));

			// Tests the effect of the action
			action.execute(&agent, &zone);
			Assert::AreEqual(8, zone.getResourceNodes().at(1).getAmount());
		}
	};
}
