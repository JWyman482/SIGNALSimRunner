@ECHO OFF
SET starttime=%time%

CLS
ECHO Is this a standalone sim? (i.e. Trainer/pilot and Trainee at this scope, running Charter here?)
ECHO 1) Yes
ECHO 2) No
Set /p stand="Choice: "
IF "%stand%" == "1" GOTO stand

CLS
ECHO Please select your scope display.
ECHO 1) BASIC
ECHO 2) PILOT
ECHO 3) ARTS
ECHO 4) PAR
SET /P display="Choice: "
IF "%display%" == "4" GOTO PAR

CLS
ECHO Which computer is running charter?
ECHO 1) Pilot Computer
ECHO 2) Center Computer
ECHO 3) Assist Computer
ECHO 4) Approach Computer
ECHO 5) This Computer
SET /P charter="Choice: "

CLS
ECHO Please select your exercise slot from Charter.
ECHO 1) 001
ECHO 2) 002
ECHO 3) 003
ECHO 4) 004
SET /P exercise="Choice: "

IF "%display%" == "1" START /WAIT SimRunner BASIC %exercise% %charter%
IF "%display%" == "2" START /WAIT SimRunner PILOT %exercise% %charter%
IF "%display%" == "3" START /WAIT SimRunner ARTS %exercise% %charter%
GOTO disp

:stand
START /WAIT SimRunner PILOT 1 5
START /WAIT pilot.exe
GOTO end

:PAR
cd..
cd PAR
START /WAIT PAR.lnk
GOTO end

:disp
IF "%display%" == "1" START /WAIT basic.exe
IF "%display%" == "2" START /WAIT pilot.exe
IF "%display%" == "3" (
	START /WAIT CommonArts.exe
	START /WAIT DEDEM.exe
)


:end
CLS
REM *********************TIMER***************
SET endtime=%time%

SET /A hrs=%endtime:~0,2%
SET /A hrs=%hrs%-%starttime:~0,2%

SET /A mins=%endtime:~3,2%
SET /A mins=%mins%-%starttime:~3,2%

IF %mins% lss 0 (
	SET /A mins=!mins!+60
	SET /A hrs=!hrs!-1
)

IF %hrs% lss 0 (
	SET /A hrs=!hrs!+24
)

ECHO TIME SIM WAS RAN:
ECHO Hours: %hrs%
ECHO Minutes: %mins%
REM *****************************************
PAUSE

exit
END: