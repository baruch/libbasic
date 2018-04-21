add_library (basic
        basic.c
)
add_definitions(-D_GNU_SOURCE)
target_include_directories (basic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#target_link_libraries(basic PUBLIC pthread)
