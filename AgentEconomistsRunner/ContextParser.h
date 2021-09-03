#pragma once

#include <string>
#include <functional>
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

	void parseAgentType(const rapidjson::Value& _atypeJson, agenteconomists::Context& _parentContext) const;
	void parseResource(const rapidjson::Value& _resourceJson, agenteconomists::Context& _parentContext) const;
	void parseZone(const rapidjson::Value& _zoneJson, agenteconomists::Context& _parentContext) const;

	void parseArray(const rapidjson::Value& _parent, std::string _arrayName, std::function<void(const rapidjson::Value&)>& _parsingFunction) const;
};

