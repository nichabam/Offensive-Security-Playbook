# Legacy Tools

## Users and Groups

Get domain users with net.exe

```
net user /domain
```

Domain user information

```
net user <username> /domain
```

Get domain groups

```
net group /domain
```

Domain group information

```
net group "group name" /domain
```

# Powersploit

[PowerView](https://powersploit.readthedocs.io/en/latest/Recon/)

```
Import-Module .\PowerView.ps1
```

## Initial Enum / Basic info

Domain info

```
Get-NetDomain
```

Domain Users info

```
Get-NetUser

Get-NetUser | select cn

# Membership
Get-NetUser <username> | select memberof
```

Domain Groups info

```
Get-NetGroup

Get-NetGroup | select cn

# Group members
Get-NetGroup "<groupname>" | select member
```

## System Info

```
Get-NetComputer

Get-NetComputer | select operatingsystem,dnshostname
```

## Local Admin Access

```
Find-LocalAdminAccess
```

## Logged on Users

```
Get-NetSession -ComputerName <hostname> -Verbose
```

note: *this actually doesnt work all the time due to NetSesssionEnumAPI permissions*

Use this *sysinternals* tool instead:

```
.\PsLoggedon.exe \\<hostname>
```

because PsLoggedon.exe does not use NetSessionEnumAPI

## SPN - Service Principal Name

```
Get-NetUser -SPN

Get-NetUser -SPN | select samaccountname, serviceprincipalname
```

```
setspn -L <SPN>
```

## Object Permissions - ACE, ACL

```
Get-ObjectAcl -Identity <name>

Get-ObjectAcl -Identity <name> | where { $_.ActiveDirectoryRights -match "GenericAll" } | select SecurityIdentifier, ActiveDirectoryRights
```

example:

```
Get-ObjectAcl -Identity "Management Department"

Get-ObjectAcl -Identity "Jeff" | where { $_.ActiveDirectoryRights -match "GenericAll" } | select SecurityIdentifier, ActiveDirectoryRights
```

Convert Sid

```
Convert-SidToName <sid>

<sid>, <sid2>, .. | Convert-SidToName
```

## Shares

```
Find-DomainShare
```

Inspect share

```
dir "\\ComputerName\ShareName\"
```