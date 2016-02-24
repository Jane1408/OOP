rem @echo off
SET program="%1"
if %program% == "" goto err

%program% > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt fewArguments.txt
if ERRORLEVEL 1 goto testFailed

%program% CheckInput.txt > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt fewArguments.txt
if ERRORLEVEL 1 goto testFailed

%program% CheckInput.txt output.txt > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt fewArguments.txt
if ERRORLEVEL 1 goto testFailed

%program% CheckInput.txt output.txt word1 word2 word3 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt manyArguments.txt
if ERRORLEVEL 1 goto testFailed

%program% help > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt help.txt
if ERRORLEVEL 1 goto testFailed

%program% CheckInput.txt output.txt ma> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe output.txt OnlyRewrite.txt
if ERRORLEVEL 1 goto testFailed

%program% CheckInput.txt output.txt ma mama> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe output.txt ReplaceAndRewrite.txt
if ERRORLEVEL 1 goto testFailed

%program% CheckBadInput.txt output.txt ma mama> out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt NotFound.txt
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>