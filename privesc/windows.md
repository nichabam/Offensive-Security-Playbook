# Enumeration

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
netstat -ano | findstr LISTENING
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

### Files

#### Get-ChildItem


Get all txt,ini,config,pdf files from C:\

```
Get-ChildItem C:\ -Recurse -Include *.txt,*.ini,*.config,*.pdf -File
```

Find txt files in the user directory that matches the regex "login"

```
Get-ChildItem C:\Users\admin -Recurse -Filter *.txt | Where-Object { $_.Name -match "login" }
```

Filter and include notes:

```
-Filter
faster but cannot handle multiple extensions

Example:
-Filter *.txt, *.ini does NOT work


-Include
Slower but can handle multiple extensions

-Recurse
Needed to use -Include
```

These two can only handle wildcards : *.txt *.ini ...
For complex patterns, use 

```
| Where-Object { $_.Name -match "REGEX HERE" }
```

### Windows Services

Get services

```
Get-CimInstance -ClassName win32_service | Select Name,State,PathName
```

To get only running services

```
| Where-Object { $_.State -match 'Running' }
```

To filter out Windows\system32

```
| Where-Object { $_.PathName -notmatch 'Windows' }
```

Check permissions on path

```
icacls "path"
```

Unquoted services

```
wmic service get name,pathname |  findstr /i /v "C:\Windows\\" | findstr /i /v """
```

### Scheduled Tasks

To query all

```
schtasks /query /fo LIST /v
```

scheduled tasks that are not by microsoft

```
Get-ScheduledTask | Select-Object TaskName, TaskPath, Author |  Where-Object { $_.Author -notmatch 'Microsoft' }
```

Get next run time with Get-ScheduledTaskInfo
```
Get-ScheduledTaskInfo <TaskPath>\<TaskName>
```
