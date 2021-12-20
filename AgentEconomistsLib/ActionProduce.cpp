#include "ActionProduce.h"
#include "Agent.h"

namespace agenteconomists
{

	bool ActionProduce::canExecute(Agent* p_agent, Zone* p_zone)
	{
		// No inventory capacity yet
		return true;
	}

	void ActionProduce::execute(Agent* p_agent, Zone* p_zone)
	{
		p_agent->addResoucre(m_resource, m_amount);
	}

}