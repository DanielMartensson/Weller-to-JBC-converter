# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appWellerToJBCCommunication_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appWellerToJBCCommunication_autogen.dir\\ParseCache.txt"
  "appWellerToJBCCommunication_autogen"
  )
endif()
