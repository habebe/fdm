cmake_minimum_required(VERSION 3.0.1)
project (fdm)

set (CMAKE_CXX_STANDARD 11)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake-modules/")



list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules/")
#list(APPEND CMAKE_MODULE_PATH "D:\\Qt\\5.10.0\\msvc2017_64\\lib\\cmake\\Qt5")
set (CMAKE_PREFIX_PATH "D:\\Qt\\5.10.0\\msvc2017_64")

set(ASSIMP_ROOT_DIR D:/dev/tools/install)
set(ASSIMP_MSVC_VERSION vc140)
set(ASSIMP_ARCHITECTURE "64")

find_path(ASSIMP_INCLUDE_DIR
		NAMES
		assimp/anim.h
		HINTS
		${ASSIMP_ROOT_DIR}/include
	)

find_path(ASSIMP_LIBRARY_DIR
		NAMES
		assimp-${ASSIMP_MSVC_VERSION}-mt.lib
		HINTS
		${ASSIMP_ROOT_DIR}/lib
		)
		
find_library(ASSIMP_LIBRARY_RELEASE	
	assimp-${ASSIMP_MSVC_VERSION}-mt.lib 			
	PATHS ${ASSIMP_LIBRARY_DIR})

find_library(ASSIMP_LIBRARY_DEBUG assimp-${ASSIMP_MSVC_VERSION}-mtd.lib			
	PATHS ${ASSIMP_LIBRARY_DIR})
		
set(ASSIMP_LIBRARY 
		optimized 	${ASSIMP_LIBRARY_RELEASE}
		debug		${ASSIMP_LIBRARY_DEBUG}
		)
		
set(ASSIMP_LIBRARIES "ASSIMP_LIBRARY_RELEASE" "ASSIMP_LIBRARY_DEBUG")
	
MESSAGE(${ASSIMP_ROOT_DIR}/lib/assimp-${ASSIMP_MSVC_VERSION}-mt.lib)
MESSAGE(ASSIMP_LIBRARY_DIR_release = ${ASSIMP_LIBRARY_RELEASE})
MESSAGE(ASSIMP_INCLUDE_DIR = ${ASSIMP_INCLUDE_DIR})

INCLUDE_DIRECTORIES(${ASSIMP_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/geometry)

MESSAGE("XX" ${CMAKE_MODULE_PATH})

#SET(CMAKE_PREFIX_PATH d:/Qt/5.10.0/msv2013_64/lib/cmake/Qt5)

find_package(Qt5Core REQUIRED)
include_directories(${Qt5Core_INCLUDE_DIRS})


add_subdirectory(geometry)
add_subdirectory(dump)

