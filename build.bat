REM delete the old bin contents
make clean

REM compile the game
make

REM copy content folder to bin
Xcopy ".\content\*" ".\bin\content\\"

REM copy SDL2.dll to bin
Xcopy ".\SDL2.dll" ".\bin\SDL2.dll*"

REM run the game
make run
