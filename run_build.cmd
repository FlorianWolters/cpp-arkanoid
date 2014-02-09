@ECHO OFF

REM COPYRIGHT (C) Florian Wolters 2014
REM
REM Author: Florian Wolters <wolters.fl@gmail.com>

CLS
SET PATH_BUILD=%~dp0build
SET MAKE_VERBOSE=OFF

IF /I "%1"=="clean" GOTO CleanBuildDirectory
GOTO WalkIntoBuildDirectory

:CleanBuildDirectory
RD /S /Q %PATH_BUILD% > NUL

:WalkIntoBuildDirectory
MD %PATH_BUILD% > NUL
PUSHD %PATH_BUILD%

cmake -G "Unix Makefiles" -D CMAKE_VERBOSE_MAKEFILE=%MAKE_VERBOSE% -Wno-dev --warn-uninitialized --warn-unused-vars --check-system-vars ..
IF ERRORLEVEL 1 (
     ECHO.
     ECHO An error occured running CMake!
     ECHO.
     GOTO OnErrorHandler
)

make
IF ERRORLEVEL 1 (
     ECHO.
     ECHO An error occured running Make!
     ECHO.
     GOTO OnErrorHandler
)

ctest
IF ERRORLEVEL 1 (
     ECHO.
     ECHO An error occured running CTest!
     ECHO.
     GOTO OnErrorHandler
)

cpack
IF ERRORLEVEL 1 (
     ECHO.
     ECHO An error occured running CPack!
     ECHO.
     GOTO OnErrorHandler
)

GOTO OnExitHandler

:OnErrorHandler
ECHO.
ECHO One or more errors occured during the build! Check the output and eventually set the variable MAKE_VERBOSE to ON.
ECHO.
PAUSE

:OnExitHandler
POPD
