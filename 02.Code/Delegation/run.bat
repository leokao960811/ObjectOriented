cls

rem compile
md build
javac -d build *.java

rem run TestWithout
java -cp build TestWithout
pause

rem run Test
java -cp build Test
pause

rem clean
rd /s/q build