/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2008                    */
/* Created on:     2017/12/8 16:26:30                           */
/*==============================================================*/


if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CITY') and o.name = 'FK_CITY_LEAD_LEADER')
alter table CITY
   drop constraint FK_CITY_LEAD_LEADER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('MONIPERSON') and o.name = 'FK_MONIPERS_WORKIN_MONISTAT')
alter table MONIPERSON
   drop constraint FK_MONIPERS_WORKIN_MONISTAT
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('MONISTATION') and o.name = 'FK_MONISTAT_MANAGE_AGENT')
alter table MONISTATION
   drop constraint FK_MONISTAT_MANAGE_AGENT
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Monitor') and o.name = 'FK_MONITOR_MONITOR_MONISTAT')
alter table Monitor
   drop constraint FK_MONITOR_MONITOR_MONISTAT
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Monitor') and o.name = 'FK_MONITOR_MONITOR2_CITY')
alter table Monitor
   drop constraint FK_MONITOR_MONITOR2_CITY
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Monitor') and o.name = 'FK_MONITOR_MONITOR3_MAINPO')
alter table Monitor
   drop constraint FK_MONITOR_MONITOR3_MAINPO
go

if exists (select 1
            from  sysobjects
           where  id = object_id('AGENT')
            and   type = 'U')
   drop table AGENT
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('CITY')
            and   name  = 'Lead_FK'
            and   indid > 0
            and   indid < 255)
   drop index CITY.Lead_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('CITY')
            and   type = 'U')
   drop table CITY
go

if exists (select 1
            from  sysobjects
           where  id = object_id('LEADER')
            and   type = 'U')
   drop table LEADER
go

if exists (select 1
            from  sysobjects
           where  id = object_id('MAINPO')
            and   type = 'U')
   drop table MAINPO
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('MONIPERSON')
            and   name  = 'WorkIn_FK'
            and   indid > 0
            and   indid < 255)
   drop index MONIPERSON.WorkIn_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('MONIPERSON')
            and   type = 'U')
   drop table MONIPERSON
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('MONISTATION')
            and   name  = 'Manage_FK'
            and   indid > 0
            and   indid < 255)
   drop index MONISTATION.Manage_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('MONISTATION')
            and   type = 'U')
   drop table MONISTATION
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Monitor')
            and   name  = 'Monitor_FK'
            and   indid > 0
            and   indid < 255)
   drop index Monitor.Monitor_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Monitor')
            and   name  = 'Monitor3_FK'
            and   indid > 0
            and   indid < 255)
   drop index Monitor.Monitor3_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Monitor')
            and   name  = 'Monitor2_FK'
            and   indid > 0
            and   indid < 255)
   drop index Monitor.Monitor2_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Monitor')
            and   type = 'U')
   drop table Monitor
go

/*==============================================================*/
/* Table: AGENT                                                 */
/*==============================================================*/
create table AGENT (
   Aid                  varchar(10)          not null,
   Aname                varchar(20)          not null,
   sex                  varchar(5)           not null,
   birthday             varchar(20)          null,
   phonenum             varchar(20)          null,
   constraint PK_AGENT primary key nonclustered (Aid)
)
go

/*==============================================================*/
/* Table: CITY                                                  */
/*==============================================================*/
create table CITY (
   CID                  varchar(10)          not null,
   Lid                  varchar(10)          not null,
   Cname                varchar(10)          not null,
   area                 int                  not null,
   townnum              int                  not null,
   population           int                  not null,
   constraint PK_CITY primary key nonclustered (CID)
)
go

/*==============================================================*/
/* Index: Lead_FK                                               */
/*==============================================================*/
create index Lead_FK on CITY (
Lid ASC
)
go

/*==============================================================*/
/* Table: LEADER                                                */
/*==============================================================*/
create table LEADER (
   Lid                  varchar(10)          not null,
   Lname                varchar(20)          not null,
   sex                  varchar(5)           not null,
   birthday             varchar(20)          null,
   gschool              varchar(20)          null,
   constraint PK_LEADER primary key nonclustered (Lid)
)
go

/*==============================================================*/
/* Table: MAINPO                                                */
/*==============================================================*/
create table MAINPO (
   PID                  varchar(10)          not null,
   Pname                varchar(20)          not null,
   ingredient           varchar(20)          null,
   namedate             varchar(10)          null,
   constraint PK_MAINPO primary key nonclustered (PID)
)
go

/*==============================================================*/
/* Table: MONIPERSON                                            */
/*==============================================================*/
create table MONIPERSON (
   MPid                 varchar(10)          not null,
   MSID                 varchar(10)          not null,
   MPname               varchar(20)          not null,
   sex                  varchar(5)           not null,
   phonenum             varchar(20)          null,
   constraint PK_MONIPERSON primary key nonclustered (MPid)
)
go

/*==============================================================*/
/* Index: WorkIn_FK                                             */
/*==============================================================*/
create index WorkIn_FK on MONIPERSON (
MSID ASC
)
go

/*==============================================================*/
/* Table: MONISTATION                                           */
/*==============================================================*/
create table MONISTATION (
   MSID                 varchar(10)          not null,
   Aid                  varchar(10)          not null,
   MSname               varchar(20)          not null,
   location             varchar(20)          not null,
   phonenum             varchar(20)          null,
   constraint PK_MONISTATION primary key nonclustered (MSID)
)
go

/*==============================================================*/
/* Index: Manage_FK                                             */
/*==============================================================*/
create index Manage_FK on MONISTATION (
Aid ASC
)
go

/*==============================================================*/
/* Table: Monitor                                               */
/*==============================================================*/
create table Monitor (
   CID                  varchar(10)          not null,
   PID                  varchar(10)          not null,
   MSID                 varchar(10)          not null,
   MID                  varchar(10)          not null,
   AQI                  int                  not null,
   Date                 varchar(20)          not null,
   Time                 varchar(10)          not null,
   constraint PK_MONITOR primary key nonclustered (CID, PID, MSID, MID)
)
go

/*==============================================================*/
/* Index: Monitor2_FK                                           */
/*==============================================================*/
create index Monitor2_FK on Monitor (
CID ASC
)
go

/*==============================================================*/
/* Index: Monitor3_FK                                           */
/*==============================================================*/
create index Monitor3_FK on Monitor (
PID ASC
)
go

/*==============================================================*/
/* Index: Monitor_FK                                            */
/*==============================================================*/
create index Monitor_FK on Monitor (
MSID ASC
)
go

alter table CITY
   add constraint FK_CITY_LEAD_LEADER foreign key (Lid)
      references LEADER (Lid)
go

alter table MONIPERSON
   add constraint FK_MONIPERS_WORKIN_MONISTAT foreign key (MSID)
      references MONISTATION (MSID)
go

alter table MONISTATION
   add constraint FK_MONISTAT_MANAGE_AGENT foreign key (Aid)
      references AGENT (Aid)
go

alter table Monitor
   add constraint FK_MONITOR_MONITOR_MONISTAT foreign key (MSID)
      references MONISTATION (MSID)
go

alter table Monitor
   add constraint FK_MONITOR_MONITOR2_CITY foreign key (CID)
      references CITY (CID)
go

alter table Monitor
   add constraint FK_MONITOR_MONITOR3_MAINPO foreign key (PID)
      references MAINPO (PID)
go

