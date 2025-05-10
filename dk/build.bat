SET "TKPATH=../../../MexTK/"
SET "FLPATH=../../../../files/"

:: compile main code, found in the src folder
"%TKPATH%MexTK.exe" -ff -i "src/dk.c" -s ftFunction -dat "%FLPATH%PlDk.dat" -ow

pause