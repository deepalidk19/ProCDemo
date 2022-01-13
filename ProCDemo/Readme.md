# Introduction

- This code is a demonstration of the use of C, ProC to interact with Oracle Database.
- It consists of 2 tables, a C based program to read 2 delimiter separated files and ProC
  to insert data from the files into the tables and use PL/SQL to output data from the 
  tables as table joins and output to a file.

# Tools and technologies used

- C using compiler from Visual C++
- Oracle database with ProC
- ProC compiler tool installed as part of the Oracle Database

# Database table definition
```
//----------------------------------------------
// SQL tables used
//----------------------------------------------
create table student
(
studentid Integer,
firstname varchar2(100),
lastname varchar2(100)
);

create table studentdetails
(
studentid Integer,
Grade     Integer, 
Year      Integer, 
GPA       Float
);     
```

# Input files definition
```
----------------------------------------------
-- Input files
----------------------------------------------
Student Master file, csv file
Format: StudentID, FirstName, LastName
-----------------------------------------------
1001,Paul,Smith
1002,Tim,Harker
1003,Rose,Shuster
1004,Sharon,Peterson
1005,Sharon,Peterson
-----------------------------------------------
Student Grade details file, csv file
Format: StudentID, Grade, Year, GPA
-----------------------------------------------
1001,10,2020,4.0
1001,11,2021,3.0
1001,8,2019,3.0
1001,9,2018,3.0
1002,10,2020,4.0
1002,11,2021,3.0
1002,8,2019,3.0
1002,9,2018,3.0
1003,10,2020,4.0
1003,11,2021,3.0
1003,8,2019,3.0
1003,9,2018,3.0
----------------------------------------------
```

# Hacking
- Clone this repository
- Install the required tools namely Oracle DB with ProC support
- Visual C++ or similar C compiler tools
- Compile the `first.pc` using the ProC tool command: `proc first.pc`. This will produce a C source file `first.c`.
- Compile the C file using the C compiler or Visual C++
- Run the compiled exe file.
- Currently only tested on Windows.

# How to run the program 
- `democlient  filename1 filename2 outputfile`
- filename1: input file containing StudentID and Name
- filename2: input file containing student details like grades
- outputfile (optional): output file path. If one is not provided output is printed to stdout

## Execution example:     
```
Output will be written to report.dat:  C:\Users\ProCDemo\ProCDemo.exe  C:\Users\ProCDemo\student.dat C:\Users\ProCDemo\details.dat C:\Users\ProCDemo\report.dat
Output will be sent to stdout:  C:\Users\ProCDemo\ProCDemo.exe  C:\Users\ProCDemo\student.dat C:\Users\ProCDemo\details.dat C:\Users\ProCDemo\report.dat
```

# Test cases considered (but not implemented)
1. Input paramters not provided
2. Partial input provided ( one file ) 
3. Invalid data input file
