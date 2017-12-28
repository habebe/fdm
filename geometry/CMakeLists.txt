
INCLUDE_DIRECTORIES(${ASSIMP_INCLUDE_DIR})
add_library(geometry
	ModelGeometryLoader.hxx ModelGeometryLoader.cpp
	ModelGeometry.cpp ModelGeometry.hxx
)


