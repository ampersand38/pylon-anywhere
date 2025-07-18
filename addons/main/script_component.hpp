#define COMPONENT main
#define COMPONENT_BEAUTIFIED main
#include "\z\pya\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_main
  #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_main
  #define DEBUG_SETTINGS DEBUG_SETTINGS_main
#endif

#include "\z\pya\addons\main\script_macros.hpp"

#define JETTISON_MODE_ALL 0
#define JETTISON_MODE_SELECTED 1
#define JETTISON_MODE_DOGFIGHT 2
