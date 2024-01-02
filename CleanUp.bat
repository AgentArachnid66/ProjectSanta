@ECHO OFF

rem Clean Up project files

del /Q /S CatAndMouse.sln
del /Q /S Build\Beta\*.*
del /Q /S Build\Stable\*.*
del /Q /S Binaries\*.*
del /Q /S Intermediate\*.*
del /Q /S Saved\*.*
del /Q /S Platforms\*.*
del /Q /S DerivedDataCache\*.*
del /Q /S .vsconfig

ECHO ...
ECHO Binary files deleted
ECHO Cleaning up folders

rmdir /Q /S Binaries
rmdir /Q /S Intermediate
rmdir /Q /S Saved
rmdir /Q /S Platforms
rmdir /Q /S DerivedDataCache
rmdir /Q /S .idea
rmdir /Q /S .vs

PAUSE