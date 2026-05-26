# SSH

```
$ ssh-keygen
Generating public/private rsa key pair.
Enter file in which to save the key (/home/kali/.ssh/id_rsa): keyfile
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in keyfile
Your public key has been saved in keyfile.pub

$ cat keyfile.pub > authorized_keys
```

Then upload authorized keys to ```user/.ssh/authorized_keys```

Example: ```/root/.ssh/authorized_keys```

Connect:

```
ssh -i keyfile user@host
```