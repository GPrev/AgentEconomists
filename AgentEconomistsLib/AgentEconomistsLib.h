#pragma once

#ifdef AGENTECONOMISTSLIB_EXPORTS
#define AELIB_API __declspec(dllexport)
#else
#define AELIB_API __declspec(dllimport)
#endif
