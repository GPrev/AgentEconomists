#pragma once
#include "Action.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// Action that consists of a series of aother actions
	/// </summary>
    class AELIB_API ActionSequence : public Action
    {
    public:
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="name">The name of the action</param>
        /// <param name="actions">The sub-actions, to be executed sequentially</param>
        ActionSequence(std::string p_name, std::vector<Action*>& p_actions) : Action(p_name), m_actions(p_actions) { };

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
		std::vector<Action*> m_actions;
    };

}

#pragma warning( pop )

