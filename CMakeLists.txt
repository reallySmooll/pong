cmake_minimum_required(VERSION 3.28)

project(pong
	VERSION 0.1.0
	LANGUAGES CXX
)

message("C compiler is ${CMAKE_C_COMPILER}")
message("C++ compiler is ${CMAKE_CXX_COMPILER}")
message("Compiler id is ${CMAKE_CXX_COMPILER_ID}")
message("Compiler version is ${CMAKE_CXX_COMPILER_VERSION}")

option(BUILD_TYPE "Debug (true) or Release (false)." TRUE)

if (BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
else()
	set(CMAKE_BUILD_TYPE Release)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	message("Building Debug...")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
	message("Building Release...")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_EXPORT_COMPILE_COMMANDS YES)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE) #link time optimization

file(GLOB_RECURSE lib_src
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB_RECURSE pong_src
	"${CMAKE_CURRENT_SOURCE_DIR}/src/Game/*.cpp"
)

add_executable(${CMAKE_PROJECT_NAME} ${lib_src} ${pong_src})

#target_include_directories("${CMAKE_PROJECT_NAME}"
#	PRIVATE
#	#${CMAKE_CURRENT_SOURCE_DIR}/include/
#		/usr/bin/include/
#)
#
# target_link_directories("${CMAKE_PROJECT_NAME}"
# 	PRIVATE
# 		${CMAKE_CURRENT_SOURCE_DIR}/lib/
# )

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set(BUILD_FOR_WIN TRUE)
endif()

option(STATIC_BUILD "Build for Windows." ${BUILD_FOR_WIN})

if (STATIC_BUILD)
	set(CMAKE_EXE_LINKER_FLAGS "-static")
	set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" CONFIG)
	set(BUILD_SHARED_LIBS OFF)	

	target_include_directories("${CMAKE_PROJECT_NAME}"
 		PRIVATE
			${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-x86_64-w64-mingw32-include/
	)

	target_link_directories("${CMAKE_PROJECT_NAME}"
 		PRIVATE
			${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-x86_64-w64-mingw32-lib/
	)

	target_compile_definitions("${CMAKE_PROJECT_NAME}"
		PRIVATE
			SDL_MAIN_HANDLED
	)

	set(sdl2 SDL2)
	set(sdl2i SDL2_image)
	set(sdl2t SDL2_ttf)
	set(sdl2m SDL2_mixer)

	find_library(sa setupapi)
	find_library(i32 imm32)
	find_library(wm winmm)
	find_library(ver version)
	find_library(rpc4 rpcrt4)
	find_library(mingw mingw32)

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,-subsystem,windows")
else()
	find_library(sdl2 SDL2)
	find_library(sdl2i SDL2_image)
	find_library(sdl2t SDL2_ttf)
	find_library(sdl2m SDL2_mixer)
endif()

target_link_libraries(${CMAKE_PROJECT_NAME}
	PRIVATE
		${mingw}
		${sa}
		${i32}
		${wm}
		${ver}
		${rpc4}
		${sdl2}
		${sdl2i}
		${sdl2t}
		${sdl2m}
)

if(MSVC) # If using the VS compiler...
	target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC _CRT_SECURE_NO_WARNINGS)

	set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup") #no console
	
	set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDebug<$<CONFIG:Debug>:Debug>")
	set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
endif()
