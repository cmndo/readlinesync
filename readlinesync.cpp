//===========================================================================
//
// Readline Sync
//
// Author : Aaron M. Shea
// Date : 2/15/2013
// Version : 0.1.1
//
//
// - readline() (asynchronously get line from keyboard)
//
//===========================================================================

#include <node.h>
#include <v8.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>

using namespace v8;

//============================================================================
//  MODULE DECLARATION
//============================================================================

Handle<Value> ReadLineMethod(const Arguments& args)
{
	HandleScope scope;

	char *input = readline("=> ");

	return scope.Close(String::New(input));
}


void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("readline"),
		FunctionTemplate::New(ReadLineMethod)->GetFunction());
}

NODE_MODULE(readlinesync, init);
