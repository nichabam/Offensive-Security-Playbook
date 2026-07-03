# Setting Up

```
sudo neo4j start

bloodhound
```

Increase label font sizes
```
s = sigma.instances(0);
s.settings('defaultLabelSize', 16);
s.settings('defaultEdgeLabelSize', 20);
s.settings('labelSize', 'fixed');
s.settings('edgeLabelSize', 'fixed');
s.settings('labelThreshold', 0);
s.refresh();
```

# Collection

```
bloodhound-python -d <domain> -u <username> -p <password> -ns <dc-ip> -c all
```