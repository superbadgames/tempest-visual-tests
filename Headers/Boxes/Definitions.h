#pragma once

#ifdef BOXES_EXPORTS
#define BOXES_API __declspec(dllexport)
#else
#define BOXES_API __declspec(dllimport)
#endif