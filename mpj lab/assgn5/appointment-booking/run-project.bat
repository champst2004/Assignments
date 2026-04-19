@echo off
setlocal

set "PROJECT_DIR=%~dp0"
set "TOMCAT_DIR=D:\Projects\REPOs\Assignments\mpj lab\assgn5\tomcat\apache-tomcat-9.0.87"
set "WAR_NAME=appointment-booking.war"

echo Building appointment-booking project...
cd /d "%PROJECT_DIR%"
call mvn clean package
if errorlevel 1 (
    echo Build failed. Please check Maven/Java setup.
    exit /b 1
)

echo Deploying WAR to Tomcat...
copy /Y "%PROJECT_DIR%target\%WAR_NAME%" "%TOMCAT_DIR%\webapps\%WAR_NAME%" >nul
if errorlevel 1 (
    echo Deployment failed. Could not copy WAR to Tomcat webapps.
    exit /b 1
)

echo Starting Tomcat...
cd /d "%TOMCAT_DIR%\bin"
call startup.bat
if errorlevel 1 (
    echo Tomcat startup command failed.
    exit /b 1
)

echo.
echo Project is starting.
echo Open: http://localhost:8080/appointment-booking/
echo.
pause
