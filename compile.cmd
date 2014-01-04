REM COPYRIGHT (C) Florian Wolters 2014
REM
REM Author: Florian Wolters <wolters.fl@gmail.com>

@ECHO OFF

SET PROJECT_NAME=arkanoid
SET PATH_BUILD=build

RD /S /Q %PATH_BUILD%
MD %PATH_BUILD%

cmake -Wno-dev --warn-uninitialized --warn-unused-vars --check-system-vars -G"MSYS Makefiles"
make
START "" "%PATH_BUILD%\%PROJECT_NAME%.exe" & EXIT
