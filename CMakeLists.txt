 set(CAS_ROOT "") # "$ENV{USERPROFILE}\Downloads\occt-combined-release-no-pch\occt-vc14-64-combined\occt-vc14-64"
 set(OpenCASCADE_DIR ${CAS_ROOT}/cmake)
 find_package(OpenCASCADE REQUIRE)
 include_directories(${OpenCASCADE_INCLUDE_DIR})
