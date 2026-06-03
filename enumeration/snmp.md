# SNMP Enum

## Port scan

```
sudo nmap -sU -p161 <IP>
```

```
sudo nmap -sU -p161 --script snmp-* <IP>
```

## Community string

common:
```
public
private
```

Bruteforce
```
onesixtyone -c /usr/share/seclists/Discovery/SNMP/snmp.txt <IP>

hydra -P /usr/share/wordlists/seclists/Discovery/SNMP/common-snmp-community-strings.txt snmp://<ip>
```

## Information

snmp-check
```
snmp-check <IP> -c public
snmp-check <IP> -c public -v 2c
```

### snmpwalk

```
# System info
snmpwalk -On -v2c -c public -t 2 -r 1 <IP> 1.3.6.1.2.1.1

# Network interfaces
snmpwalk -On -v2c -c public -t 2 -r 1 <IP> 1.3.6.1.2.1.2.2

# Running processes + arguments
snmpwalk -On -v2c -c public -t 2 -r 1 <IP> 1.3.6.1.2.1.25.4.2.1

# Installed software
snmpwalk -On -v2c -c public -t 2 -r 1 <IP> 1.3.6.1.2.1.25.6.3.1

# TCP connections / listening ports
snmpwalk -On -v2c -c public -t 2 -r 1 <IP> 1.3.6.1.2.1.6.13

# Storage / mounted filesystems
snmpwalk -On -v2c -c public -t 2 -r 1 <IP> 1.3.6.1.2.1.25.2.3

# Net-SNMP extend scripts/output — VERY IMPORTANT
snmpwalk -On -v2c -c public -t 2 -r 1 <IP> 1.3.6.1.4.1.8072.1.3.2
```

Windows
```
# Users
snmpwalk -On -v2c -c public -t 2 -r 1 <IP> 1.3.6.1.4.1.77.1.2.25

# Shares
snmpwalk -On -v2c -c public -t 2 -r 1 <IP> 1.3.6.1.4.1.77.1.2.27
```