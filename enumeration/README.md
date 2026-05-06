# Enumeration

**Enumerate everything.**

Prioritize breadth first and get as much information on the target as possible before going deep into one possible attack point.

Enumerate all technologies and versions. Don't rush like it's a CTF

## Rough methodology
- Upon identifying a host:
    - nmap to enumerate ports

- Web (HTTP[s])
    - Directory Busting
    - Web components (Wappalyzer)
    - Sitemaps
    - Page Source
    - Web logic
    - Input fields
        - Injection (SQLi, Command)
        - File uploads
        - LFI, RFI

- SMB
    - Anonymous

- SNMP

- FTP

- More...