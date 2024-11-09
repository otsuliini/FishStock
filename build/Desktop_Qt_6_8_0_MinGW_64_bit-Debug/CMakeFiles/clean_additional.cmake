# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FishStock_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FishStock_autogen.dir\\ParseCache.txt"
  "FishStock_autogen"
  )
endif()
