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

set(srcDir ${CMAKE_SOURCE_DIR}/src)
FILE(GLOB children RELATIVE ${srcDir} ${srcDir}/*)

SET(dirlist "")
FOREACH(child ${children})
  IF(IS_DIRECTORY ${srcDir}/${child})
    LIST(APPEND dirlist ${child})
  ENDIF()
ENDFOREACH()


FOREACH(folder ${dirlist})
  file(GLOB SRCs
    "${srcDir}/${folder}/*.cpp"
  )

  FOREACH(file ${SRCs})
    get_filename_component(barename ${file} NAME_WE)
    add_executable(${barename} ${file})
    set(groupName ${folder}/${barename})
    SOURCE_GROUP(${groupName} FILES ${file})
  ENDFOREACH()
ENDFOREACH()
