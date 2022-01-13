
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
           char  filnam[9];
};
static const struct sqlcxp sqlfpn =
{
    8,
    "first.pc"
};


static unsigned int sqlctx = 18667;


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

 static const char *sq0005 = 
"select A.STUDENTID ,FIRSTNAME ,GRADE ,GPA ,YEAR  from STUDENT A ,STUDENTDETA\
ILS B where A.STUDENTID=B.STUDENTID order by A.STUDENTID            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,178,0,0,
5,0,0,1,59,0,4,150,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
28,0,0,2,71,0,3,157,0,0,3,3,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,
55,0,0,3,82,0,4,251,0,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,
82,0,0,4,78,0,3,258,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,4,0,0,
113,0,0,5,144,0,9,285,0,0,0,0,0,1,0,
128,0,0,5,0,0,13,315,0,0,5,0,0,1,0,2,3,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,3,0,0,
163,0,0,5,0,0,15,324,0,0,0,0,0,1,0,
178,0,0,0,0,0,27,335,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,10,0,0,1,10,0,0,
209,0,0,7,0,0,30,405,0,0,0,0,0,1,0,
224,0,0,8,0,0,32,412,0,0,0,0,0,1,0,
};


#pragma warning(disable : 4996)
/* exec sql begin declare section; */ 

char user_name[20],password[20];
/* exec sql end declare section; */ 

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
/*system/or@cl321c*/


#define DELIMITER ","
#define ERROR -1
#define SUCCESS -0

//-----------------------------------------------
// DECLARE SQL variables
//------------------------------------------------
/* EXEC SQL BEGIN DECLARE SECTION; */ 



struct student_details 
{ 
    int      studentid; 
    char     firstname[50];
    int      grade; 
    float    gpa;
    int      year;
}; 
struct student_details *student_rec_ptr; 
char data[50];

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

int errrpt( void )
   {
   printf("%.70s (%d)\n", sqlca.sqlerrm.sqlerrmc, -sqlca.sqlcode);
   return(0);
   }

char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

 
//--------------------------------------------------
// Routine to read Student master data to table
//-------------------------------------------------
int readStudentid( char *filename)
{
     char dataBuffer[500];
     char student[3][100];
     char *token;
     int count = 0;
     int i = 0;

    //------------------------------------------
    // open file
    //------------------------------------------
    FILE *fp = fopen(filename, "r");
    if( fp == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        return ERROR; 
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
        while( token != NULL ) 
        {
           strcpy( student[i], token );
           i++;
           token = strtok(NULL, DELIMITER);
        }

        //---------------------------------
        // each recod should have 3 fields
        //--------------------------------
        if( i < 2)
        {
               printf("\nERROR: Please validate data in row %d of input file. NULL values not allowed", count);
               return ERROR;
        }

        //--------------------------------------------
        // check if any of the values are null
        //--------------------------------------------
         for( int i = 0; i < 3; i++)
         {
            if( strcmp( student[i], "") == 0  || strlen(student[i]) == 0) 
            {
               printf("\nERROR: Please validate data in row %d of input file. NULL values not allowed", count);
               return ERROR;
            }

         }

        //---------------------------------------------
        // check if record already exists
        //--------------------------------------------
         studentid = atoi(student[0]); 
         strcpy( firstname,student[1] );
         strcpy( lastname,student[2] );

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
         sqlstm.offset = (unsigned int  )5;
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
           /* EXEC SQL INSERT INTO STUDENT(STUDENTID,FIRSTNAME,LASTNAME) VALUES (:studentid,:firstname,:lastname); */ 

{
           struct sqlexd sqlstm;
           sqlstm.sqlvsn = 13;
           sqlstm.arrsiz = 3;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.stmt = "insert into STUDENT (STUDENTID,FIRSTNAME,LASTNAME)\
 values (:b0,:b1,:b2)";
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )28;
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
            printf("\nINFO: Duplicate Record in Row %d for StudentID %d", count,studentid );
        }


    }   
    return 0; 

}

//--------------------------------------------------
// Routine to read Student master data to table
//-------------------------------------------------
int readStudentDetails( char *filename)
{
     char dataBuffer[500];
     char student[4][100];
     char *token;
     int count = 0;
     int i = 0;

    //------------------------------------------
    // open file
    //------------------------------------------
    FILE *fp = fopen(filename, "r");
    if( fp == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        return ERROR; 
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
        while( token != NULL ) 
        {
           strcpy( student[i], token );
           i++;
           token = strtok(NULL, DELIMITER);
        }

        //---------------------------------
        // each recod should have 3 fields
        //--------------------------------
        if( i < 4)
        {
               printf("\nERROR: Please validate data in row %d of input file. NULL values not allowed", count);
               return ERROR;
        }

        //--------------------------------------------
        // check if any of the values are null
        //--------------------------------------------
         for( int i = 0; i < 4; i++)
         {
            if( strcmp( student[i], "") == 0  || strlen(student[i]) == 0) 
            {
               printf("\nERROR: Please validate data in row %d of input file. NULL values not allowed", count);
               return ERROR;
            }

         }

        //---------------------------------------------
        // check if record already exists
        //--------------------------------------------
        studentid = atoi(student[0]);
        grade =  atoi(student[1]);
        year =  atoi(student[2]);
        gpa  = atof( student[3]);
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
        sqlstm.offset = (unsigned int  )55;
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


        //-------------------------------------
        // validate and insert to table
        //-------------------------------------
        if( reccount == 0)
        {
           printf("\n %d) Record being inserted to Student table", count);
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
           sqlstm.offset = (unsigned int  )82;
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
            printf("\nINFO: Duplicate Record in Row %d for StudentID %d,%d", count,studentid,grade  );
        }


    }   
    return 0; 

}

//--------------------------------------------------
// Routine to create a consolidated report
//-------------------------------------------------
int createreport( char *outfile)
{

    //-------------------------------------------------
    // declare cursor joining Student and Details table
    //-------------------------------------------------
    /* EXEC SQL DECLARE STDREPORT CURSOR FOR 
    SELECT A.STUDENTID, FIRSTNAME, GRADE, GPA, YEAR
    FROM STUDENT A, STUDENTDETAILS B 
    WHERE A.STUDENTID = B.STUDENTID
    ORDER BY A.STUDENTID; */ 

	/* EXEC SQL OPEN STDREPORT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )113;
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



    //----------------------------
    // initialize memory 
    //----------------------------
    if ((student_rec_ptr = 
        (struct student_details *) malloc(sizeof(struct student_details))) == 0)
    { 
        printf("Memory allocation error.\n"); 
        exit(EXIT_FAILURE); 
    } 

    //-------------------------------------
    // open output file in write mode
    //-------------------------------------
    FILE *fp = fopen(outfile, "w");
    if( fp == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        return ERROR; 
    }

    //------------------------------------
    // process data
    //------------------------------------
    for (;;) 
    { 
        /* EXEC SQL FETCH STDREPORT INTO :student_rec_ptr; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )128;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (           int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (         void  *)&student_rec_ptr->studentid;
        sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)student_rec_ptr->firstname;
        sqlstm.sqhstl[1] = (unsigned int  )50;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)&student_rec_ptr->grade;
        sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (         void  *)&student_rec_ptr->gpa;
        sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         void  *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned int  )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (         void  *)&student_rec_ptr->year;
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

 
        printf("\n Combined report: %d,%s, %d, %f, %d", student_rec_ptr->studentid, student_rec_ptr->firstname, student_rec_ptr->grade, 
        student_rec_ptr->gpa, student_rec_ptr->year);
        ltrim(rtrim(student_rec_ptr->firstname));
        fprintf( fp, "\n%d,%s,%d,%f,%d", student_rec_ptr->studentid, student_rec_ptr->firstname, student_rec_ptr->grade, 
        student_rec_ptr->gpa, student_rec_ptr->year);

    } 
    fclose(fp);
    /* EXEC SQL CLOSE STDREPORT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )163;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

 

    return 0;


}

int dblogin()
{
	strcpy(user_name, "system");
	strcpy(password, "or@cl321c");
  	/* exec sql connect:user_name identified by :password; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )10;
   sqlstm.offset = (unsigned int  )178;
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

int main () {

    //------------------------------------------
    // variable declaration
    //------------------------------------------
    char filename1[100];

    //-------------------------------------
	// login to database
	//-------------------------------------
    /* EXEC SQL WHENEVER SQLERROR GOTO errexit; */ 

    if( dblogin() != SUCCESS) { goto errexit; }


    //-----------------------------------------------
    // read studentID information into table STUDENT
    //-----------------------------------------------
    strcpy( filename1, "C:\\Users\\deepa\\OneDrive\\Documents\\c-code\\ProC\\input1.dat");
    int ret = readStudentid( filename1);
    if( ret != 0 )
    {
        goto errexit; 
    }
    

    //----------------------------------------------
    // read student details to table STUDENTDETAILS
    //----------------------------------------------
    strcpy( filename1, "C:\\Users\\deepa\\OneDrive\\Documents\\c-code\\ProC\\input2.dat");
    ret = readStudentDetails( filename1);
    if( ret != 0 )
    {
        goto errexit; 
    }
    


    //-----------------------------------------------
    // get consolidated report
    //-----------------------------------------------
    ret = createreport("C:\\Users\\deepa\\OneDrive\\Documents\\c-code\\ProC\\output.dat"); 


    


 

//----------------------------
// close
//----------------------------
printf("\n Processing successfully completed.\n\n");
/* EXEC SQL COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )209;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto errexit;
}

 
//_getch();
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
   sqlstm.offset = (unsigned int  )224;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   return 1;
	
}