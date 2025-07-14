# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(GPUtilsTests LANGUAGES CXX)

# ---- Dependencies ----

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(GPUtils_test source/GPUtils_test.cpp)
target_link_libraries(
    GPUtils_test PRIVATE
    GPUtils_lib
    Catch2::Catch2WithMain
)
target_compile_features(GPUtils_test PRIVATE cxx_std_17)

catch_discover_tests(GPUtils_test)

# ---- End-of-file commands ----

add_folders(Test)
