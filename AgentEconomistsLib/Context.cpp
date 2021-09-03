#include "Context.h"
#include <sstream>

namespace agenteconomists
{

	std::string Context::toString() const
	{
		std::stringstream sStream;

		sStream << "Context : " << m_agentTypes.size() << " agent types, " << m_resources.size() << " resources, " << m_zones.size() << " zones." << std::endl;

		return sStream.str();
	}

}