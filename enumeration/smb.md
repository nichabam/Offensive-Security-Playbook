# SMB

## smbclient

```
smbclient -L \\\\192.168.232.55
```

With NT hash
```
smbclient \\\\<ip>\\<share> -U <username> --pw-nt-hash <NT hash>
```