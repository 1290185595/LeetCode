aux_source_directory(. LIB_SRC_LIST)
add_library(lib ${LIB_SRC_LIST})

set(
        LIB_INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}
        CACHE INTERNAL "LIB_INCLUDE_DIR"
)
