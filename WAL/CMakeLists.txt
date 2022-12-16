cmake_minimum_required(VERSION 3.10)



include(${WAL_CMAKE_DIR}/APIOptions.cmake)



set(WAL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source PARENT_SCOPE)
set(WAL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)



configure_file(ConfigurationFiles/WAL/.BuildInfo ${CMAKE_CURRENT_BINARY_DIR}/ConfigurationFiles/WAL/.BuildInfo)



file(GLOB WALSourceFiles
    "Source/WAL/*.cpp"
    "Source/WAL/*.h"
)
source_group("Source\\WAL" FILES ${WALSourceFiles})

file(GLOB WALSourceWindowsFiles
    "Source/WAL/Windows/*.cpp"
    "Source/WAL/Windows/*.h"
)
source_group("Source\\WAL\\Windows" FILES ${WALSourceWindowsFiles})



add_library(WAL STATIC
    ${WALSourceFiles}
    ${WALSourceWindowsFiles}
)



target_link_libraries(WAL
    PUBLIC 
        UL
)

target_include_directories(WAL
    PUBLIC 
        ${CMAKE_CURRENT_BINARY_DIR}/ConfigurationFiles
        ${CMAKE_CURRENT_SOURCE_DIR}/Source
        ${CMAKE_CURRENT_SOURCE_DIR}/../UL/UL/Source
)

target_compile_definitions(WAL
    PRIVATE WAL_EXPORTS=1
)