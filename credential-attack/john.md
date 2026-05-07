# JtR

## Rules

```
[List.Rules:rulename]
c $1 $3 $7 $!
c $137@
u ^1#
```

Case change

```
c      # Capitalize → password → Password
u      # UPPERCASE → PASSWORD
l      # lowercase → password
t      # Toggle all → pAssWORD → PaSSword
T0     # Toggle first char → Password
T1     # Toggle second char → pAssword
```

Append / Prepend

```
$1     # Append "1" → password1
$!     # Append "!" → password!
$123   # Append "123" → password123

^!     # Prepend "!" → !password
^2024  # Prepend "2024" → 2024password
```

Substitutions

```
sa@    # a → @ → p@ssword
so0    # o → 0 → passw0rd
se3    # e → 3 → passw3rd
si1    # i → 1
ss$    # s → $
```

## SSH

```
ssh2john id_rsa > key.hash

john --wordlist=/usr/share/wordlists/rockyou.txt key.hash

john --wordlist=/usr/share/wordlists/rockyou.txt --rules=sshRules key.hash
```

## KeePass

```
keepass2john database.kdbx > key.hash

john --wordlist=/usr/share/wordlists/rockyou.txt key.hash
```