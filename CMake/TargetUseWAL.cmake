
function(TargetUseWAL TargetName)
    
    add_dependencies(${TargetName} WAL)

    target_link_libraries(${TargetName} 
        PRIVATE WAL
    )

    target_include_directories(${TargetName} 
        PUBLIC ${WAL_SOURCE_DIR}
    )

endfunction(TargetUseWAL)
