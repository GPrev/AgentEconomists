#pragma once

#include <string>
#include "Context.h"
#include "rapidjson/document.h"

class ContextParser
{
public:
	agenteconomists::Context parseFile(std::string _fileName) const { agenteconomists::Context context; return parseFileTo(_fileName, context); }
	agenteconomists::Context& parseFileTo(std::string _fileName, agenteconomists::Context& _rOut) const;
	agenteconomists::Context& parseStringTo(std::string _json, agenteconomists::Context& _rOut) const;

private:
	agenteconomists::Context& parseDocTo(rapidjson::Document& _doc, agenteconomists::Context& _rOut) const;
};

