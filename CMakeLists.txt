cmake_minimum_required( VERSION 3.1 )

include(cmake/version.cmake)

project( bflib VERSION ${VER_STRING} LANGUAGES C )
set(PROJECT_DESCRIPTION "Bullfrog Engine Emulation Library - for use to remake
classic games like Syndicate Wars, Magic Carpet or Dungeon Keeper.")
set(TARGET_NAME bullfrog)

include(GNUInstallDirs)
include(FindPkgConfig)

if( NOT CMAKE_BUILD_TYPE )
	set( CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE )
endif()

set( CMAKE_C_STANDARD 99 )
set( CMAKE_C_STANDARD_REQUIRED ON )

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-switch" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wextra" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror-implicit-function-declaration -Wno-conversion -Wno-traditional-conversion -Wno-sign-compare" )

# Add Math::Math
include(cmake/FindMath.cmake)

file( GLOB_RECURSE c_files ${CMAKE_CURRENT_SOURCE_DIR}/src/bullfrog/*.c)
file( GLOB_RECURSE h_files ${CMAKE_CURRENT_SOURCE_DIR}/src/bullfrog/*.h)

if( NOT ${TARGET_NAME}_TYPE )
    ## build library as shared by default
    set( ${TARGET_NAME}_TYPE SHARED )
endif()

add_compile_definitions( VER_MAJOR=${VER_MAJOR} VER_MINOR=${VER_MINOR} VER_RELEASE=${VER_RELEASE} VER_BUILD=${VER_BUILD} PACKAGE_SUFFIX=${PACKAGE_SUFFIX} GIT_REVISION=${GIT_REVISION} )

add_library( ${TARGET_NAME} ${TARGET_NAME_TYPE} ${c_files} )
set_target_properties( ${TARGET_NAME} PROPERTIES PUBLIC_HEADER "${h_files}" )
target_include_directories( ${TARGET_NAME} PUBLIC Math::Math
			$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
			$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/>
			$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/deps/findfirst>
			$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${TARGET_NAME}>
			PRIVATE "."
			)
target_link_libraries(${TARGET_NAME} Math::Math)

# pkg-config variables
set(target_name "lib${TARGET_NAME}")
set(stdclibs "${CMAKE_C_STANDARD_LIBRARIES}" Math::Math)
set(install_prefix "${CMAKE_INSTALL_PREFIX}")
set(install_libdir "${CMAKE_INSTALL_LIBDIR}")
set(install_includedir "${CMAKE_INSTALL_INCLUDEDIR}/${TARGET_NAME}")
configure_file(lib${TARGET_NAME}.pc.in ${PROJECT_BINARY_DIR}/lib${TARGET_NAME}.pc @ONLY)

set(ENV{PKG_CONFIG_PATH} "${PROJECT_BINARY_DIR}:$ENV{PKG_CONFIG_PATH}")

install( TARGETS ${TARGET_NAME} EXPORT lib${TARGET_NAME}Config 
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libraries
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT binaries 
	PUBLIC_HEADER DESTINATION
	${CMAKE_INSTALL_INCLUDEDIR}/${TARGET_NAME} COMPONENT headers
        )

install(FILES ${PROJECT_BINARY_DIR}/lib${TARGET_NAME}.pc DESTINATION
	${CMAKE_INSTALL_LIBDIR}/pkgconfig/)


