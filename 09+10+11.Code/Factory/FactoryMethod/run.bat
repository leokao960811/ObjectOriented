cls

rem compile
md build
javac -d build *.java

rem run
java -cp build PizzaTestDrive
pause

rem clean
rd /s/q build