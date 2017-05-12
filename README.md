Jump Rope City
==============

This repository is the continuation of the Jump Rope City project from my CS370 Software Engineering class at SUNY Polytechnic Institute. I decided to continue working, and in an effort to keep my teammates work in place I have decided to fork the repository and work from here.

## Development:

Development will continue as I have free time, there is a long road ahead to get to where this project should be. Many features to implement and some things to be tweaked. If you would like to experiment with this stuff I will leave instructions to run the program below.

## Build:

As of right not we are only guaranteeing that Jump Rope City can be built and run on a Linux machine. Jump Rope City sits within the miniAT file system. In order to do that please follow the steps below:

#### MiniAT:
In order to get things working you must go to the links below and follow their instructions for setup and building of miniAT.

	Download Instructions: http://www.miniat.org/download
	Build Instructions: http://www.miniat.org/getting-started/build
	
#### Jump Rope City:
From here you will clone Jump Rope City into the miniAT file structure, follow the commands below, this assumes that you copied MiniAT into your home directory.

	cd ~/miniat/system
	git clone https://github.com/AlwaysKamin/JumpRopeCity.git
	
Now that everything is set up in the correct directories and all of your dependencies are correctly installed you're all set to run the programs. View the Run section to see how this is done.

## Run:
So in order to run the program in its current state it is required that you pass in an assembly file. Now in order to do this you must first write an assembly file to control your character(MiniAT Robot). This can be done by following the assembly guidelines in the documents folder. Once you have the assembly file written you are going to save it to the directory:

	~/miniat/system/JumpRopeCity/AssemblyPrograms
	
Once placed here you will then edit your sconscript file which can be found in Jump Rope City's root directory. At the end of this file you will append a line that says buildMash('AssemblyPrograms/*YOURFILE.asm*'). From here we will finally be able to run the program, in order to do this please follow the commands below:

	cd ~/miniat
	scons
	./out/exe/JumpRopeCity *YOURFILE.bin*
	
