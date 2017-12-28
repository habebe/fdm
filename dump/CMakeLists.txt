
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../geometry)
add_executable(dump 
	main.cpp
)

target_link_libraries(dump geometry)
target_link_libraries(dump ${ASSIMP_LIBRARY_RELEASE})
target_link_libraries(dump ${Qt5Core_LIBRARIES})
