
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[8];
};
static const struct sqlcxp sqlfpn =
{
    7,
    "demo.pc"
};


static unsigned int sqlctx = 8835;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
            void  *sqhstv[5];
   unsigned int   sqhstl[5];
            int   sqhsts[5];
            void  *sqindv[5];
            int   sqinds[5];
   unsigned int   sqharm[5];
   unsigned int   *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {13,5};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

 static const char *sq0007 = 
"select A.STUDENTID ,FIRSTNAME ,GRADE ,GPA ,YEAR  from STUDENT A ,STUDENTDETA\
ILS B where A.STUDENTID=B.STUDENTID order by A.STUDENTID,GRADE            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,178,0,0,
5,0,0,1,21,0,2,224,0,0,0,0,0,1,0,
20,0,0,2,59,0,4,298,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
43,0,0,3,89,0,3,307,0,0,3,3,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,
70,0,0,4,28,0,2,367,0,0,0,0,0,1,0,
85,0,0,5,82,0,4,437,0,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,
112,0,0,6,78,0,3,446,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,4,0,0,
143,0,0,7,150,0,9,517,0,0,0,0,0,1,0,
158,0,0,7,0,0,13,525,0,0,5,0,0,1,0,2,3,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,3,0,0,
193,0,0,7,0,0,15,543,0,0,0,0,0,1,0,
208,0,0,0,0,0,27,572,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,10,0,0,1,10,0,0,
239,0,0,9,0,0,30,657,0,0,0,0,0,1,0,
254,0,0,10,0,0,32,670,0,0,0,0,0,1,0,
};


/*------------------------------------------------------------------------------
Name: Deepali Abhyankar
Date: 2022/01/12
Details: 
Program to consolidate data from two input files. Code reads the input files and
loads them to database tables. The database tables are then joined to generate
the output. This demo highlights C, Pro*c, PL/SQL, Oracle Database. 

Tables:Student, Student Details

Input: 
a) Student input file.
Format: StudentID, FirstName, LastName
e.g.
1001,Paul,Smith
1002,Tim,Harker

b) Student Detail file. 
Format: StudentID, Grade, Year, GPA
e.g
1001,10,2020,4.0
1001,11,2021,3.0
1001,8,2019,3.0
1001,9,2018,3.0
1002,10,2020,4.0
1002,11,2021,3.0

c) Delimiter for input is comma (,). 

Execution: 
democlient  filename1   filename2 filename3(optional)
   Required parameters: 
      filename1 - Student file containg StudentID and Name
	  filename2 - Student detail file containg grades
      filename3 - Optional, output will be writen to this file if provided
                - default output to stdout
------------------------------------------------------------------------------*/
#pragma warning(disable : 4996) /* pragma to supress warning for using scanf */
/* exec sql include sqlca;
 */ 
/*
 * $Header: precomp/public/sqlca.h /nt/2 2020/07/19 18:53:20 dgoddard Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>


#define DELIMITER ","
#define ERROR -1
#define SUCCESS 0
#define READ_MODE "r"
#define WRITE_MODE "w"
#define FILE_LENGTH 200
#define INT_MAX_STR "2147483647"

//-----------------------------------------------
// DECLARE SQL variables
//------------------------------------------------
/* EXEC SQL BEGIN DECLARE SECTION; */ 

char user_name[20],password[20];

struct student_details 
{ 
    int      studentid; 
    char     firstname[100];
    int      grade; 
    float    gpa;
    int      year;
}; 
struct student_details *student_record; 

char firstname[100]; 
char lastname[100]; 
int studentid; 
int reccount;
int grade; 
int year; 
float gpa;

/* EXEC SQL END DECLARE SECTION; */ 

//--------------------------------------------------
// END OF PL/SQL declare
//-------------------------------------------------

//-------------------------------------
// print oracle error
//-------------------------------------
int errrpt( void )
{
   printf("%.70s (%d)\n", sqlca.sqlerrm.sqlerrmc, -sqlca.sqlcode);
   return(0);
}

//--------------------------------------------------
// code to remove extra spaces from string on left
//-------------------------------------------------
char *ltrim(char *inp)
{
    while(isspace(*inp)) inp++;
    return inp;
}

//---------------------------------------------------
// code to remove extra spaces from string on right
//---------------------------------------------------
char *rtrim(char *inp)
{
    char* m = inp + strlen(inp);
    while(isspace(*--m));
    *(m+1) = '\0';
    return inp;
}

//------------------------------------------
// open file
// Input: Filename, MODE
// MODE = READ/WRITE/APPEND
//------------------------------------------
FILE * openfile( char *filename, char* MODE)
{
    printf("\nINFO: Opening file %s", filename);

    FILE *fp = fopen(filename, MODE);
    if( fp == NULL)
    {
        printf("\nUnable to open file %s, ", filename);
        return NULL; 
    }
    return fp; 
}

//---------------------------------------------------
// validat studentid parameter
//--------------------------------------------------
int validateStudentid( char* studentid, int count)
{

  //-----------------------------
  // check all chars are digits
  //-----------------------------
  int i=0;
  while(i<strlen(studentid) )
  {
     
     if(studentid[i] > 57 || studentid[i] < 48)
     {
        printf("\nERROR: Invalid StudentID in row %d. Please validate data", count);
        return ERROR;
     }
    i++;
  }

  if(studentid <=0 || strlen(studentid) > 10 || strcmp( studentid, INT_MAX_STR) > 0)
  {
       printf("\nERROR: Invalid StudentID in row %d. Please validate data", count);
       return ERROR;
  }

   return SUCCESS;
}

//---------------------------------------------------
// validat input parameters
//--------------------------------------------------
int validateInput( char *studentid, int year, float gpa, int grade, int count )
{
        if(validateStudentid( studentid, count) == ERROR)
        {
            return ERROR;
        }
        if ( year < 2010 || year > 2050)
        {
            printf("\nERROR: Invalid year in row %d. Please validate data", count);
            return ERROR;
        }
        if ( gpa < 1.0 || gpa > 4.0)
        {
            printf("\nERROR: Invalid gpa %f in row %d. Please validate data", gpa,count);
            return ERROR;
        }
        if ( grade < 9 || grade > 12)
        {
            printf("\nERROR: Invalid grade in row %d. Valid high school grade 9,10,11,12", count);
            return ERROR;
        }

        return SUCCESS;

}

 
//-----------------------------------------------------------------
// Routine to read Student master data to table
// Input: FileName
// Output: Data loaded to Student table
// Note: Student table is truncated prior to load
// 
// Processing: 
// - Open input file
// - Truncate Student table
// - For each entry in input file
//     - parse to get StudentId, Firstname, lastname
//     - Validate input data
//     - Check if record already exits in Student table for StudentId
//     - If not, then insert
//-----------------------------------------------------------------
int readStudentid( char *filename)
{
     char dataBuffer[1000];
     char student[3][200];
     char *token;
     int count = 0;
     int insertedreccount = 0;
     int i = 0;

    //------------------------------------------
    // open file
    //------------------------------------------
    FILE *fp = openfile( filename, READ_MODE); 
    if( fp == NULL) return ERROR;

    //------------------------------------------
    // delete data from Student table 
    //------------------------------------------
    /* EXEC SQL DELETE FROM STUDENT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "delete  from STUDENT ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    //------------------------------------------------------
    // Read each record in input file and load to DB table
    //------------------------------------------------------
    while (fgets(dataBuffer,1000, fp)!=NULL)
    {    
    
        //-----------------------
        // increment record count
        //-----------------------
        count++; 

        //----------------------------------------
        // set all values to NULL
        //----------------------------------------
        for( int i = 0; i < 3; i++)
         strcpy(student[i], "");


        //-------------------------------------
        // input values are comma delimited
        //-------------------------------------
        i = 0; 
        token = strtok(dataBuffer, DELIMITER);   
        while( token != NULL && i < 3) 
        {
           strncpy( student[i], token, 200 );
           i++;
           token = strtok(NULL, DELIMITER);
        }

        //---------------------------------
        // each record should have 3 fields
        //--------------------------------
        if( i < 3)
        {

               printf("\nERROR: Please validate data in row %d of input file. Incorrect number of parameters for record. ", count);
               goto ERRORLOC;
        }

        //--------------------------------------------
        // check if any of the values are null
        //--------------------------------------------
         for( int i = 0; i < 3; i++)
         {
            if( strcmp( student[i], "") == 0  || strlen(student[i]) == 0) 
            {
               printf("\nERROR: Please validate data in row %d of input file. Empty values not allowed", count);
               goto ERRORLOC;
            }

         }

        //--------------------------------------------
        // check for numeric and valid length
        //--------------------------------------------
        if( validateStudentid(student[0], count) == ERROR) 
        {
            goto ERRORLOC;
        }
        if( strlen(student[1]) > 100 || strlen(student[2]) > 100) 
        {
            printf("\nERROR: Please validate data in row %d of input file. FirstName, LastName should be less than 100 charaters", count);
            goto ERRORLOC;
        }
        strcpy( firstname,student[1] );
        strcpy( lastname,student[2] );
        studentid = atoi(student[0]); 

        //---------------------------------------------
        // check if record already exists
        //---------------------------------------------
         /* EXEC SQL SELECT COUNT(*) INTO :reccount FROM STUDENT  WHERE STUDENTID = :studentid; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 13;
         sqlstm.arrsiz = 2;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "select count(*)  into :b0  from STUDENT where STUDEN\
TID=:b1";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )20;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.sqlpfmem = (unsigned int  )0;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqhstv[0] = (         void  *)&reccount;
         sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         void  *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned int  )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (         void  *)&studentid;
         sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         void  *)0;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned int  )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqphss = sqlstm.sqhsts;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqpins = sqlstm.sqinds;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlstm.sqpadto = sqlstm.sqadto;
         sqlstm.sqptdso = sqlstm.sqtdso;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        //-------------------------------------
        // validate and insert to table
        //-------------------------------------
        if( reccount == 0)
        {
           printf("\n %d) Record being inserted to Student table", count);
           insertedreccount++;
           /* EXEC SQL INSERT INTO STUDENT(STUDENTID,FIRSTNAME,LASTNAME) VALUES ( trim(:studentid),trim(:firstname),trim(:lastname)); */ 

{
           struct sqlexd sqlstm;
           sqlstm.sqlvsn = 13;
           sqlstm.arrsiz = 3;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.stmt = "insert into STUDENT (STUDENTID,FIRSTNAME,LASTNAME)\
 values (trim(:b0),trim(:b1),trim(:b2))";
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )43;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)4352;
           sqlstm.occurs = (unsigned int  )0;
           sqlstm.sqhstv[0] = (         void  *)&studentid;
           sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         void  *)0;
           sqlstm.sqinds[0] = (         int  )0;
           sqlstm.sqharm[0] = (unsigned int  )0;
           sqlstm.sqadto[0] = (unsigned short )0;
           sqlstm.sqtdso[0] = (unsigned short )0;
           sqlstm.sqhstv[1] = (         void  *)firstname;
           sqlstm.sqhstl[1] = (unsigned int  )100;
           sqlstm.sqhsts[1] = (         int  )0;
           sqlstm.sqindv[1] = (         void  *)0;
           sqlstm.sqinds[1] = (         int  )0;
           sqlstm.sqharm[1] = (unsigned int  )0;
           sqlstm.sqadto[1] = (unsigned short )0;
           sqlstm.sqtdso[1] = (unsigned short )0;
           sqlstm.sqhstv[2] = (         void  *)lastname;
           sqlstm.sqhstl[2] = (unsigned int  )100;
           sqlstm.sqhsts[2] = (         int  )0;
           sqlstm.sqindv[2] = (         void  *)0;
           sqlstm.sqinds[2] = (         int  )0;
           sqlstm.sqharm[2] = (unsigned int  )0;
           sqlstm.sqadto[2] = (unsigned short )0;
           sqlstm.sqtdso[2] = (unsigned short )0;
           sqlstm.sqphsv = sqlstm.sqhstv;
           sqlstm.sqphsl = sqlstm.sqhstl;
           sqlstm.sqphss = sqlstm.sqhsts;
           sqlstm.sqpind = sqlstm.sqindv;
           sqlstm.sqpins = sqlstm.sqinds;
           sqlstm.sqparm = sqlstm.sqharm;
           sqlstm.sqparc = sqlstm.sqharc;
           sqlstm.sqpadto = sqlstm.sqadto;
           sqlstm.sqptdso = sqlstm.sqtdso;
           sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        }
        else
        {
            printf("\nINFO: Duplicate StudentID Record in Row %d for StudentID %d in table STUDENT", count,studentid );
        }
    }
    //-----------------------------------------
    // check if input file had any data
    //-----------------------------------------
    if( insertedreccount == 0)
    {
        printf("\nERROR: No data inserted to StudentID table. Please validate input");
        goto ERRORLOC;
    }

//----------------return-----------------------------------
if( fp!= NULL) fclose(fp);
return 0;     

ERRORLOC:
    if( fp!= NULL) fclose(fp);
    return ERROR;
    

}

//-----------------------------------------------------------------
// Routine to read Student grade details data to table
// Input: FileName
// Output: Data loaded to StudentDetails table
// Note: StudentDetails table is truncated prior to load
// 
// Processing: 
// - Open input file
// - Truncate StudentDetails table
// - For each entry in input file
//     - parse to get StudentId, Grade, Year,GPA
//     - Validate input data
//     - Check if record already exits table for StudentId, Grade
//     - If not, then insert
//-----------------------------------------------------------------
int readStudentDetails( char *filename)
{
     char dataBuffer[1000];
     char student[4][100];
     char *token;
     int count = 0;
     int i = 0;
     int insertedreccount = 0;

    //------------------------------------------
    // open file
    //------------------------------------------
    FILE *fp = openfile( filename, READ_MODE); 
    if( fp == NULL) return ERROR;

    //------------------------------------------
    // truncate existing data from table
    //------------------------------------------
    /* EXEC SQL DELETE FROM STUDENTDETAILS; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "delete  from STUDENTDETAILS ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )70;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    //------------------------------------------------------
    // Read each record in input file and load to DB table
    //------------------------------------------------------
    while (fgets(dataBuffer,1000, fp)!=NULL)
    {    
    
        //-----------------------
        // increment record count
        //-----------------------
        count++; 

        //----------------------------------------
        // set all values to NULL
        //----------------------------------------
        for( int i = 0; i < 4; i++)
         strcpy(student[i], "");


        //-------------------------------------
        // input values are comma delimited
        //-------------------------------------
        i = 0; 
        token = strtok(dataBuffer, DELIMITER);   
        while( token != NULL && i < 4) 
        {
           strcpy( student[i], token );
           i++;
           token = strtok(NULL, DELIMITER);
        }

        //---------------------------------
        // each recod should have 4 fields
        //--------------------------------
        if( i < 4)
        {
		
           printf("\nERROR: Please validate data in row %d of input file. Invalid number of input parameters", count);
           goto ERRORLOC;
        }

        //--------------------------------------------
        // check if any of the values are null
        //--------------------------------------------
         for( int i = 0; i < 4; i++)
         {
            if( strcmp( student[i], "") == 0  || strlen(student[i]) == 0) 
            {
               printf("\nERROR: Please validate data in row %d of input file. NULL values not allowed", count);
               goto ERRORLOC;
            }

         }

        //---------------------------------------------
        // validate input data
        //--------------------------------------------
        studentid = atoi(student[0]);
        grade =  atoi(student[1]);
        year =  atoi(student[2]);
        gpa  = atof( student[3]);
        if( validateInput(student[0], year, gpa , grade,count) == ERROR)
        {
            goto ERRORLOC;
        }

        //---------------------------------------------
        // check if record already exists
        //--------------------------------------------
        /* EXEC SQL SELECT COUNT(*) INTO :reccount FROM STUDENTDETAILS  WHERE STUDENTID = :studentid AND GRADE = :grade ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count(*)  into :b0  from STUDENTDETAILS where \
(STUDENTID=:b1 and GRADE=:b2)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )85;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)&reccount;
        sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)&studentid;
        sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)&grade;
        sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        //-----------------------------------------
        // insert to table if record does not exist
        //-----------------------------------------
        if( reccount == 0)
        {
           insertedreccount++;
           printf("\n %d) Record being inserted to Student Detail table", count);
           /* EXEC SQL INSERT INTO STUDENTDETAILS(STUDENTID,GRADE,YEAR, GPA) VALUES (:studentid,:grade,:year, :gpa); */ 

{
           struct sqlexd sqlstm;
           sqlstm.sqlvsn = 13;
           sqlstm.arrsiz = 4;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.stmt = "insert into STUDENTDETAILS (STUDENTID,GRADE,YEAR,G\
PA) values (:b0,:b1,:b2,:b3)";
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )112;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)4352;
           sqlstm.occurs = (unsigned int  )0;
           sqlstm.sqhstv[0] = (         void  *)&studentid;
           sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         void  *)0;
           sqlstm.sqinds[0] = (         int  )0;
           sqlstm.sqharm[0] = (unsigned int  )0;
           sqlstm.sqadto[0] = (unsigned short )0;
           sqlstm.sqtdso[0] = (unsigned short )0;
           sqlstm.sqhstv[1] = (         void  *)&grade;
           sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
           sqlstm.sqhsts[1] = (         int  )0;
           sqlstm.sqindv[1] = (         void  *)0;
           sqlstm.sqinds[1] = (         int  )0;
           sqlstm.sqharm[1] = (unsigned int  )0;
           sqlstm.sqadto[1] = (unsigned short )0;
           sqlstm.sqtdso[1] = (unsigned short )0;
           sqlstm.sqhstv[2] = (         void  *)&year;
           sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
           sqlstm.sqhsts[2] = (         int  )0;
           sqlstm.sqindv[2] = (         void  *)0;
           sqlstm.sqinds[2] = (         int  )0;
           sqlstm.sqharm[2] = (unsigned int  )0;
           sqlstm.sqadto[2] = (unsigned short )0;
           sqlstm.sqtdso[2] = (unsigned short )0;
           sqlstm.sqhstv[3] = (         void  *)&gpa;
           sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
           sqlstm.sqhsts[3] = (         int  )0;
           sqlstm.sqindv[3] = (         void  *)0;
           sqlstm.sqinds[3] = (         int  )0;
           sqlstm.sqharm[3] = (unsigned int  )0;
           sqlstm.sqadto[3] = (unsigned short )0;
           sqlstm.sqtdso[3] = (unsigned short )0;
           sqlstm.sqphsv = sqlstm.sqhstv;
           sqlstm.sqphsl = sqlstm.sqhstl;
           sqlstm.sqphss = sqlstm.sqhsts;
           sqlstm.sqpind = sqlstm.sqindv;
           sqlstm.sqpins = sqlstm.sqinds;
           sqlstm.sqparm = sqlstm.sqharm;
           sqlstm.sqparc = sqlstm.sqharc;
           sqlstm.sqpadto = sqlstm.sqadto;
           sqlstm.sqptdso = sqlstm.sqtdso;
           sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        }
        else
        {
            printf("\nINFO: Duplicate Student Detail Record in Row %d for StudentID %d,%d", count,studentid,grade  );
        }


  }   
 //-----------------------------------------
 // check if input file had any data
 //-----------------------------------------
 if( insertedreccount == 0)
 {
        printf("\nERROR: No data inserted to Student Detail table. Please validate input");
        goto ERRORLOC;
 }
//----------------------------------return--------------------------------------------
if( fp!= NULL) fclose(fp);
return 0;     

ERRORLOC:
    if( fp!= NULL) fclose(fp);
    return ERROR;

}

//--------------------------------------------------
// Routine to create a consolidated report
// Details: 
//   - Define cursor joing tables 
//         Student, StudentDetails on StudentID
//   - If outfile is not null 
//         open output file in write mode
//   - Open cursor
//       if output file opened
//            - add data to output file
//       else print data to stdout
//-------------------------------------------------
int createreport( char *outfile)
{

    //----------------------------
    // initialize memory 
    //----------------------------
    if ((student_record = 
        (struct student_details *) malloc(sizeof(struct student_details))) == 0)
    { 
        printf("Memory allocation error.\n"); 
        exit(EXIT_FAILURE); 
    } 

    //---------------------------------------------
    // open output file in write mode
    // File will be overriten if it already exists
    //----------------------------------------------
    FILE *fp = NULL;
    if( strlen(outfile) > 1)
    {
       fp = openfile( outfile, WRITE_MODE); 
       if( fp == NULL) return ERROR;
    }

    //-------------------------------------------------
    // declare cursor joining Student and Details table
    //-------------------------------------------------
    /* EXEC SQL DECLARE STDREPORT CURSOR FOR 
    SELECT A.STUDENTID, FIRSTNAME, GRADE, GPA, YEAR
    FROM STUDENT A, STUDENTDETAILS B 
    WHERE A.STUDENTID = B.STUDENTID
    ORDER BY A.STUDENTID, GRADE; */ 

    /* EXEC SQL OPEN STDREPORT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0007;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )143;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 


    //------------------------------------
    // process data
    //------------------------------------
    for (;;) 
    { 
        /* EXEC SQL FETCH STDREPORT INTO :student_record; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )158;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (           int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (         void  *)&student_record->studentid;
        sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)student_record->firstname;
        sqlstm.sqhstl[1] = (unsigned int  )100;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)&student_record->grade;
        sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (         void  *)&student_record->gpa;
        sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         void  *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned int  )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (         void  *)&student_record->year;
        sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         void  *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned int  )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
}

 
        if( fp == NULL)
        {
          printf("\n %d,%s, %d, %f, %d", student_record->studentid, ltrim( rtrim(student_record->firstname)), student_record->grade, 
          student_record->gpa, student_record->year);
        }
        else
        {        
          fprintf( fp, "%d,%s,%d,%f,%d\n", student_record->studentid, ltrim( rtrim(student_record->firstname)), student_record->grade, 
          student_record->gpa, student_record->year);
        }

    } 

    //--------------------------------------
    // close file, close cursor and return
    //--------------------------------------
    if( fp != NULL ) fclose(fp);
    /* EXEC SQL CLOSE STDREPORT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )193;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

 


//----------------------------------return--------------------------------------------
return 0;     

ERRORLOC:
    if( fp!= NULL) fclose(fp);
    return ERROR;


}

/*----------------------------------------------------------------
* Function to login to database
* getLoginDetails is an extern function to get userid and pwd
------------------------------------------------------------------*/
int dblogin()
{
    //------------------------------------------
    // extern function to get login credentials
    //------------------------------------------
    //getlogindetails();  
	strcpy(user_name, "system");
	strcpy(password, "or@cl321c");

    //-----------------------------------
    // login
    //-----------------------------------
  	/* exec sql connect:user_name identified by :password; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )10;
   sqlstm.offset = (unsigned int  )208;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (         void  *)user_name;
   sqlstm.sqhstl[0] = (unsigned int  )20;
   sqlstm.sqhsts[0] = (         int  )20;
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)password;
   sqlstm.sqhstl[1] = (unsigned int  )20;
   sqlstm.sqhsts[1] = (         int  )20;
   sqlstm.sqindv[1] = (         void  *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned int  )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlstm.sqlcmax = (unsigned int )100;
   sqlstm.sqlcmin = (unsigned int )2;
   sqlstm.sqlcincr = (unsigned int )1;
   sqlstm.sqlctimeout = (unsigned int )0;
   sqlstm.sqlcnowait = (unsigned int )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if (sqlca.sqlcode==0) {
		printf("success"); return SUCCESS; 
	}
	else {
		printf("Error code:%d\nError message:%s",sqlca.sqlcode,sqlca.sqlerrm.sqlerrmc);
        return ERROR; 
	}

}



//----------------------------------------------
// Main routine
//----------------------------------------------
int main (int argc, char *argv[]) {

    //-------------------------------------------------------------
    // check input arguments
    // 1. Input Student file - Required
    // 2. Student detail file - Required
    // 3. Output file - optional
    //                  o/p sent to stdout if file is not provided
    //--------------------------------------------------------------
    if( argc < 3)
    {
        printf("\nERROR: Input files not provided");
        printf("\nRequired parameters: ");
        printf("\n StudentFile - csv file containing student details ");
        printf("\n GradeFile   - csv file containing student grade details ");
        exit(0);
    }

    char inputfile1[FILE_LENGTH];
    char inputfile2[FILE_LENGTH];
    char outputfile[FILE_LENGTH];
    strncpy( inputfile1, argv[1], FILE_LENGTH);
    strncpy( inputfile2, argv[2], FILE_LENGTH);

    if( argc == 4)
    { 
       strncpy( outputfile, argv[3],FILE_LENGTH);
    }
    else 
    { 
       strcpy( outputfile, "");
    }
   
    
    //-------------------------------------
    // login to database
    //-------------------------------------
    /* EXEC SQL WHENEVER SQLERROR GOTO errexit; */ 

    if( dblogin() != SUCCESS) { goto errexit; }



    //-----------------------------------------------
    // read studentID information into table STUDENT
    //-----------------------------------------------
    int ret = readStudentid( inputfile1);
    if( ret != 0 )
    {
        goto CLEANUP; 
    }
    

    //----------------------------------------------
    // read student details to table STUDENTDETAILS
    //----------------------------------------------
    ret = readStudentDetails( inputfile2);
    if( ret != 0 )
    {
        goto CLEANUP; 
    }

    //-----------------------------------------------
    // get consolidated report
    //-----------------------------------------------
    ret = createreport(outputfile);

    //------------------------------------------
    // commit data in db
    //------------------------------------------
    /* EXEC SQL COMMIT WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )239;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto errexit;
}




//----------------------------
// close
//----------------------------
CLEANUP:
printf("\nProcessing completed.\n\n");
exit(EXIT_SUCCESS); 

errexit:
   errrpt();
   /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

   /* EXEC SQL ROLLBACK WORK RELEASE; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )254;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   return 1;
	
}
