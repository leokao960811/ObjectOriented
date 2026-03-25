cls

rem compile
md build
javac -d build *.java

rem run
java -cp build Test
pause

rem add new class
copy newclass/DualMajor.java .
javac -d build DualMajor.java

rem uncomment the line in Test.java that references DualMajor and recompile and re-run
pause
javac -d build Test.java
java -cp build Test
pause

rem clean
del DualMajor.java
rd /s/q build

rem re-comment the line in Test.java that references DualMajor