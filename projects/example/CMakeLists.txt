#--------------------------------------------------------------------------
# example project
#--------------------------------------------------------------------------

PROJECT(example)
FILE(GLOB example_headers code/*.h)
FILE(GLOB example_sources code/*.cc code/*.cpp)

SET(files_example ${example_headers} ${example_sources} code/Raycast.cpp code/Raycast.h code/Plane.h code/AABB.h code/PlaneSweep.cpp code/PlaneSweep.h code/Collison.cpp code/Collision.h)
SOURCE_GROUP("example" FILES ${files_example})

ADD_EXECUTABLE(example ${files_example})
TARGET_LINK_LIBRARIES(example core render)
ADD_DEPENDENCIES(example core render)