#--------------------------------------------------------------------------
# FUCYOUEL project
#--------------------------------------------------------------------------

PROJECT(FUCYOUEL)
FILE(GLOB FUCYOUEL_headers code/*.h)
FILE(GLOB FUCYOUEL_sources code/*.cc)

SET(files_FUCYOUEL ${FUCYOUEL_headers} ${FUCYOUEL_sources})
SOURCE_GROUP("FUCYOUEL" FILES ${files_FUCYOUEL})

ADD_EXECUTABLE(FUCYOUEL ${files_FUCYOUEL})
TARGET_LINK_LIBRARIES(FUCYOUEL core render)
ADD_DEPENDENCIES(FUCYOUEL core render)