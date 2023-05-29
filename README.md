# Jawa-lang
OS: <img alt="Windows" src="https://img.shields.io/badge/Windows-0078D6?logo=windows&logoColor=white&style=flat"/><br><br>
_This repository is for my fun project hobby of creating the new Jawa programming language based on C programming language that i've learned so far._

## About this programming language 🤔
Jawa lang (Jawa Language) or Jawa Programming Language is a programming language that actually more like scripting language (like Python) that build on top of basic C programming language. This programming language take the inspiration from Native Jawa Language that use for everyday communication in Central Java and Yogyakarta Province, Indonesia.

## Example code and syntax 📄

- Print 'Hello world!'
  ```
  ketok "Hello world".
  ```
- Do some basic arithmetic operation 
  ```
  nomer sepuluh kuwi 10.
  nomer duaLima kuwi 25.
  nomer hasilTambah kuwi sepuluh + duaLima.

  ketok "Hasil tambah = " hasilTambah.

  nomer kali kuwi 5.
  nomer hasilKali kuwi hasilTambah * kali.

  ketok "Setelah di kali = " hasilKali.
  ```
- _coming soon ......_
  
## Rules 📌

- Each line of code is terminated by period (.)
- Automatically add new line after period (.)
- Use ``noEnter`` flag after period (.) behind line of code to prevent adding new line for printing the text buffer
  example :
  ```
  ketok "Hello world!".noEnter
  ketok "Another world!".
  ```
## Requirements 
> MUST HAVE gcc compiler installed on your computer

## Build and Run the code ⚙🛠

- Store the code in ``.jawa`` file extension (e.g ``test.jawa``)
- Move the ``jawa.exe`` file inside the same directory of your ``.jawa`` source code file
- Run the command prompt in that directory
- Type this command :
  ```bat
  jawa.exe <fileName>.jawa
  ```
  
  example
  ```bat
  jawa.exe test.jawa
  ```
- Then press enter and wait until the ``jawaOutput.exe`` file is appear and automatically launch the executable from compiled ``.jawa`` source code

## Coming soon
