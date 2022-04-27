#------------------------ Tool Specifications & Options ----------------------

COMPILER  =  lcc

CC        =  "C:\Program Files\MATLAB\R2021b\sys\lcc64\lcc64\bin\lcc64.exe"
LD        =  "C:\Program Files\MATLAB\R2021b\sys\lcc64\lcc64\bin\lcclnk64.exe"
LIBCMD    =  "C:\Program Files\MATLAB\R2021b\sys\lcc64\lcc64\bin\lcclib64.exe"
CFLAGS    =  -dll -noregistrylookup  -c -Zp8 -DLCC_WIN64 -DMATLAB_MEX_FILE -nodeclspec
LDFLAGS   =  -s -dll -entry LibMain heHADKpvsIONXN8Jrnl0qB_cclib.def -L"C:\Program Files\MATLAB\R2021b\sys\lcc64\lcc64\lib64"

OBJECTS = \
	   acados_wrapper.obj \
	   slcc_interface_heHADKpvsIONXN8Jrnl0qB.obj \
	   lccstub.obj \

STATICLIBS = \

#------------------------------ Include/Lib Path ------------------------------

INCLUDE_PATH = \
     -I"c:\program files\matlab\r2021b\extern\include" \
     -I"c:\program files\matlab\r2021b\simulink\include" \
     -I"c:\users\mario bertelli\desktop\tv_test\tvtests\codicegenerato\slprj\_slcc\hehadkpvsionxn8jrnl0qb" \
     -I"c:\users\mario bertelli\desktop\tv_test\tvtests\itb_nucleo_configuration\inc" \
     -I"c:\users\mario bertelli\desktop\tv_test\tvtests\codicegenerato" \
     -I"c:\users\mario bertelli\desktop\tv_test\tvtests" \
     -I"c:\users\mario bertelli\desktop\tv_test\tvtests\itb_nucleo_configuration\src" \
     -I"c:\program files\matlab\r2021b\sys\lcc64\lcc64\include64" \
     -I"c:\program files\matlab\r2021b\sys\lcc64\lcc64\mex" \

#--------------------------------- Rules --------------------------------------

heHADKpvsIONXN8Jrnl0qB_cclib.dll : $(MAKEFILE) $(OBJECTS)
	$(LD) $(LDFLAGS) /OUT:heHADKpvsIONXN8Jrnl0qB_cclib.dll $(OBJECTS)  $(STATICLIBS) "C:\Program Files\MATLAB\R2021b\extern\lib\win64\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2021b\extern\lib\win64\microsoft\libmx.lib"
acados_wrapper.obj :	c:\users\MARIOB~1\desktop\tv_test\tvtests\ITB_NU~1\Src\ACADOS~2.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "c:\users\mario bertelli\desktop\tv_test\tvtests\ITB_Nucleo_configuration\Src\acados_wrapper.c"
slcc_interface_heHADKpvsIONXN8Jrnl0qB.obj :	C:\Users\MARIOB~1\Desktop\TV_Test\TVTests\CODICE~1\slprj\_slcc\HEHADK~1\SLCC_I~1.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Users\Mario Bertelli\Desktop\TV_Test\TVTests\CodiceGenerato\slprj\_slcc\heHADKpvsIONXN8Jrnl0qB\slcc_interface_heHADKpvsIONXN8Jrnl0qB.c"
lccstub.obj :	C:\PROGRA~1\MATLAB\R2021b\sys\lcc64\lcc64\mex\lccstub.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2021b\sys\lcc64\lcc64\mex\lccstub.c"
