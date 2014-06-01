cmake_minimum_required(VERSION 2.8)


include_directories(glfw/include/GLFW/)

add_subdirectory(glfw)

set(Sources
	main.cxx
	CRender.cxx
	CPicture.cxx
	CGraph.cxx
	TimFunction.cxx
)

set(Headers
	IFunction.hxx
	CRender.hxx
	CPicture.hxx
	CGraph.hxx
	TimFunction.hxx
)
SET(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(CourseTask ${Sources} ${Headers})
target_link_libraries(CourseTask glfw ${GLFW_LIBRARIES})

if ("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
	add_custom_command(OUTPUT RunTestCommand COMMAND ./Build/CourseTask WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
		add_custom_target(RunTest ALL DEPENDS RunTestCommand CourseTask)
endif()