#include "Agent.h"

namespace agenteconomists
{

	void Agent::addResoucre(Resource* p_resource, int p_amount)
	{
		m_inventory[p_resource] += p_amount;
	}

}