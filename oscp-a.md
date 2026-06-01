# OSCP A Lessons / Missed Patterns

1. Unknown port enumeration
- Do not dismiss unknown ports just because Nmap gives a weird or uncertain service name.
- If Nmap shows something like cgms?, treat it as unknown.
- Search the port number and common services:
  - "port 3003"
  - "3003 tcp service"
  - "3003 exploit"
  - "<nmap guess> <port>"
- Correlate unknown ports with web leaks such as /heartbeat, /health, /status, /api, /debug, /metrics.

2. Recursive web enumeration
- If a directory like /api is found, recursively fuzz inside it.
- High-value endpoints:
  - /api/heartbeat
  - /api/health
  - /api/status
  - /api/debug
  - /api/metrics
  - /server-status
  - /actuator
- These may reveal backend services, databases, hostnames, ports, or versions.

3. pspy for Linux privesc
- Run pspy when local enumeration is unclear.
- Look for UID=0 processes running scripts or commands.
- Focus on:
  - root-executed writable scripts
  - cron jobs
  - relative paths
  - wildcard usage
  - commands exposing credentials
  - services/scripts triggered by web activity

4. Symlink behavior
- If root executes a symlinked script, check both:
  - the symlink path
  - the real target path using readlink -f
- Writing to a symlink usually writes through to the target.
- Replacing a symlink changes where it points, if the parent directory is writable.
- Always check:
  - ls -l symlink
  - readlink -f symlink
  - ls -l target
  - ls -ld parent_directory

5. Shell stability
- If Bash is available, /dev/tcp reverse shells can be stable and simple.
- Useful when nc is missing or unreliable.
- Still upgrade shell afterward when possible:
  - python3 pty
  - stty rows/cols
  - export TERM=xterm