cmake_minimum_required(VERSION 2.6.4)
####################GTEST START#######################################
set(GTESTDIR gtest/googletest)
set(CUR ../../)
# Defines pre_project_set_up_hermetic_build() and set_up_hermetic_build().
include(${GTESTDIR}/cmake/hermetic_build.cmake OPTIONAL)

if (COMMAND pre_project_set_up_hermetic_build)
  pre_project_set_up_hermetic_build()
endif()

project(gtest CXX C)
cmake_minimum_required(VERSION 2.6.4)

include(${GTESTDIR}/cmake/internal_utils.cmake)
config_compiler_and_linker() 

# Where Google Test's .h files can be found.
include_directories(
  ${GTESTDIR}/include
  ${GTESTDIR})

# Where Google Test's libraries can be found.
link_directories(./${GTESTDIR}/src)

# Summary of tuple support for Microsoft Visual Studio:
# Compiler    version(MS)  version(cmake)  Support
# ----------  -----------  --------------  -----------------------------
# <= VS 2010  <= 10        <= 1600         Use Google Tests's own tuple.
# VS 2012     11           1700            std::tr1::tuple + _VARIADIC_MAX=10
# VS 2013     12           1800            std::tr1::tuple
if (MSVC AND MSVC_VERSION EQUAL 1700)
  add_definitions(/D _VARIADIC_MAX=10)
endif()

########################################################################
#
# Defines the gtest & gtest_main libraries.  User tests should link
# with one of them.
cxx_library(gtest "${cxx_strict}" ${GTESTDIR}/src/gtest-all.cc)
cxx_library(gtest_main "${cxx_strict}" ${GTESTDIR}/src/gtest_main.cc)
target_link_libraries(gtest_main gtest)

# If the CMake version supports it, attach header directory information
# to the targets for when we are part of a parent build (ie being pulled
# in via add_subdirectory() rather than being a standalone build).
if (DEFINED CMAKE_VERSION AND NOT "${CMAKE_VERSION}" VERSION_LESS "2.8.11")
  target_include_directories(gtest      INTERFACE "${GTESTDIR}/include")
  target_include_directories(gtest_main INTERFACE "${GTESTDIR}/include")
endif()

########################################################################
#
# Install rules
install(TARGETS gtest gtest_main
  DESTINATION lib)
install(DIRECTORY ${GTESTDIR}/include/gtest
  DESTINATION include)
################GTEST END################################################
cxx_executable(unittest test gtest_main ./test/unittest.cc)