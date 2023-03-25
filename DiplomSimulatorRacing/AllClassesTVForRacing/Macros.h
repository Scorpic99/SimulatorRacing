#pragma once
#ifdef ALLCLASSESTV_EXPORTS
#define ALLCLASSESTV_API __declspec(dllexport)
#else
#define ALLCLASSESTV_API __declspec(dllimport)
#endif
