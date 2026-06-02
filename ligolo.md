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