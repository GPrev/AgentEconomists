#pragma once
#include "Action.h"
#include "Resource.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// Action that consumes a resource from the inventory
	/// </summary>
	class AELIB_API ActionConsume : public Action
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="p_name">Name of the action</param>
		/// <param name="p_resource">Resource to consume</param>
		/// <param name="p_amount">Amount to consume</param>
		ActionConsume(std::string p_name, Resource* p_resource, int p_amount) : Action(p_name), m_resource(p_resource), m_amount(p_amount) { };

		/// <summary>
		/// Check if an Agent is allowed to perform an action.
		/// </summary>
		/// <returns>True if the Agent can perform the action, false otherwise</returns>
		virtual bool canExecute(Agent* p_agent, Zone* p_zone);

		/// <summary>
		/// Make an Agent perform an action.
		/// </summary>
		virtual void execute(Agent* p_agent, Zone* p_zone);

	private:
		Resource* m_resource;
		int m_amount;
	};

}

#pragma warning( pop )

