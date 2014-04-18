module main;

import std.stdio;
import core.thread;
import std.conv;
import std.concurrency;

/**
*   This program was wrotted just for fun
*   and for studying spawn function in D language
*   This 'algorithm' works for O(m), where m is max inputed value
*/

void f(int i)
{
    Thread.sleep(dur!("msecs")(i));
    //  For too slow computers use:
    //  Thread.sleep(dur!("seconds")(i));
    writeln(i);
}

int main(string[] args)
in
{
    assert(args.length > 1, "Please, enter some integers to sortn.\n");
}
body
{
    foreach(i; 1..args.length)
       spawn(&f, to!int(args[i]));

    return 0;
}
