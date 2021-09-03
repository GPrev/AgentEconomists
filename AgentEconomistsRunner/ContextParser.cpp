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
#define NODES "Nodes"
#define ZONE_RESOURCE "resource"
#define ZONE_AMOUNT "initAmount"
#define ZONE_GROWTH "growth"

using namespace rapidjson;
using namespace agenteconomists;

Context& ContextParser::parseFileTo(std::string _fileName, Context& _rOut) const
{
	std::ifstream fileStream(_fileName);
	IStreamWrapper streamWrapper(fileStream);
	Document doc;
	doc.ParseStream(streamWrapper);

	return parseDocTo(doc, _rOut);
}

Context& ContextParser::parseStringTo(std::string _json, Context& _rOut) const
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

std::string ContextParser::getStringMember(const rapidjson::Value& _parent, std::string _memberName, std::string _defaultValue) const
{
	std::string res = _defaultValue;
	if (_parent.HasMember(_memberName.c_str()))
	{
		res = _parent[_memberName.c_str()].GetString();
	}
	return res;
}

int ContextParser::getIntMember(const rapidjson::Value& _parent, std::string _memberName, int _defaultValue) const
{
	int res = _defaultValue;
	if (_parent.HasMember(_memberName.c_str()))
	{
		res = _parent[_memberName.c_str()].GetInt();
	}
	return res;
}

Context& ContextParser::parseDocTo(Document& _doc, Context& _rOut) const
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

void ContextParser::parseAgentType(const Value& _atypeJson, Context& _parentContext) const
{
	_parentContext.addAgentType(_atypeJson[AGENT_TYPE_NAME].GetString());
}

void ContextParser::parseResource(const Value& _resourceJson, Context& _parentContext) const
{
	_parentContext.addResource(_resourceJson[RESOURCE_NAME].GetString());
}

void ContextParser::parseZone(const Value& _zoneJson, Context& _parentContext) const
{
	ZoneDescription& zone = _parentContext.addZone(_zoneJson[ZONE_NAME].GetString());

	std::function<void(const Value&)> fnNode = [this, &zone](const Value& _val) { parseNode(_val, zone); };
	parseArray(_zoneJson, NODES, fnNode);
}

void ContextParser::parseNode(const Value& _zoneJson, ZoneDescription& _parentZone) const
{
	std::string name = getStringMember(_zoneJson, ZONE_NAME);
	std::string resource = getStringMember(_zoneJson, ZONE_RESOURCE);
	int amout = getIntMember(_zoneJson, ZONE_AMOUNT);
	int growth = getIntMember(_zoneJson, ZONE_GROWTH);
	
	_parentZone.addNode(name, resource, amout, growth);
}
