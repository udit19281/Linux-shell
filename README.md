# Linux-shell
following 10 commands have been implemented with 3 options each.
1) echo =display a line of text
- echo -n string //do not output tratling newline
- echo -E string //disable interpretation of backslash escapes.
- echo string //print string

2) cd = change directory
- cd path //change directory to path
- cd -L path //force symbolic link
- cd -h //show help menu
- cd //cd to home directory
3) pwd =Print the name of the current working directory.
- pwd -P //avoid all symlinks
- pwd -h //show help menu
- pwd //print current directory.
4) history =show command history
- history //print history max size=1000 commands
- history -c //clear history
- history -d offset // remove value at offset from history
5) exit =exit the shell
- exit -n N //exit with status N
- exit -h //show help menu
- exit //normal exit with status 0
6) ls =list directory
- ls //list directory
- ls -1 //print in new line
- ls -a //do not ignore entries starting with .
7) cat = concatenate files and print on the standard output
- cat file.txt //show content of file
- cat -E file.txt //display $ at end of each line
- cat -n file.txt // number all output lines
8) rm =remove file
- rm file //remove file
- rm -i file //prompt before removal
- rm -f file //ignore nonexistent file and arguments,never prompt
9) mkdir =make directories
- mkdir namedir //make directory with name=namedir
- mkdir -v namedir //print a message for each created directory
- mkdir -p namedir //do not show error if existing
10) date =print date and time
- date //print current date and time in IST
- date -u //print date in UTC
- date -help //show help menu
# Run Command
make
