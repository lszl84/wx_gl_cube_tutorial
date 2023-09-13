

message(STATUS "Will download and install glm in ${STAGED_INSTALL_PREFIX}")

include(ExternalProject)
ExternalProject_Add(glm_external
    GIT_REPOSITORY
    https://github.com/g-truc/glm.git
    GIT_TAG
    0.9.9.8
    GIT_SHALLOW
    1
    CONFIGURE_COMMAND
    ""
    BUILD_COMMAND
    ""
    UPDATE_COMMAND
    ""
    INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory ${EP_SOURCE_DIR_PREFIX}/glm_external/glm ${STAGED_INSTALL_PREFIX}/include/glm
    BUILD_BYPRODUCTS ${STAGED_INSTALL_PREFIX}/include/glm
    CMAKE_ARGS
    -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
    -DCMAKE_BUILD_TYPE=Release
    -DCMAKE_CXX_STANDARD_REQUIRED=${CMAKE_CXX_STANDARD_REQUIRED}
    CMAKE_CACHE_ARGS
    -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
    TEST_AFTER_INSTALL
    0
    DOWNLOAD_NO_PROGRESS
    1
    LOG_CONFIGURE
    1
    LOG_BUILD
    1
    LOG_INSTALL
    1
    )