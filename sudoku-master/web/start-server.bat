@echo off
cd /d %~dp0
powershell -Command "Start-Process powershell -ArgumentList 'cd \"%CD%\"; python -m http.server 8000' -NoNewWindow"
echo Server started at http://localhost:8000
pause
