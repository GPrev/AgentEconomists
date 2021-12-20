#include "Agent.h"
#include "Market.h"

namespace agenteconomists {
	Agent::Agent()
	{
	}

	void Agent::act(Zone* p_zone)
	{
	}

	void Agent::goToMarket(Market* p_market)
	{
	}

	void Agent::addResoucre(Resource* p_resource, int p_amount)
	{
		m_inventory[p_resource] += p_amount;
	}
}


