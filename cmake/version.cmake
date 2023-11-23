set(VER_MAJOR 0)
set(VER_MINOR 5)
set(VER_RELEASE 0)
set(VER_BUILD 3165)
set(PACKAGE_SUFFIX "")
set(VER_STRING ${VER_MAJOR}.${VER_MINOR}.${VER_RELEASE}.${VER_BUILD})

# Get the latest abbreviated commit hash of the working branch
execute_process(
	COMMAND git describe --always
	WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
	OUTPUT_VARIABLE GIT_REVISION
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
