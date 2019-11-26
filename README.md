# get_next_line

A C function that reads any valid file line by line until the end.

### Table of content
* [What is get_next_line?](#what-is-get_next_line)
* [Why would I use/try it?](#why-would-i-usetry-it)
* [How do I use it?](#how-do-i-use-it)

### What is get_next_line?

get_next_line is an individual project at [1337][1] that basically reads a file line by line.

### Why would I use/try it?

You probably will never have to use this function if you are not a 1337 student. The goal is to get better at C.

After finishing this project, you'll definitely learn some more about static variables, pointers, arrays, linked lists (if you decide to do the bonus part), dynamic memory allocation and file manipulation.

Bare in mind that my code is not the best ;).

### How do I use it?

I added a main file called **main.c**, it takes a file name as an argument, opens it and passes the file descriptor (fd) to get_next_line until get_next_line returns -1 or 0.

**Note:** get_next_line returns -1, 0, 1 depending on wether an error has occurred, the reading has been completed or a line has been read respectively.

Alright, so first of all, download/clone this repo:

	git clone https://github.com/abdoabida/get_next_line
	
Get into it and build the library:
	
	cd get_next_line
	make -C libft/

Give it some time to compile all the files.

Build the executable:
	
	gcc -Wall -Wextra -Werror -L./libft -lft -o gnl get_next_line.c main.c

-L tells it where your library is found. `./libft`

-l takes the name of your library. This is the set of characters that come after `lib` in your library name.

**NOTE:** -L and -l might look a little bit too much, you could replace those flags with `libft/libft.a` if you want.

Alright, the last command created a `gnl` executable in your directory. Now test it with the file called `test`:

	./gnl test

It should read the whole file to you. Kinda like a basic `cat` implementation.


The instructions are clear enough, so I won't add anything else. If you have any questions, feel free to [ask me][8].

Enjoy.

[1]: https://www.1337.ma "1337 Khouribga"