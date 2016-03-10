rem @echo off
SET program="%1"
if %program% == "" goto err

%program% > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt FewArguments.txt
if ERRORLEVEL 1 goto testFailed

%program% 10> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt FewArguments.txt
if ERRORLEVEL 1 goto testFailed

%program% 5 12> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt FewArguments.txt
if ERRORLEVEL 1 goto testFailed

%program% 1 3 -4> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt TwoRoots.txt
if ERRORLEVEL 1 goto testFailed

%program% 10 5 4 12> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt manyArguments.txt
if ERRORLEVEL 1 goto testFailed

%program% help > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt help.txt
if ERRORLEVEL 1 goto testFailed

%program% 0 2 1 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt NotQuadraticEquation.txt
if ERRORLEVEL 1 goto testFailed

%program% 2 4 2 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt OneRoot.txt
if ERRORLEVEL 1 goto testFailed

%program% 5 1 10 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt NoRoots.txt
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>