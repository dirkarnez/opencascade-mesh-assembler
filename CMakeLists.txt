set(CAS_ROOT "") # "$ENV{USERPROFILE}\Downloads\occt-combined-release-no-pch\occt-vc14-64-combined\occt-vc14-64"
set(OpenCASCADE_DIR ${CAS_ROOT}/cmake)
find_package(OpenCASCADE REQUIRE)
include_directories(${OpenCASCADE_INCLUDE_DIR})

target_include_directories(cascadio PUBLIC
   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/upstream/OCCT/include/opencascade>
   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/upstream/OCCT/inc>)

 # Set path to executable directories
 target_link_directories(
   cascadio PUBLIC
   "${CMAKE_CURRENT_SOURCE_DIR}/upstream/OCCT/win64/gcc/lib"
   "${CMAKE_CURRENT_SOURCE_DIR}/upstream/OCCT/win64/vc14/lib"
   "${CMAKE_CURRENT_SOURCE_DIR}/upstream/OCCT/lin64/gcc/lib"
   "${CMAKE_CURRENT_SOURCE_DIR}/upstream/OCCT/lin32/gcc/lib"
   "${CMAKE_CURRENT_SOURCE_DIR}/upstream/OCCT/mac64/clang/lib"
 )
  
# Add all possible libraries we might need
target_link_libraries(cascadio PRIVATE
 TKCAF TKPrim TKShHealing TKDEPLY TKRWMesh TKBinL TKBRep TKVCAF TKDESTL TKCDF TKTObj TKMath TKHLR TKBinTObj TKFillet TKOffset TKStd TKV3d TKFeat TKBO TKGeomBase TKernel TKStdL TKG3d TKBin TKService TKDE TKExpress TKGeomAlgo TKDEIGES TKDEGLTF TKLCAF TKDEVRML TKXmlL TKXCAF TKDECascade TKXSBase TKDESTEP TKG2d TKBool TKTopAlgo TKXml TKXmlXCAF TKDEOBJ TKXMesh TKXmlTObj TKBinXCAF TKMesh
)
