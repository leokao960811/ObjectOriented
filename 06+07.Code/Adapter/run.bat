cls

rem compile
md build
javac -d build *.java

rem run
java -cp build DuckTestDrive
pause

rem run
java -cp build TurkeyTestDrive
pause

rem clean
rd /s/q build