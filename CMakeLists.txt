cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(Simulateur)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABLE_OUTPUT_PATH ./bin/${CMAKE_BUILD_TYPE})

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories( ${Qt5Widgets_INCLUDES} include/)  

file(
	GLOB_RECURSE
	SOURCES
	"src/*.cc"
	)
file(
            GLOB_RECURSE
            HEADERS
            "include/*.h"
            )

add_executable (Simulateur ${SOURCES} ${HEADERS})


target_link_libraries(Simulateur ${Qt5Widgets_LIBRARIES})	


#Crée l'archive du project
SET(DIST_DIR "${CMAKE_PROJECT_NAME}")
ADD_CUSTOM_TARGET(dist 
		  COMMAND rm -rf ${DIST_DIR}
		  COMMAND mkdir  ${DIST_DIR}
		  COMMAND cp -r ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/bin ${CMAKE_SOURCE_DIR}/doc ${CMAKE_SOURCE_DIR}/.gitignore ${CMAKE_SOURCE_DIR}/CMakeLists.txt ${DIST_DIR} || true 
		  COMMAND rm -rf ${DIST_DIR}/build
		  COMMAND mkdir ${DIST_DIR}/build
		  COMMAND rm -rf ${DIST_DIR}/build
  		  COMMAND tar --exclude="*~" --exclude="._*" --exclude="CMakeFiles" --exclude="cmake*" -zcvf ${DIST_DIR}.tar.gz ${DIST_DIR}
		  COMMAND rm -rf  ${DIST_DIR}
    	  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

ADD_CUSTOM_TARGET(run COMMAND ./bin/Debug/Simulateur)
