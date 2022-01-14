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
1005,Sharon,Wang
1002,Tim,Harker
1003,Rose,Peterson
1001,Paul,Smith
1004,Sharon,Peterson
-----------------------------------------------
Student Grade details file, csv file
Format: StudentID, Grade, Year, GPA
-----------------------------------------------
1001,10,2019,3.0
1001,9,2018,3.0
1002,12,2020,4.0
1002,9,2018,3.0
1003,12,2020,4.0
1003,11,2021,3.0
1003,10,2019,3.0
1003,9,2018,3.0
1002,11,2021,3.0
1002,10,2019,3.0
1001,12,2020,4.0
1001,11,2021,3.0
----------------------------------------------
Output
1001,Paul,9,3.000000,2018
1001,Paul,10,3.000000,2019
1001,Paul,11,3.000000,2021
1001,Paul,12,4.000000,2020
1002,Tim,9,3.000000,2018
1002,Tim,10,3.000000,2019
1002,Tim,11,3.000000,2021
1002,Tim,12,4.000000,2020
1003,Rose,9,3.000000,2018
1003,Rose,10,3.000000,2019
1003,Rose,11,3.000000,2021
1003,Rose,12,4.000000,2020
----------------------------------------------
```

# Hacking
- Clone this repository
- Install the required tools namely Oracle DB with ProC support
- Visual C++ or similar C compiler tools
- Compile the `demo.pc` using the ProC tool command: `proc demo.pc`. This will produce a C source file `demo.c`.
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
# Input validations
1. StudentId should be numeric
1. Each entry in Student file should have at least three parameters
2. Year between 2020-2050
3. GPA between 1-4
4. Grade between 9-12 ( high school!)
5. No validations for firstname and lastname other than strlen

# Test cases considered, implemented, tested manually. 
1. Input paramters not provided: code fails with error
2. Partial input provided ( one file ): code fails with error
3. Invalid data input file ( E.g. Studentid, firstname): code fails with error
4. Empty input file: code fails with error
5. Duplicates in input file ( code disregards duplicates)
   
   Student file: Student ID is the key for duplicate validation
   
   Detail file: StudentId, Grade is the key for duplicate validation
5. Firstname/lastname strlen > 100: code fails with error
6. Tested with duplicate entries: code continues processing
7. Tested with invalid entries: code fails with error

# Improvements that can be made
1. Delimiter should be made configurable
2. More validations for firstname/lastname (include not allowed character list)
3. For duplicate records, update the record with the latest entry in input file
4. Add more validations for gpa,grade,year ( numeric, range)



