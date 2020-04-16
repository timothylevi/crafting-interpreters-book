package com.craftinginterpreters.lox;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class Lox {
  // Whether an error occurred while running the program.
  // This will be used to kill a program run from a file.
  static boolean hadError = false;

  // The entry-point to our interpreter.
  // If `jlox` is called from the command line with:
  //    more than one argument, exit immediately
  //    exactly one argument, read from the file and run
  //    exactly zero arguments, open an interactive REPL
  public static void main(String[] args) throws IOException {
    if (args.length > 1) {
      System.out.println("Usage: jlox [script]");
      System.exit(64);
    } else if (args.length == 1) {
      runFile(args[0]);
    } else {
      runPrompt();
    }
  }

  // Interpret and run a file from a given path. This function
  // creates a `bytes` array from reading the file from the path,
  // and then calls `run` with a string of bytes using the
  // default charset. If an error is reported, then kill the program.
  private static void runFile(String path) throws IOException {
    byte[] bytes = Files.readAllBytes(Paths.get(path));
    run(new String(bytes, Charset.defaultCharset()));

    if (hadError) System.exit(65)
  }

  // Create a REPL by reading the stream from system input
  // generating a buffered reader which can read one line at a time
  // and then beginning an infinite loop which prints a prompt
  // symbol ">", and then calls `run` with a new line.
  private static void runPrompt() throws IOException {
    InputStreamReader input = new InputStreamReader(System.in);
    BufferedReader reader = new BufferedReader(input);

    for (;;) {
      System.out.print("> ");
      run(reader.readLine());

      // NOTE: I don't think this is necessary
      hadError = false;
    }
  }

  // Create a new scanner with source code (from the file or
  // from the REPL), scan the tokens in the source code, and
  // print out each of the tokens on a new line.
  private static void run(String source) {
    Scanner scanner = new Scanner(source);
    List<Token> tokens = scanner.scanTokens();

    for (Token token : tokens) {
      System.out.println(token);
    }
  }
}
