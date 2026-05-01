# SQL Enumeration Cheat Sheet (MySQL & MSSQL)

## 1. Show Databases
### MySQL
```
SHOW DATABASES;
```

### MSSQL
```
SELECT name FROM sys.databases;
```

## 2. Show Tables within a database
### MySQL
```
USE database_name;

SHOW TABLES;
```

### MSSQL
```
USE database_name;

SELECT name FROM sys.tables;
```

## 3. Show Columns within a table
### MySQL
```
DESCRIBE table_name;

SHOW COLUMNS FROM table_name;
```

### MSSQL
```
SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'table_name';
```

## 4. Ordering
### MySQL
```
SELECT * FROM table_name ORDER BY column_name;
```

### MSSQL
```
SELECT * FROM table_name ORDER BY column_name;
```

## 5. Important System tables

### MySQL
```
INFORMATION_SCHEMA.TABLES

INFORMATION_SCHEMA.COLUMNS

INFORMATION_SCHEMA.SCHEMATA
```

### MSSQL
Core
```
sys.databases
sys.tables
sys.columns
sys.objects
```

Users / Auth
```
sys.database_principals
sys.server_principals
sys.sql_logins
sysusers
syslogins
```
