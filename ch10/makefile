# executable files for this directory
OBJECTS =  test.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include GNU_makefile_template

# one or more files in this directory includes a header
# defined in chapter 9
LOCFLAGS=-I ../9

# additional dependencies or rules follow --
# see makefile for chapter 2 for additional explanation if needed
test.exe: main.o TextQuery.o TextQuery.h
	$(CC) $(CCFLAGS) main.o TextQuery.o \
			-o test.exe

3ed_query.exe: 3ed_query.o 3ed_querymain.o 3ed_query.h ../8/get_openfile.o
	$(CC) $(CCFLAGS) 3ed_querymain.o 3ed_query.o \
	                ../8/get_openfile.o -o 3ed_query.exe

query.exe: TextQuery.o querymain.o TextQuery.h \
	          ../8/get_openfile.o ../7/mk_plural2.o
	$(CC) $(CCFLAGS) querymain.o TextQuery.o ../8/get_openfile.o \
		        ../7/mk_plural2.o -o query.exe

word_transform.exe: word_transform.o ../8/get_openfile.o
	$(CC) $(CCFLAGS) word_transform.o \
	                ../8/get_openfile.o -o word_transform.exe
