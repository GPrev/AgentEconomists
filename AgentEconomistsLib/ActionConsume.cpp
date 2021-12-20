#include "ActionConsume.h"
#include "Agent.h"

namespace agenteconomists
{

    bool ActionConsume::canExecute(Agent* p_agent, Zone* p_zone)
    {
        return p_agent->getQuantity(m_resource) >= m_amount;
    }

    void ActionConsume::execute(Agent* p_agent, Zone* p_zone)
    {
        p_agent->addResoucre(m_resource, -m_amount);
    }

}