cmake_minimum_required(VERSION 3.10)



file(GLOB InitWALSourceFiles
    "Source/*.cpp"
    "Source/*.h"
)
source_group("Source" FILES ${InitWALSourceFiles})



add_executable(Samples.InitWAL
    ${InitWALSourceFiles}
)



set_target_properties(Samples.InitWAL
    PROPERTIES 
        FOLDER "Samples"
)



include(${WAL_CMAKE_DIR}/TargetUseWAL.cmake)
TargetUseWAL(Samples.InitWAL)