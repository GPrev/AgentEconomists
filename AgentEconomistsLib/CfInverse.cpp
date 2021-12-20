#include "CfInverse.h"

agenteconomists::CfInverse::CfInverse(double coef)
	: m_coef(coef)
{
}

double agenteconomists::CfInverse::evaluate(double p_nbPossessed)
{
	return 1 - (1/(m_coef * p_nbPossessed + 1));
}
