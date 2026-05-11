cls

rem compile
md build
javac -d build *.java

rem run
java -cp build Test
pause

rem clean
rd /s/q build