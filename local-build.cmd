@REM run as Administrator
@echo off
cd /d %~dp0
set DOWNLOADS_DIR=%USERPROFILE%\Downloads
set DOWNLOADS_DIR_LINUX=%DOWNLOADS_DIR:\=/%

SET PATH=^
%DOWNLOADS_DIR%\PortableGit\bin;^
%DOWNLOADS_DIR%\winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64-9.0.0-r1\mingw64;^
%DOWNLOADS_DIR%\winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64-9.0.0-r1\mingw64\bin;^
%DOWNLOADS_DIR%\cmake-3.29.3-windows-x86_64\bin;

@REM set PATH=^
@REM D:\Softwares\winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64-9.0.0-r1\mingw64;^
@REM D:\Softwares\winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64-9.0.0-r1\mingw64\bin;^
@REM D:\Softwares\cmake-3.23.0-rc1-windows-x86_64\bin;

@REM cmake.exe -G"MinGW Makefiles" ^
cmake -G "Visual Studio 17 2022" -A x64 ^
-DCMAKE_BUILD_TYPE=Debug ^
-DOpenCASCADE_DIR="%DOWNLOADS_DIR_LINUX%/occt-combined-release-no-pch/occt-vc14-64-combined/occt-vc14-64/cmake" ^
-B./cmake-build &&^
cd cmake-build &&^
cmake --build . &&^
echo "Successful build"
pause
