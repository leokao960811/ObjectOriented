cls

rem compile
md build
javac -d build *.java

rem run
java -cp build identity
pause

rem clean
rd /s/q build