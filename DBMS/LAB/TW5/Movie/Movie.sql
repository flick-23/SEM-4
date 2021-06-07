create database movie;
use movie;

CREATE TABLE ACTOR(
ACT_ID INT,
ACT_NAME VARCHAR(20),
ACT_GENDER CHAR(1),
PRIMARY KEY(ACT_ID)
);

INSERT INTO ACTOR VALUES(1,"AKSHAY KUMAR","M");
INSERT INTO ACTOR VALUES(2,"SALMAN KHAN","M");
INSERT INTO ACTOR VALUES(3,"ALIA BHAT","F");
INSERT INTO ACTOR VALUES(4,"KATRINA KAIF","F");
INSERT INTO ACTOR VALUES(5,"SRK","M");

CREATE TABLE DIRECTOR(
DIR_ID INT,
DIR_NAME VARCHAR (20),
DIR_PHONE  INT,
PRIMARY KEY(DIR_ID)
);

INSERT INTO DIRECTOR VALUES(1,"SLB",123456789);
INSERT INTO DIRECTOR VALUES(2,"RGV",234567891);
INSERT INTO DIRECTOR VALUES(3,"KJO",345678912);
INSERT INTO DIRECTOR VALUES(4,"ADITYA CHOPRA",456789123);
INSERT INTO DIRECTOR VALUES(5,"PRABU DEVA",567891234);
INSERT INTO DIRECTOR VALUES(6,"RAGHAVA L",678912345);
INSERT INTO DIRECTOR VALUES(7,"JAGAN SHAKTI",789123456);
INSERT INTO DIRECTOR VALUES(8,"TINU DESAI",891234567);

CREATE TABLE MOVIES(
MOV_ID INT,
MOV_TITLE VARCHAR (25),
MOV_YEAR INT,
MOV_LANG VARCHAR (12),
DIR_ID INT,
PRIMARY KEY (MOV_ID),
FOREIGN KEY (DIR_ID) REFERENCES DIRECTOR (DIR_ID)
);

INSERT INTO MOVIES VALUES(1,"DEVDAS",NULL,"HINDI",1);
INSERT INTO MOVIES VALUES(2,"RADHE",NULL,"HINDI",5);
INSERT INTO MOVIES VALUES(3,"DDLJ",NULL,"HINDI",4);
INSERT INTO MOVIES VALUES(4,"LAXMI BOMB",NULL,"HINDI",6);
INSERT INTO MOVIES VALUES(5,"MISSION MANGAL",NULL,"HINDI",7);
INSERT INTO MOVIES VALUES(6,"RUSTOM",NULL,"HINDI",8);

CREATE TABLE MOVIE_CAST(
ACT_ID INT,
MOV_ID INT,
ROLE VARCHAR(10),
PRIMARY KEY (ACT_ID, MOV_ID),
FOREIGN KEY (ACT_ID) REFERENCES ACTOR (ACT_ID),
FOREIGN KEY (MOV_ID) REFERENCES MOVIES (MOV_ID)
);

INSERT INTO MOVIE_CAST VALUES(1,4,"LEAD");
INSERT INTO MOVIE_CAST VALUES(1,5,NULL);
INSERT INTO MOVIE_CAST VALUES(1,6,NULL);
INSERT INTO MOVIE_CAST VALUES(2,2,NULL);
INSERT INTO MOVIE_CAST VALUES(3,1,NULL);
INSERT INTO MOVIE_CAST VALUES(3,3,NULL);

CREATE TABLE RATING(
MOV_ID INT,
REV_STARS VARCHAR (25),
PRIMARY KEY (MOV_ID),
FOREIGN KEY (MOV_ID) REFERENCES MOVIES (MOV_ID)
);

INSERT INTO RATING VALUES(1,4);
INSERT INTO RATING VALUES(2,3);
INSERT INTO RATING VALUES(3,5);
INSERT INTO RATING VALUES(4,4);
INSERT INTO RATING VALUES(5,3);
INSERT INTO RATING VALUES(6,3);

SELECT MOV_TITLE FROM MOVIES WHERE DIR_ID IN (SELECT DIR_ID FROM DIRECTOR WHERE DIR_NAME ="SLB");

SELECT MOV_TITLE FROM MOVIES as M, MOVIE_CAST as MV WHERE M.MOV_ID = MV.MOV_ID AND ACT_ID IN (SELECT ACT_ID FROM MOVIE_CAST GROUP BY ACT_ID HAVING COUNT(ACT_ID) > 1) GROUP BY MOV_TITLE HAVING COUNT(*)>1;

SELECT MOV_TITLE, MAX(REV_STARS) FROM MOVIES INNER JOIN RATING USING (MOV_ID) GROUP BY MOV_TITLE HAVING MAX(REV_STARS)>0 ORDER BY MOV_TITLE;

UPDATE RATING SET REV_STARS = 5 WHERE MOV_ID IN (SELECT MOV_ID FROM MOVIES WHERE DIR_ID IN (SELECT DIR_ID FROM DIRECTOR WHERE DIR_NAME ="RGV"));
