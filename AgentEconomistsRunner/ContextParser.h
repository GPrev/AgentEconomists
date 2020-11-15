#pragma once

#include <string>
#include "Context.h"

class ContextParser
{
public:
	agenteconomists::Context parseFile(std::string _fileName) const { agenteconomists::Context context; return parseFileTo(_fileName, context); }
	agenteconomists::Context& parseFileTo(std::string _fileName, agenteconomists::Context& _rOut) const;
};

