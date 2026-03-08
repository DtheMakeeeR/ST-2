add_executable(${PROJECT_NAME}.test
    AllTests.cpp
    tests.cpp
)

target_link_libraries(${PROJECT_NAME}.test
    PRIVATE
    ${PROJECT_NAME}
    GTest::gtest_main
)

target_compile_definitions(${PROJECT_NAME}.test
    PRIVATE
    TEST_DIR="${CMAKE_CURRENT_LIST_DIR}"
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}.test)

install(TARGETS ${PROJECT_NAME}.test
    DESTINATION "${tool_dest}"
)