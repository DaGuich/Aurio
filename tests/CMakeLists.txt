add_executable(auriltest main.c)
target_link_libraries(auriltest PRIVATE cmocka PRIVATE auril)
add_test(auriltest auriltest)