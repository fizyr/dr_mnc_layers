find_path(YamlCpp_INCLUDE_DIR
	NAMES yaml-cpp/yaml.h
	DOC "The directory where yaml-cpp includes reside"
)

find_library(YamlCpp_LIBRARY
	NAMES yaml-cpp
	DOC "The yaml-cpp library"
)

set(YamlCpp_INCLUDE_DIRS ${YamlCpp_INCLUDE_DIR})
set(YamlCpp_LIBRARIES    ${YamlCpp_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(YamlCpp
	FOUND_VAR YamlCpp_FOUND
	REQUIRED_VARS YamlCpp_INCLUDE_DIR YamlCpp_LIBRARY
)

mark_as_advanced(YamlCpp_FOUND)
