# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MoveGraf_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MoveGraf_autogen.dir\\ParseCache.txt"
  "MoveGraf_autogen"
  )
endif()
