#include "CfLinear.h"

agenteconomists::CfLinear::CfLinear(double coef)
    : m_coef(coef)
{
}

double agenteconomists::CfLinear::evaluate(double p_nbPossessed)
{
    return m_coef * p_nbPossessed;
}
