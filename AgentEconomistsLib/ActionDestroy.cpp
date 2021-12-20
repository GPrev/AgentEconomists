#include "ActionDestroy.h"
#include "Zone.h"

namespace agenteconomists
{

    bool ActionDestroy::canExecute(Agent* p_agent, Zone* p_zone)
    {
        int amountAvailable = 0;
        for (ResourceNode& node : p_zone->getResourceNodes())
        {
            if (node.getResource() == m_resource)
            {
                amountAvailable += node.getAmount();
            }
        }
        return amountAvailable >= m_amount;
    }

    void ActionDestroy::execute(Agent* p_agent, Zone* p_zone)
    {
        int amountLeft = m_amount;
        for (ResourceNode& node : p_zone->getResourceNodes())
        {
            if (node.getResource() == m_resource)
            {
                int amountDestroyed = std::min(amountLeft, m_amount);
                node.addAmount(-amountDestroyed);
                amountLeft -= amountDestroyed;
            }
        }
    }

}