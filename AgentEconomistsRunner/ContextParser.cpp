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

agenteconomists::Context& ContextParser::parseDocTo(Document& _doc, agenteconomists::Context& _rOut) const
{
	if (!_doc.HasParseError())
	{
		_rOut.clear();

		if (_doc.HasMember(AGENT_TYPES))
		{
			const Value& rAgentTypes = _doc[AGENT_TYPES];
			if (rAgentTypes.IsArray())
			{
				for (SizeType i = 0; i < rAgentTypes.Size(); i++)
				{
					const Value& rAgentType = rAgentTypes[i];
					_rOut.addAgentType(rAgentType[AGENT_TYPE_NAME].GetString());
				}
			}
		}

		if (_doc.HasMember(RESOURCES))
		{
			const Value& rResources = _doc[RESOURCES];
			if (rResources.IsArray())
			{
				for (SizeType i = 0; i < rResources.Size(); i++)
				{
					const Value& rResource = rResources[i];
					_rOut.addResource(rResource[RESOURCE_NAME].GetString());
				}
			}
		}

		if (_doc.HasMember(ZONES))
		{
			const Value& rZones = _doc[ZONES];
			if (rZones.IsArray())
			{
				for (SizeType i = 0; i < rZones.Size(); i++)
				{
					const Value& rZone = rZones[i];
					_rOut.addZone(rZone[ZONE_NAME].GetString());
				}
			}
		}
	}

	return _rOut;
}