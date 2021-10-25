## copied from ATL/Examples/MixedEffects/OrangeTree
#
## -*- Makefile -*-
##
## User: matthew
## Time: Jun 25, 2015 9:07:06 AM
## Makefile created by Oracle Solaris Studio.
##
## This file is generated automatically.
##


#### Compiler and tool definitions shared by all build targets #####
CCC = c++
CXX = c++
BASICOPTS = -O3 -s -m64
CCFLAGS = -std=c++14
CXXFLAGS =-O3 -std=c++14
CCADMIN = 


# Define the target directories.
TARGETDIR_ATL_goa_wp=build


all: $(TARGETDIR_ATL_goa_wp)/ATL_goa_wp

## Target: ATL_goa_wp
OBJS_ATL_goa_wp =  \
	$(TARGETDIR_ATL_goa_wp)/main.o
USERLIBS_ATL_goa_wp = $(SYSLIBS_ATL_goa_wp)
DEPLIBS_ATL_goa_wp =
LDLIBS_ATL_goa_wp = $(USERLIBS_ATL_goa_wp)


# Link or archive
$(TARGETDIR_ATL_goa_wp)/ATL_goa_wp: $(TARGETDIR_ATL_goa_wp) $(OBJS_ATL_goa_wp) $(DEPLIBS_ATL_goa_wp)
	$(LINK.cc) $(CCFLAGS_ATL_goa_wp) $(CPPFLAGS_ATL_goa_wp) -o $@ $(OBJS_ATL_goa_wp) $(LDLIBS_ATL_goa_wp)


# Compile source files into .o files
$(TARGETDIR_ATL_goa_wp)/main.o: $(TARGETDIR_ATL_goa_wp) main.cpp
	$(COMPILE.cc) $(CCFLAGS_ATL_goa_wp) $(CPPFLAGS_ATL_goa_wp) -o $@ main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_ATL_goa_wp)/ATL_goa_wp \
		$(TARGETDIR_ATL_goa_wp)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_ATL_goa_wp)


# Create the target directory (if needed)
$(TARGETDIR_ATL_goa_wp):
	mkdir -p $(TARGETDIR_ATL_goa_wp)


# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Linux

run : ${Target}
	./$(TARGETDIR_ATL_goa_wp)/ATL_goa_wp

