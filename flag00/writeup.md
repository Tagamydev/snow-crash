From the subject we know we need to find files that are known by flag00 user.
So we run

```bash
level00@SnowCrash:~$ find / -group flag00 2> /dev/null
/usr/sbin/john
/rofs/usr/sbin/john
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
```

This seems like a cesar cypher using an online tool 


```html
https://www.dcode.fr/caesar-cipher
```

we find that the cypher means 'nottoohardhere' we then use that password to
move onto the flag00 user and run the command getflag getting 

```html
x24ti5gi3x0ol2eh4esiuxias
```