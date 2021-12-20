#include "ActionSequence.h"

namespace agenteconomists
{

    bool ActionSequence::canExecute(Agent* p_agent, Zone* p_zone)
    {
        bool possible = true;
        for (Action* action : m_actions)
        {
            possible = possible && action->canExecute(p_agent, p_zone);
        }
        return false;
    }

    void ActionSequence::execute(Agent* p_agent, Zone* p_zone)
    {
        for (Action* action : m_actions)
        {
            action->execute(p_agent, p_zone);
        }
    }

}