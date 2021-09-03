#include "ContextParser.h"
#include <fstream>
#include <iostream>
#include <sstream>

#pragma warning(push, 0)        
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"
#pragma warning(pop)

#define AGENT_TYPES "AgentTypes"
#define AGENT_TYPE_NAME "name"
#define RESOURCES "Reources"
#define RESOURCE_NAME "name"
#define ZONES "Zones"
#define ZONE_NAME "name"

using namespace rapidjson;

agenteconomists::Context& ContextParser::parseFileTo(std::string _fileName, agenteconomists::Context& _rOut) const
{
	std::ifstream fileStream(_fileName);
	IStreamWrapper streamWrapper(fileStream);
	Document doc;
	doc.ParseStream(streamWrapper);

	return parseDocTo(doc, _rOut);
}

agenteconomists::Context& ContextParser::parseStringTo(std::string _json, agenteconomists::Context& _rOut) const
{
	std::stringstream sStream;
	sStream << _json;
	IStreamWrapper streamWrapper(sStream);
	Document doc;
	doc.ParseStream(streamWrapper);

	return parseDocTo(doc, _rOut);
}

void ContextParser::parseArray(const Value& _parent, std::string _arrayName, std::function<void(const Value&)>& _parsingFunction) const
{
	if (_parent.HasMember(_arrayName.c_str()))
	{
		const Value& arrayValue = _parent[_arrayName.c_str()];
		if (arrayValue.IsArray())
		{
			for (SizeType i = 0; i < arrayValue.Size(); i++)
			{
				_parsingFunction(arrayValue[i]);
			}
		}
	}
}

agenteconomists::Context& ContextParser::parseDocTo(Document& _doc, agenteconomists::Context& _rOut) const
{
	if (!_doc.HasParseError())
	{
		_rOut.clear();

		std::function<void(const Value&)> fnAgentType = [this, &_rOut](const Value& _val) { parseAgentType(_val, _rOut); };
		parseArray(_doc, AGENT_TYPES, fnAgentType);

		std::function<void(const Value&)> fnResource = [this, &_rOut](const Value& _val) { parseResource(_val, _rOut); };
		parseArray(_doc, RESOURCES, fnResource);

		std::function<void(const Value&)> fnZone = [this, &_rOut](const Value& _val) { parseZone(_val, _rOut); };
		parseArray(_doc, ZONES, fnZone);
	}

	return _rOut;
}

void ContextParser::parseAgentType(const Value& _atypeJson, agenteconomists::Context& _parentContext) const
{
	_parentContext.addAgentType(_atypeJson[AGENT_TYPE_NAME].GetString());
}

void ContextParser::parseResource(const Value& _resourceJson, agenteconomists::Context& _parentContext) const
{
	_parentContext.addResource(_resourceJson[RESOURCE_NAME].GetString());
}

void ContextParser::parseZone(const Value& _zoneJson, agenteconomists::Context& _parentContext) const
{
	_parentContext.addZone(_zoneJson[ZONE_NAME].GetString());
}
