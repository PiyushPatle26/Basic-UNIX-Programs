LS(1) User Commands LS(1)

NAME
ls - list directory contents

SYNOPSIS
ls [OPTION]... [FILE]...

DESCRIPTION
List information about the FILEs (the current directory by default).
Sort entries alphabetically if none of -cftuvSUX nor --sort is speci‐
fied.

       Mandatory  arguments  to  long  options are mandatory for short options
       too.

       -a, --all
              do not ignore entries starting with .

       --author
              with -l, print the author of each file

       -b, --escape
              print C-style escapes for nongraphic characters


       -c     with -lt: sort by, and show, ctime (time of last modification of
              file status information); with -l: show ctime and sort by  name;
              otherwise: sort by ctime, newest first

       -d, --directory
              list directories themselves, not their contents

       -f     do not sort, enable -aU, disable -ls --color

       --file-type
              likewise, except do not append '*'

       -r, --reverse
              reverse order while sorting

       -R, --recursive
              list subdirectories recursively

       -Z, --context
              print any security context of each file

       -1     list one file per line.  Avoid '\n' with -q or -b

       --help display this help and exit

       --version
              output version information and exit
