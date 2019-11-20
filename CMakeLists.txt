cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(Simulateur)

set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABLE_OUTPUT_PATH ./bin/${CMAKE_BUILD_TYPE})


find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0 )
include_directories( ${GTKMM_INCLUDE_DIRS} include/)  
link_directories(${GTKMM_LIBRARY_DIRS})
file(
	GLOB
	SOURCES
	"src/*.cc" "src/core/*.cc" "src/gui/*.cc" "src/states/*.cc"
	)
add_executable (Simulateur ${SOURCES}) 


target_link_libraries(Simulateur ${GTKMM_LIBRARIES})	


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