## Powershell

### Users and Groups
See which groups current user is in

```
whoami /groups
```

Get a list of local users

```
Get-LocalUser
```

Get a list of existing groups

```
Get-LocalGroup
```

Get members of a group

```
Get-LocalGroupMember <group name>
```

### System

```
systeminfo
```

Network information

```
ipconfig /all


# Routing table
route print

# Active network connections
netstat
```

Applications

```
# 32-Bit
Get-ItemProperty "HKLM:\SOFTWARE\Wow6432Node\Microsoft\Windows\CurrentVersion\Uninstall\*"

# 64-Bit
Get-ItemProperty "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\*"
```

Processes

```
Get-Process
```

### Powershell Filtering

For powershell cmd-let, use Select-Object or select to filter outputs

Example:

```
| select name, path
```

to output everything

```
| select *
```

Inspect all properties to find out what to filter

```
Get-Process | Get-Member
```