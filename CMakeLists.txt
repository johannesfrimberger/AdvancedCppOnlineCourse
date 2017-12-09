cmake_minimum_required(VERSION 3.1)

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

project(AdvancedCppOnlineCourseExamples)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set source directory
set(srcDir ${CMAKE_SOURCE_DIR}/src)

# Find all files in source folder
FILE(GLOB children RELATIVE ${srcDir} ${srcDir}/*)

# Make sure all list elements are directories
SET(dir_list "")
FOREACH(child ${children})
  IF(IS_DIRECTORY ${srcDir}/${child})
    LIST(APPEND dir_list ${child})
  ENDIF()
ENDFOREACH()

# Create a separate executable for each cpp file
FOREACH(folder ${dir_list})

  file(GLOB SRCs
    "${srcDir}/${folder}/*.cpp"
  )

  FOREACH(file ${SRCs})
    get_filename_component(bare_name ${file} NAME_WE)
    add_executable(${bare_name} ${file})
    set(group_name ${folder}/${bare_name})
    SOURCE_GROUP(${group_name} FILES ${file})
  ENDFOREACH()

ENDFOREACH()
