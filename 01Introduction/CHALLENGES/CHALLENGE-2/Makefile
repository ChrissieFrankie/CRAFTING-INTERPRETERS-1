# default target without specifying a target
all: HelloWorld.class 

# HelloWorld.class depends on HelloWorld.java, when HelloWorld.java is newer than HelloWorld.class/inexistant execute javac HelloWorld.java
HelloWorld.class: HelloWorld.java
		javac HelloWorld.java 		

# run target depends on HelloWorld.class, check dependency, execute java HelloWorld
run: HelloWorld.class 
		java HelloWorld

# clean target
clean:
		del /Q /F *.class