SET "TKPATH=../../../MexTK/"
SET "FLPATH=../../../../files/"

:: compile main code, found in the src folder
"%TKPATH%MexTK.exe" -ff -i "src/luigi.c" -s ftFunction -dat "%FLPATH%PlLg.dat" -ow

pause