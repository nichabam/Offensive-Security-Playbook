# WPSCAN

```wpscan --url http://<url> --enumerate -ap,u,t```

```
ap = All plugins
u  = User IDs
t  = Popular themes

wpscan -h for more options
```

- Check plugins for outdated versions that may be vulnerable

# Misconfigured Directories

Sometimes directory busting may reveal these directories which indicates Wordpress as the underlying CMS.
```
/wp-content
/wp-includes
```

# Login page

```
/wp-admin
/wp-login.php
```